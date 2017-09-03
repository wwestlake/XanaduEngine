#include "stdafx.h"
#include "XAllocator.h"
#include "XMemoryManager.h"

namespace Xanadu {
	namespace Engine {

		XAllocator::XAllocator()
		{
			_manager = new XMemoryManager(1024 * 1024, 64);
		}


	}
}