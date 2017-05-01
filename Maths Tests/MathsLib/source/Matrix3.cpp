#include "Matrix2.h"
#include "Matrix4.h"
#include "Matrix3.h"
#include <math.h>

namespace AFMaths
{
    /*##################################################
    constructors and destructors
    ##################################################*/

    // default constructor
    Matrix3::Matrix3()
    {
        *this = Matrix3::identity();
    }

    // construct with a float
    Matrix3::Matrix3(const float& newValue)
    {
        for (unsigned int i = 0; i < 9; i++)
        {
            m[i] = newValue;
        }
    }

    // construct with floats
    Matrix3::Matrix3(const float& newx1, const float& newx2, const float& newx3, const float& newy1, const float& newy2, const float& newy3, const float& newz1, const float& newz2, const float& newz3)
    {
        x1 = newx1;
        y1 = newy1;
        z1 = newz1;

        x2 = newx2;
        y2 = newy2;
        z2 = newz2;

        x3 = newx3;
        y3 = newy3;
        z3 = newz3;
    }

    // construct with Vectors
    Matrix3::Matrix3(Vector3& newAxis1, Vector3& newAxis2, Vector3& newAxis3)
    {
        vecs[0] = newAxis1;
        vecs[1] = newAxis2;
        vecs[2] = newAxis3;
    }

    // construct with another Matrix
    Matrix3::Matrix3(const Matrix2& newMatrix)
    {
        *this = Matrix3(0);
        for (unsigned int i = 0; i < 2; i++)
        {
            for (unsigned int j = 0; j < 2; j++)
            {
                mm[i][j] = newMatrix.mm[i][j];
            }
        }
    }

    // construct with another Matrix
    Matrix3::Matrix3(const Matrix3& newMatrix)
    {
        for (unsigned int i = 0; i < 9; i++)
        {
            m[i] = newMatrix.m[i];
        }
    }

    // construct with another Matrix
    Matrix3::Matrix3(const Matrix4& newMatrix)
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                mm[i][j] = newMatrix.mm[i][j];
            }
        }
    }

    // destructor
    Matrix3::~Matrix3()
    {

    }

    /*##################################################
    functions
    ##################################################*/

    // returns the determinant of the matrix
    float Matrix3::determinant()
    {
        Matrix2 block1(y2, y3, z2, z3);
        Matrix2 block2(y1, y3, z1, z3);
        Matrix2 block3(y1, y2, z1, z2);

        return (x1 * block1.determinant() - x2 * block2.determinant() + x3 * block3.determinant());
    }

    // returns the identity matrix
    Matrix3 Matrix3::identity()
    {
        return Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
    }

    // returns a matrix of 0s
    Matrix3 Matrix3::zero()
    {
        return Matrix3(0);
    }

    // sets the matrix to the rotation matrix for a given angle on the x axis
    void Matrix3::setRotateX(const float& angle)
    {
        *this = Matrix3(1, 0, 0, 0, cosf(angle), sinf(angle), 0, -sinf(angle), cosf(angle));
    }

    // sets the matrix to the rotation matrix for a given angle on the y axis
    void Matrix3::setRotateY(const float& angle)
    {
        *this = Matrix3(cosf(angle), 0, -sinf(angle), 0, 1, 0, sinf(angle), 0, cosf(angle));
    }

    // sets the matrix to the rotation matrix for a given angle on the z axis
    void Matrix3::setRotateZ(const float& angle)
    {
        *this = Matrix3(cosf(angle), sinf(angle), 0, -sinf(angle), cosf(angle), 0, 0, 0, 1);
    }

    // transposes this matrix
    void Matrix3::transpose()
    {
        Matrix3 temp(*this);
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                temp.mm[i][j] = this->mm[j][i];
            }
        }
        *this = temp;
    }

    // returns the transposed matrix
    Matrix3 Matrix3::transposed()
    {
        Matrix3 temp(*this);
        temp.transpose();
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
                stream << matrix.mm[j][i] << " ";
            }
            stream << std::endl;
        }
        return stream;
    }

    // returns a pointer to a float array
    Matrix3::operator float* ()
    {
        return &m[0];
    }

    // [] operator that returns vector
    Vector3& Matrix3::operator [] (const int& index)
    {
        return vecs[index];
    }

    // returns true if matricies are equal
    bool Matrix3::operator == (const Matrix3& rhs)
    {
        for (unsigned int i = 0; i < 9; i++)
        {
            if (m[i] != rhs.m[i])
            {
                return false;
            }
        }
        return true;
    }

    // = operator with a matrix
    void Matrix3::operator = (const Matrix3& newMatrix)
    {
        for (unsigned int i = 0; i < 9; i++)
        {
            m[i] = newMatrix.m[i];
        }
    }

    // + operator with a matrix
    Matrix3 Matrix3::operator + (const Matrix3& rhs)
    {
        Matrix3 temp;

        for (unsigned int i = 0; i < 9; i++)
        {
            temp.m[i] = m[i] + rhs.m[i];
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

        for (unsigned int i = 0; i < 9; i++)
        {
            temp.m[i] = m[i] - rhs.m[i];
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
                    sum += mm[k][i] * rhs.mm[j][k];
                }
                temp.mm[j][i] = sum;
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
        Vector3 temp;

        for (unsigned int i = 0; i < 1; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                float sum = 0;
                for (unsigned int k = 0; k < 3; k++)
                {
                    sum += mm[k][j] * rhs.v[k];
                }
                temp.v[j] = sum;
            }
        }

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

        for (unsigned int i = 0; i < 9; i++)
        {
            temp.m[i] = m[i] + scalar;
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

        for (unsigned int i = 0; i < 9; i++)
        {
            temp.m[i] = m[i] - scalar;
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

        for (unsigned int i = 0; i < 9; i++)
        {
            temp.m[i] = m[i] * scalar;
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

        for (unsigned int i = 0; i < 9; i++)
        {
            temp.m[i] = m[i] / scalar;
        }

        return temp;
    }

    // /= operator with a scalar
    void Matrix3::operator /= (const float& scalar)
    {
        *this = *this / scalar;
    }
}
