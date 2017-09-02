#ifndef __XINDIVIDUAL_H
#define __XINDIVIDUAL_H

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
#include "XThing.h"
#include "Transform.h"
#include "XComponent.h"
#include <boost/intrusive/avltree.hpp>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>

namespace Xanadu {
	namespace Engine {

		using namespace boost;
		using namespace boost::intrusive;
		using namespace std;

		struct ComponentRecord {
			string Name;
			XComponent* Component;
		
		
			ComponentRecord(XComponent* comp);
		
			boost::shared_ptr<XComponent> operator->() {
				return boost::shared_ptr<XComponent>( Component );
			}

		};

		struct ChildRecord {
			string Name;
			XThing* Child;

			ChildRecord(XThing* child);

			boost::shared_ptr<XThing> operator->() {
				return boost::shared_ptr<XThing>(Child);
			}



		};

		class XANADU_API XIndividual :	public XThing
		{
		public:
			XIndividual();
			virtual ~XIndividual();

			Transform* GetTransform() const 
			{
				return _transform;
			}

			void SetTransform(Transform* newTransform) 
			{
				_transform = newTransform;
			}

			template <typename T>
			boost::shared_ptr<T> FindComponent(string name) {
				BOOST_STATIC_ASSERT((boost::is_base_of<XComponent, T>::value));
				for (auto iter = _comps->begin(); iter != _comps->end(); ++iter) {
					if ((*iter).Name.compare(name) == 0) return shared_ptr<T>(iter->Component);
				}
				return shared_ptr<T>();
			}

			template <typename T>
			boost::shared_ptr<T> FindChild(string name) {
				BOOST_STATIC_ASSERT((boost::is_base_of<XThing, T>::value));
				for (auto iter = _children->begin(); iter != _children->end(); ++iter) {
					if ((*iter).Name.compare(name) == 0) return shared_ptr<T>(iter->Child);
				}
				return shared_ptr<T>();
			}

			void AddComponent(XComponent* comp) {
				_comps->push_back(ComponentRecord(comp));
			}


		private:
			Transform* _transform;
			vector<ComponentRecord>* _comps;
			vector<ChildRecord>* _children;
		};
	}
}


#endif

