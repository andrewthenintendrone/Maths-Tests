#include "Matrix3.h"
#include "Matrix2.h"
#include <math.h>

/*##################################################
Matrix3 constructor and destructor
##################################################*/
Matrix3::Matrix3()
{
    *this = Matrix3::identity();
}

Matrix3::Matrix3(const float& newx1, const float& newy1, const float& newz1, const float& newx2, const float& newy2, const float& newz2, const float& newx3, const float& newy3, const float& newz3)
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

Matrix3::Matrix3(const Vector3& newVec1, const Vector3& newVec2, const Vector3& newVec3)
{
	vecs[0] = newVec1;
	vecs[1] = newVec2;
	vecs[2] = newVec3;
}

Matrix3::Matrix3(const float& newValue)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		f[i] = newValue;
	}
}

Matrix3::Matrix3(const Matrix3& newM)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		f[i] = newM.f[i];
	}
}

Matrix3::~Matrix3()
{

}

/*##################################################
Matrix3 Functions
##################################################*/
float Matrix3::determinant()
{
    Matrix2 block1(y2, z2, y3, z3);
    Matrix2 block2(x2, z2, x3, z3);
    Matrix2 block3(x2, y2, x3, y3);

    return (x1 * block1.determinant() - y1 * block2.determinant() + z1 * block3.determinant());
}

void Matrix3::setRotateX(const float& angle)
{
    Matrix3 rotationMatrix(1, 0, 0, 0, cosf(angle), sinf(angle), 0, -sinf(angle), cosf(angle));
    *this *= rotationMatrix;
}

void Matrix3::setRotateY(const float& angle)
{
    Matrix3 rotationMatrix(cosf(angle), 0, -sinf(angle), 0, 1, 0, sinf(angle), 0, cosf(angle));
    *this *= rotationMatrix;
}

void Matrix3::setRotateZ(const float& angle)
{
    Matrix3 rotationMatrix(cosf(angle), sinf(angle), 0, -sinf(angle), cosf(angle), 0, 0, 0, 1);
    *this *= rotationMatrix;
}

/*##################################################
Matrix3 shortcuts for commonly used Matrix3s
##################################################*/
Matrix3 Matrix3::identity()
{
	return Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

/*##################################################
Matrix3 overloaded operators
##################################################*/
Matrix3::operator float* ()
{
	return &x1;
}

Vector3& Matrix3::operator [] (const int& index)
{
	return vecs[index];
}

void Matrix3::operator = (const Matrix3& rhs)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		f[i] = rhs.f[i];
	}
}

void Matrix3::operator += (const Matrix3& rhs)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		f[i] += rhs.f[i];
	}
}

Matrix3 Matrix3::operator + (const Matrix3& rhs)
{
	Matrix3 temp(*this);
	temp += rhs;
	return temp;
}

void Matrix3::operator -= (const Matrix3& rhs)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		f[i] -= rhs.f[i];
	}
}

Matrix3 Matrix3::operator - (const Matrix3& rhs)
{
	Matrix3 temp(*this);
	temp -= rhs;
	return temp;
}

void Matrix3::operator *= (const float& scalar)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		f[i] *= scalar;
	}
}

Matrix3 Matrix3::operator * (const float& scalar)
{
	Matrix3 temp(*this);
	temp *= scalar;
	return temp;
}

void Matrix3::operator *= (const Matrix3& rhs)
{
    Matrix3 temp;
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            float sum = 0;
            for (unsigned int k = 0; k < 3; k++)
            {
                sum += f[i * 3 + k] * rhs.f[k * 3 + j];
            }
            temp.f[i * 3 + j] = sum;
        }
    }
    *this = temp;
}

Matrix3 Matrix3::operator * (const Matrix3& rhs)
{
    Matrix3 temp(*this);
    temp *= rhs;
    return temp;
}

void Matrix3::operator *= (Vector3& rhs)
{
    for (unsigned int i = 0; i < 3; i++)
    {
        rhs[i] = rhs.dot(vecs[i]);
    }
}

Vector3 Matrix3::operator * (Vector3& rhs)
{
    Matrix3 tempMatrix(*this);
    Vector3 tempVector(*rhs);

    tempMatrix *= tempVector;

    return tempVector;
}

void Matrix3::operator /= (const float& scalar)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		f[i] /= scalar;
	}
}

Matrix3 Matrix3::operator / (const float& scalar)
{
	Matrix3 temp(*this);
	temp /= scalar;
	return temp;
}

std::ostream& operator << (std::ostream& stream, const Matrix3& matrix)
{
	for (unsigned int i = 0; i < 3; i++)
	{
        for (unsigned int j = 0; j < 3; j++)
        {
            stream << matrix.f[j * 3 + i] << " ";
        }
		stream << std::endl;
	}
	return stream;
}