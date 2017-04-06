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
            float m[2][2];
        };
		struct
		{
			float f[4];
		};
		struct
		{
			float x1;
			float y1;
			float x2;
			float y2;
		};
	};

	// constructors and destructor
	Matrix2();
    Matrix2(const float& newx1, const float& newy1, const float& newx2, const float& newy2);
	Matrix2(const Vector2& newVec1, const Vector2& newVec2);
	Matrix2(const float& newValue);
	Matrix2(const Matrix2& newM);
	~Matrix2();

	// functions
	float determinant();
    void setRotate(const float& angle);

	// static Matrix2 shortcuts
	static Matrix2 identity();

	// overloaded operators
	operator float *();
	Vector2& operator [] (const int& index);
	void operator = (const Matrix2& rhs);
	void operator += (const Matrix2& rhs);
	Matrix2 operator + (const Matrix2& rhs);
	void operator -= (const Matrix2& rhs);
	Matrix2 operator - (const Matrix2& rhs);
	void operator *= (const float& scalar);
	Matrix2 operator * (const float& scalar);
    void operator *= (const Matrix2& rhs);
	Matrix2 operator * (const Matrix2& rhs);
    void operator *= (Vector2& rhs);
    Vector2 operator * (Vector2& rhs);
	void operator /= (const float& scalar);
	Matrix2 operator / (const float& scalar);
	friend std::ostream& operator << (std::ostream& stream, const Matrix2& matrix);
};