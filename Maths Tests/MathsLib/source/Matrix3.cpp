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
Matrix3::Matrix3(const float& new11, const float& new12, const float& new13, const float& new21, const float& new22, const float& new23, const float& new31, const float& new32, const float& new33)
{
    m[0][0] = new11;
    m[0][1] = new12;
    m[0][2] = new13;

    m[1][0] = new21;
    m[1][1] = new22;
    m[1][2] = new23;

    m[2][0] = new31;
    m[2][1] = new32;
    m[2][2] = new33;
}

// construct with Vectors
Matrix3::Matrix3(Vector3& newAxis1, Vector3& newAxis2, Vector3& newAxis3)
{
    m[0][0] = newAxis1.x;
    m[0][1] = newAxis1.y;
    m[0][2] = newAxis1.z;

    m[1][0] = newAxis2.x;
    m[1][1] = newAxis2.y;
    m[1][2] = newAxis2.z;

    m[2][0] = newAxis3.x;
    m[2][1] = newAxis3.y;
    m[2][2] = newAxis3.z;
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
    Matrix2 block1(m[1][1], m[1][2], m[2][1], m[2][2]);
    Matrix2 block2(m[1][0], m[1][2], m[2][0], m[2][2]);
    Matrix2 block3(m[1][0], m[1][1], m[2][0], m[2][1]);

    return (m[0][0] * block1.determinant() - m[0][1] * block2.determinant() + m[0][2] * block3.determinant());
}

// rotates the matrix on the x axis by a given angle
void Matrix3::setRotateX(const float& angle)
{
    Matrix3 rotationMatrix(1, 0, 0, 0, cosf(angle), -sinf(angle), 0, sinf(angle), cosf(angle));
    *this *= rotationMatrix.transposed();
}

// rotates the matrix on the y axis by a given angle
void Matrix3::setRotateY(const float& angle)
{
    Matrix3 rotationMatrix(cosf(angle), 0, sinf(angle), 0, 1, 0, -sinf(angle), 0, cosf(angle));
    *this *= rotationMatrix.transposed();
}

// rotates the matrix on the z axis by a given angle
void Matrix3::setRotateZ(const float& angle)
{
    Matrix3 rotationMatrix(cosf(angle), -sinf(angle), 0, sinf(angle), cosf(angle), 0, 0, 0, 1);
    *this *= rotationMatrix.transposed();
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
            stream << matrix.m[i][j] << " ";
        }
        stream << std::endl;
    }
    return stream;
}

// * operator
Matrix3::operator float* ()
{
    return &m[0][0];
}

// [] operator that returns vector
Vector3 Matrix3::operator [] (const int& index)
{
    return vecs[index];
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
Matrix3 Matrix3::operator * (Matrix3& rhs)
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

    return temp;
}

// *= operator with a matrix
void Matrix3::operator *= (Matrix3& rhs)
{
    *this = *this * rhs;
}

// * operator with a vector
Vector3 Matrix3::operator * (Vector3& rhs)
{
    Matrix3 temp(this->transposed());

    return Vector3(temp[0].dot(rhs), temp[1].dot(rhs), temp[2].dot(rhs));
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