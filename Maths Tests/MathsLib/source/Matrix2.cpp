#include "Matrix2.h"

/*##################################################
Matrix2 constructor and destructor
##################################################*/
Matrix2::Matrix2()
{
	for (unsigned int x = 0; x < 2; x++)
	{
		for (unsigned int y = 0; y < 2; y++)
		{
			m[x][y] = 0;
		}
	}
}

Matrix2::Matrix2(const float newM[2][2])
{
	for (unsigned int x = 0; x < 2; x++)
	{
		for (unsigned int y = 0; y < 2; y++)
		{
			m[x][y] = newM[x][y];
		}
	}
}

Matrix2::Matrix2(const float& newM)
{
	for (unsigned int x = 0; x < 2; x++)
	{
		for (unsigned int y = 0; y < 2; y++)
		{
			m[x][y] = newM;
		}
	}
}

Matrix2::~Matrix2()
{

}

void Matrix2::operator += (const Matrix2& rhs)
{
	for (unsigned int x = 0; x < 2; x++)
	{
		for (unsigned int y = 0; y < 2; y++)
		{
			m[x][y] += rhs.m[x][y];
		}
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
	for (unsigned int x = 0; x < 2; x++)
	{
		for (unsigned int y = 0; y < 2; y++)
		{
			m[x][y] -= rhs.m[x][y];
		}
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
	for (unsigned int x = 0; x < 2; x++)
	{
		for (unsigned int y = 0; y < 2; y++)
		{
			m[x][y] *= scalar;
		}
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
	for (unsigned int x = 0; x < 2; x++)
	{
		for (unsigned int y = 0; y < 2; y++)
		{
			m[x][y] /= scalar;
		}
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
			stream << matrix.m[x][y] << ", ";
		}
		stream << std::endl;
	}
	return stream;
}