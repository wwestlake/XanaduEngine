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





