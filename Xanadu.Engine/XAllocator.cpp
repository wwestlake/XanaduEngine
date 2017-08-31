#include "stdafx.h"
#include "XAllocator.h"

namespace Xanadu {
	namespace Engine {

		allocation_record Xanadu::Engine::XAllocator::mem_allocate(size_t size)
		{
			allocation_record rec;

			if (findSpace(size, rec)) {
				_allocations.push_back(rec);
				return rec;
			}
			throw allocation_failed_exception();
		}

		void Xanadu::Engine::XAllocator::mem_deallocate(allocation_record& rec)
		{
			rec.allocated = false;
		}

		

		bool Xanadu::Engine::XAllocator::findSpace(size_t size, allocation_record & record)
		{
			allocation_record* found = nullptr;

			for (auto rec : _allocations) {
				if (!rec.allocated && rec.length >= size) {
					if (found != nullptr && rec.length < found->length) {
						found = &rec;
					}
					else if (found == nullptr) {
						found = &rec;
					}
				}
			}

			if (found != nullptr) {
				found->allocated = true;
				found->length = size;
				record = *found;
				return true;
			}

			if (size <= _available) {
				found = new allocation_record();
				found->start = _free;
				found->allocated = true;
				found->offset = _free - _pool;
				while (size % _alignment != 0) size++;
				found->length = size;
				_free += size;
				_available -= size;
				record = *found;
				return true;
			}

			return false;
		}

		allocation_record * XAllocator::findRecord(poolptr ptr)
		{
			for (auto rec : _allocations) {
				if (rec.start == ptr) return &rec;
			}
			return nullptr;
		}


	}
}