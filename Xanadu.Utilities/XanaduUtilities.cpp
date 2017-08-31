// XanaduUtilities.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "XanaduUtilities.h"
#include <fstream>
#include <streambuf>
#include <iostream>


namespace Xanadu {
	namespace Utilities {

		std::string TextFile::ReadTextFile() {
			std::ifstream t(_filename);
			std::string str;
			t.seekg(0, std::ios::end);
			str.reserve(t.tellg());
			t.seekg(0, std::ios::beg);
			str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
			t.close();
			return str;
		}

		size_t TextFile::FileSize() {
			std::ifstream t(_filename);
			t.seekg(0, std::ios::end);
			size_t size = t.tellg();
			t.close();
			return size;
		}

	}
}





