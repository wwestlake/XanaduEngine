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


#include "FileManager.h"

#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include "defines.h"


namespace Xanadu {
	namespace Utilities {

		boost::shared_ptr<FileManager> FileManager::instance;

		boost::shared_ptr<FileManager> FileManager::Instance()
		{
			if (nullptr == instance) {
				instance = boost::shared_ptr<FileManager>(new FileManager());
			}
			return boost::shared_ptr<FileManager>(instance);
		}


		FileManager::FileManager()
		{
		}


		FileManager::~FileManager()
		{
		}


		std::string FileManager::AppDataPath()
		{
			WCHAR path[MAX_PATH];
			HRESULT result = SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, (LPWSTR)path);
			auto wpath = std::wstring(path);
			using convert_type = std::codecvt_utf8<wchar_t>;
			std::wstring_convert<convert_type, wchar_t> converter;
			std::string converted_str = converter.to_bytes(wpath);

			return converted_str + PATH_SEPERATOR + APP_COMPANY + PATH_SEPERATOR + APP_NAME;
		}

		std::string FileManager::LogPath(std::string & logfile)
		{
			return AppDataPath() + PATH_SEPERATOR + APP_LOG_FOLDER + PATH_SEPERATOR + logfile;
		}

		std::list<fs::directory_entry> FileManager::GetDirectoryList(std::string & path)
		{
			std::list<fs::directory_entry> result;

			if (fs::exists(path)) {
				if (fs::is_directory(path)) {
					for (fs::directory_entry& x : fs::directory_iterator(path)) {
						result.push_back(fs::directory_entry(x));
					}
				}
			}
			return result;
		}

		std::list<fs::directory_entry> FileManager::GetDirectoryList_Directories(std::string & path)
		{
			std::list<fs::directory_entry> result;
			auto dirlist = GetDirectoryList(path);
			for (fs::directory_entry x : dirlist) {
				if (fs::is_directory(x.path())) {
					result.push_back(x);
				}
			}
			return result;
		}

		std::list<fs::directory_entry> FileManager::GetDirectoryList_Files(std::string & path)
		{
			std::list<fs::directory_entry> result;
			auto dirlist = GetDirectoryList(path);
			for (fs::directory_entry x : dirlist) {
				if (fs::is_regular_file(x.path())) {
					result.push_back(x);
				}
			}
			return result;
		}

	}
}


