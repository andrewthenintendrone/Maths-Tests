#include "Vector2.h"
#include "Vector4.h"
#include "Vector3.h"

namespace AFMaths
{
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
    Vector3::Vector3(const Vector2& newVector)
    {
        *this = Vector3::Zero();
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // construct with a vector
    Vector3::Vector3(const Vector3& newVector)
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // construct with a vector
    Vector3::Vector3(const Vector4& newVector)
    {
        *this = Vector3::Zero();
        for (unsigned int i = 0; i < 3; i++)
        {
            v[i] = newVector.v[i];
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

    // returns the cross product of vectors
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
        return{ 1, 0, 0 };
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

    // returns a pointer to a float array
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
    void Vector3::operator = (const Vector2& newVector)
    {
        *this = Vector3::Zero();
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // sets vector with a vector
    void Vector3::operator = (const Vector3& newVector)
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // sets vector with a vector
    void Vector3::operator = (const Vector4& newVector)
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            v[i] = newVector.v[i];
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

    // * operator with a vector
    Vector3 Vector3::operator * (const Vector3& rhs)
    {
        return Vector3(x * rhs.x, y * rhs.y, z * rhs.z);
    }

    // *= operator with a vector
    void Vector3::operator *= (const Vector3& rhs)
    {
        *this = *this * rhs;
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

    /*##################################################
    swizzling
    ##################################################*/

    // returns Vector2(x, x)
    Vector2 Vector3::GetXX()
    {
        return Vector2(x, x);
    }

    // returns Vector2(x, y)
    Vector2 Vector3::GetXY()
    {
        return Vector2(x, y);
    }

    // returns Vector2(x, z)
    Vector2 Vector3::GetXZ()
    {
        return Vector2(x, z);
    }

    // returns Vector2(y, x)
    Vector2 Vector3::GetYX()
    {
        return Vector2(y, x);
    }

    // returns Vector2(y, y)
    Vector2 Vector3::GetYY()
    {
        return Vector2(y, y);
    }

    // returns Vector2(y, z)
    Vector2 Vector3::GetYZ()
    {
        return Vector2(y, z);
    }

    // returns Vector2(z, x)
    Vector2 Vector3::GetZX()
    {
        return Vector2(z, x);
    }

    // returns Vector2(z, y)
    Vector2 Vector3::GetZY()
    {
        return Vector2(z, y);
    }

    // returns Vector2(z, z)
    Vector2 Vector3::GetZZ()
    {
        return Vector2(z, z);
    }

    // returns Vector3(x, x, x)
    Vector3 Vector3::GetXXX()
    {
        return Vector3(x, x, x);
    }

    // returns Vector3(x, x, y)
    Vector3 Vector3::GetXXY()
    {
        return Vector3(x, x, y);
    }

    // returns Vector3(x, x, z)
    Vector3 Vector3::GetXXZ()
    {
        return Vector3(x, x, z);
    }

    // returns Vector3(x, y, x)
    Vector3 Vector3::GetXYX()
    {
        return Vector3(x, y, x);
    }

    // returns Vector3(x, y, y)
    Vector3 Vector3::GetXYY()
    {
        return Vector3(x, y, y);
    }

    // returns Vector3(x, z, x)
    Vector3 Vector3::GetXZX()
    {
        return Vector3(x, z, x);
    }

    // returns Vector3(x, z, y)
    Vector3 Vector3::GetXZY()
    {
        return Vector3(x, z, y);
    }

    // returns Vector3(x, z, z)
    Vector3 Vector3::GetXZZ()
    {
        return Vector3(x, z, z);
    }

    // returns Vector3(y, x, x)
    Vector3 Vector3::GetYXX()
    {
        return Vector3(y, x, x);
    }

    // returns Vector3(y, x, y)
    Vector3 Vector3::GetYXY()
    {
        return Vector3(y, x, y);
    }

    // returns Vector3(y, x, z)
    Vector3 Vector3::GetYXZ()
    {
        return Vector3(y, x, z);
    }

    // returns Vector3(y, y, x)
    Vector3 Vector3::GetYYX()
    {
        return Vector3(y, y, x);
    }

    // returns Vector3(y, y, y)
    Vector3 Vector3::GetYYY()
    {
        return Vector3(y, y, y);
    }

    // returns Vector3(y, y, z)
    Vector3 Vector3::GetYYZ()
    {
        return Vector3(y, y, z);
    }

    // returns Vector3(y, z, x)
    Vector3 Vector3::GetYZX()
    {
        return Vector3(y, z, x);
    }

    // returns Vector3(y, z, y)
    Vector3 Vector3::GetYZY()
    {
        return Vector3(y, z, y);
    }

    // returns Vector3(y, z, z)
    Vector3 Vector3::GetYZZ()
    {
        return Vector3(y, z, z);
    }

    // returns Vector3(z, x, x)
    Vector3 Vector3::GetZXX()
    {
        return Vector3(z, x, x);
    }

    // returns Vector3(z, x, y)
    Vector3 Vector3::GetZXY()
    {
        return Vector3(z, x, y);
    }

    // returns Vector3(z, x, z)
    Vector3 Vector3::GetZXZ()
    {
        return Vector3(z, x, z);
    }

    // returns Vector3(z, y, x)
    Vector3 Vector3::GetZYX()
    {
        return Vector3(z, y, x);
    }

    // returns Vector3(z, y, y)
    Vector3 Vector3::GetZYY()
    {
        return Vector3(z, y, y);
    }

    // returns Vector3(z, y, z)
    Vector3 Vector3::GetZYZ()
    {
        return Vector3(z, y, z);
    }

    // returns Vector3(z, z, x)
    Vector3 Vector3::GetZZX()
    {
        return Vector3(z, z, x);
    }

    // returns Vector3(z, z, y)
    Vector3 Vector3::GetZZY()
    {
        return Vector3(z, z, y);
    }

    // returns Vector3(z, z, z)
    Vector3 Vector3::GetZZZ()
    {
        return Vector3(z, z, z);
    }

    // returns Vector4(x, x, x, x)
    Vector4 Vector3::GetXXXX()
    {
        return Vector4(x, x, x, x);
    }

    // returns Vector4(x, x, x, y)
    Vector4 Vector3::GetXXXY()
    {
        return Vector4(x, x, x, y);
    }

    // returns Vector4(x, x, x, z)
    Vector4 Vector3::GetXXXZ()
    {
        return Vector4(x, x, x, z);
    }

    // returns Vector4(x, x, y, x)
    Vector4 Vector3::GetXXYX()
    {
        return Vector4(x, x, y, x);
    }

    // returns Vector4(x, x, y, y)
    Vector4 Vector3::GetXXYY()
    {
        return Vector4(x, x, y, y);
    }

    // returns Vector4(x, x, y, z)
    Vector4 Vector3::GetXXYZ()
    {
        return Vector4(x, x, y, z);
    }

    // returns Vector4(x, x, z, x)
    Vector4 Vector3::GetXXZX()
    {
        return Vector4(x, x, z, x);
    }

    // returns Vector4(x, x, z, y)
    Vector4 Vector3::GetXXZY()
    {
        return Vector4(x, x, z, y);
    }

    // returns Vector4(x, x, z, z)
    Vector4 Vector3::GetXXZZ()
    {
        return Vector4(x, x, z, z);
    }

    // returns Vector4(x, y, x, x)
    Vector4 Vector3::GetXYXX()
    {
        return Vector4(x, y, x, x);
    }

    // returns Vector4(x, y, x, y)
    Vector4 Vector3::GetXYXY()
    {
        return Vector4(x, y, x, y);
    }

    // returns Vector4(x, y, x, z)
    Vector4 Vector3::GetXYXZ()
    {
        return Vector4(x, y, x, z);
    }

    // returns Vector4(x, y, y, x)
    Vector4 Vector3::GetXYYX()
    {
        return Vector4(x, y, y, x);
    }

    // returns Vector4(x, y, y, y)
    Vector4 Vector3::GetXYYY()
    {
        return Vector4(x, y, y, y);
    }

    // returns Vector4(x, y, y, z)
    Vector4 Vector3::GetXYYZ()
    {
        return Vector4(x, y, y, z);
    }

    // returns Vector4(x, y, z, x)
    Vector4 Vector3::GetXYZX()
    {
        return Vector4(x, y, z, x);
    }

    // returns Vector4(x, y, z, y)
    Vector4 Vector3::GetXYZY()
    {
        return Vector4(x, y, z, y);
    }

    // returns Vector4(x, y, z, z)
    Vector4 Vector3::GetXYZZ()
    {
        return Vector4(x, y, z, z);
    }

    // returns Vector4(x, z, x, x)
    Vector4 Vector3::GetXZXX()
    {
        return Vector4(x, z, x, x);
    }

    // returns Vector4(x, z, x, y)
    Vector4 Vector3::GetXZXY()
    {
        return Vector4(x, z, x, y);
    }

    // returns Vector4(x, z, x, z)
    Vector4 Vector3::GetXZXZ()
    {
        return Vector4(x, z, x, z);
    }

    // returns Vector4(x, z, y, x)
    Vector4 Vector3::GetXZYX()
    {
        return Vector4(x, z, y, x);
    }

    // returns Vector4(x, z, y, y)
    Vector4 Vector3::GetXZYY()
    {
        return Vector4(x, z, y, y);
    }

    // returns Vector4(x, z, y, z)
    Vector4 Vector3::GetXZYZ()
    {
        return Vector4(x, z, y, z);
    }

    // returns Vector4(x, z, z, x)
    Vector4 Vector3::GetXZZX()
    {
        return Vector4(x, z, z, x);
    }

    // returns Vector4(x, z, z, y)
    Vector4 Vector3::GetXZZY()
    {
        return Vector4(x, z, z, y);
    }

    // returns Vector4(x, z, z, z)
    Vector4 Vector3::GetXZZZ()
    {
        return Vector4(x, z, z, z);
    }

    // returns Vector4(y, x, x, x)
    Vector4 Vector3::GetYXXX()
    {
        return Vector4(y, x, x, x);
    }

    // returns Vector4(y, x, x, y)
    Vector4 Vector3::GetYXXY()
    {
        return Vector4(y, x, x, y);
    }

    // returns Vector4(y, x, x, z)
    Vector4 Vector3::GetYXXZ()
    {
        return Vector4(y, x, x, z);
    }

    // returns Vector4(y, x, y, x)
    Vector4 Vector3::GetYXYX()
    {
        return Vector4(y, x, y, x);
    }

    // returns Vector4(y, x, y, y)
    Vector4 Vector3::GetYXYY()
    {
        return Vector4(y, x, y, y);
    }

    // returns Vector4(y, x, y, z)
    Vector4 Vector3::GetYXYZ()
    {
        return Vector4(y, x, y, z);
    }

    // returns Vector4(y, x, z, x)
    Vector4 Vector3::GetYXZX()
    {
        return Vector4(y, x, z, x);
    }

    // returns Vector4(y, x, z, y)
    Vector4 Vector3::GetYXZY()
    {
        return Vector4(y, x, z, y);
    }

    // returns Vector4(y, x, z, z)
    Vector4 Vector3::GetYXZZ()
    {
        return Vector4(y, x, z, z);
    }

    // returns Vector4(y, y, x, x)
    Vector4 Vector3::GetYYXX()
    {
        return Vector4(y, y, x, x);
    }

    // returns Vector4(y, y, x, y)
    Vector4 Vector3::GetYYXY()
    {
        return Vector4(y, y, x, y);
    }

    // returns Vector4(y, y, x, z)
    Vector4 Vector3::GetYYXZ()
    {
        return Vector4(y, y, x, z);
    }

    // returns Vector4(y, y, y, x)
    Vector4 Vector3::GetYYYX()
    {
        return Vector4(y, y, y, x);
    }

    // returns Vector4(y, y, y, y)
    Vector4 Vector3::GetYYYY()
    {
        return Vector4(y, y, y, y);
    }

    // returns Vector4(y, y, y, z)
    Vector4 Vector3::GetYYYZ()
    {
        return Vector4(y, y, y, z);
    }

    // returns Vector4(y, y, z, x)
    Vector4 Vector3::GetYYZX()
    {
        return Vector4(y, y, z, x);
    }

    // returns Vector4(y, y, z, y)
    Vector4 Vector3::GetYYZY()
    {
        return Vector4(y, y, z, y);
    }

    // returns Vector4(y, y, z, z)
    Vector4 Vector3::GetYYZZ()
    {
        return Vector4(y, y, z, z);
    }

    // returns Vector4(y, z, x, x)
    Vector4 Vector3::GetYZXX()
    {
        return Vector4(y, z, x, x);
    }

    // returns Vector4(y, z, x, y)
    Vector4 Vector3::GetYZXY()
    {
        return Vector4(y, z, x, y);
    }

    // returns Vector4(y, z, x, z)
    Vector4 Vector3::GetYZXZ()
    {
        return Vector4(y, z, x, z);
    }

    // returns Vector4(y, z, y, x)
    Vector4 Vector3::GetYZYX()
    {
        return Vector4(y, z, y, x);
    }

    // returns Vector4(y, z, y, y)
    Vector4 Vector3::GetYZYY()
    {
        return Vector4(y, z, y, y);
    }

    // returns Vector4(y, z, y, z)
    Vector4 Vector3::GetYZYZ()
    {
        return Vector4(y, z, y, z);
    }

    // returns Vector4(y, z, z, x)
    Vector4 Vector3::GetYZZX()
    {
        return Vector4(y, z, z, x);
    }

    // returns Vector4(y, z, z, y)
    Vector4 Vector3::GetYZZY()
    {
        return Vector4(y, z, z, y);
    }

    // returns Vector4(y, z, z, z)
    Vector4 Vector3::GetYZZZ()
    {
        return Vector4(y, z, z, z);
    }

    // returns Vector4(z, x, x, x)
    Vector4 Vector3::GetZXXX()
    {
        return Vector4(z, x, x, x);
    }

    // returns Vector4(z, x, x, y)
    Vector4 Vector3::GetZXXY()
    {
        return Vector4(z, x, x, y);
    }

    // returns Vector4(z, x, x, z)
    Vector4 Vector3::GetZXXZ()
    {
        return Vector4(z, x, x, z);
    }

    // returns Vector4(z, x, y, x)
    Vector4 Vector3::GetZXYX()
    {
        return Vector4(z, x, y, x);
    }

    // returns Vector4(z, x, y, y)
    Vector4 Vector3::GetZXYY()
    {
        return Vector4(z, x, y, y);
    }

    // returns Vector4(z, x, y, z)
    Vector4 Vector3::GetZXYZ()
    {
        return Vector4(z, x, y, z);
    }

    // returns Vector4(z, x, z, x)
    Vector4 Vector3::GetZXZX()
    {
        return Vector4(z, x, z, x);
    }

    // returns Vector4(z, x, z, y)
    Vector4 Vector3::GetZXZY()
    {
        return Vector4(z, x, z, y);
    }

    // returns Vector4(z, x, z, z)
    Vector4 Vector3::GetZXZZ()
    {
        return Vector4(z, x, z, z);
    }

    // returns Vector4(z, y, x, x)
    Vector4 Vector3::GetZYXX()
    {
        return Vector4(z, y, x, x);
    }

    // returns Vector4(z, y, x, y)
    Vector4 Vector3::GetZYXY()
    {
        return Vector4(z, y, x, y);
    }

    // returns Vector4(z, y, x, z)
    Vector4 Vector3::GetZYXZ()
    {
        return Vector4(z, y, x, z);
    }

    // returns Vector4(z, y, y, x)
    Vector4 Vector3::GetZYYX()
    {
        return Vector4(z, y, y, x);
    }

    // returns Vector4(z, y, y, y)
    Vector4 Vector3::GetZYYY()
    {
        return Vector4(z, y, y, y);
    }

    // returns Vector4(z, y, y, z)
    Vector4 Vector3::GetZYYZ()
    {
        return Vector4(z, y, y, z);
    }

    // returns Vector4(z, y, z, x)
    Vector4 Vector3::GetZYZX()
    {
        return Vector4(z, y, z, x);
    }

    // returns Vector4(z, y, z, y)
    Vector4 Vector3::GetZYZY()
    {
        return Vector4(z, y, z, y);
    }

    // returns Vector4(z, y, z, z)
    Vector4 Vector3::GetZYZZ()
    {
        return Vector4(z, y, z, z);
    }

    // returns Vector4(z, z, x, x)
    Vector4 Vector3::GetZZXX()
    {
        return Vector4(z, z, x, x);
    }

    // returns Vector4(z, z, x, y)
    Vector4 Vector3::GetZZXY()
    {
        return Vector4(z, z, x, y);
    }

    // returns Vector4(z, z, x, z)
    Vector4 Vector3::GetZZXZ()
    {
        return Vector4(z, z, x, z);
    }

    // returns Vector4(z, z, y, x)
    Vector4 Vector3::GetZZYX()
    {
        return Vector4(z, z, y, x);
    }

    // returns Vector4(z, z, y, y)
    Vector4 Vector3::GetZZYY()
    {
        return Vector4(z, z, y, y);
    }

    // returns Vector4(z, z, y, z)
    Vector4 Vector3::GetZZYZ()
    {
        return Vector4(z, z, y, z);
    }

    // returns Vector4(z, z, z, x)
    Vector4 Vector3::GetZZZX()
    {
        return Vector4(z, z, z, x);
    }

    // returns Vector4(z, z, z, y)
    Vector4 Vector3::GetZZZY()
    {
        return Vector4(z, z, z, y);
    }

    // returns Vector4(z, z, z, z)
    Vector4 Vector3::GetZZZZ()
    {
        return Vector4(z, z, z, z);
    }
}
