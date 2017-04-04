#pragma once
#include <math.h>
#include <iostream>

class Vector3
{
public:
	// variables
	float x;
	float y;
	float z;

	// constructors and destructor
	Vector3();
	Vector3(float newX, float newY, float newZ);
	~Vector3();

	// functions
	float dot(Vector3& rhs);
	Vector3 cross(Vector3& rhs);
	float magnitude();
	float squaremagnitude();
	void normalise();
	Vector3 normalized();
	float angle(Vector3& rhs);

	// static Vector3 shortcuts
	static Vector3 Up();
	static Vector3 Down();
	static Vector3 Left();
	static Vector3 Right();
	static Vector3 Forward();
	static Vector3 Back();
	static Vector3 Zero();

	// operator overloads
	bool operator == (const Vector3& rhs);
	void operator = (const Vector3& rhs);
	Vector3 operator + (const Vector3& rhs);
	void operator += (const Vector3& rhs);
	Vector3 operator - (const Vector3& rhs);
	void operator -= (const Vector3& rhs);
	Vector3 operator * (const float& scalar);
	friend Vector3 operator * (const float& scalar, Vector3& vector);
	void operator *= (const float& scalar);
	Vector3 operator / (const float& scalar);
	void operator /= (const float& scalar);
	friend std::ostream& operator << (std::ostream& stream, const Vector3& vector);
};