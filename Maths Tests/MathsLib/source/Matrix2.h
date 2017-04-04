#pragma once
#include <iostream>
#include "Vector2.h"

class Matrix2
{
public:
	union
	{
		struct
		{
			Vector2 vecs[2];
		};
		struct
		{
			float m[4];
		};
		struct
		{
			float x0;
			float x1;
			float y0;
			float y1;
		};
	};

	// constructors and destructor
	Matrix2();
    Matrix2(const float& newx0, const float& newx1, const float& newy0, const float& newy1);
	Matrix2(const Vector2& row1, const Vector2& row2);
	Matrix2(const float& newM);
	Matrix2(const Matrix2& newM);
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