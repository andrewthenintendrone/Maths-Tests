#include "Matrix2.h"
#include <math.h>

/*##################################################
constructors and destructors
##################################################*/

// default constructor
Matrix2::Matrix2()
{
    *this = Matrix2::identity();
}

// construct with a float
Matrix2::Matrix2(const float& newValue)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] = newValue;
	}
}

// construct with floats
Matrix2::Matrix2(const float& newx1, const float& newy1, const float& newx2, const float& newy2)
{
	x1 = newx1;
	y1 = newy1;
	x2 = newx2;
	y2 = newy2;
}

// construct with Vectors
Matrix2::Matrix2(Vector2& newAxis1, Vector2& newAxis2)
{
	vecs[0] = newAxis1;
	vecs[1] = newAxis2;
}

// construct with another Matrix
Matrix2::Matrix2(const Matrix2& newMatrix)
{
    for (unsigned int i = 0; i < 4; i++)
    {
		m[i] = newMatrix.m[i];
    }
}

Matrix2::~Matrix2()
{

}

/*##################################################
functions
##################################################*/

// returns the determinant of the matrix
float Matrix2::determinant()
{
    return (x1 * y2 - y1 * x2);
}

// returns the identity matrix
Matrix2 Matrix2::identity()
{
    return Matrix2(1, 0, 0, 1);
}

// returns a matrix of 0s
Matrix2 Matrix2::zero()
{
    return Matrix2(0);
}

// rotates the matrix by a given angle
void Matrix2::setRotate(const float& angle)
{
    Matrix2 rotationMatrix(cosf(angle), -sinf(angle), sinf(angle), cosf(angle));
    *this *= rotationMatrix;
}

// returns the transposed matrix
Matrix2 Matrix2::transposed()
{
    Matrix2 temp;

    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            temp.mm[i][j] = this->mm[j][i];
        }
    }

    return temp;
}

/*##################################################
overloads
##################################################*/

// stream << operator
std::ostream& operator << (std::ostream& stream, const Matrix2& matrix)
{
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            stream << matrix.mm[i][j] << " ";
        }
        stream << std::endl;
    }
    return stream;
}

// * operator
Matrix2::operator float* ()
{
    return &m[0];
}

// [] operator that returns vector
Vector2 Matrix2::operator [] (const int& index)
{
    switch (index)
    {
    case 0:
        return Vector2(x1, x2);
    case 1:
        return Vector2(y1, y2);
    default:
        return Vector2(0, 0);
    }
}

// returns true if matricies are equal
bool Matrix2::operator == (const Matrix2& rhs)
{
    for (unsigned int i = 0; i < 4; i++)
    {
		if (m[i] != rhs.m[i])
		{
			return false;
		}
    }
    return true;
}

// = operator with a matrix
void Matrix2::operator = (const Matrix2& newMatrix)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		m[i] = newMatrix.m[i];
	}
}

// + operator with a matrix
Matrix2 Matrix2::operator + (const Matrix2& rhs)
{
    Matrix2 temp;

    for (unsigned int i = 0; i < 4; i++)
    {
		temp.m[i] = m[i] + rhs.m[i];
    }

    return temp;
}

// += operator with a matrix
void Matrix2::operator += (const Matrix2& rhs)
{
    *this = *this + rhs;
}

// - operator with a matrix
Matrix2 Matrix2::operator - (const Matrix2& rhs)
{
    Matrix2 temp;

	for (unsigned int i = 0; i < 4; i++)
	{
		temp.m[i] = m[i] - rhs.m[i];
	}

    return temp;
}

// -= operator with a matrix
void Matrix2::operator -= (const Matrix2& rhs)
{
    *this = *this - rhs;
}

// * operator with a matrix
Matrix2 Matrix2::operator * (Matrix2& rhs)
{
    Matrix2 temp;

    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            float sum = 0;
            for (unsigned int k = 0; k < 2; k++)
            {
                sum += mm[i][k] * rhs.mm[k][j];
            }
            temp.mm[i][j] = sum;
        }
    }

    return temp;
}

// *= operator with a matrix
void Matrix2::operator *= (Matrix2& rhs)
{
    *this = *this * rhs;
}

// * operator with a vector
Vector2 Matrix2::operator * (Vector2& rhs)
{
    Vector2 temp[2];

    return Vector2(temp[0].dot(rhs), temp[1].dot(rhs));
}

// *= operator with a vector
void Matrix2::operator *= (Vector2& rhs)
{
    rhs = *this * rhs;
}

// + operator with a scalar
Matrix2 Matrix2::operator + (const float& scalar)
{
    Matrix2 temp;

	for (unsigned int i = 0; i < 4; i++)
	{
		temp.m[i] = m[i] + scalar;
	}

    return temp;
}

// += operator with a scalar
void Matrix2::operator += (const float& scalar)
{
    *this = *this * scalar;
}

// - operator with a scalar
Matrix2 Matrix2::operator - (const float& scalar)
{
    Matrix2 temp;

	for (unsigned int i = 0; i < 4; i++)
	{
		temp.m[i] = m[i] - scalar;
	}

    return temp;
}

// -= operator with a scalar
void Matrix2::operator -= (const float& scalar)
{
    *this = *this - scalar;
}

// * operator with a scalar
Matrix2 Matrix2::operator * (const float& scalar)
{
    Matrix2 temp(*this);

	for (unsigned int i = 0; i < 4; i++)
	{
		temp.m[i] = m[i] * scalar;
	}

    return temp;
}

// *= operator with a scalar
void Matrix2::operator *= (const float& scalar)
{
    *this = *this * scalar;
}

// / operator with a scalar
Matrix2 Matrix2::operator / (const float& scalar)
{
    Matrix2 temp(*this);

	for (unsigned int i = 0; i < 4; i++)
	{
		temp.m[i] = m[i] / scalar;
	}

    return temp;
}

// /= operator with a scalar
void Matrix2::operator /= (const float& scalar)
{
    *this = *this / scalar;
}