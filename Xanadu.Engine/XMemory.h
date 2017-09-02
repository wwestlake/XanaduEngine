#ifndef XANADU_SINGLE_INCLUDE_XMEMORY_H
#define XANADU_SINGLE_INCLUDE_XMEMORY_H

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
#include <vector>
#include <stdlib.h>
#include <boost/shared_ptr.hpp>
#include <boost/intrusive/avltree.hpp>
#include <map>

namespace Xanadu {
	namespace Engine {

		using namespace std;
		using namespace boost::intrusive;

		typedef char* memory_ptr;
		typedef boost::shared_ptr< char > shared_memory_ptr;

		struct AllocationRecord : public avl_set_base_hook<optimize_size<true>> {
			memory_ptr location;
			size_t size;
			bool in_use;

			friend bool operator< (const AllocationRecord& a, const AllocationRecord& b)
			{
				return a.size < b.size;
			}
			friend bool operator> (const AllocationRecord& a, const AllocationRecord& b)
			{
				return a.size > b.size;
			}
			friend bool operator== (const AllocationRecord& a, const AllocationRecord& b)
			{
				return a.size == b.size;
			}

		};

		typedef avltree<AllocationRecord> tree_t;

		struct Greater {
			bool operator() (const AllocationRecord& rec, const size_t size) const
			{
				return !rec.in_use && (rec.size <= size);
			}
			bool operator() (const size_t size, const AllocationRecord& rec) const
			{
				return !rec.in_use && (size >= rec.size);
			}
		};

		struct PageRecord {

			PageRecord(shared_memory_ptr _memory, size_t _size) 
			{
				memory = _memory;
				size = _size;
				free = _memory.get();
				allocations = new tree_t;
			}

			shared_memory_ptr memory;
			size_t size;
			memory_ptr free;
			tree_t* allocations;
		};

		class XMemoryManager;

		class XANADU_API XMemory {
		public:
			XMemory(size_t page_size, size_t num_pages);
			~XMemory();

			static void deleter(memory_ptr memory);

			size_t GetAvailableMemory();

			friend class XMemoryManager;

			AllocationRecord* GetAllocationRecord(memory_ptr ptr) 
			{
				return allocation_index[ptr];
			}
			
			void RegisterAllocationIndex(memory_ptr ptr, AllocationRecord* rec) 
			{
				allocation_index[ptr] = rec;
			}

		private:
			vector<PageRecord> pages;
			std::map<memory_ptr, AllocationRecord*> allocation_index;
		};

	}
}

#endif



