#include "Vector3.h"

/*##################################################
constructors and destructor
##################################################*/

// default to 0s
Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

// construct with a float
Vector3::Vector3(const float& value)
{
	for (unsigned int i = 0; i < 3; i++)
	{
		v[i] = value;
	}
}

// construct with floats
Vector3::Vector3(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

// construct with a vector
Vector3::Vector3(const Vector3& vector)
{
	for (unsigned int i = 0; i < 3; i++)
	{
		v[i] = vector.v[i];
	}
}

// destructor
Vector3::~Vector3()
{

}

/*##################################################
functions
##################################################*/

// returns the dot product of vectors
float Vector3::dot(Vector3& rhs)
{
	float sum = 0;

	for (unsigned int i = 0; i < 3; i++)
	{
		sum += v[i] * rhs.v[i];
	}

	return sum;
}

Vector3 Vector3::cross(Vector3& rhs)
{
	Vector3 temp;

	temp.x = y * rhs.z - z * rhs.y;
	temp.y = z * rhs.x - x * rhs.z;
	temp.z = x * rhs.y - y * rhs.x;

	return temp;
}

// returns the magnitude of the vector
float Vector3::magnitude()
{
	return sqrt(x * x + y * y + z * z);
}

// returns the squared magnitude of the vector
float Vector3::squaremagnitude()
{
	return(x * x + y * y + z * z);
}

// normalises the vector by dividing by magnitude
void Vector3::normalise()
{
	float mag = magnitude();

	for (unsigned int i = 0; i < 3; i++)
	{
		v[i] /= mag;
	}
}

// returns the normalised vector
Vector3 Vector3::normalized()
{
	Vector3 temp(*this);
	temp.normalise();
	return temp;
}

// returns the vector normalized by a certain percentage
Vector3 Vector3::semiNormalized(float ammount)
{
	float mag = magnitude() * fabs(ammount);
	Vector3 temp(this->normalized());

	for (unsigned int i = 0; i < 3; i++)
	{
		temp.v[i] *= mag;
	}

	return temp;
}

// returns a glm vec of the vector
glm::vec3 Vector3::toGLM()
{
	return glm::vec3(x, y, z);
}

/*##################################################
shortcuts
##################################################*/

// returns a vector pointing up
Vector3 Vector3::Up()
{
	return{ 0, 1, 0 };
}

// returns a vector pointing down
Vector3 Vector3::Down()
{
	return{ 0, -1, 0 };
}

// returns a vector pointing left
Vector3 Vector3::Left()
{
	return{ -1, 0, 0 };
}

// returns a vector pointing right
Vector3 Vector3::Right()
{
	return{ -1, 0, 0 };
}

// returns a vector pointing forward
Vector3 Vector3::Forward()
{
	return{ 0, 0, 1 };
}

// returns a vector pointing back
Vector3 Vector3::Back()
{
	return{ 0, 0, -1 };
}

// returns a vector of 0s
Vector3 Vector3::Zero()
{
	return Vector3(0);
}

/*##################################################
overloads
##################################################*/

// stream << operator
std::ostream& operator << (std::ostream& stream, const Vector3& vector)
{
	stream << "( ";

	for (unsigned int i = 0; i < 3; i++)
	{
		stream << vector.v[i] << " ";
	}

	stream << ")" << std::endl;

	return stream;
}

// returns a pointer
Vector3::operator float* ()
{
	return &x;
}

// returns v index
float& Vector3::operator [] (const int& index)
{
	return v[index];
}

// returns true if vectors are equal
bool Vector3::operator == (const Vector3& rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

// sets vector with a vector
void Vector3::operator = (const Vector3& rhs)
{
	for (unsigned int i = 0; i < 3; i++)
	{
		v[i] = rhs.v[i];
	}
}

// + operator with a vector
Vector3 Vector3::operator + (const Vector3& rhs)
{
	Vector3 temp;

	for (unsigned int i = 0; i < 3; i++)
	{
		temp[i] = v[i] + rhs.v[i];
	}

	return temp;
}

// += operator with a vector
void Vector3::operator += (const Vector3& rhs)
{
	*this = *this + rhs;
}

// - operator with a vector
Vector3 Vector3::operator - (const Vector3& rhs)
{
	Vector3 temp;

	for (unsigned int i = 0; i < 3; i++)
	{
		temp[i] = v[i] - rhs.v[i];
	}

	return temp;
}

// -= operator with a vector
void Vector3::operator -= (const Vector3& rhs)
{
	*this = *this - rhs;
}

// * operator with a float
Vector3 Vector3::operator * (const float& scalar)
{
	Vector3 temp;

	for (unsigned int i = 0; i < 3; i++)
	{
		temp[i] = v[i] * scalar;
	}

	return temp;
}

// *= operator with a float
void Vector3::operator *= (const float& scalar)
{
	*this = *this * scalar;
}

// float * operator
Vector3 operator * (const float& scalar, Vector3& vector)
{
	return vector * scalar;
}

// / operator with a float
Vector3 Vector3::operator / (const float& scalar)
{
	Vector3 temp(*this);
	temp /= scalar;
	return temp;
}

// /= operator with a float
void Vector3::operator /= (const float& scalar)
{
	for (unsigned int i = 0; i < 3; i++)
	{
		v[i] /= scalar;
	}
}
