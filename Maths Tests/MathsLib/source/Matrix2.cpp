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
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            m[i][j] = newValue;
        }
    }
}

// construct with floats
Matrix2::Matrix2(const float& newXx, const float& newYx, const float& newXy, const float& newYy)
{
    m[0][0] = newXx;
    m[0][1] = newYx;
    m[1][0] = newXy;
    m[1][1] = newYy;
}

// construct with Vectors
Matrix2::Matrix2(Vector2& newAxis1, Vector2& newAxis2)
{
    m[0][0] = newAxis1.x;
    m[0][1] = newAxis2.x;
    m[1][0] = newAxis1.y;
    m[1][1] = newAxis2.y;
}

// construct with another Matrix
Matrix2::Matrix2(const Matrix2& newMatrix)
{
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            m[i][j] = newMatrix.m[i][j];
        }
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
    return (Xx * Xy - Yx * Yy);
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
    Matrix2 rotationMatrix(cosf(angle), sinf(angle), -sinf(angle), cosf(angle));
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
            temp.m[i][j] = this->m[j][i];
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
            stream << matrix.m[i][j] << " ";
        }
        stream << std::endl;
    }
    return stream;
}

// * operator
Matrix2::operator float* ()
{
    return &m[0][0];
}

// [] operator that returns vector
Vector2 Matrix2::operator [] (const int& index)
{
    switch (index)
    {
    case 0:
        return Vector2(Xx, Xy);
    case 1:
        return Vector2(Yx, Yy);
    default:
        return Vector2(0, 0);
    }
}

// returns true if matricies are equal
bool Matrix2::operator == (const Matrix2& rhs)
{
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            if (m[i][j] != rhs.m[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

// = operator with a matrix
void Matrix2::operator = (const Matrix2& newMatrix)
{
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            m[i][j] = newMatrix.m[i][j];
        }
    }
}

// + operator with a matrix
Matrix2 Matrix2::operator + (const Matrix2& rhs)
{
    Matrix2 temp;

    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            temp.m[i][j] = m[i][j] + rhs.m[i][j];
        }
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

    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            temp.m[i][j] = m[i][j] - rhs.m[i][j];
        }
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
                sum += m[i][k] * rhs.m[k][j];
            }
            temp.m[i][j] = sum;
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

    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            temp.m[i][j] = m[i][j] + scalar;
        }
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

    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            temp.m[i][j] = m[i][j] - scalar;
        }
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

    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            temp.m[i][j] *= scalar;
        }
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

    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            temp.m[i][j] /= scalar;
        }
    }

    return temp;
}

// /= operator with a scalar
void Matrix2::operator /= (const float& scalar)
{
    *this = *this / scalar;
}