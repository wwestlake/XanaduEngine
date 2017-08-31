#ifndef __GLAPP_H
#define __GLAPP_H

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



#include "defines.h"
#include "GLUtil.h"

namespace Xanadu {
	namespace Engine {

		class XANADU_API GLApp
		{
		public:
			GLApp();
			GLApp(HINSTANCE hInstance);
			virtual ~GLApp();


			// main application loop
			int Run();

			//Framework Methods
			virtual bool Init();
			virtual void Update(float deltaTime) = 0;
			virtual void Render() = 0;
			virtual LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

			float GetFPS() { return m_FPS; }

			bool OutErrorMessage(std::string & message);

		protected:
			HWND		m_hAppWnd;
			HINSTANCE	m_hAppInstance;
			HDC			m_hDevContext;
			HGLRC		m_hGLRenderContext;
			UINT		m_ClientWidth;
			UINT		m_ClientHeight;
			DWORD		m_WindowStyle;
			LPWSTR		m_AppTitle;
			float		m_FPS;

		protected:

			// Initialize Window
			bool InitWindow();

			// Initialize OpenGL
			bool InitGL();

			// Calcujlate the Frames Per Second
			void CalculateFPS(float deltaTime);

			// Shutdown OpenGL
			void Shutdown();



		};

	}
}
#endif