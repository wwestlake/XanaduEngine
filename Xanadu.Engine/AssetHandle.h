#ifndef XANADU_SINGLE_INCLUDE_ASSETHANDLE_H
#define XANADU_SINGLE_INCLUDE_ASSETHANDLE_H

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

namespace Xanadu {
	namespace Engine {

		class XAllocator;

		template <typename T>
		struct asset_handle_state;

		template <typename T>
		struct AssetHandle {

			AssetHandle(T* ptr, XAllocator* alloc);
			AssetHandle(const AssetHandle& handle);
			~AssetHandle();

			T* operator->();


		private:
			asset_handle_state<T>* _state;

		};

		template <typename T>
		struct asset_handle_state {
			asset_handle_state(T* ptr, XAllocator* alloc, int refcount) :
				_ptr(ptr), _alloc(alloc), _refcount(refcount) {}

			asset_handle_state(const asset_handle_state& state) : 
				_ptr(state._ptr), _alloc(state._alloc), _refcount(state._refcount) {}

			T* _ptr;
			XAllocator* _alloc;
			int _refcount;
		};

		template<typename T>
		AssetHandle<T>::AssetHandle(T * ptr, XAllocator* alloc)
		{
			_state = new asset_handle_state<T>(ptr, alloc, 1);
		}

		template<typename T>
		AssetHandle<T>::AssetHandle(const AssetHandle<T>& handle)
		{
			_state = handle._state;
			_state->_refcount++;
		}


		template<typename T>
		AssetHandle<T>::~AssetHandle()
		{
			_state->_refcount--;
			if (_state->_refcount == 0) {
				cout << "-x-";
				_state->_alloc->Dealocate<T>(_state->_ptr);
			}
		}

		template<typename T>
		T * AssetHandle<T>::operator->()
		{
			return _state->_ptr;
		}

	}
}


#endif
