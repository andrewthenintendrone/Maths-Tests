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
    xAxis = newxAxis;
    yAxis = newyAxis;
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
    Matrix2 rotationMatrix(cosf(angle), sinf(angle), -sinf(angle), cosf(angle));
    *this *= rotationMatrix;
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
    return &Xx;
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

    return temp;
}

// *= operator with a matrix
void Matrix2::operator *= (const Matrix2& rhs)
{
    Matrix2 temp(*this);

    temp = temp * rhs;

    *this = temp;
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