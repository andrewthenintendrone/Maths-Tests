#include "Matrix3.h"
#include "Matrix2.h"
#include <math.h>

/*##################################################
constructors and destructors
##################################################*/

// default constructor
Matrix3::Matrix3()
{
    *this = Matrix3::identity();
}

// construct with floats
Matrix3::Matrix3(const float& newXx, const float& newXy, const float& newXz, const float& newYx, const float& newYy, const float& newYz, const float& newZx, const float& newZy, const float& newZz)
{
    Xx = newXx;
    Xy = newXy;
    Xz = newXz;
    Yx = newYx;
    Yy = newYy;
    Yz = newYz;
    Zx = newZx;
    Zy = newZy;
    Zz = newZz;
}

// construct with Vectors
Matrix3::Matrix3(Vector3& newxAxis, Vector3& newyAxis, Vector3& newzAxis)
{
    Xx = newxAxis.x;
    Xy = newxAxis.y;
    Xz = newxAxis.z;

    Yx = newyAxis.x;
    Yy = newyAxis.y;
    Yz = newyAxis.z;

    Zx = newzAxis.x;
    Zy = newzAxis.y;
    Zx = newzAxis.z;
}

// construct with another Matrix
Matrix3::Matrix3(const Matrix3& newMatrix)
{
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            m[i][j] = newMatrix.m[i][j];
        }
    }
}

Matrix3::~Matrix3()
{

}

/*##################################################
functions
##################################################*/

// returns the identity matrix
Matrix3 Matrix3::identity()
{
    return Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

// returns the determinant of the matrix
float Matrix3::determinant()
{
    Matrix2 block1(Yy, Yz, Zy, Zz);
    Matrix2 block2(Xy, Xz, Zy, Zz);
    Matrix2 block3(Xy, Xz, Yy, Yz);

    return (Xx * block1.determinant() - Yx * block2.determinant() + Zx * block3.determinant());
}

// rotates the matrix on the x axis by a given angle
void Matrix3::setRotateX(const float& angle)
{
    Matrix3 rotationMatrix(1, 0, 0, 0, cosf(angle), -sinf(angle), 0, sinf(angle), cosf(angle));
    *this *= rotationMatrix;
}

// rotates the matrix on the y axis by a given angle
void Matrix3::setRotateY(const float& angle)
{
    Matrix3 rotationMatrix(cosf(angle), 0, sinf(angle), 0, 1, 0, -sinf(angle), 0, cosf(angle));
    *this *= rotationMatrix;
}

// rotates the matrix on the z axis by a given angle
void Matrix3::setRotateZ(const float& angle)
{
    Matrix3 rotationMatrix(cosf(angle), -sinf(angle), 0, sinf(angle), cosf(angle), 0, 0, 0, 1);
    *this *= rotationMatrix;
}

// returns the transposed matrix
Matrix3 Matrix3::transposed()
{
    Matrix3 temp;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
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
std::ostream& operator << (std::ostream& stream, const Matrix3& matrix)
{
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            stream << matrix.m[j][i] << " ";
        }
        stream << std::endl;
    }
    return stream;
}

// * operator
Matrix3::operator float* ()
{
    return &Xx;
}

// [] operator that returns vector
Vector3 Matrix3::operator [] (const int& index)
{
    switch (index)
    {
    case 0:
        return Vector3(Xx, Xy, Xz);
    case 1:
        return Vector3(Yx, Yy, Yz);
    case 2:
        return Vector3(Zx, Zy, Zz);
    default:
        return Vector3(0, 0, 0);
    }
}

// = operator with a matrix
void Matrix3::operator = (const Matrix3& newMatrix)
{
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            m[i][j] = newMatrix.m[i][j];
        }
    }
}

// + operator with a matrix
Matrix3 Matrix3::operator + (const Matrix3& rhs)
{
    Matrix3 temp;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            temp.m[i][j] = m[i][j] + rhs.m[i][j];
        }
    }

    return temp;
}

// += operator with a matrix
void Matrix3::operator += (const Matrix3& rhs)
{
    *this = *this + rhs;
}

// - operator with a matrix
Matrix3 Matrix3::operator - (const Matrix3& rhs)
{
    Matrix3 temp;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            temp.m[i][j] = m[i][j] - rhs.m[i][j];
        }
    }

    return temp;
}

// -= operator with a matrix
void Matrix3::operator -= (const Matrix3& rhs)
{
    *this = *this - rhs;
}

// * operator with a matrix
Matrix3 Matrix3::operator * (const Matrix3& rhs)
{
    Matrix3 temp;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            float sum = 0;
            for (unsigned int k = 0; k < 3; k++)
            {
                sum += m[i][k] * rhs.m[k][j];
            }
            temp.m[i][j] = sum;
        }
    }

    return temp.transposed();
}

// *= operator with a matrix
void Matrix3::operator *= (const Matrix3& rhs)
{
    *this = *this * rhs;
}

// * operator with a vector
Vector3 Matrix3::operator * (Vector3& rhs)
{
    Vector3 temp;

    temp.x = Vector3(Xx, Yx, Zx).dot(rhs);
    temp.y = Vector3(Xy, Yy, Zy).dot(rhs);
    temp.z = Vector3(Xz, Yz, Zz).dot(rhs);

    return temp;
}

// *= operator with a vector
void Matrix3::operator *= (Vector3& rhs)
{
    rhs = *this * rhs;
}

// + operator with a scalar
Matrix3 Matrix3::operator + (const float& scalar)
{
    Matrix3 temp;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            temp.m[i][j] = m[i][j] + scalar;
        }
    }

    return temp;
}

// += operator with a scalar
void Matrix3::operator += (const float& scalar)
{
    *this = *this * scalar;
}

// - operator with a scalar
Matrix3 Matrix3::operator - (const float& scalar)
{
    Matrix3 temp;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            temp.m[i][j] = m[i][j] - scalar;
        }
    }

    return temp;
}

// -= operator with a scalar
void Matrix3::operator -= (const float& scalar)
{
    *this = *this - scalar;
}

// * operator with a scalar
Matrix3 Matrix3::operator * (const float& scalar)
{
    Matrix3 temp(*this);

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            temp.m[i][j] *= scalar;
        }
    }

    return temp;
}

// *= operator with a scalar
void Matrix3::operator *= (const float& scalar)
{
    *this = *this * scalar;
}

// / operator with a scalar
Matrix3 Matrix3::operator / (const float& scalar)
{
    Matrix3 temp(*this);

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            temp.m[i][j] /= scalar;
        }
    }

    return temp;
}

// /= operator with a scalar
void Matrix3::operator /= (const float& scalar)
{
    *this = *this / scalar;
}