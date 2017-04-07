#include "Matrix2.h"

Matrix2::Matrix2()
{
    // set to identity
}

// construct with floats
Matrix2::Matrix2(const float& newXx, const float& newXy, const float& newYx, const float& newYy)
{
    m[0][0] = newXx;
    m[0][1] = newXy;
    m[1][0] = newYx;
    m[1][1] = newYy;
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

// + operator with a Matrix
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

// - operator with a Matrix
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

// stream << operator
std::ostream& operator << (std::ostream& stream, const Matrix2& matrix)
{
    stream << matrix.xAxis;
    stream << std::endl;
    stream << matrix.yAxis;
    return stream;
}