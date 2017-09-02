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
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <vector>
#include <boost/thread/mutex.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>
#include <boost/shared_ptr.hpp>
#include "XThing.h"
#include "XMemoryManager.h"

namespace Xanadu {
	namespace Engine {

		using namespace boost;

		class XANADU_API XAllocator {

		public:

			XAllocator(XMemoryManager* manager) {
				_manager = manager;
			}

			template <typename T> 
			boost::shared_ptr<T> Allocate() {
				BOOST_STATIC_ASSERT((boost::is_base_of<XThing, T>::value));
				auto ptr = _manager->Allocate(sizeof(T));
				auto new_ptr = new (ptr.get(), &XAllocator::Deallocate) T;
				return boost::shared_ptr<T>(new_ptr);
			}

			template <typename T>
			void Deallocate(T object) {
				BOOST_STATIC_ASSERT((boost::is_base_of<XThing, T>::value));
				T::~T();
				_manager->Deallocate(object);
			}

		private:
			XMemoryManager* _manager;
		};


	}
}



#endif