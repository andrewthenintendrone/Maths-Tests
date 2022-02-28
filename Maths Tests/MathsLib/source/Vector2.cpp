#include "Vector3.h"
#include "Vector4.h"
#include "Vector2.h"

namespace AMMaths
{
    /*##################################################
    constructors and destructor
    ##################################################*/

    // default to 0s
    Vector2::Vector2()
    {
        x = 0;
        y = 0;
    }

    // construct with a float
    Vector2::Vector2(const float& value)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = value;
        }
    }

    // construct with floats
    Vector2::Vector2(float newX, float newY)
    {
        x = newX;
        y = newY;
    }

    // construct with a vector
    Vector2::Vector2(const Vector2& newVector)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // construct with a vector
    Vector2::Vector2(const Vector3& newVector)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // construct with a vector
    Vector2::Vector2(const Vector4& newVector)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // destructor
    Vector2::~Vector2()
    {

    }

    /*##################################################
    functions
    ##################################################*/

    // returns the dot product of vectors
    float Vector2::dot(Vector2& rhs)
    {
        float sum = 0;

        for (unsigned int i = 0; i < 2; i++)
        {
            sum += v[i] * rhs.v[i];
        }

        return sum;
    }

    // returns the cross product of vectors
    Vector2 Vector2::cross(Vector2& rhs)
    {
        Vector2 temp;

        temp.x = x * rhs.y - y * rhs.x;
        temp.y = y * rhs.x - x * rhs.y;

        return temp;
    }

    // returns the magnitude of the vector
    float Vector2::magnitude()
    {
        return sqrt(x * x + y * y);
    }

    // returns the squared magnitude of the vector
    float Vector2::squaremagnitude()
    {
        return(x * x + y * y);
    }

    // normalises the vector by dividing by magnitude
    void Vector2::normalise()
    {
        float mag = magnitude();

        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] /= mag;
        }
    }

    // returns the normalised vector
    Vector2 Vector2::normalized()
    {
        Vector2 temp(*this);
        temp.normalise();
        return temp;
    }

    // returns a glm vec of the vector
    glm::vec2 Vector2::toGLM()
    {
        return glm::vec2(x, y);
    }

    /*##################################################
    shortcuts
    ##################################################*/

    // returns a vector pointing up
    Vector2 Vector2::Up()
    {
        return{ 0, 1 };
    }

    // returns a vector pointing down
    Vector2 Vector2::Down()
    {
        return{ 0, -1 };
    }

    // returns a vector pointing left
    Vector2 Vector2::Left()
    {
        return{ -1, 0 };
    }

    // returns a vector pointing right
    Vector2 Vector2::Right()
    {
        return{ 1, 0 };
    }

    // returns a vector of 0s
    Vector2 Vector2::Zero()
    {
        return Vector2(0);
    }

    /*##################################################
    overloads
    ##################################################*/

    // stream << operator
    std::ostream& operator << (std::ostream& stream, const Vector2& vector)
    {
        stream << "( ";

        for (unsigned int i = 0; i < 2; i++)
        {
            stream << vector.v[i] << " ";
        }

        stream << ")" << std::endl;

        return stream;
    }

    // returns a pointer to a float array
    Vector2::operator float* ()
    {
        return &x;
    }

    // returns v index
    float& Vector2::operator [] (const int& index)
    {
        return v[index];
    }

    // returns true if vectors are equal
    bool Vector2::operator == (const Vector2& rhs)
    {
        return (x == rhs.x && y == rhs.y);
    }

    // sets vector with a vector
    void Vector2::operator = (const Vector2& newVector)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // sets vector with a vector
    void Vector2::operator = (const Vector3& newVector)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // sets vector with a vector
    void Vector2::operator = (const Vector4& newVector)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // + operator with a vector
    Vector2 Vector2::operator + (const Vector2& rhs)
    {
        Vector2 temp;

        for (unsigned int i = 0; i < 2; i++)
        {
            temp[i] = v[i] + rhs.v[i];
        }

        return temp;
    }

    // += operator with a vector
    void Vector2::operator += (const Vector2& rhs)
    {
        *this = *this + rhs;
    }

    // - operator with a vector
    Vector2 Vector2::operator - (const Vector2& rhs)
    {
        Vector2 temp;

        for (unsigned int i = 0; i < 2; i++)
        {
            temp[i] = v[i] - rhs.v[i];
        }

        return temp;
    }

    // -= operator with a vector
    void Vector2::operator -= (const Vector2& rhs)
    {
        *this = *this - rhs;
    }

    // * operator with a vector
    Vector2 Vector2::operator * (const Vector2& rhs)
    {
        return Vector2(x * rhs.x, y * rhs.y);
    }

    // *= operator with a vector
    void Vector2::operator *= (const Vector2& rhs)
    {
        *this = *this * rhs;
    }

    // * operator with a float
    Vector2 Vector2::operator * (const float& scalar)
    {
        Vector2 temp;

        for (unsigned int i = 0; i < 2; i++)
        {
            temp[i] = v[i] * scalar;
        }

        return temp;
    }

    // *= operator with a float
    void Vector2::operator *= (const float& scalar)
    {
        *this = *this * scalar;
    }

    // float * operator
    Vector2 operator * (const float& scalar, Vector2& vector)
    {
        return vector * scalar;
    }

    // / operator with a float
    Vector2 Vector2::operator / (const float& scalar)
    {
        Vector2 temp(*this);
        temp /= scalar;
        return temp;
    }

    // /= operator with a float
    void Vector2::operator /= (const float& scalar)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] /= scalar;
        }
    }

    /*##################################################
    swizzling
    ##################################################*/

    // returns Vector2(x, x)
    Vector2 Vector2::GetXX()
    {
        return Vector2(x, x);
    }

    // returns Vector2(y, x)
    Vector2 Vector2::GetYX()
    {
        return Vector2(y, x);
    }

    // returns Vector2(y, y)
    Vector2 Vector2::GetYY()
    {
        return Vector2(y, y);
    }

    // returns Vector3(x, x, x)
    Vector3 Vector2::GetXXX()
    {
        return Vector3(x, x, x);
    }

    // returns Vector3(x, x, y)
    Vector3 Vector2::GetXXY()
    {
        return Vector3(x, x, y);
    }

    // returns Vector3(x, y, x)
    Vector3 Vector2::GetXYX()
    {
        return Vector3(x, y, x);
    }

    // returns Vector3(x, y, y)
    Vector3 Vector2::GetXYY()
    {
        return Vector3(x, y, y);
    }

    // returns Vector3(y, x, x)
    Vector3 Vector2::GetYXX()
    {
        return Vector3(y, x, x);
    }

    // returns Vector3(y, x, y)
    Vector3 Vector2::GetYXY()
    {
        return Vector3(y, x, y);
    }

    // returns Vector3(y, y, x)
    Vector3 Vector2::GetYYX()
    {
        return Vector3(y, y, x);
    }

    // returns Vector3(y, y, y)
    Vector3 Vector2::GetYYY()
    {
        return Vector3(y, y, y);
    }

    // returns Vector4(x, x, x, x)
    Vector4 Vector2::GetXXXX()
    {
        return Vector4(x, x, x, x);
    }

    // returns Vector4(x, x, x, y)
    Vector4 Vector2::GetXXXY()
    {
        return Vector4(x, x, x, y);
    }

    // returns Vector4(x, x, y, x)
    Vector4 Vector2::GetXXYX()
    {
        return Vector4(x, x, y, x);
    }

    // returns Vector4(x, x, y, y)
    Vector4 Vector2::GetXXYY()
    {
        return Vector4(x, x, y, y);
    }

    // returns Vector4(x, y, x, x)
    Vector4 Vector2::GetXYXX()
    {
        return Vector4(x, y, x, x);
    }

    // returns Vector4(x, y, x, y)
    Vector4 Vector2::GetXYXY()
    {
        return Vector4(x, y, x, y);
    }

    // returns Vector4(x, y, y, x)
    Vector4 Vector2::GetXYYX()
    {
        return Vector4(x, y, y, x);
    }

    // returns Vector4(x, y, y, y)
    Vector4 Vector2::GetXYYY()
    {
        return Vector4(x, y, y, y);
    }

    // returns Vector4(y, x, x, x)
    Vector4 Vector2::GetYXXX()
    {
        return Vector4(y, x, x, x);
    }

    // returns Vector4(y, x, x, y)
    Vector4 Vector2::GetYXXY()
    {
        return Vector4(y, x, x, y);
    }

    // returns Vector4(y, x, y, x)
    Vector4 Vector2::GetYXYX()
    {
        return Vector4(y, x, y, x);
    }

    // returns Vector4(y, x, y, y)
    Vector4 Vector2::GetYXYY()
    {
        return Vector4(y, x, y, y);
    }

    // returns Vector4(y, y, x, x)
    Vector4 Vector2::GetYYXX()
    {
        return Vector4(y, y, x, x);
    }

    // returns Vector4(y, y, x, y)
    Vector4 Vector2::GetYYXY()
    {
        return Vector4(y, y, x, y);
    }

    // returns Vector4(y, y, y, x)
    Vector4 Vector2::GetYYYX()
    {
        return Vector4(y, y, y, x);
    }

    // returns Vector4(y, y, y, y)
    Vector4 Vector2::GetYYYY()
    {
        return Vector4(y, y, y, y);
    }
}
