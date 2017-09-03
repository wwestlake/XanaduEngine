/***************************************************************************************
Xanadu Open GL Windows Game Engine
Copyright (C) 2017  William W. Westlake Jr.
wwestlake@lagdaemon.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************************/


#include "GLApp.h"
#include "GLUtil.h"
#include "SystemLogger.h"
#include <map>
#include <boost/shared_ptr.hpp>
#include "XMemoryManager.h"
#include "XIndividual.h"
#include "MessageDispatcher.h"

namespace util = Xanadu::Utilities;


namespace Xanadu {
	namespace Engine {

		namespace
		{
			std::map<HWND, GLApp*> apps;
		}

		LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			GLApp* callback = apps[hwnd];

			if (callback)
				return callback->MsgProc(hwnd, msg, wParam, lParam);
			else
				return DefWindowProc(hwnd, msg, wParam, lParam);
		}

		XIndividual* test;

		GLApp::GLApp()
		{
			test = new XIndividual();
		}

		GLApp::GLApp(HINSTANCE hInstance)
		{
			test = new XIndividual();
			m_hAppInstance = hInstance;
			m_hAppWnd = NULL;
			m_hDevContext = NULL;
			m_hGLRenderContext = NULL;
			m_ClientWidth = 1200;
			m_ClientHeight = 900;
			m_AppTitle = L"OpenGL Application";
			m_WindowStyle = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX;
			m_FPS = 0.0f;
		}

		GLApp::~GLApp()
		{
		}

		int GLApp::Run()
		{
			__int64 prevTime = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&prevTime);
			__int64 countsPerSec = 0;
			QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
			float secondsPerCount = 1.0f / countsPerSec;
			MSG msg = { 0 };
			while (WM_QUIT != msg.message)
			{
				if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				else
				{
					__int64 curTime = 0;
					QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
					float deltaTime = (curTime - prevTime) * secondsPerCount;
					MessageDispatcher::GetInstance()->Tick(deltaTime);
					Update(deltaTime);
					Render();
					CalculateFPS(deltaTime);

					SwapBuffers(m_hDevContext);

					prevTime = curTime;
				}
			}

			Shutdown();
			return static_cast<int>(msg.wParam);
		}

		bool GLApp::Init()
		{
			if (!InitWindow()) return false;
			if (!InitGL()) return false;
			return true;
		}


		bool GLApp::InitWindow()
		{
			WNDCLASSEX wcex;
			ZeroMemory(&wcex, sizeof(WNDCLASSEX));
			wcex.cbClsExtra = 0;
			wcex.cbWndExtra = 0;
			wcex.cbSize = sizeof(WNDCLASSEX);
			wcex.style = CS_HREDRAW | CS_VREDRAW;
			wcex.hInstance = m_hAppInstance;
			wcex.lpfnWndProc = MainWndProc;
			wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
			wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
			wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
			wcex.lpszClassName = L"GLAPPWNDCLASS";
			wcex.lpszMenuName = NULL;
			wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

			if (!RegisterClassEx(&wcex)) return OutErrorMessage(std::string("Failed to register WNDCLASSEX"));

			// adjust window to reqursted client size
			RECT r = { 0, 0, m_ClientWidth, m_ClientHeight };
			AdjustWindowRect(&r, m_WindowStyle, FALSE);
			int width = r.right - r.left;
			int height = r.bottom - r.top;
			int x = GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2;
			int y = GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2;

			// create application window
			m_hAppWnd = CreateWindow(wcex.lpszClassName, m_AppTitle, m_WindowStyle, x, y, width, height, NULL, NULL, m_hAppInstance, NULL);
			if (!m_hAppWnd) return OutErrorMessage(std::string("Unable to create window"));

			apps[m_hAppWnd] = this;

			// show window
			ShowWindow(m_hAppWnd, SW_SHOW);

			return true;
		}

		LRESULT GLApp::MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			switch (msg)
			{
			case WM_DESTROY:
				PostQuitMessage(0);
				return 0;

			default:
				return DefWindowProc(hwnd, msg, wParam, lParam);
			}
			return LRESULT();
		}

		bool GLApp::OutErrorMessage(std::string & message)
		{
			util::SystemLogger::Instance()->Critical(message);
			return false;
		}


		bool GLApp::InitGL()
		{
			// create device context
			m_hDevContext = GetDC(m_hAppWnd);

			// create pixel format descriptor
			PIXELFORMATDESCRIPTOR pfd;
			ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

			pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
			pfd.nVersion = 1;
			pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
			pfd.iPixelType = PFD_TYPE_RGBA;
			pfd.cColorBits = 32;
			pfd.cDepthBits = 24;
			pfd.cStencilBits = 8;

			int format = ChoosePixelFormat(m_hDevContext, &pfd);
			if (!SetPixelFormat(m_hDevContext, format, &pfd)) return OutErrorMessage(std::string("Unable to Set Pixel Format!"));

			// Create Render Context
			m_hGLRenderContext = wglCreateContext(m_hDevContext);
			if (!wglMakeCurrent(m_hDevContext, m_hGLRenderContext)) return OutErrorMessage(std::string("Unable to create and activate a render context"));

			// initialize glew
			if (glewInit()) return OutErrorMessage(std::string("Failed to initialize glew"));



			return true;
		}

		void GLApp::CalculateFPS(float deltaTime)
		{
			static float elapsed = 0;
			static int frameCount = 0;

			elapsed += deltaTime;
			frameCount++;


			if (elapsed >= 1.0f)
			{
				m_FPS = (float)frameCount;

#ifdef _DEBUG
				//std::stringstream ss;
				//ss << m_AppTitle << " FPS:" << m_FPS << " " << glGetString(GL_VENDOR);
				//ss << " " << glGetString(GL_RENDER);
				//ss << " " << glGetString(GL_VERSION);
				//SetWindowText(m_hAppWnd, ss.str().c_str());
#endif
				elapsed = 0.0f;
				frameCount = 0;
			}


		}

		void GLApp::Shutdown()
		{
			wglMakeCurrent(NULL, NULL);
			wglDeleteContext(m_hGLRenderContext);
			ReleaseDC(m_hAppWnd, m_hDevContext);
		}
	}
}


