#include "stdafx.h"
#include "XAllocator.h"
#include "XMemoryManager.h"

namespace Xanadu {
	namespace Engine {

		XAllocator::XAllocator()
		{
			_manager = new XMemoryManager(1024 * 1024, 64);
		}

		XAllocator::XAllocator(size_t page_size, size_t num_pages) 
		{
			_manager = new XMemoryManager(page_size, num_pages);
		}


	}
}