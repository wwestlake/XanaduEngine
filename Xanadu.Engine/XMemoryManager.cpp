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
			vector<XMemory*> _memory;
			map<char*, allocation*> addr_alloc_map;

			~alloc_state() {
				for (auto iter = _memory.begin(); iter != _memory.end(); ++iter) {
					delete *iter;
				}
				for (auto iter = addr_alloc_map.begin(); iter != addr_alloc_map.end(); ++iter) {
					delete (*iter).second;
				}
			}

		};
		// && (alloc.size <= (min_size * 1.5))
		struct FindAllocationBySize {
			int operator() (const size_t min_size, const allocation& alloc) const {
				if (!alloc.in_use && (alloc.size >= min_size)) return 0;
				return 1;
			}

			int operator() (const allocation& alloc, const size_t min_size) const {
				if (!alloc.in_use && (alloc.size >= min_size)) return 0;
				return 1;
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
		}

		XMemoryManager::~XMemoryManager()
		{
			delete state;
		}


		allocation* XMemoryManager::find(size_t size)
		{
			auto iter = state->allocations.find(size, FindAllocationBySize());
			if (iter != state->allocations.end()) {
				if (! (*iter).in_use) 
					return &*iter;
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
			auto result = new allocation();
			return result;
		}

		char* XMemoryManager::Allocate(size_t size)
		{
			size_t _size = size + 4;
			auto alloc = find(_size);
			if (alloc != nullptr) {
				alloc->in_use = true;
				return alloc->address;
			}
			else 
			{
				int i = 0;
				for (auto iter = state->_memory.begin(); iter != state->_memory.end(); ++iter) {
					if ((*iter)->IsAvailable(_size)) {
						char* result = (*iter)->GetFreePtr();
						char* newfreeptr = result + _size;
						while (((size_t)newfreeptr % 4) > 0) newfreeptr++;
						(*iter)->SetFreePtr(newfreeptr);
						auto alloc = CreateAllocation();
						alloc->address = result;
						alloc->in_use = true;
						alloc->size = _size;
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
