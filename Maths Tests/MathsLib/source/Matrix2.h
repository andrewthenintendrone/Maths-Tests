#pragma once
#include <iostream>

class Matrix2
{
public:
	// use union for easier access
	union
	{
		struct
		{
			float xAxis[2];
			float yAxis[2];
		};
		float m[2][2];
	};

	// constructors and destructor
	Matrix2();
	Matrix2(const float newM[2][2]);
	Matrix2(const float& newM);
	~Matrix2();

	// functions
	float determinant();
	Matrix2 dot(const Matrix2& rhs);

	// static Matrix2 shortcuts
	static Matrix2 identity();

	// overloaded operators
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