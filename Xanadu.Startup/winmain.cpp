#include <iostream>
#include <ShlObj.h>
#include "GLApp.h"
#include "Colors.h"
#include "FileManager.h"
#include "SystemLogger.h"
#include "MessageDispatcher.h"


#include <list>
#include <boost/filesystem.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/exception/to_string.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "Guid.h"

namespace fs = boost::filesystem;
namespace xnd = Xanadu::Engine;
namespace util = Xanadu::Utilities;

class TestApp : public xnd::GLApp
{
public:
	TestApp(HINSTANCE hInstance);
	~TestApp();
	bool Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) override;
};

int start()
{
	auto app = TestApp(0);
	app.Init();
	return app.Run();
}


int main()
{
	auto log = util::SystemLogger::Instance();

	log->Info( "Starting Xanadu Game Engine" );
	log->Info( "Copyright (C)2017, William W. Westlake Jr." );
	log->Info( "email: wwestlake@lagdaemon.com" );
	log->Info( "All Rights Reserved" );

#if 1
	return start();
#else
	std::cout << "Press Any Key" << std::endl;
	char in[255];
	std::cin >> in;

#endif
}


TestApp::TestApp(HINSTANCE hInstance) : GLApp(hInstance)
{
}

TestApp::~TestApp()
{
}

bool TestApp::Init()
{
	if (!GLApp::Init()) return false;
	return true;
}

void TestApp::Update(float deltaTime)
{
}

void TestApp::Render()
{
	glClearColor(RGB_FROM_COLOR(Xanadu::Colors::LightSteelBlue));
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
}

LRESULT TestApp::MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	default:
		return GLApp::MsgProc(hwnd, msg, wParam, lParam);
	}
}
