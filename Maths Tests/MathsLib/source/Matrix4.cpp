#include "Matrix4.h"

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

Matrix4::Matrix4(const float& newx0, const float& newx1, const float& newx2, const float& newx3, const float& newy0, const float& newy1, const float& newy2, const float& newy3, const float& newz0, const float& newz1, const float& newz2, const float& newz3, const float& neww0, const float& neww1, const float& neww2, const float& neww3)
{
	x0 = newx0;
	x1 = newx1;
	x2 = newx2;
	x3 = newx3;
	y0 = newy0;
	y1 = newy1;
	y2 = newy2;
	y3 = newy3;
	z0 = newz0;
	z1 = newz1;
	z2 = newz2;
	z3 = newz3;
	w0 = neww0;
	w1 = neww1;
	w2 = neww2;
	w3 = neww3;
}

Matrix4::Matrix4(const Vector4& row1, const Vector4& row2, const Vector4& row3, const Vector4& row4)
{
	vecs[0] = row1;
	vecs[1] = row2;
	vecs[2] = row3;
	vecs[3] = row4;
}

Matrix4::Matrix4(const float& newM)
{
	for (unsigned int i = 0; i < 16; i++)
	{
		m[i] = newM;
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
    return(x0 * y1 * z2 * w3 + x1 * y2 * z3 * w0 + x2 * y3 * z0 * w1 + x3 * y0 * z1 * w2) - (w0 * z1 * y2 * x3 + w1 * z2 * y3 * x0 + w2 * z3 * y0 * x1 + w3 * z0 * y1 * x2);
}

Matrix4 Matrix4::dot(const Matrix4& rhs)
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

Matrix4 Matrix4::identity()
{
	return Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

/*##################################################
Matrix4 overloaded operators
##################################################*/
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