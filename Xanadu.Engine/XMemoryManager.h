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

		template <typename T>
		struct XANADU_API MemoryHandle {
			static_assert((boost::is_base_of<XThing, T>::value), "MemoryHandle Type Parameter must derive from XThing");
			boost::shared_ptr<T> ptr;

		};

		class out_of_memory_exception {};

		// XMemoryManager provides an abstraction over memory managers that implement a variety 
		// of memory management strategies.  Several strategies are provided below, additional
		// strategies may be implemented by implementing this interface.
		class XANADU_API XMemoryManager {
		public:

			XMemoryManager(size_t page_size, size_t num_pages)
			{
				memory = new XMemory(page_size, num_pages);
			}

			virtual boost::shared_ptr<char> Allocate(size_t size) = 0;
			virtual void Deallocate(boost::shared_ptr<char> ptr) = 0;

		protected:
			XMemory* memory;

			vector<PageRecord>& GetPages() {
				return memory->pages;
			}

		};

		// A linear memory manager that allows reuse of existing blocks that have been deallocated 
		// if the block is large enough, otherwise if allocates new storage.  This memory manager
		// does no memory degragmentation and should be used for allocating long lived stable objects.
		class XLinearMemoryManager : public XMemoryManager {
		public:
			XLinearMemoryManager(size_t page_size, size_t num_pages) : XMemoryManager(page_size, num_pages) {}

			virtual boost::shared_ptr<char> Allocate(size_t size) override
			{
				auto pages = GetPages();

				for (auto iter = pages.begin(); iter != pages.end(); ++iter) 
				{
					auto page = *iter;
					auto alloc = page.allocations->find(size, Greater());
					if (alloc != page.allocations->end()) 
					{
						auto rec = *alloc;
						rec.in_use = true;
						return boost::shared_ptr<char>(rec.location);
					}
					else 
					{
						auto free = (char*)page.free;
						auto start = (char*)page.memory.get();

						if (free + size > start + page.size) continue;

						auto rec = new AllocationRecord();
						rec->size = size;
						rec->location = free;
						rec->in_use = true;
						page.allocations->push_back(*rec);
						page.free = free + size;
						memory->RegisterAllocationIndex(rec->location, rec);
						return boost::shared_ptr<char>(rec->location);
					}
					throw out_of_memory_exception();
				}
			}

			virtual void Deallocate(boost::shared_ptr<char> ptr) override
			{
				auto rec = memory->GetAllocationRecord(ptr.get());
				rec->in_use = false;
			}

		};


	}
}

#endif