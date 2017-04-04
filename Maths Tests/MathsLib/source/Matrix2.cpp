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

Matrix2::Matrix2(const float newx0, const float newx1, const float newy0, const float newy1)
{
	x0 = newx0;
	x1 = newx1;
	y0 = newy0;
	y1 = newy1;
}

Matrix2::Matrix2(const Vector2& row1, const Vector2& row2)
{
	vecs[0] = row1;
	vecs[1] = row2;
}

Matrix2::Matrix2(const float& newM)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] = newM;
	}
}

Matrix2::Matrix2(const Matrix2& newM)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] = newM.m[i];
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
	return (x0 * y1) - (y0 * x1);
}

Matrix2 Matrix2::dot(const Matrix2& rhs)
{
    Matrix2 temp;

    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            float sum = 0;
            for (unsigned int k = 0; k < 2; k++)
            {
                sum += m[i * 2 + k] * rhs.m[k * 2 + j];
            }
            temp.m[i * 2 + j] = sum;
        }
    }

    return temp;
}

Matrix2 Matrix2::identity()
{
	return Matrix2(1, 0, 0, 1);
}

/*##################################################
Matrix2 overloaded operators
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
	Matrix2 temp(*this);
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
	Matrix2 temp(*this);
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
	Matrix2 temp(*this);
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
	Matrix2 temp(*this);
	temp /= scalar;
	return temp;
}

std::ostream& operator << (std::ostream& stream, const Matrix2& matrix)
{
	for (unsigned int i = 0; i < 2; i++)
	{
		stream << matrix.vecs[i];
		stream << std::endl;
	}
	return stream;
}