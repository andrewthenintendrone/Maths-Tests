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
Matrix4::Matrix4(const float& new11, const float& new12, const float& new13, const float& new14, const float& new21, const float& new22, const float& new23, const float& new24, const float& new31, const float& new32, const float& new33, const float& new34, const float& new41, const float& new42, const float& new43, const float& new44)
{
    m[0][0] = new11;
    m[0][1] = new12;
    m[0][2] = new13;
    m[0][3] = new14;

    m[1][0] = new21;
    m[1][1] = new22;
    m[1][2] = new23;
    m[1][3] = new24;

    m[2][0] = new31;
    m[2][1] = new32;
    m[2][2] = new33;
    m[2][3] = new34;

    m[3][0] = new41;
    m[3][1] = new42;
    m[3][2] = new43;
    m[3][3] = new44;
}

// construct with Vectors
Matrix4::Matrix4(Vector4& newAxis1, Vector4& newAxis2, Vector4& newAxis3, Vector4& newAxis4)
{
    m[0][0] = newAxis1.x;
    m[0][1] = newAxis1.y;
    m[0][2] = newAxis1.z;
    m[0][3] = newAxis1.w;

    m[1][0] = newAxis2.x;
    m[1][1] = newAxis2.y;
    m[1][2] = newAxis2.z;
    m[1][3] = newAxis2.w;

    m[2][0] = newAxis3.x;
    m[2][1] = newAxis3.y;
    m[2][2] = newAxis3.z;
    m[2][3] = newAxis3.w;

    m[3][0] = newAxis4.x;
    m[3][1] = newAxis4.y;
    m[3][2] = newAxis4.z;
    m[3][3] = newAxis4.w;
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
    Matrix3 block1(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);
    Matrix3 block2(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);
    Matrix3 block3(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);
    Matrix3 block4(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);

    return (m[0][0] * block1.determinant() - m[0][1] * block2.determinant() + m[0][2] * block3.determinant() - m[0][3] * block4.determinant());
}

// rotates the matrix on the x axis by a given angle
void Matrix4::setRotateX(const float& angle)
{
    Matrix4 rotationMatrix(1, 0, 0, 0, 0, cosf(angle), -sinf(angle), 0, 0, sinf(angle), cosf(angle), 0, 0, 0, 0, 1);
    *this *= rotationMatrix.transposed();
}

// rotates the matrix on the y axis by a given angle
void Matrix4::setRotateY(const float& angle)
{
    Matrix4 rotationMatrix(cosf(angle), 0, sinf(angle), 0, 0, 1, 0, 0, -sinf(angle), 0, cosf(angle), 0, 0, 0, 0, 1);
    *this *= rotationMatrix.transposed();
}

// rotates the matrix on the z axis by a given angle
void Matrix4::setRotateZ(const float& angle)
{
    Matrix4 rotationMatrix(cosf(angle), -sinf(angle), 0, 0, sinf(angle), cosf(angle), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    *this *= rotationMatrix.transposed();
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
            stream << matrix.m[i][j] << " ";
        }
        stream << std::endl;
    }
    return stream;
}

// * operator
Matrix4::operator float* ()
{
    return &m[0][0];
}

// [] operator that returns vector
Vector4 Matrix4::operator [] (const int& index)
{
    return vecs[index];
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
Matrix4 Matrix4::operator * (Matrix4& rhs)
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

    return temp;
}

// *= operator with a matrix
void Matrix4::operator *= (Matrix4& rhs)
{
    *this = *this * rhs;
}

// * operator with a vector
Vector4 Matrix4::operator * (Vector4& rhs)
{
    Matrix4 temp(this->transposed());

    return Vector4(temp[0].dot(rhs), temp[1].dot(rhs), temp[2].dot(rhs), temp[3].dot(rhs));
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