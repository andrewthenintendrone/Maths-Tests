#include "Matrix3.h"
#include "Matrix2.h"

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

Matrix3::Matrix3(const float& newx1, const float& newy1, const float& newz1, const float& newx2, const float& newy2, const float& newz2, const float& newx3, const float& newy3, const float& newz3)
{
	x1 = newx1;
	y1 = newy1;
	z1 = newz1;
	x2 = newx2;
	y2 = newy2;
	z2 = newz2;
	x3 = newx3;
	y3 = newy3;
	z3 = newz3;
}

Matrix3::Matrix3(const Vector3& newVec1, const Vector3& newVec2, const Vector3& newVec3)
{
	vecs[0] = newVec1;
	vecs[1] = newVec2;
	vecs[2] = newVec3;
}

Matrix3::Matrix3(const float& newValue)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		m[i] = newValue;
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
    Matrix2 block1(y2, z2, y3, z3);
    Matrix2 block2(x2, z2, x3, z3);
    Matrix2 block3(x2, y2, x3, y3);

    return (x1 * block1.determinant() - y1 * block2.determinant() + z1 * block3.determinant());
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
Matrix3::operator float* ()
{
	return &x1;
}

Vector3& Matrix3::operator [] (const int& index)
{
	return vecs[index];
}

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