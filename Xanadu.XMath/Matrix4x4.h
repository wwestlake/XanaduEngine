#ifndef XANADU_SINGLE_INCLUDE_MATRIX4X4_H
#define XANADU_SINGLE_INCLUDE_MATRIX4X4_H

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
#include <array>
#include <iostream>
#include <iomanip>
#include "Vector3d.h"
#include "Quaternion.h"

#define C0R0 0
#define C0R1 1
#define C0R2 2
#define C0R3 3

#define C1R0 4
#define C1R1 5
#define C1R2 6
#define C1R3 7

#define C2R0 8
#define C2R1 9
#define C2R2 10
#define C2R3 11

#define C3R0 12
#define C3R1 13
#define C3R2 14
#define C3R3 15

#define ELEM(COL, ROW) (COL * 4 + ROW)

namespace Xanadu {
	namespace XMath {

		class Matrix4x4 {
		public:

			
			Matrix4x4() 
			{
				for (int i = 0; i < 16; i++) _elem[i] = 0;
			}

			Matrix4x4(float floats[4][4]) {
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						_elem[i * 4 + j] = floats[i][j];

			}

			Matrix4x4(
				float c0r0, float c1r0, float c2r0, float c3r0,
				float c0r1, float c1r1, float c2r1, float c3r1,
				float c0r2, float c1r2, float c2r2, float c3r2,
				float c0r3, float c1r3, float c2r3, float c3r3
				) 
			{
				_elem[C0R0] = c0r0;
				_elem[C0R1] = c0r1;
				_elem[C0R2] = c0r2;
				_elem[C0R3] = c0r3;

				_elem[C1R0] = c1r0;
				_elem[C1R1] = c1r1;
				_elem[C1R2] = c1r2;
				_elem[C1R3] = c1r3;

				_elem[C2R0] = c2r0;
				_elem[C2R1] = c2r1;
				_elem[C2R2] = c2r2;
				_elem[C2R3] = c2r3;

				_elem[C3R0] = c3r0;
				_elem[C3R1] = c3r1;
				_elem[C3R2] = c3r2;
				_elem[C3R3] = c3r3;
			}

			static Matrix4x4 Identity() 
			{
				auto result = Matrix4x4();
				result._elem[C0R0] = 1.f;
				result._elem[C1R1] = 1.f;
				result._elem[C2R2] = 1.f;
				result._elem[C3R3] = 1.f;
				return result;
			}

			static Matrix4x4 Zero() 
			{
				return Matrix4x4();
			}


			float* Data() 
			{
				return _elem.data();
			}

			Matrix4x4 Transpose() const {
				return Matrix4x4(
					_elem[C0R0], _elem[C0R1], _elem[C0R2], _elem[C0R3],
					_elem[C1R0], _elem[C1R1], _elem[C1R2], _elem[C1R3],
					_elem[C2R0], _elem[C2R1], _elem[C2R2], _elem[C2R3],
					_elem[C3R0], _elem[C3R1], _elem[C3R2], _elem[C3R3]
				);
			}

			Matrix4x4 operator+(const Matrix4x4& b)
			{
				auto result = Matrix4x4();
				for (int i = 0; i < 16; i++) 
				{
					result._elem[i] = _elem[i] + b._elem[i];
				}
				return result;
			}

			Matrix4x4 operator-(const Matrix4x4& b)
			{
				auto result = Matrix4x4();
				for (int i = 0; i < 16; i++) 
				{
					result._elem[i] = _elem[i] - b._elem[i];
				}
				return result;
			}

			Matrix4x4 operator*(float b) 
			{
				auto result = Matrix4x4();
				for (int i = 0; i < 16; i++) 
				{
					result._elem[i] = _elem[i] * b;
				}
				return result;
			}

			float get(int c, int r) 
			{
				return _elem[c * 4 + r];
			}

			void set(int c, int r, float value) 
			{
				_elem[c * 4 + r] = value;
			}


			Matrix4x4 operator*(const Matrix4x4& b) 
			{
				float result[4][4];
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++) 
					{
						result[i][j] = 0;
						for (int k = 0; k < 4; k++) 
						{
							result[i][j] += _elem[ELEM(i, j)] * b._elem[ELEM(k, j)];
						}
					}
				}
				return Matrix4x4(result);
			}


			Matrix4x4& operator+=(const Matrix4x4& rhs) 
			{
				for (int i = 0; i < 16; i++) 
				{
					_elem[i] = _elem[i] + rhs._elem[i];
				}
				return *this;
			}

			Matrix4x4& operator-=(const Matrix4x4& rhs) 
			{
				for (int i = 0; i < 16; i++) 
				{
					_elem[i] = _elem[i] - rhs._elem[i];
				}
				return *this;
			}

			Matrix4x4& operator*=(float rhs) 
			{
				for (int i = 0; i < 16; i++) 
				{
					_elem[i] = _elem[i] * rhs;
				}
				return *this;
			}

			float operator()(int col, int row) 
			{
				if (col >= 0 && col < 4 && row >= 0 && row < 4) {
					return _elem[col * 4 + row];
				}
			}

			Matrix4x4 MakeScale(Vector3d scale) 
			{
				auto result = Matrix4x4::Identity();
				result._elem[C0R0] = scale.X();
				result._elem[C1R1] = scale.Y();
				result._elem[C2R2] = scale.Z();
			}

			Matrix4x4 MakeTranslation(Vector3d translation) 
			{
				auto result = Matrix4x4::Identity();
				result._elem[C3R0] = translation.X();
				result._elem[C3R1] = translation.Y();
				result._elem[C3R2] = translation.Z();
			}

			Matrix4x4 MakeRotation(const Quaternion& q) 
			{
				float w2 = q._w * q._w, x2 = q._x * q._x, y2 = q._y * q._y, z2 = q._z * q._z;
				float wx = q._w * q._x, wy = q._w * q._y, wz = q._w * q._z;
				float xy = q._y * q._z, xz = q._x * q._z;
				float yz = q._y * q._z;

				return Matrix4x4(
					w2 + x2 - y2 - z2, 2 * (xy - wz), 2 * (xz - wy), 0,
					2 * (xy + wz), w2 - x2 + y2 - z2, 2 * (yz - wz), 0,
					2 * (xz - wy), 2 * (yz - wx), w2 - x2 - y2 + z2, 0,
					0,0,0,1
				);
			}


			friend std::ostream& operator<<(std::ostream& os, const Matrix4x4& mat) 
			{
				//os << std::setw(10);
				os << "|" << mat._elem[C0R0] << "," << mat._elem[C1R0] << "," << mat._elem[C2R0] << "," << mat._elem[C3R0] << "|" << std::endl;
				os << "|" << mat._elem[C0R1] << "," << mat._elem[C1R1] << "," << mat._elem[C2R1] << "," << mat._elem[C3R1] << "|" << std::endl;
				os << "|" << mat._elem[C0R2] << "," << mat._elem[C1R2] << "," << mat._elem[C2R2] << "," << mat._elem[C3R2] << "|" << std::endl;
				os << "|" << mat._elem[C0R3] << "," << mat._elem[C1R3] << "," << mat._elem[C2R3] << "," << mat._elem[C3R3] << "|" << std::endl;
				return os;
			}

		private:
			std::array<float, 16> _elem;
		};

	}
}



#endif

