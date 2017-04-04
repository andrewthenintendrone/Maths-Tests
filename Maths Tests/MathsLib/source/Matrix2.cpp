#include "Matrix2.h"

/*##################################################
Matrix2 constructor and destructor
##################################################*/
Matrix2::Matrix2()
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] = Matrix2::identity().m[i];
	}
}

Matrix2::Matrix2(const float newM[4])
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] = newM[i];
	}
}

Matrix2::Matrix2(const float& newM)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] = newM;
	}
}

Matrix2::Matrix2(const Vector2& column1, const Vector2& column2)
{

}

Matrix2::~Matrix2()
{

}

/*##################################################
Matrix2 Functions
##################################################*/
float Matrix2::determinant()
{
	return (m[0] * m[3] - m[1] * m[2]);
}

Matrix2 Matrix2::dot(const Matrix2& rhs)
{
	Matrix2 temp;

	temp.m[0] = m[0] * rhs.m[0] + m[1] * rhs.m[2];
	temp.m[1] = m[0] * rhs.m[1] + m[1] * rhs.m[3];
	temp.m[2] = m[2] * rhs.m[0] + m[3] * rhs.m[2];
	temp.m[3] = m[2] * rhs.m[1] + m[3] * rhs.m[3];

	return temp;
}

Matrix2 Matrix2::identity()
{
	float temp[4] = { 1, 0, 0, 1 };
	return Matrix2(temp);
}

/*##################################################
Vector2 overloaded operators
##################################################*/
void Matrix2::operator = (const Matrix2& rhs)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] = rhs.m[i];
	}
}

void Matrix2::operator += (const Matrix2& rhs)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] += rhs.m[i];
	}
}

Matrix2 Matrix2::operator + (const Matrix2& rhs)
{
	Matrix2 temp = m;
	temp += rhs;
	return temp;
}

void Matrix2::operator -= (const Matrix2& rhs)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] -= rhs.m[i];
	}
}

Matrix2 Matrix2::operator - (const Matrix2& rhs)
{
	Matrix2 temp = m;
	temp -= rhs;
	return temp;
}

void Matrix2::operator *= (const float& scalar)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] *= scalar;
	}
}

Matrix2 Matrix2::operator * (const float& scalar)
{
	Matrix2 temp = m;
	temp *= scalar;
	return temp;
}

void Matrix2::operator /= (const float& scalar)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] /= scalar;
	}
}

Matrix2 Matrix2::operator / (const float& scalar)
{
	Matrix2 temp = m;
	temp /= scalar;
	return temp;
}

std::ostream& operator << (std::ostream& stream, const Matrix2& matrix)
{
	for (unsigned int x = 0; x < 2; x++)
	{
		for (unsigned int y = 0; y < 2; y++)
		{
			stream << matrix.m[2 * y + x] << ", ";
		}
		stream << std::endl;
	}
	stream << std::endl;
	return stream;
}