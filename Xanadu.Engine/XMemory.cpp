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


#include "XMemory.h"
#include <iostream>

namespace Xanadu {
	namespace Engine {


		XMemory::XMemory(size_t page_size, size_t num_pages) 
		{
			for (size_t i = 0; i < num_pages; i++)
			{
				memory_ptr ptr = (memory_ptr)malloc(page_size);
				PageRecord rec(shared_memory_ptr( ptr, &XMemory::deleter ), page_size);
				pages.push_back(rec);
			}
		}

		XMemory::~XMemory() 
		{
		}

		void XMemory::deleter(memory_ptr memory) {
			free(memory);
		}

		size_t XMemory::GetAvailableMemory() {
			size_t result = 0;
			for (auto iter = pages.begin(); iter != pages.end(); ++iter) {
				result += (*iter).size;
			}
			return result;
		}
	}
}

