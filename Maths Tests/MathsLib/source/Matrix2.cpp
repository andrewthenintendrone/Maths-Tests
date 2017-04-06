#include "Matrix2.h"
#include <math.h>
#include "radians.h"

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

Matrix2::Matrix2(const float& newx1, const float& newy1, const float& newx2, const float& newy2)
{
	x1 = newx1;
	y1 = newy1;
	x2 = newx2;
	y2 = newy2;
}

Matrix2::Matrix2(const Vector2& newVec1, const Vector2& newVec2)
{
	vecs[0] = newVec1;;
	vecs[1] = newVec2;
}

Matrix2::Matrix2(const float& newValue)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] = newValue;
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
    return (x1 * y2 - x2 * y1);
}

void Matrix2::setRotate(const float& angle)
{
    float a = degreesToRadians(angle);
    Matrix2 rotationMatrix(cosf(a), sinf(a), -sinf(a), cosf(a));
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

void Matrix2::operator *= (const Matrix2& rhs)
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
        for (unsigned int j = 0; j < 2; j++)
        {
            stream << matrix.m[j * 2 + i] << " ";
        }
        std::cout << std::endl;
    }
	return stream;
}