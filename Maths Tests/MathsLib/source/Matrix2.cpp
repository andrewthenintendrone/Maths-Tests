#include "Matrix2.h"
#include <math.h>

/*##################################################
Matrix2 constructor and destructor
##################################################*/
Matrix2::Matrix2()
{
    *this = Matrix2::identity();
}

Matrix2::Matrix2(const float& newx1, const float& newy1, const float& newx2, const float& newy2)
{
	x1 = newx1;
	y1 = newy1;
	x2 = newx2;
	y2 = newy2;
}

Matrix2::Matrix2(const Vector2& newVec1, const Vector2& newVec2)
{
    vecs[0] = newVec1;
	vecs[1] = newVec2;
}

Matrix2::Matrix2(const float& newValue)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		f[i] = newValue;
	}
}

Matrix2::Matrix2(const Matrix2& newM)
{
    *this = newM;
}

Matrix2::~Matrix2()
{

}

/*##################################################
Matrix2 Functions
##################################################*/
float Matrix2::determinant()
{
    return (x1 * y2 - y1 * x2);
}

void Matrix2::setRotate(const float& angle)
{
    Matrix2 rotationMatrix(cosf(angle), sinf(angle), -sinf(angle), cosf(angle));
    *this *= rotationMatrix;
}

/*##################################################
Matrix2 shortcuts for commonly used Matrix2s
##################################################*/
Matrix2 Matrix2::identity()
{
	return Matrix2(1, 0, 0, 1);
}

/*##################################################
Matrix2 overloaded operators
##################################################*/
Matrix2::operator float* ()
{
	return &x1;
}

Vector2& Matrix2::operator [] (const int& index)
{
	return vecs[index];
}

void Matrix2::operator = (const Matrix2& rhs)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		f[i] = rhs.f[i];
	}
}

void Matrix2::operator += (const Matrix2& rhs)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		f[i] += rhs.f[i];
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
		f[i] -= rhs.f[i];
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
		f[i] *= scalar;
	}
}

Matrix2 Matrix2::operator * (const float& scalar)
{
	Matrix2 temp(*this);
	temp *= scalar;
	return temp;
}

void Matrix2::operator *= (const Matrix2& rhs)
{
    Matrix2 temp;
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; i++)
        {
            float sum = 0;
            for (unsigned int k = 0; k < 2; k++)
            {
                sum += m[i][k] * rhs.m[k][j];
            }
            temp.m[i][j] = sum;
        }
    }
    *this = temp;
}

Matrix2 Matrix2::operator * (const Matrix2& rhs)
{
	Matrix2 temp(*this);
    temp *= rhs;
	return temp;
}

void Matrix2::operator *= (Vector2& rhs)
{
    for (unsigned int i = 0; i < 2; i++)
    {
        rhs[i] = rhs.dot(vecs[i]);
    }
}

Vector2 Matrix2::operator * (Vector2& rhs)
{
    Matrix2 tempMatrix(*this);
    Vector2 tempVector(*rhs);

    tempMatrix *= tempVector;

    return tempVector;
}

void Matrix2::operator /= (const float& scalar)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		f[i] /= scalar;
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
        for (unsigned int j = 0; j < 2; j++)
        {
            stream << matrix.f[j * 2 + i] << " ";
        }
        std::cout << std::endl;
    }
	return stream;
}