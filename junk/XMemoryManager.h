#ifndef __XMEMORY_MANAGER_H
#define __XMEMORY_MANAGER_H

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

#include <boost/shared_ptr.hpp>
#include "XAllocator.h"

namespace Xanadu {
	namespace Engine {

		class XANADU_API XMemoryManager
		{
		public:

			static boost::shared_ptr<XMemoryManager> GetInstance();
		
			template <typename T>
			asset_handle<T>& RegisterComponent();

			template <typename T>
			void RemoveComponent(asset_handle<T>& handle);

			~XMemoryManager();

		protected:
			static boost::shared_ptr<XMemoryManager> _instance;

			XAllocator* _allocator;

			XMemoryManager(size_t size);


		};

		template<typename T>
		inline asset_handle<T>& XMemoryManager::RegisterComponent()
		{
			return _allocator->allocate<T>();
		}

		template<typename T>
		inline void XMemoryManager::RemoveComponent(asset_handle<T>& handle)
		{
			_allocator->deallocate(handle);
		}

	}
}


#endif



