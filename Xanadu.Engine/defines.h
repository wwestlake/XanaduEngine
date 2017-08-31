#ifndef __DEFINES_H
#define __DEFINES_H

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


#ifdef XANADUENGINE_EXPORTS
#define XANADU_API __declspec(dllexport)   
#define XANADU_API_HEADER_ONLY
#else  
#define XANADU_API __declspec(dllimport)   
#define XANADU_API_HEADER_ONLY
#endif  

#include <string>

#define X_TEXT(A) std::string(A)

#define APP_COMPANY X_TEXT("LagDaemon")
#define APP_NAME X_TEXT("Xanadu")
#define APP_LOG_FOLDER X_TEXT("Logs")
#define PATH_SEPERATOR X_TEXT("\\")

#define MEMORY_ALLOCATION 1024 * 1024 * 1024

#endif