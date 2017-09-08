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
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include "Guid.h"

namespace fs = boost::filesystem;
namespace xnd = Xanadu::Engine;
namespace util = Xanadu::Utilities;

class TestApp : public xnd::GLApp
{
public:
	TestApp(HINSTANCE hInstance, int argc, char** argv);
	~TestApp();
	bool Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) override;
};

int start(int argc, char** argv)
{
	auto app = TestApp(0, argc, argv);
	app.Init();
	return app.Run();
}

string get_input() {
	string inp;
	char tmp;
	for (;;) {
		cin.get(tmp);
		if (tmp != '\n')inp += tmp;
		else break;
	}
	return inp;
}


void repl() {
	std::string prompt = "xan> ";
	bool running = true;
	char buffer[256];
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Xanadu Game Engine, Command Interpreter" << std::endl;
	std::cout << "Copyright (C) 2013, William Westlake" << std::endl;

	while (running)
	{
		std::cout << prompt;
		string input = get_input();
		if (input.compare("quit") == 0) {
			return;
		}
		if (input.length() > 0) std::cout << input << std::endl;
	}
}

int main(int argc, char** argv)
{
	auto log = util::SystemLogger::Instance();

	log->Info( "Starting Xanadu Game Engine" );
	log->Info( "Copyright (C)2017, William W. Westlake Jr." );
	log->Info( "email: wwestlake@lagdaemon.com" );
	log->Info( "All Rights Reserved" );

#if 1
	boost::thread main_thread(start, argc, argv);
	boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
	boost::thread repl_thread(repl);

	//main_thread.join();
	repl_thread.join();
	return 0;
#else
	std::cout << "Press Any Key" << std::endl;
	char in[255];

	std::cin >> in;

#endif
}


TestApp::TestApp(HINSTANCE hInstance, int argc, char** argv) : GLApp(hInstance, argc, argv)
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
