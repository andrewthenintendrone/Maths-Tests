#pragma once
#include <iostream>
#include "Vector4.h"

class Matrix4
{
public:
	union
	{
		struct
		{
			Vector4 vecs[4];
		};
		struct
		{
			float m[16];
		};
		struct
		{
			float x0;
			float x1;
			float x2;
			float x3;
			float y0;
			float y1;
			float y2;
			float y3;
			float z0;
			float z1;
			float z2;
			float z3;
			float w0;
			float w1;
			float w2;
			float w3;
		};
	};

	// constructors and destructor
	Matrix4();
	Matrix4(const float& newx0, const float& newx1, const float& newx2, const float& newx3, const float& newy0, const float& newy1, const float& newy2, const float& newy3, const float& newz0, const float& newz1, const float& newz2, const float& newz3, const float& neww0, const float& neww1, const float& neww2, const float& neww3);
	Matrix4(const Vector4& row1, const Vector4& row2, const Vector4& row3, const Vector4& row4);
	Matrix4(const float& newM);
	Matrix4(const Matrix4& newM);
	~Matrix4();

	// functions
	float determinant();
	Matrix4 dot(const Matrix4& rhs);

	// static Matrix4 shortcuts
	static Matrix4 identity();

	// overloaded operators
	void operator = (const Matrix4& rhs);
	void operator += (const Matrix4& rhs);
	Matrix4 operator + (const Matrix4& rhs);
	void operator -= (const Matrix4& rhs);
	Matrix4 operator - (const Matrix4& rhs);
	void operator *= (const float& scalar);
	Matrix4 operator * (const float& scalar);
	void operator /= (const float& scalar);
	Matrix4 operator / (const float& scalar);
	friend std::ostream& operator << (std::ostream& stream, const Matrix4& matrix);
};