#include "Vector3.h"

/*##################################################
Vector3 constructor and destructor
##################################################*/
Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

Vector3::~Vector3()
{

}

/*##################################################
Vector3 Functions
##################################################*/
float Vector3::getMagnitude()
{
	return (float)sqrt(x * x + y * y + z * z);
}

float Vector3::getSquaredMagnitude()
{
    return(x * x + y * y + z * z);
}

void Vector3::Normalize()
{
	float magnitude = getMagnitude();
	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
}

Vector3 Vector3::normalized()
{
	Vector3 temp = *this;
	float magnitude = getMagnitude();
	temp.Normalize();
	return temp;
}

Vector3 Vector3::crossProduct(Vector3& lhs, Vector3& rhs)
{
	return Vector3(lhs.y * rhs.z - lhs.z * rhs.y, lhs.x * rhs.z - lhs.z * rhs.x, lhs.x * rhs.y - lhs.y * rhs.x);
}

/*##################################################
Vector3 shortcuts for commonly used Vector3s
##################################################*/
Vector3 Vector3::Up()
{
	return{ 0.0f, 1.0f, 0.0f };
}

Vector3 Vector3::Down()
{
	return{ 0.0f, -1.0f, 0.0f };
}

Vector3 Vector3::Left()
{
	return{ -1.0f, 0.0f, 0.0f };
}

Vector3 Vector3::Right()
{
	return{ -1.0f, 0.0f, 0.0f };
}

Vector3 Vector3::Forward()
{
	return{ 0.0f, 0.0f, 1.0f };
}

Vector3 Vector3::Back()
{
	return{ 0.0f, 0.0f, -1.0f };
}

Vector3 Vector3::Zero()
{
	return{ 0.0f, 0.0f, 0.0f };
}

/*##################################################
Vector3 overloaded operators
##################################################*/
bool Vector3::operator == (const Vector3& rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

void Vector3::operator = (const Vector3& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

Vector3 Vector3::operator + (const Vector3& rhs)
{
	Vector3 temp = { x, y, z };
	temp += rhs;
	return temp;
}

Vector3 Vector3::operator - (const Vector3& rhs)
{
	Vector3 temp = { x, y, z };
	temp -= rhs;
	return temp;
}

void Vector3::operator += (const Vector3& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
}

void Vector3::operator -= (const Vector3& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
}

std::ostream& operator << (std::ostream& stream, const Vector3& vector)
{
	stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	return stream;
}
