#include "Vector4.h"

/*##################################################
Vector4 constructor and destructor
##################################################*/
Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	t = 0.0f;
}

Vector4::Vector4(float newX, float newY, float newZ, float newT)
{
	x = newX;
	y = newY;
	z = newZ;
	t = newT;
}

Vector4::~Vector4()
{

}

/*##################################################
Vector4 overloaded operators
##################################################*/
bool Vector4::operator == (const Vector4& rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z && t == rhs.t);
}

void Vector4::operator = (const Vector4& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	t = vec.t;
}

Vector4 Vector4::operator + (const Vector4& rhs)
{
	Vector4 temp = { x, y, z, t };
	temp += rhs;
	return temp;
}

Vector4 Vector4::operator - (const Vector4& rhs)
{
	Vector4 temp = { x, y, z, t };
	temp -= rhs;
	return temp;
}

void Vector4::operator += (const Vector4& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	t += vec.t;
}

void Vector4::operator -= (const Vector4& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	t -= vec.t;
}

std::ostream& operator << (std::ostream& stream, const Vector4& vector)
{
	stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.t << ")";
	return stream;
}
