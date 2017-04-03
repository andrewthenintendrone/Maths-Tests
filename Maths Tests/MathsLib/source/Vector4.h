#pragma once
#include <math.h>
#include <iostream>

class Vector4
{
public:
	// variables
	float x;
	float y;
	float z;
	float w;

	// constructors and destructor
	Vector4();
	Vector4(float newX, float newY, float newZ, float newW);
	~Vector4();

	// functions
	float dot(Vector4& rhs);
	Vector4 cross(Vector4& rhs);
	float magnitude();
	float squaremagnitude();
	void normalise();
	Vector4 normalized();
	float angle(Vector4& rhs);
	Vector4 perpendicular();

	// static Vector3 shortcuts
	static Vector4 Zero();

	// operator overloads
	bool operator == (const Vector4& rhs);
	void operator = (const Vector4& rhs);
	Vector4 operator + (const Vector4& rhs);
	void operator += (const Vector4& rhs);
	Vector4 operator - (const Vector4& rhs);
	void operator -= (const Vector4& rhs);
	Vector4 operator * (const float& scalar);
	friend Vector4 operator * (const float& scalar, Vector4& vector);
	void operator *= (const float& scalar);
	Vector4 operator / (const float& scalar);
	void operator /= (const float& scalar);
	friend std::ostream& operator << (std::ostream& stream, const Vector4& vector);
};