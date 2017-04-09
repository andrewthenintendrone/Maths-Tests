#include "Vector4.h"

/*##################################################
constructors and destructor
##################################################*/

// default to 0s
Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

// construct with a float
Vector4::Vector4(const float& value)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		v[i] = value;
	}
}

// construct with floats
Vector4::Vector4(float newX, float newY, float newZ, float newW)
{
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

// construct with a vector
Vector4::Vector4(const Vector4& vector)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		v[i] = vector.v[i];
	}
}

// destructor
Vector4::~Vector4()
{

}

/*##################################################
functions
##################################################*/

// returns the dot product of vectors
float Vector4::dot(Vector4& rhs)
{
	float sum = 0;

	for (unsigned int i = 0; i < 4; i++)
	{
		sum += v[i] * rhs.v[i];
	}

	return sum;
}

// returns the magnitude of the vector
float Vector4::magnitude()
{
	return sqrt(x * x + y * y + z * z + w * w);
}

// returns the squared magnitude of the vector
float Vector4::squaremagnitude()
{
	return(x * x + y * y + z * z + w * w);
}

// normalises the vector by dividing by magnitude
void Vector4::normalise()
{
	float mag = magnitude();

	for (unsigned int i = 0; i < 4; i++)
	{
		v[i] /= mag;
	}
}

// returns the normalised vector
Vector4 Vector4::normalized()
{
	Vector4 temp(*this);
	temp.normalise();
	return temp;
}

/*##################################################
shortcuts
##################################################*/

// returns a vector pointing up
Vector4 Vector4::Up()
{
	return{ 0, 1, 0, 0 };
}

// returns a vector pointing down
Vector4 Vector4::Down()
{
	return{ 0, -1, 0, 0 };
}

// returns a vector pointing left
Vector4 Vector4::Left()
{
	return{ -1, 0, 0, 0 };
}

// returns a vector pointing right
Vector4 Vector4::Right()
{
	return{ -1, 0, 0, 0 };
}

// returns a vector pointing forward
Vector4 Vector4::Forward()
{
	return{ 0, 0, 1, 0 };
}

// returns a vector pointing back
Vector4 Vector4::Back()
{
	return{ 0, 0, -1, 0 };
}

// returns a vector of 0s
Vector4 Vector4::Zero()
{
	return Vector4(0);
}

/*##################################################
overloads
##################################################*/

// stream << operator
std::ostream& operator << (std::ostream& stream, const Vector4& vector)
{
	stream << "( ";

	for (unsigned int i = 0; i < 4; i++)
	{
		stream << vector.v[i] << " ";
	}

	stream << ")" << std::endl;

	return stream;
}

// returns a pointer
Vector4::operator float* ()
{
	return &x;
}

// returns v index
float& Vector4::operator [] (const int& index)
{
	return v[index];
}

// returns true if vectors are equal
bool Vector4::operator == (const Vector4& rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w);
}

// sets vector with a vector
void Vector4::operator = (const Vector4& rhs)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		v[i] = rhs.v[i];
	}
}

// + operator with a vector
Vector4 Vector4::operator + (const Vector4& rhs)
{
	Vector4 temp;

	for (unsigned int i = 0; i < 4; i++)
	{
		temp[i] = v[i] + rhs.v[i];
	}

	return temp;
}

// += operator with a vector
void Vector4::operator += (const Vector4& rhs)
{
	*this = *this + rhs;
}

// - operator with a vector
Vector4 Vector4::operator - (const Vector4& rhs)
{
	Vector4 temp;

	for (unsigned int i = 0; i < 4; i++)
	{
		temp[i] = v[i] - rhs.v[i];
	}

	return temp;
}

// -= operator with a vector
void Vector4::operator -= (const Vector4& rhs)
{
	*this = *this - rhs;
}

// * operator with a float
Vector4 Vector4::operator * (const float& scalar)
{
	Vector4 temp;

	for (unsigned int i = 0; i < 4; i++)
	{
		temp[i] = v[i] * scalar;
	}

	return temp;
}

// *= operator with a float
void Vector4::operator *= (const float& scalar)
{
	*this = *this * scalar;
}

// float * operator
Vector4 operator * (const float& scalar, Vector4& vector)
{
	return vector * scalar;
}

// / operator with a float
Vector4 Vector4::operator / (const float& scalar)
{
	Vector4 temp(*this);
	temp /= scalar;
	return temp;
}

// /= operator with a float
void Vector4::operator /= (const float& scalar)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		v[i] /= scalar;
	}
}
