#include "Vector4.h"

/*##################################################
Vector4 constructor and destructor
##################################################*/
Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

Vector4::Vector4(float newX, float newY, float newZ, float newW)
{
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

Vector4::Vector4(int newX, int newY, int newZ, int newW)
{
	x = (float)newX;
	y = (float)newY;
	z = (float)newZ;
	w = (float)newW;
}

Vector4::~Vector4()
{

}

/*##################################################
Vector4 overloaded operators
##################################################*/
bool Vector4::operator == (const Vector4& rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.z);
}

void Vector4::operator = (const Vector4& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;
}

Vector4 Vector4::operator + (const Vector4& rhs)
{
	Vector4 temp = { x, y, z, w };
	temp += rhs;
	return temp;
}

Vector4 Vector4::operator - (const Vector4& rhs)
{
	Vector4 temp = { x, y, z, w };
	temp -= rhs;
	return temp;
}

void Vector4::operator += (const Vector4& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	w += vec.w;
}

void Vector4::operator -= (const Vector4& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	w -= vec.w;
}

std::ostream& operator << (std::ostream& stream, const Vector4& vector)
{
	stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
	return stream;
}
