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
#include "Vector3d.h"

namespace Xanadu {
	namespace XMath {

		Vector3d::Vector3d()
		{
			x_ = 0.0f;
			y_ = 0.0f;
			z_ = 0.0f;
		}

		Vector3d::Vector3d(float x, float y, float z)
		{
			x_ = x;
			y_ = y;
			z_ = z;
		}

		Vector3d::Vector3d(const Vector3d& vector)
		{
			x_ = vector.x_;
			y_ = vector.y_;
			z_ = vector.z_;
		}


		Vector3d::~Vector3d()
		{
		}


		float Vector3d::X() const { return x_; }
		void Vector3d::X(float x) { x_ = x; }

		float Vector3d::Roll() const { return x_; }
		void Vector3d::Roll(float roll) { x_ = roll; }

		float Vector3d::Pitch() const { return y_; }
		void Vector3d::Pitch(float roll) { y_ = roll; }

		float Vector3d::Yaw() const { return z_; }
		void Vector3d::Yaw(float roll) { z_ = roll; }

		float Vector3d::Y() const { return y_; }
		void Vector3d::Y(float y) { y_ = y; }

		float Vector3d::Z() const { return z_; }
		void Vector3d::Z(float z) { z_ = z; }

		Vector3d Vector3d::operator+(const Vector3d& vector)
		{
			return Vector3d(x_ + vector.x_, y_ + vector.y_, z_ + vector.z_);
		}

		Vector3d Vector3d::operator*(float a)
		{
			return Vector3d(x_ * a, y_ * a, z_ * a);
		}

		Vector3d Vector3d::Up()
		{
			return Vector3d(0.0f, 0.0f, 1.0f);
		}

		Vector3d Vector3d::Forward()
		{
			return Vector3d(0.0f, 1.0f, 0.0f);
		}

		Vector3d Vector3d::Right()
		{
			return Vector3d(1.0f, 0.0f, 0.0f);
		}

		std::string Vector3d::ToString()
		{
			std::stringstream ss;
			ss << "[" << x_ << ", " << y_ << ", " << z_ << "]";
			return ss.str();
		}

	}
}