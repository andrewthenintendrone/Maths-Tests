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
	Vector4(int newX, int newY, int newZ, int newW);
	~Vector4();

	// operator overloads
	bool operator == (const Vector4& rhs);
	void operator = (const Vector4& vec);
	Vector4 operator + (const Vector4& rhs);
	Vector4 operator - (const Vector4& rhs);
	void operator += (const Vector4& vec);
	void operator -= (const Vector4& vec);
	friend std::ostream& operator << (std::ostream& stream, const Vector4& vector);
};