#include "stdafx.h"
#include "Vector3d.h"


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
