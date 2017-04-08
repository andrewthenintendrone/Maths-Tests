#include "Matrix4.h"
#include "Matrix3.h"
#include <math.h>

/*##################################################
constructors and destructors
##################################################*/

// default constructor
Matrix4::Matrix4()
{
    *this = Matrix4::identity();
}

// construct with floats
Matrix4::Matrix4(const float& newXx, const float& newXy, const float& newXz, const float& newXw, const float& newYx, const float& newYy, const float& newYz, const float& newYw, const float& newZx, const float& newZy, const float& newZz, const float& newZw, const float& newWx, const float& newWy, const float& newWz, const float& newWw)
{
    Xx = newXx;
    Xy = newXy;
    Xz = newXz;
    Xw = newXw;
    Yx = newYx;
    Yy = newYy;
    Yz = newYz;
    Yw = newYw;
    Zx = newZx;
    Zy = newZy;
    Zz = newZz;
    Zw = newZw;
    Wx = newWx;
    Wy = newWy;
    Wz = newWz;
    Ww = newWw;
}

// construct with Vectors
Matrix4::Matrix4(Vector4& newxAxis, Vector4& newyAxis, Vector4& newzAxis, Vector4& newwAxis)
{
    Xx = newxAxis.x;
    Xy = newxAxis.y;
    Xz = newxAxis.z;
    Xw = newxAxis.w;

    Yx = newyAxis.x;
    Yy = newyAxis.y;
    Yz = newyAxis.z;
    Yw = newyAxis.w;

    Zx = newzAxis.x;
    Zy = newzAxis.y;
    Zz = newzAxis.z;
    Zw = newzAxis.w;

    Wx = newwAxis.x;
    Wy = newwAxis.y;
    Wz = newwAxis.z;
    Ww = newwAxis.w;
}

// construct with another Matrix
Matrix4::Matrix4(const Matrix4& newMatrix)
{
    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
        {
            m[i][j] = newMatrix.m[i][j];
        }
    }
}

Matrix4::~Matrix4()
{

}

/*##################################################
functions
##################################################*/

// returns the identity matrix
Matrix4 Matrix4::identity()
{
    return Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

// returns the determinant of the matrix
float Matrix4::determinant()
{
    Matrix3 block1(Yy, Yz, Yw, Zy, Zz, Zw, Wy, Wz, Ww);
    Matrix3 block2(Xy, Xz, Xw, Zy, Zz, Zw, Wy, Wz, Ww);
    Matrix3 block3(Xy, Xz, Xw, Yy, Yz, Yw, Wy, Wz, Ww);
    Matrix3 block4(Xy, Xz, Xw, Yy, Yz, Yw, Zy, Zz, Zw);

    return (Xx * block1.determinant() - Yx * block2.determinant() + Zx * block3.determinant() - Wx * block4.determinant());
}

// rotates the matrix on the x axis by a given angle
void Matrix4::setRotateX(const float& angle)
{
    Matrix4 rotationMatrix(1, 0, 0, 0, 0, cosf(angle), -sinf(angle), 0, 0, sinf(angle), cosf(angle), 0, 0, 0, 0, 1);
    *this *= rotationMatrix;
}

// rotates the matrix on the y axis by a given angle
void Matrix4::setRotateY(const float& angle)
{
    Matrix4 rotationMatrix(cosf(angle), 0, sinf(angle), 0, 0, 1, 0, 0, -sinf(angle), 0, cosf(angle), 0, 0, 0, 0, 1);
    *this *= rotationMatrix;
}

// rotates the matrix on the z axis by a given angle
void Matrix4::setRotateZ(const float& angle)
{
    Matrix4 rotationMatrix(cosf(angle), -sinf(angle), 0, 0, sinf(angle), cosf(angle), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    *this *= rotationMatrix;
}

// returns the transposed matrix
Matrix4 Matrix4::transposed()
{
    Matrix4 temp;

    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
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
std::ostream& operator << (std::ostream& stream, const Matrix4& matrix)
{
    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
        {
            stream << matrix.m[j][i] << " ";
        }
        stream << std::endl;
    }
    return stream;
}

// * operator
Matrix4::operator float* ()
{
    return &Xx;
}

// [] operator that returns vector
Vector4 Matrix4::operator [] (const int& index)
{
    switch (index)
    {
    case 0:
        return Vector4(Xx, Xy, Xz, Xw);
    case 1:
        return Vector4(Yx, Yy, Yz, Yw);
    case 2:
        return Vector4(Zx, Zy, Zz, Zw);
    case 3:
        return Vector4(Wx, Wy, Wz, Ww);
    default:
        return Vector4(0, 0, 0, 0);
    }
}

// = operator with a matrix
void Matrix4::operator = (const Matrix4& newMatrix)
{
    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
        {
            m[i][j] = newMatrix.m[i][j];
        }
    }
}

// + operator with a matrix
Matrix4 Matrix4::operator + (const Matrix4& rhs)
{
    Matrix4 temp;

    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
        {
            temp.m[i][j] = m[i][j] + rhs.m[i][j];
        }
    }

    return temp;
}

