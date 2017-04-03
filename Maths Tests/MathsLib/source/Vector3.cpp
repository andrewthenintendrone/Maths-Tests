#include "Vector3.h"

/*##################################################
Vector3 constructor and destructor
##################################################*/
Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
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
float Vector3::dot(Vector3& rhs)
{
	return(x * rhs.x + y * rhs.y);
}

Vector3 Vector3::cross(Vector3& rhs)
{
	return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}

float Vector3::magnitude()
{
	return sqrt(x * x + y * y + z * z);
}

float Vector3::squaremagnitude()
{
	return(x * x + y * y + z * z);
}

void Vector3::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

Vector3 Vector3::normalized()
{
	Vector3 temp = *this;
	float magnitude = temp.magnitude();
	temp.normalise();
	return temp;
}

float Vector3::angle(Vector3& rhs)
{
	return acosf(Vector3::dot(rhs.normalized()));
}

Vector3 Vector3::perpendicular()
{
	return Vector3(-y, x, 0);
}

/*##################################################
Vector3 shortcuts for commonly used Vector3s
##################################################*/
Vector3 Vector3::Up()
{
	return{ 0, 1, 0 };
}

Vector3 Vector3::Down()
{
	return{ 0, -1, 0 };
}

Vector3 Vector3::Left()
{
	return{ -1, 0, 0 };
}

Vector3 Vector3::Right()
{
	return{ -1, 0, 0 };
}

Vector3 Vector3::Forward()
{
	return{ 0, 0, 1 };
}

Vector3 Vector3::Back()
{
	return{ 0, 0, -1 };
}

Vector3 Vector3::Zero()
{
	return{ 0, 0, 0 };
}

/*##################################################
Vector3 overloaded operators
##################################################*/
bool Vector3::operator == (const Vector3& rhs)
{
	return (x == rhs.x && y == rhs.y);
}

void Vector3::operator = (const Vector3& vec)
{
	x = vec.x;
	y = vec.y;
}

Vector3 Vector3::operator + (const Vector3& rhs)
{
	Vector3 temp = *this;
	temp += rhs;
	return temp;
}

void Vector3::operator += (const Vector3& vec)
{
	x += vec.x;
	y += vec.y;
}

Vector3 Vector3::operator - (const Vector3& rhs)
{
	Vector3 temp = *this;
	temp -= rhs;
	return temp;
}

void Vector3::operator -= (const Vector3& vec)
{
	x -= vec.x;
	y -= vec.y;
}

Vector3 Vector3::operator * (const float& scalar)
{
	Vector3 temp = *this;
	temp *= scalar;
	return temp;
}

Vector3 operator * (const float& scalar, Vector3& vector)
{
	return vector * scalar;
}

void Vector3::operator *= (const float& scalar)
{
	x *= scalar;
	y *= scalar;
}

Vector3 Vector3::operator / (const float& scalar)
{
	Vector3 temp = *this;
	temp /= scalar;
	return temp;
}

void Vector3::operator /= (const float& scalar)
{
	x /= scalar;
	y /= scalar;
}

std::ostream& operator << (std::ostream& stream, const Vector3& vector)
{
	stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	return stream;
}
