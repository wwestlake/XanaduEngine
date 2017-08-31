#ifndef __TRANSFORM_H
#define __TRANSFORM_H

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


#include "Vector3d.h"
#include "defines.h"

namespace Xanadu {
	namespace Engine {

		class XANADU_API Transform
		{
		public:
			Transform() : _position(0, 0, 0), _rotation(0, 0, 0), _scale(1, 1, 1) {}
			Transform(const Transform& other) : _position(other._position), _rotation(other._rotation), _scale(other._scale) {}

			~Transform();

			void Translate(float x, float y, float z);
			void Translate(const Xanadu::XMath::Vector3d& position);
			void Rotate(float roll, float pitch, float yaw);
			void Rotate(const Xanadu::XMath::Vector3d& rotation);
			void Scale(float sx, float sy, float sz);
			void Scale(const Xanadu::XMath::Vector3d& scale);

			Xanadu::XMath::Vector3d GetPosition() const { return _position; }
			Xanadu::XMath::Vector3d GetRotation() const { return _rotation; }
			Xanadu::XMath::Vector3d GetScale() const { return _scale; }

		private:
			Xanadu::XMath::Vector3d _position;
			Xanadu::XMath::Vector3d _rotation;
			Xanadu::XMath::Vector3d _scale;

		};

	}
}


#endif
