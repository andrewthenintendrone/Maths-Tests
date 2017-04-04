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

Matrix3::Matrix3(const float newx0, const float newx1, const float newx2, const float newy0, const float newy1, const float newy2, const float newz0, const float newz1, const float newz2)
{
	x0 = newx0;
	x1 = newx1;
	x2 = newx2;
	y0 = newy0;
	y1 = newy1;
	y2 = newy2;
	z0 = newz0;
	z1 = newz1;
	z2 = newz2;
}

Matrix3::Matrix3(const Vector3& row1, const Vector3& row2, const Vector3& row3)
{
	vecs[0] = row1;
	vecs[1] = row2;
	vecs[2] = row3;
}

Matrix3::Matrix3(const float& newM)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		m[i] = newM;
	}
}

Matrix3::Matrix3(const Matrix3& newM)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		m[i] = newM.m[i];
	}
}

Matrix3::~Matrix3()
{

}

/*##################################################
Matrix3 Functions
##################################################*/
float Matrix3::determinant()
{
	return (x0 * y1 * z2 + x1 * y2 * z0 + x2 * y0 * z1) - (z0 * y1 * x2 + z1 * y2 * x0 + z2 * y0 * x1);
}

Matrix3 Matrix3::dot(const Matrix3& rhs)
{
    Matrix3 temp;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            float sum = 0;
            for (unsigned int k = 0; k < 3; k++)
            {
                sum += m[i * 3 + k] * rhs.m[k * 3 + j];
            }
            temp.m[i * 3 + j] = sum;
        }
    }

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
	Matrix3 temp(*this);
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
	Matrix3 temp(*this);
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
	Matrix3 temp(*this);
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
	Matrix3 temp(*this);
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