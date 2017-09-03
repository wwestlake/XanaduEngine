#ifndef XANADU_SINGLE_INCLUDE_XOMPONENT_H
#define XANADU_SINGLE_INCLUDE_XOMPONENT_H

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
#include <string>

namespace Xanadu {
	namespace Engine {

		using namespace std;

		class  XANADU_API  XComponent : public XThing
		{
		public:
			XComponent(string name);
			~XComponent();

			string GetName() 
			{
				return _name;
			}

		protected:
			string _name;
			Transform* _transform;

			virtual void Tick(float deltaTime);
			virtual void BeginPlay();
			virtual void Update(float deltaTime);
			virtual void Render(float deltaTime);

		};

	}
}


#endif

