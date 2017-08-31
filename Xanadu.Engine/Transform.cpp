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


#include "stdafx.h"
#include "Transform.h"

namespace Xanadu {
	namespace Engine {

		Transform::~Transform()
		{
		}

		void Transform::Translate(float x, float y, float z) 
		{
			_position = Xanadu::XMath::Vector3d(x, y, z);
		}

		void Transform::Translate(const Xanadu::XMath::Vector3d& position)
		{
			_position = Xanadu::XMath::Vector3d(position);
		}

		void Transform::Rotate(float roll, float pitch, float yaw)
		{
			_rotation = Xanadu::XMath::Vector3d(roll, pitch, yaw);
		}

		void Transform::Rotate(const Xanadu::XMath::Vector3d& rotation)
		{
			_rotation = Xanadu::XMath::Vector3d(rotation);
		}

		void Transform::Scale(float sx, float sy, float sz)
		{
			_scale = Xanadu::XMath::Vector3d(sx, sy, sz);
		}

		void Transform::Scale(const Xanadu::XMath::Vector3d& scale)
		{
			_scale = Xanadu::XMath::Vector3d(scale);
		}

	}
}
