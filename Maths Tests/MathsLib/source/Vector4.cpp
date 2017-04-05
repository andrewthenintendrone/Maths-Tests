#include "Vector4.h"

/*##################################################
Vector4 constructor and destructor
##################################################*/
Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(const float& newValue)
{
	x = newValue;
	y = newValue;
	z = newValue;
	w = newValue;
}

Vector4::Vector4(float newX, float newY, float newZ, float newW)
{
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

Vector4::Vector4(const Vector4& newVector)
{
	x = newVector.x;
	y = newVector.y;
	z = newVector.z;
	w = newVector.w;
}

Vector4::~Vector4()
{

}

/*##################################################
Vector4 Functions
##################################################*/
float Vector4::dot(Vector4& rhs)
{
	return(x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w);
}

Vector4 Vector4::cross(Vector4& rhs)
{
	return Vector4(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x, 0);
}

float Vector4::magnitude()
{
	return sqrt(x * x + y * y + z * z + w * w);
}

float Vector4::squaremagnitude()
{
	return(x * x + y * y + z * z + w * w);
}

void Vector4::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;
}

Vector4 Vector4::normalized()
{
	Vector4 temp(*this);
	float magnitude = temp.magnitude();
	temp.normalise();
	return temp;
}

float Vector4::angle(Vector4& rhs)
{
	return acosf(Vector4::dot(rhs.normalized()));
}

Vector4 Vector4::perpendicular()
{
	return Vector4(-y, x, 0, 0);
}

/*##################################################
Vector4 shortcuts for commonly used Vector4s
##################################################*/
Vector4 Vector4::Zero()
{
	return{ 0, 0, 0, 0 };
}

/*##################################################
Vector4 overloaded operators
##################################################*/
float& Vector4::operator [] (const int& index)
{
	return v[index];
}

bool Vector4::operator == (const Vector4& rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w);
}

void Vector4::operator = (const Vector4& rhs)
{
	x = rhs.x;
	y = rhs.y;
    z = rhs.z;
    w = rhs.w;
}

Vector4 Vector4::operator + (const Vector4& rhs)
{
	Vector4 temp(*this);
	temp += rhs;
	return temp;
}

void Vector4::operator += (const Vector4& rhs)
{
	x += rhs.x;
	y += rhs.y;
    z += rhs.z;
    w += rhs.w;
}

Vector4 Vector4::operator - (const Vector4& rhs)
{
	Vector4 temp(*this);
	temp -= rhs;
	return temp;
}

void Vector4::operator -= (const Vector4& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
}

Vector4 Vector4::operator * (const float& scalar)
{
	Vector4 temp(*this);
	temp *= scalar;
	return temp;
}

Vector4 operator * (const float& scalar, Vector4& vector)
{
	return vector * scalar;
}

void Vector4::operator *= (const float& scalar)
{
	x *= scalar;
	y *= scalar;
    z *= scalar;
    w *= scalar;
}

Vector4 Vector4::operator / (const float& scalar)
{
	Vector4 temp(*this);
	temp /= scalar;
	return temp;
}

void Vector4::operator /= (const float& scalar)
{
	x /= scalar;
	y /= scalar;
    z /= scalar;
    w /= scalar;
}

std::ostream& operator << (std::ostream& stream, const Vector4& vector)
{
	stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
	return stream;
}
