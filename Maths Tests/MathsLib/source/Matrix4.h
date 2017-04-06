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
			float x1;
			float y1;
			float z1;
			float w1;
			float x2;
			float y2;
			float z2;
			float w2;
			float x3;
			float y3;
			float z3;
			float w3;
			float x4;
			float y4;
			float z4;
			float w4;
		};
	};

	// constructors and destructor
	Matrix4();
	Matrix4(const float& newx1, const float& newy1, const float& newz1, const float& neww1, const float& newx2, const float& newy2, const float& newz2, const float& neww2, const float& newx3, const float& newy3, const float& newz3, const float& neww3, const float& newx4, const float& newy4, const float& newz4, const float& neww4);
	Matrix4(const Vector4& newVec1, const Vector4& newVec2, const Vector4& newVec3, const Vector4& newVec4);
	Matrix4(const float& newValue);
	Matrix4(const Matrix4& newM);
	~Matrix4();

	// functions
	float determinant();
    void setRotateX(const float& angle);
    void setRotateY(const float& angle);
    void setRotateZ(const float& angle);

	// static Matrix4 shortcuts
	static Matrix4 identity();

	// overloaded operators
	operator float *();
	Vector4 operator [] (const int& index);
	void operator = (const Matrix4& rhs);
	void operator += (const Matrix4& rhs);
	Matrix4 operator + (const Matrix4& rhs);
	void operator -= (const Matrix4& rhs);
	Matrix4 operator - (const Matrix4& rhs);
	void operator *= (const float& scalar);
	Matrix4 operator * (const float& scalar);
    void operator *= (const Matrix4& rhs);
    Matrix4 operator * (const Matrix4& rhs);
    void operator *= (Vector4& rhs);
    Vector4 operator * (Vector4& rhs);
	void operator /= (const float& scalar);
	Matrix4 operator / (const float& scalar);
	friend std::ostream& operator << (std::ostream& stream, const Matrix4& matrix);
};