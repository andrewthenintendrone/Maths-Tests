#include "Matrix3.h"

/*##################################################
Matrix3 constructor and destructor
##################################################*/
Matrix3::Matrix3()
{
	for (unsigned int i = 0; i < 9; i++)
	{
		m[i] = Matrix3::identity().m[i];
	}
}

Matrix3::Matrix3(const float x0, const float x1, const float x2, const float y0, const float y1, const float y2, const float z0, const float z1, const float z2)
{
	m[0] = x0;
	m[1] = x1;
	m[2] = x2;
	m[3] = y0;
	m[4] = y1;
	m[5] = y2;
	m[6] = z0;
	m[7] = z1;
	m[8] = z2;
}

Matrix3::Matrix3(const float& newM)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		m[i] = newM;
	}
}

Matrix3::Matrix3(const Vector3& row1, const Vector3& row2, const Vector3& row3)
{
	vecs[0] = row1;
	vecs[1] = row2;
	vecs[2] = row3;
}

Matrix3::~Matrix3()
{

}

/*##################################################
Matrix3 Functions
##################################################*/
float Matrix3::determinant()
{
	return (m[0] * m[3] - m[1] * m[2]);
}

Matrix3 Matrix3::dot(const Matrix3& rhs)
{
	Matrix3 temp;

	temp.m[0] = m[0] * rhs.m[0] + m[1] * rhs.m[2];
	temp.m[1] = m[0] * rhs.m[1] + m[1] * rhs.m[3];
	temp.m[2] = m[2] * rhs.m[0] + m[3] * rhs.m[2];
	temp.m[3] = m[2] * rhs.m[1] + m[3] * rhs.m[3];

	return temp;
}

Matrix3 Matrix3::identity()
{
	return Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

/*##################################################
Matrix3 overloaded operators
##################################################*/
void Matrix3::operator = (const Matrix3& rhs)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		m[i] = rhs.m[i];
	}
}

void Matrix3::operator += (const Matrix3& rhs)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		m[i] += rhs.m[i];
	}
}

Matrix3 Matrix3::operator + (const Matrix3& rhs)
{
	Matrix3 temp;
	temp += rhs;
	return temp;
}

void Matrix3::operator -= (const Matrix3& rhs)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		m[i] -= rhs.m[i];
	}
}

Matrix3 Matrix3::operator - (const Matrix3& rhs)
{
	Matrix3 temp = *this;
	temp -= rhs;
	return temp;
}

void Matrix3::operator *= (const float& scalar)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		m[i] *= scalar;
	}
}

Matrix3 Matrix3::operator * (const float& scalar)
{
	Matrix3 temp = *this;
	temp *= scalar;
	return temp;
}

void Matrix3::operator /= (const float& scalar)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		m[i] /= scalar;
	}
}

Matrix3 Matrix3::operator / (const float& scalar)
{
	Matrix3 temp = *this;
	temp /= scalar;
	return temp;
}

std::ostream& operator << (std::ostream& stream, const Matrix3& matrix)
{
	for (unsigned int i = 0; i < 3; i++)
	{
		stream << matrix.vecs[i];
		stream << std::endl;
	}
	return stream;
}