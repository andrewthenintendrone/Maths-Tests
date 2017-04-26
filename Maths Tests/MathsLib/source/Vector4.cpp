#include "Vector4.h"

namespace AFMaths
{
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

    // construct with a vector
    Vector4::Vector4(const Vector3& vector)
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            v[i] = vector.v[i];
        }
        w = 0;
    }

    // construct with a vector
    Vector4::Vector4(const Vector2& vector)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = vector.v[i];
        }
        z = 0;
        w = 0;
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

    Vector4 Vector4::cross(Vector4& rhs)
    {
        Vector4 temp;

        temp.x = y * rhs.z - z * rhs.y;
        temp.y = z * rhs.x - x * rhs.z;
        temp.z = x * rhs.y - y * rhs.x;
        temp.w = 0;

        return temp;
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

    // returns a glm vec of the vector
    glm::vec4 Vector4::toGLM()
    {
        return glm::vec4(x, y, z, w);
    }

    // returns a glm vec of the vector
    glm::vec3 Vector4::toGLM3()
    {
        return glm::vec3(x, y, z);
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
        return{ 1, 0, 0, 0 };
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

    // sets vector with a vector
    void Vector4::operator = (const Vector3& rhs)
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            v[i] = rhs.v[i];
        }
        w = 0;
    }

    // sets vector with a vector
    void Vector4::operator = (const Vector2& rhs)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = rhs.v[i];
        }
        z = 0;
        w = 0;
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

    // * operator with a vector
    Vector4 Vector4::operator * (const Vector4& rhs)
    {
        return Vector4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
    }

    // *= operator with a vector
    void Vector4::operator *= (const Vector4& rhs)
    {
        *this = *this * rhs;
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

}
