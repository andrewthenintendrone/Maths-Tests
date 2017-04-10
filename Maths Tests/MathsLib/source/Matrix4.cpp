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

// construct with a float
Matrix4::Matrix4(const float& newValue)
{
	for (unsigned int i = 0; i < 16; i++)
	{
		m[i] = newValue;
	}
}

// construct with floats
Matrix4::Matrix4(const float& newx1, const float& newy1, const float& newz1, const float& neww1, const float& newx2, const float& newy2, const float& newz2, const float& neww2, const float& newx3, const float& newy3, const float& newz3, const float& neww3, const float& newx4, const float& newy4, const float& newz4, const float& neww4)
{
	x1 = newx1;
	y1 = newy1;
	z1 = newz1;
	w1 = neww1;
	x2 = newx2;
	y2 = newy2;
	z2 = newz2;
	w2 = neww2;
	x3 = newx3;
	y3 = newy3;
	z3 = newz3;
	x4 = newx4;
	y4 = newy4;
	z4 = newz4;
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
Matrix4::Matrix4(const Matrix4& newMatrix)
{
	for (unsigned int i = 0; i < 16; i++)
	{
		m[i] = newMatrix.m[i];
	}
}

Matrix4::~Matrix4()
{

}

/*##################################################
functions
##################################################*/

// returns the determinant of the matrix
float Matrix4::determinant()
{
	Matrix3 block1(y2, z2, w2, y3, z3, w3, y4, z4, w4);
	Matrix3 block2(x2, z2, w2, x3, z3, w3, x4, z4, w4);
	Matrix3 block3(x2, y2, w2, x3, y3, w3, x4, y4, w4);
	Matrix3 block4(x2, y2, z2, x3, y3, z3, x4, y4, z4);

	return (x1 * block1.determinant() - y1 * block2.determinant() + z1 * block3.determinant() - w1 * block4.determinant());
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

// rotates the matrix on the x axis by a given angle
void Matrix4::setRotateX(const float& angle)
{
	Matrix4 rotationMatrix(1, 0, 0, 0, 0, cosf(angle), -sinf(angle), 0, 0, sinf(angle), cosf(angle), 0, 0, 0, 0, 1);
	*this *= rotationMatrix;
}

// rotates the matrix on the y axis by a given angle
void Matrix4::setRotateY(const float& angle)
{
	Matrix4 rotationMatrix(cosf(angle), 0, sinf(angle), 0, 0, 1, 0, 0, sinf(angle), 0, cosf(angle), 0, 0, 0, 0, 1);
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
			temp.mm[i][j] = this->mm[j][i];
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
			stream << matrix.mm[i][j] << " ";
		}
		stream << std::endl;
	}
	return stream;
}

// * operator
Matrix4::operator float* ()
{
	return &m[0];
}

// [] operator that returns vector
Vector4 Matrix4::operator [] (const int& index)
{
	switch (index)
	{
	case 0:
		return Vector4(x1, x2, x3, x4);
	case 1:
		return Vector4(y1, y2, y3, y4);
	case 2:
		return Vector4(z1, z2, z3, z4);
	case 3:
		return Vector4(w1, w2, w3, w4);
	default:
		return Vector4(0, 0, 0, 0);
	}
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
				sum += mm[i][k] * rhs.mm[k][j];
			}
			temp.mm[i][j] = sum;
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
	return Vector4(vecs[0].dot(rhs), vecs[1].dot(rhs), vecs[2].dot(rhs), vecs[3].dot(rhs));
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