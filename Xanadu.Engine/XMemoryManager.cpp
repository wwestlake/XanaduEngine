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

#include "XMemoryManager.h"
#include <vector>
#include <boost/intrusive/avltree.hpp>
#include <iostream>
#include <map>

namespace Xanadu {
	namespace Engine {

		namespace avl = boost::intrusive;

		struct allocation : avl::avl_set_base_hook<avl::optimize_size<true>> {
			char* address;
			size_t size;
			size_t page;
			bool in_use;

			friend bool operator <(const allocation& a, const allocation& b)
			{
				return a.size < b.size;
			}

			friend bool operator >(const allocation& a, const allocation& b)
			{
				return a.size > b.size;
			}

			friend bool operator ==(const allocation& a, const allocation& b)
			{
				return a.size == b.size;
			}


		};
	
		struct alloc_state {
			avl::avltree<allocation> allocations;
			XMemory* _internal_memory;
			vector<XMemory*> _memory;
			map<char*, allocation*> addr_alloc_map;
		};

		struct FindAllocationBySize {
			bool operator()(size_t size, const allocation& alloc) const
			{
				return (!alloc.in_use) && (alloc.size >= size);
			}
			bool operator()(const allocation& alloc, size_t size) const
			{
				return (!alloc.in_use) && (alloc.size >= size);
			}
		};

		

		XMemoryManager::XMemoryManager(size_t page_size, size_t num_pages)
		{
			state = new alloc_state();
			_num_pages = num_pages;
			_page_size = page_size;
			//state->_memory = new XMemory*[num_pages];
			for (int i = 0; i < num_pages; i++)
			{
				state->_memory.push_back( new XMemory(page_size) );
			}
			state->_internal_memory = new XMemory(page_size * 10);
		}

		allocation* XMemoryManager::find(size_t size)
		{
			auto iter = state->allocations.find(size, FindAllocationBySize());
			if (iter != state->allocations.end()) {
				if (! (*iter).in_use) return &*iter;
			}
			return nullptr;
		}

		allocation* XMemoryManager::find(char* ptr)
		{
			for (auto iter = state->allocations.begin(); iter != state->allocations.end(); ++iter) {
				if ((*iter).address == ptr) return &*iter;
			}
			return nullptr;
		}

		allocation* XMemoryManager::CreateAllocation() 
		{
			size_t size = sizeof(allocation) + 4;
			char* ptr = state->_internal_memory->GetFreePtr();
			char* newfreeptr = ptr + size;
			while (((size_t)newfreeptr % 4) > 0) newfreeptr++;
			state->_internal_memory->SetFreePtr(newfreeptr);
			auto result = new (ptr) allocation;
			return result;
		}

		char* XMemoryManager::Allocate(size_t size)
		{
			size_t _size = size + 4;
			auto alloc = find(_size);
			if (alloc != nullptr) {
				std::cout << "Allocating object" << std::endl;
				alloc->in_use = true;
				return alloc->address;
			}
			else 
			{
				int i = 0;
				for (auto iter = state->_memory.begin(); iter != state->_memory.end(); ++iter) {
					if ((*iter)->IsAvailable(size)) {
						char* result = (*iter)->GetFreePtr();
						char* newfreeptr = result + size;
						while (((size_t)newfreeptr % 4) > 0) newfreeptr++;
						(*iter)->SetFreePtr(newfreeptr);
						auto alloc = CreateAllocation();
						alloc->address = result;
						alloc->in_use = true;
						alloc->size = size;
						alloc->page = i;
						state->allocations.push_back(*alloc);
						i++;
						state->addr_alloc_map[result] = alloc;
						return result;
					}
				}
			}
			state->_memory.push_back(new XMemory(_page_size));
			std::cout << "Allocated new page" << std::endl;
			return Allocate(size);
			throw out_of_memory_exception();
		}

		void XMemoryManager::Deallocate(char* address)
		{
			auto alloc = state->addr_alloc_map[address];
			if (alloc != nullptr) {
				alloc->in_use = false;
			}
		}


	}
}
