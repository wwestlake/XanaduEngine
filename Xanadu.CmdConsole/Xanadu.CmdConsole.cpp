// Xanadu.CmdConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#ifdef _DEBUG
#undef _DEBUG
#include <python.h>
#define _DEBUG
#else
#include <python.h>
#endif

using namespace std;

int main() {

	PyObject* pInt;
	Py_Initialize();

	PyRun_SimpleString("print('Hello World from Embedded Python!!!')");

	Py_Finalize();

	char in[255];
	std::cin >> in;

	return 0;
}

