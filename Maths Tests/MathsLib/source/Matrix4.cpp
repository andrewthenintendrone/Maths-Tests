#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include <math.h>

namespace AMMaths
{
    /*##################################################
    constructors and destructors
    ##################################################*/

    // default constructor
    Matrix4::Matrix4()
    {
        *this = Matrix4::identity();
    }

    // construct with a float
    Matrix4::Matrix4(const float& newValue)
    {
        for (unsigned int i = 0; i < 16; i++)
        {
            m[i] = newValue;
        }
    }

    // construct with floats
    Matrix4::Matrix4(const float& newx1, const float& newx2, const float& newx3, const float& newx4, const float& newy1, const float& newy2, const float& newy3, const float& newy4, const float& newz1, const float& newz2, const float& newz3, const float& neww1, const float& neww2, const float& neww3, const float& newz4, const float& neww4)
    {
        x1 = newx1;
        x2 = newx2;
        x3 = newx3;
        x4 = newx4;

        y1 = newy1;
        y2 = newy2;
        y3 = newy3;
        y4 = newy4;

        z1 = newz1;
        z2 = newz2;
        z3 = newz3;
        z4 = newz4;

        w1 = neww1;
        w2 = neww2;
        w3 = neww3;
        w4 = neww4;
    }

    // construct with Vectors
    Matrix4::Matrix4(Vector4& newAxis1, Vector4& newAxis2, Vector4& newAxis3, Vector4& newAxis4)
    {
        vecs[0] = newAxis1;
        vecs[1] = newAxis2;
        vecs[2] = newAxis3;
        vecs[3] = newAxis4;
    }

    // construct with another Matrix
    Matrix4::Matrix4(const Matrix2& newMatrix)
    {
        *this = Matrix4(0);
        for (unsigned int i = 0; i < 2; i++)
        {
            for (unsigned int j = 0; j < 2; j++)
            {
                mm[i][j] = newMatrix.mm[i][j];
            }
        }
    }

    // construct with another Matrix
    Matrix4::Matrix4(const Matrix3& newMatrix)
    {
        *this = Matrix4(0);
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                mm[i][j] = newMatrix.mm[i][j];
            }
        }
    }

    // construct with another Matrix
    Matrix4::Matrix4(const Matrix4& newMatrix)
    {
        for (unsigned int i = 0; i < 16; i++)
        {
            m[i] = newMatrix.m[i];
        }
    }

    // destructor
    Matrix4::~Matrix4()
    {

    }

    /*##################################################
    functions
    ##################################################*/

    // returns the determinant of the matrix
    float Matrix4::determinant()
    {
        Matrix3 block1(y2, y3, y4, z2, z3, z4, w2, w3, w4);
        Matrix3 block2(y1, y3, y4, z1, z3, z4, w1, w3, w4);
        Matrix3 block3(y1, y2, y4, z1, z2, z4, w1, w2, w4);
        Matrix3 block4(y1, y2, y3, z1, z2, z3, w1, w2, w3);

        return (x1 * block1.determinant() - x2 * block2.determinant() + x3 * block3.determinant() - x4 * block4.determinant());
    }

    // returns the identity matrix
    Matrix4 Matrix4::identity()
    {
        return Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    }

    // returns a matrix of 0s
    Matrix4 Matrix4::zero()
    {
        return Matrix4(0);
    }

    // sets the matrix to the rotation matrix for a given angle on the x axis
    void Matrix4::setRotateX(const float& angle)
    {
        *this = Matrix4(1, 0, 0, 0, 0, cosf(angle), sinf(angle), 0, 0, -sinf(angle), cosf(angle), 0, 0, 0, 0, 1);
    }

    // sets the matrix to the rotation matrix for a given angle on the y axis
    void Matrix4::setRotateY(const float& angle)
    {
        *this = Matrix4(cosf(angle), 0, -sinf(angle), 0, 0, 1, 0, 0, sinf(angle), 0, cosf(angle), 0, 0, 0, 0, 1);
    }

    // sets the matrix to the rotation matrix for a given angle on the z axis
    void Matrix4::setRotateZ(const float& angle)
    {
        *this = Matrix4(cosf(angle), sinf(angle), 0, 0, -sinf(angle), cosf(angle), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    }

    // transposes this matrix
    void Matrix4::transpose()
    {
        Matrix4 temp(*this);
        for (unsigned int i = 0; i < 4; i++)
        {
            for (unsigned int j = 0; j < 4; j++)
            {
                temp.mm[i][j] = this->mm[j][i];
            }
        }
        *this = temp;
    }

    // returns the transposed matrix
    Matrix4 Matrix4::transposed()
    {
        Matrix4 temp(*this);
        temp.transpose();
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
                stream << matrix.mm[j][i] << " ";
            }
            stream << std::endl;
        }
        return stream;
    }

    // returns a pointer to a float array
    Matrix4::operator float* ()
    {
        return &m[0];
    }

    // [] operator that returns vector
    Vector4& Matrix4::operator [] (const int& index)
    {
        return vecs[index];
    }

    // returns true if matricies are equal
    bool Matrix4::operator == (const Matrix4& rhs)
    {
        for (unsigned int i = 0; i < 16; i++)
        {
            if (m[i] != rhs.m[i])
            {
                return false;
            }
        }
        return true;
    }

    // = operator with a matrix
    void Matrix4::operator = (const Matrix2& newMatrix)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            for (unsigned int j = 0; j < 2; j++)
            {
                mm[i][j] = newMatrix.mm[i][j];
            }
        }
    }

    // = operator with a matrix
    void Matrix4::operator = (const Matrix3& newMatrix)
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                mm[i][j] = newMatrix.mm[i][j];
            }
        }
    }

    // = operator with a matrix
    void Matrix4::operator = (const Matrix4& newMatrix)
    {
        for (unsigned int i = 0; i < 16; i++)
        {
            m[i] = newMatrix.m[i];
        }
    }

    // + operator with a matrix
    Matrix4 Matrix4::operator + (const Matrix4& rhs)
    {
        Matrix4 temp;

        for (unsigned int i = 0; i < 16; i++)
        {
            temp.m[i] = m[i] + rhs.m[i];
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

        for (unsigned int i = 0; i < 16; i++)
        {
            temp.m[i] = m[i] - rhs.m[i];
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
                    sum += mm[k][i] * rhs.mm[j][k];
                }
                temp.mm[j][i] = sum;
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
        Vector4 temp;

        for (unsigned int i = 0; i < 1; i++)
        {
            for (unsigned int j = 0; j < 4; j++)
            {
                float sum = 0;
                for (unsigned int k = 0; k < 4; k++)
                {
                    sum += mm[k][j] * rhs.v[k];
                }
                temp.v[j] = sum;
            }
        }

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

        for (unsigned int i = 0; i < 16; i++)
        {
            temp.m[i] = m[i] + scalar;
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

        for (unsigned int i = 0; i < 16; i++)
        {
            temp.m[i] = m[i] - scalar;
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

        for (unsigned int i = 0; i < 16; i++)
        {
            temp.m[i] = m[i] * scalar;
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

        for (unsigned int i = 0; i < 16; i++)
        {
            temp.m[i] = m[i] / scalar;
        }

        return temp;
    }

    // /= operator with a scalar
    void Matrix4::operator /= (const float& scalar)
    {
        *this = *this / scalar;
    }
}
