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

// construct with floats
Matrix2::Matrix2(const float& newXx, const float& newXy, const float& newYx, const float& newYy)
{
    Xx = newXx;
    Xy = newXy;
    Yx = newYx;
    Yy = newYy;
}

// construct with Vectors
Matrix2::Matrix2(Vector2& newxAxis, Vector2& newyAxis)
{
    Xx = newxAxis.x;
    Xy = newxAxis.y;

    Yx = newyAxis.x;
    Yy = newyAxis.y;
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

// returns the identity matrix
Matrix2 Matrix2::identity()
{
    return Matrix2(1, 0, 0, 1);
}

// returns the determinant of the matrix
float Matrix2::determinant()
{
    return (m[0][0] * m[1][1] - m[1][0] * m[0][1]);
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
            stream << matrix.m[j][i] << " ";
        }
        stream << std::endl;
    }
    return stream;
}

// * operator
Matrix2::operator float* ()
{
    return &Xx;
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
Matrix2 Matrix2::operator * (const Matrix2& rhs)
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

    return temp.transposed();
}

// *= operator with a matrix
void Matrix2::operator *= (const Matrix2& rhs)
{
    *this = *this * rhs;
}

// * operator with a vector
Vector2 Matrix2::operator * (Vector2& rhs)
{
    Vector2 temp;

    temp.x = Vector2(Xx, Yx).dot(rhs);
    temp.y = Vector2(Xy, Yy).dot(rhs);

    return temp;
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