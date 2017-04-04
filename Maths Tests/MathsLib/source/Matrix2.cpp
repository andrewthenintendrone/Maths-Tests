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

/*##################################################
Matrix2 Functions
##################################################*/
float Matrix2::determinant()
{
	return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
}

Matrix2 Matrix2::dot(const Matrix2& rhs)
{
	Matrix2 temp;

	float a = m[0][0];
	float b = m[0][1];
	float c = m[1][0];
	float d = m[1][1];
	float e = rhs.m[0][0];
	float f = rhs.m[0][1];
	float g = rhs.m[1][0];
	float h = rhs.m[1][1];

	temp.m[0][0] = a * e + b * g;
	temp.m[0][1] = a * f + b * h;
	temp.m[1][0] = c * e + d * g;
	temp.m[1][1] = c * f + d * h;

	return temp;
}

Matrix2 Matrix2::identity()
{
	Matrix2 temp;
	for (unsigned int x = 0; x < 2; x++)
	{
		for (unsigned int y = 0; y < 2; y++)
		{
			if (x == y)
			{
				temp.m[x][y] = 0;
			}
		}
	}
}

/*##################################################
Vector2 overloaded operators
##################################################*/
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