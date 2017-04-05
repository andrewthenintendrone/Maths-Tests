#include "Matrix4.h"
#include "Matrix3.h"

/*##################################################
Matrix4 constructor and destructor
##################################################*/
Matrix4::Matrix4()
{
	for (unsigned int i = 0; i < 9; i++)
	{
		m[i] = Matrix4::identity().m[i];
	}
}

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
	w3 = neww3;
	x4 = newx4;
	y4 = newy4;
	z4 = newz4;
	w4 = neww4;
}

Matrix4::Matrix4(const Vector4& newVec1, const Vector4& newVec2, const Vector4& newVec3, const Vector4& newVec4)
{
	vecs[0] = newVec1;
	vecs[1] = newVec2;
	vecs[2] = newVec3;
	vecs[3] = newVec4;
}

Matrix4::Matrix4(const float& newValue)
{
	for (unsigned int i = 0; i < 16; i++)
	{
		m[i] = newValue;
	}
}

Matrix4::Matrix4(const Matrix4& newM)
{
	for (unsigned int i = 0; i < 16; i++)
	{
		m[i] = newM.m[i];
	}
}

Matrix4::~Matrix4()
{

}

/*##################################################
Matrix4 Functions
##################################################*/
float Matrix4::determinant()
{
	Matrix3 block1(y2, z2, w2, y3, z3, w3, y4, z4, w4);
	Matrix3 block2(x2, z2, w2, x3, z3, w3, x4, z4, w4);
	Matrix3 block3(x2, y2, w2, x3, y3, w3, x4, y4, w4);
	Matrix3 block4(x2, y2, z2, x3, y3, z3, x4, y4, z4);

    return (x1 * block1.determinant() - y1 * block2.determinant() + z1 * block3.determinant() - w1 * block4.determinant());
}

Matrix4 Matrix4::identity()
{
	return Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

/*##################################################
Matrix4 overloaded operators
##################################################*/
Matrix4::operator float* ()
{
	return &x1;
}

Vector4 Matrix4::operator [] (const int& index)
{
	return vecs[index];
}

void Matrix4::operator = (const Matrix4& rhs)
{
	for (unsigned int i = 0; i < 16; i++)
	{
		m[i] = rhs.m[i];
	}
}

void Matrix4::operator += (const Matrix4& rhs)
{
	for (unsigned int i = 0; i < 16; i++)
	{
		m[i] += rhs.m[i];
	}
}

Matrix4 Matrix4::operator + (const Matrix4& rhs)
{
	Matrix4 temp(*this);
	temp += rhs;
	return temp;
}

void Matrix4::operator -= (const Matrix4& rhs)
{
	for (unsigned int i = 0; i < 16; i++)
	{
		m[i] -= rhs.m[i];
	}
}

Matrix4 Matrix4::operator - (const Matrix4& rhs)
{
	Matrix4 temp(*this);
	temp -= rhs;
	return temp;
}

void Matrix4::operator *= (const float& scalar)
{
	for (unsigned int i = 0; i < 16; i++)
	{
		m[i] *= scalar;
	}
}

Matrix4 Matrix4::operator * (const float& scalar)
{
	Matrix4 temp(*this);
	temp *= scalar;
	return temp;
}

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
				sum += m[i * 4 + k] * rhs.m[k * 4 + j];
			}
			temp.m[i * 4 + j] = sum;
		}
	}

	return temp;
}

void Matrix4::operator /= (const float& scalar)
{
	for (unsigned int i = 0; i < 16; i++)
	{
		m[i] /= scalar;
	}
}

Matrix4 Matrix4::operator / (const float& scalar)
{
	Matrix4 temp(*this);
	temp /= scalar;
	return temp;
}

std::ostream& operator << (std::ostream& stream, const Matrix4& matrix)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		stream << matrix.vecs[i];
		stream << std::endl;
	}
	return stream;
}