#include "stdafx.h"
#include "XMemoryManager.h"


namespace Xanadu {
	namespace Engine {

		XANADU_API boost::shared_ptr<XMemoryManager> XMemoryManager::_instance;

		XMemoryManager::XMemoryManager(size_t size)
		{
			_allocator = new XAllocator(size);
		}


		boost::shared_ptr<XMemoryManager> XMemoryManager::GetInstance()
		{
			if (_instance == nullptr) _instance = boost::shared_ptr<XMemoryManager>( new XMemoryManager(MEMORY_ALLOCATION) );
			return boost::shared_ptr<XMemoryManager>(_instance);
		}

		XMemoryManager::~XMemoryManager()
		{
		}


	}
}


