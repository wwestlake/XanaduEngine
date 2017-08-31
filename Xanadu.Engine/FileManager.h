#ifndef __FILE_MANAGER_H
#define __FILE_MANAGER_H

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
#include <string>
#include <ShlObj.h>
#include <boost/shared_ptr.hpp>
#include <list>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace Xanadu {
	namespace Utilities {
		class XANADU_API FileManager
		{
		public:
			static boost::shared_ptr<FileManager> Instance();


			~FileManager();
			std::string AppDataPath();
			std::string LogPath(std::string & logfile);
			std::list<fs::directory_entry> GetDirectoryList(std::string & path);
			std::list<fs::directory_entry> GetDirectoryList_Directories(std::string & path);
			std::list<fs::directory_entry> GetDirectoryList_Files(std::string & path);

		private:
			static boost::shared_ptr<FileManager> instance;
			FileManager();

		};
	}
}

#endif