// += operator with a matrix
void Matrix4::operator += (const Matrix4& rhs)
{
    *this = *this + rhs;
}

// - operator with a matrix
Matrix4 Matrix4::operator - (const Matrix4& rhs)
{
    Matrix4 temp;

    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
        {
            temp.m[i][j] = m[i][j] - rhs.m[i][j];
        }
    }

    return temp;
}

// -= operator with a matrix
void Matrix4::operator -= (const Matrix4& rhs)
{
    *this = *this - rhs;
}

// * operator with a matrix
Matrix4 Matrix4::operator * (const Matrix4& rhs)
{
    Matrix4 temp;

    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
        {
            float sum = 0;
            for (unsigned int k = 0; k < 4; k++)
            {
                sum += m[i][k] * rhs.m[k][j];
            }
            temp.m[i][j] = sum;
        }
    }

    return temp.transposed();
}

// *= operator with a matrix
void Matrix4::operator *= (const Matrix4& rhs)
{
    *this = *this * rhs;
}

// * operator with a vector
Vector4 Matrix4::operator * (Vector4& rhs)
{
    Vector4 temp;

    temp.x = Vector4(Xx, Yx, Zx, Wx).dot(rhs);
    temp.y = Vector4(Xy, Yy, Zy, Wy).dot(rhs);
    temp.z = Vector4(Xz, Yz, Zz, Wz).dot(rhs);
    temp.w = Vector4(Xw, Yw, Zw, Ww).dot(rhs);

    return temp;
}

// *= operator with a vector
void Matrix4::operator *= (Vector4& rhs)
{
    rhs = *this * rhs;
}

// + operator with a scalar
Matrix4 Matrix4::operator + (const float& scalar)
{
    Matrix4 temp;

    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
        {
            temp.m[i][j] = m[i][j] + scalar;
        }
    }

    return temp;
}

// += operator with a scalar
void Matrix4::operator += (const float& scalar)
{
    *this = *this * scalar;
}

// - operator with a scalar
Matrix4 Matrix4::operator - (const float& scalar)
{
    Matrix4 temp;

    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
        {
            temp.m[i][j] = m[i][j] - scalar;
        }
    }

    return temp;
}

// -= operator with a scalar
void Matrix4::operator -= (const float& scalar)
{
    *this = *this - scalar;
}

// * operator with a scalar
Matrix4 Matrix4::operator * (const float& scalar)
{
    Matrix4 temp(*this);

    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
        {
            temp.m[i][j] *= scalar;
        }
    }

    return temp;
}

// *= operator with a scalar
void Matrix4::operator *= (const float& scalar)
{
    *this = *this * scalar;
}

// / operator with a scalar
Matrix4 Matrix4::operator / (const float& scalar)
{
    Matrix4 temp(*this);

    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
        {
            temp.m[i][j] /= scalar;
        }
    }

    return temp;
}

// /= operator with a scalar
void Matrix4::operator /= (const float& scalar)
{
    *this = *this / scalar;
}