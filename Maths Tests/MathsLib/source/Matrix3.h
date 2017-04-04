#pragma once
#include <iostream>
#include "Vector3.h"

class Matrix3
{
public:
	union
	{
		struct
		{
			Vector3 vecs[3];
		};
		struct
		{
			float m[9];
		};
		struct
		{
			float x0;
			float x1;
			float x2;
			float y0;
			float y1;
			float y2;
			float z0;
			float z1;
			float z2;
		};
	};

	// constructors and destructor
	Matrix3();
	Matrix3(const float newx0, const float newx1, const float newx2, const float newy0, const float newy1, const float newy2, const float newz0, const float newz1, const float newz2);
	Matrix3(const Vector3& row1, const Vector3& row2, const Vector3& row3);
	Matrix3(const float& newM);
	Matrix3(const Matrix3& newM);
	~Matrix3();

	// functions
	float determinant();
	Matrix3 dot(const Matrix3& rhs);

	// static Matrix3 shortcuts
	static Matrix3 identity();

	// overloaded operators
	void operator = (const Matrix3& rhs);
	void operator += (const Matrix3& rhs);
	Matrix3 operator + (const Matrix3& rhs);
	void operator -= (const Matrix3& rhs);
	Matrix3 operator - (const Matrix3& rhs);
	void operator *= (const float& scalar);
	Matrix3 operator * (const float& scalar);
	void operator /= (const float& scalar);
	Matrix3 operator / (const float& scalar);
	friend std::ostream& operator << (std::ostream& stream, const Matrix3& matrix);
};