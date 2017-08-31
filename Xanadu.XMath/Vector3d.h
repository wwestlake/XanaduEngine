#ifndef XANADU_SINGLE_INCLUDE_VECTOR3D_H
#define XANADU_SINGLE_INCLUDE_VECTOR3D_H

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

#include <string>
#include <sstream>
#include "defines.h"

namespace Xanadu {
	namespace XMath {

		class XANADU_XMATH_API Vector3d
		{
		public:
			Vector3d();
			Vector3d(float x, float y, float z);
			Vector3d(const Vector3d& vector);
			~Vector3d();
			float X() const;
			void X(float x);
			float Y() const;
			void Y(float y);
			float Z() const;
			void Z(float z);
			Vector3d operator+(const Vector3d& vector);
			Vector3d operator*(float a);
			static Vector3d Up();
			static Vector3d Forward();
			static Vector3d Right();
			std::string ToString();
			float Roll() const;
			void Roll(float roll);
			float Pitch() const;
			void Pitch(float pitch);
			float Yaw() const;
			void Yaw(float yaw);


		private:
			float x_, y_, z_;

		};
	}
}

#endif
