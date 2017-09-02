#ifndef XANADU_SINGLE_INCLUDE_QUATERNION_H
#define XANADU_SINGLE_INCLUDE_QUATERNION_H

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
#include <math.h>

namespace Xanadu {
	namespace XMath {

		class Matrix4x4;

		class Quaternion {
		public:

			Quaternion(float w, float x, float y, float z) : _w(w), _x(x), _y(y), _z(z) {}

			float Magnitude() {
				return sqrt(_w*_w + _x*_x + _y*_y + _z*_z);
			}

			Quaternion Normalize() {
				float mag = Magnitude();
				return Quaternion(_w / mag, _x / mag, _y / mag, _z / mag);
			}

			Quaternion operator*(const Quaternion& q2) {
				return Quaternion(
					_w*q2._w - _x*q2._x - _y*q2._y - _z*q2._z,
					_w*q2._x + _x*q2._w + _y*q2._z - _z*q2._y,
					_w*q2._y - _x*q2._z + _y*q2._w + _z*q2._x,
					_w*q2._z + _x*q2._y - _y*q2._x + _z*q2._w
				);
			}

			friend class Matrix4x4;

		private:
			float _w, _x, _y, _z;

		};


	}


}

#endif
