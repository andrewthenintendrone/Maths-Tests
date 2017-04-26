#include "Vector2.h"

namespace AFMaths
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
    Vector2::Vector2(const Vector2& vector)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = vector.v[i];
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

    // returns a pointer
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
    void Vector2::operator = (const Vector2& rhs)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = rhs.v[i];
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

}
