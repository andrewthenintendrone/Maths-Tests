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
		float m[9];
	};

	// constructors and destructor
	Matrix3();
	Matrix3(const float x0, const float x1, const float x2, const float y0, const float y1, const float y2, const float z0, const float z1, const float z2);
	Matrix3(const Vector3& row1, const Vector3& row2, const Vector3& row3);
	Matrix3(const float& newM);
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