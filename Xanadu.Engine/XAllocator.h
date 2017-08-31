#ifndef __XALLOCATOR_H
#define __XALLOCATOR_H

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
#include <assert.h>
#include <stdlib.h>
#include <vector>
#include <boost/thread/mutex.hpp>

namespace Xanadu {
	namespace Engine {

		typedef __int8 u8;
		typedef unsigned long ulong;
		typedef unsigned char* poolptr;

		template <typename T> struct asset_handle;

		class XANADU_API allocation_failed_exception {};


		struct XANADU_API allocation_record {
			poolptr start;
			size_t length;
			ulong offset;
			bool allocated = false;
		};


		class XANADU_API XAllocator {
		public:

			XAllocator(size_t size, u8 alignment = 4) {
				_alignment = alignment;
				_pool = (poolptr)malloc(size);
				_free = _pool;
				_available = size;
			}

			virtual ~XAllocator() {
				for (auto rec : _allocations) {
					mem_deallocate(rec);
				}
				free(_pool);
			}

			template <typename T>
			asset_handle<T> allocate();

			template <typename T>
			void deallocate(asset_handle<T> t);

			allocation_record* findRecord(ulong offset);

			template <typename T> friend struct asset_handle;

		protected:
			u8 _alignment;
			poolptr _pool;
			poolptr _free;
			size_t _available;
			std::vector<allocation_record> _allocations;
			boost::mutex _mtx;

			allocation_record mem_allocate(size_t size);
			void mem_deallocate(allocation_record& rec);

			bool findSpace(size_t size, allocation_record& record);
			allocation_record* findRecord(poolptr ptr);
		};


		template <typename T>
		struct asset_handle {
			ulong id;
			XAllocator* _allocator;
			boost::mutex _mtx;

			T* operator->() {
				//_mtx.lock();
				T* result = nullptr;

				allocation_record* record = nullptr;

				for (auto rec : _allocator->_allocations) {
					if (rec.offset == id) {
						record = &rec;
					}
				}

				if (record != nullptr && record->allocated)
				{
					result = (T*)(record->start);
				}
				//_mtx.unlock();
				return result;
			}

		};


		template<typename T>
		inline asset_handle<T> XAllocator::allocate()
		{
			_mtx.lock();
			size_t size = sizeof(T);
			auto rec = mem_allocate(size);
			struct asset_handle<T> result;
			result.id = rec.offset;
			result._allocator = this;
			T* p = new ((void*)(rec.start)) T;
			_mtx.unlock();
			return result;
		}

		template<typename T>
		inline void XAllocator::deallocate(asset_handle<T> handle)
		{
			_mtx.lock();
			for (auto rec : _allocations) {
				if (rec.offset == handle.id) {
					mem_deallocate(rec);
					handle->T::~T();
					break;
				}
			}
			_mtx.unlock();
		}

		inline allocation_record* XAllocator::findRecord(ulong offset)
		{
			_mtx.lock();
			for (auto rec : _allocations) {
				if (rec.offset == offset) {
					_mtx.unlock();
					return &rec;
				}
			}
			_mtx.unlock();
			return nullptr;
		}

	}


}



#endif