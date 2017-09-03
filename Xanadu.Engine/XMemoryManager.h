#ifndef XANADU_SINGLE_INCLUDE_XMEMORYMANAGER_H
#define XANADU_SINGLE_INCLUDE_XMEMORYMANAGER_H

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
#include "XMemory.h"
#include "XThing.h"
#include <boost/shared_ptr.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>

namespace Xanadu {
	namespace Engine {

		using namespace boost;

		class XANADU_API out_of_memory_exception {};

		struct allocation;
		struct alloc_state;

		class XMemoryManager {
		public:
			XMemoryManager(size_t page_size, size_t num_pages);

			char* Allocate(size_t size);
			void Deallocate(char* address);

		protected:
			allocation* find(size_t size);
			allocation* find(char* ptr);


		private:
			size_t _num_pages;
			size_t _page_size;
			XMemory** _memory;
			alloc_state* state;
		};

	}
}

#endif