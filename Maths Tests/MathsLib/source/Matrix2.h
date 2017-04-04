#pragma once
#include <iostream>
#include "Vector2.h"

class Matrix2
{
public:
	float m[4];

	// constructors and destructor
	Matrix2();
	Matrix2(const float newM[4]);
	Matrix2(const Vector2& column1, const Vector2& column2);
	Matrix2(const float& newM);
	~Matrix2();

	// functions
	float determinant();
	Matrix2 dot(const Matrix2& rhs);

	// static Matrix2 shortcuts
	static Matrix2 identity();

	// overloaded operators
	void operator = (const Matrix2& rhs);
	void operator += (const Matrix2& rhs);
	Matrix2 operator + (const Matrix2& rhs);
	void operator -= (const Matrix2& rhs);
	Matrix2 operator - (const Matrix2& rhs);
	void operator *= (const float& scalar);
	Matrix2 operator * (const float& scalar);
	void operator /= (const float& scalar);
	Matrix2 operator / (const float& scalar);
	friend std::ostream& operator << (std::ostream& stream, const Matrix2& matrix);
};