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
			float x1;
			float y1;
			float z1;
			float x2;
			float y2;
			float z2;
			float x3;
			float y3;
			float z3;
		};
	};

	// constructors and destructor
	Matrix3();
    Matrix3(const float& newx1, const float& newy1, const float& newz1, const float& newx2, const float& newy2, const float& newz2, const float& newx3, const float& newy3, const float& newz3);
	Matrix3(const Vector3& newVec1, const Vector3& newVec2, const Vector3& newVec3);
	Matrix3(const float& newValue);
	Matrix3(const Matrix3& newM);
	~Matrix3();

	// functions
	float determinant();

	// static Matrix3 shortcuts
	static Matrix3 identity();

	// overloaded operators
	operator float *();
	Vector3& operator [] (const int& index);
	void operator = (const Matrix3& rhs);
	void operator += (const Matrix3& rhs);
	Matrix3 operator + (const Matrix3& rhs);
	void operator -= (const Matrix3& rhs);
	Matrix3 operator - (const Matrix3& rhs);
	void operator *= (const float& scalar);
	Matrix3 operator * (const float& scalar);
    void operator *= (const Matrix3& rhs);
    Matrix3 operator * (const Matrix3& rhs);
    void operator *= (Vector3& rhs);
    Vector3 operator * (Vector3& rhs);
	void operator /= (const float& scalar);
	Matrix3 operator / (const float& scalar);
	friend std::ostream& operator << (std::ostream& stream, const Matrix3& matrix);
};