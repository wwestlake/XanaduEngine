#ifndef XANADU_SINGLE_INCLUDE_XANADUUTILITIES_H
#define XANADU_SINGLE_INCLUDE_XANADUUTILITIES_H
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

#ifdef XANADUUTILITIES_EXPORTS
#define XANADUUTILITIES_API __declspec(dllexport)
#else
#define XANADUUTILITIES_API __declspec(dllimport)
#endif

#include <string>


namespace Xanadu {
	namespace Utilities {
		class XANADUUTILITIES_API TextFile {
		public:

			TextFile(std::string filename) : _filename(filename)
			{
				_filesize = FileSize();
				_fileContents = ReadTextFile();
			}

			size_t GetFileSize() {
				return _filesize;
			}

			std::string GetContents() {
				return _fileContents;
			}

		private:
			std::string _filename;
			std::string _fileContents;
			size_t _filesize;

			std::string  ReadTextFile();
			size_t  FileSize();

		};
	}
}





#endif
