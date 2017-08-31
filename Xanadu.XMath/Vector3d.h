#pragma once
#include <string>
#include <sstream>
#include "defines.h"


class XANADU_API Vector3d
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
private:
	float x_, y_, z_;

};

