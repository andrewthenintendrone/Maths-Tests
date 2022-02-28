#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace AMMaths
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
    Vector4::Vector4(const Vector2& newVector)
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // construct with a vector
    Vector4::Vector4(const Vector3& newVector)
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // construct with a vector
    Vector4::Vector4(const Vector4& newVector)
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            v[i] = newVector.v[i];
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

    // returns the cross product of vectors
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

    // returns a pointer to a float array
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
    void Vector4::operator = (const Vector2& newVector)
    {
        *this = Vector4::Zero();
        for (unsigned int i = 0; i < 2; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // sets vector with a vector
    void Vector4::operator = (const Vector3& newVector)
    {
        *this = Vector4::Zero();
        for (unsigned int i = 0; i < 3; i++)
        {
            v[i] = newVector.v[i];
        }
    }

    // sets vector with a vector
    void Vector4::operator = (const Vector4& newVector)
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            v[i] = newVector.v[i];
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

    /*##################################################
    swizzling
    ##################################################*/

    // returns Vector2(x, x)
    Vector2 Vector4::GetXX()
    {
        return Vector2(x, x);
    }

    // returns Vector2(x, y)
    Vector2 Vector4::GetXY()
    {
        return Vector2(x, y);
    }

    // returns Vector2(x, z)
    Vector2 Vector4::GetXZ()
    {
        return Vector2(x, z);
    }

    // returns Vector2(x, w)
    Vector2 Vector4::GetXW()
    {
        return Vector2(x, w);
    }

    // returns Vector2(y, x)
    Vector2 Vector4::GetYX()
    {
        return Vector2(y, x);
    }

    // returns Vector2(y, y)
    Vector2 Vector4::GetYY()
    {
        return Vector2(y, y);
    }

    // returns Vector2(y, z)
    Vector2 Vector4::GetYZ()
    {
        return Vector2(y, z);
    }

    // returns Vector2(y, w)
    Vector2 Vector4::GetYW()
    {
        return Vector2(y, w);
    }

    // returns Vector2(z, x)
    Vector2 Vector4::GetZX()
    {
        return Vector2(z, x);
    }

    // returns Vector2(z, y)
    Vector2 Vector4::GetZY()
    {
        return Vector2(z, y);
    }

    // returns Vector2(z, z)
    Vector2 Vector4::GetZZ()
    {
        return Vector2(z, z);
    }

    // returns Vector2(z, w)
    Vector2 Vector4::GetZW()
    {
        return Vector2(z, w);
    }

    // returns Vector2(w, x)
    Vector2 Vector4::GetWX()
    {
        return Vector2(w, x);
    }

    // returns Vector2(w, y)
    Vector2 Vector4::GetWY()
    {
        return Vector2(w, y);
    }

    // returns Vector2(w, z)
    Vector2 Vector4::GetWZ()
    {
        return Vector2(w, z);
    }

    // returns Vector2(w, w)
    Vector2 Vector4::GetWW()
    {
        return Vector2(w, w);
    }

    // returns Vector3(x, x, x)
    Vector3 Vector4::GetXXX()
    {
        return Vector3(x, x, x);
    }

    // returns Vector3(x, x, y)
    Vector3 Vector4::GetXXY()
    {
        return Vector3(x, x, y);
    }

    // returns Vector3(x, x, z)
    Vector3 Vector4::GetXXZ()
    {
        return Vector3(x, x, z);
    }

    // returns Vector3(x, x, w)
    Vector3 Vector4::GetXXW()
    {
        return Vector3(x, x, w);
    }

    // returns Vector3(x, y, x)
    Vector3 Vector4::GetXYX()
    {
        return Vector3(x, y, x);
    }

    // returns Vector3(x, y, y)
    Vector3 Vector4::GetXYY()
    {
        return Vector3(x, y, y);
    }

    // returns Vector3(x, y, z)
    Vector3 Vector4::GetXYZ()
    {
        return Vector3(x, y, z);
    }

    // returns Vector3(x, y, w)
    Vector3 Vector4::GetXYW()
    {
        return Vector3(x, y, w);
    }

    // returns Vector3(x, z, x)
    Vector3 Vector4::GetXZX()
    {
        return Vector3(x, z, x);
    }

    // returns Vector3(x, z, y)
    Vector3 Vector4::GetXZY()
    {
        return Vector3(x, z, y);
    }

    // returns Vector3(x, z, z)
    Vector3 Vector4::GetXZZ()
    {
        return Vector3(x, z, z);
    }

    // returns Vector3(x, z, w)
    Vector3 Vector4::GetXZW()
    {
        return Vector3(x, z, w);
    }

    // returns Vector3(x, w, x)
    Vector3 Vector4::GetXWX()
    {
        return Vector3(x, w, x);
    }

    // returns Vector3(x, w, y)
    Vector3 Vector4::GetXWY()
    {
        return Vector3(x, w, y);
    }

    // returns Vector3(x, w, z)
    Vector3 Vector4::GetXWZ()
    {
        return Vector3(x, w, z);
    }

    // returns Vector3(x, w, w)
    Vector3 Vector4::GetXWW()
    {
        return Vector3(x, w, w);
    }

    // returns Vector3(y, x, x)
    Vector3 Vector4::GetYXX()
    {
        return Vector3(y, x, x);
    }

    // returns Vector3(y, x, y)
    Vector3 Vector4::GetYXY()
    {
        return Vector3(y, x, y);
    }

    // returns Vector3(y, x, z)
    Vector3 Vector4::GetYXZ()
    {
        return Vector3(y, x, z);
    }

    // returns Vector3(y, x, w)
    Vector3 Vector4::GetYXW()
    {
        return Vector3(y, x, w);
    }

    // returns Vector3(y, y, x)
    Vector3 Vector4::GetYYX()
    {
        return Vector3(y, y, x);
    }

    // returns Vector3(y, y, y)
    Vector3 Vector4::GetYYY()
    {
        return Vector3(y, y, y);
    }

    // returns Vector3(y, y, z)
    Vector3 Vector4::GetYYZ()
    {
        return Vector3(y, y, z);
    }

    // returns Vector3(y, y, w)
    Vector3 Vector4::GetYYW()
    {
        return Vector3(y, y, w);
    }

    // returns Vector3(y, z, x)
    Vector3 Vector4::GetYZX()
    {
        return Vector3(y, z, x);
    }

    // returns Vector3(y, z, y)
    Vector3 Vector4::GetYZY()
    {
        return Vector3(y, z, y);
    }

    // returns Vector3(y, z, z)
    Vector3 Vector4::GetYZZ()
    {
        return Vector3(y, z, z);
    }

    // returns Vector3(y, z, w)
    Vector3 Vector4::GetYZW()
    {
        return Vector3(y, z, w);
    }

    // returns Vector3(y, w, x)
    Vector3 Vector4::GetYWX()
    {
        return Vector3(y, w, x);
    }

    // returns Vector3(y, w, y)
    Vector3 Vector4::GetYWY()
    {
        return Vector3(y, w, y);
    }

    // returns Vector3(y, w, z)
    Vector3 Vector4::GetYWZ()
    {
        return Vector3(y, w, z);
    }

    // returns Vector3(y, w, w)
    Vector3 Vector4::GetYWW()
    {
        return Vector3(y, w, w);
    }

    // returns Vector3(z, x, x)
    Vector3 Vector4::GetZXX()
    {
        return Vector3(z, x, x);
    }

    // returns Vector3(z, x, y)
    Vector3 Vector4::GetZXY()
    {
        return Vector3(z, x, y);
    }

    // returns Vector3(z, x, z)
    Vector3 Vector4::GetZXZ()
    {
        return Vector3(z, x, z);
    }

    // returns Vector3(z, x, w)
    Vector3 Vector4::GetZXW()
    {
        return Vector3(z, x, w);
    }

    // returns Vector3(z, y, x)
    Vector3 Vector4::GetZYX()
    {
        return Vector3(z, y, x);
    }

    // returns Vector3(z, y, y)
    Vector3 Vector4::GetZYY()
    {
        return Vector3(z, y, y);
    }

    // returns Vector3(z, y, z)
    Vector3 Vector4::GetZYZ()
    {
        return Vector3(z, y, z);
    }

    // returns Vector3(z, y, w)
    Vector3 Vector4::GetZYW()
    {
        return Vector3(z, y, w);
    }

    // returns Vector3(z, z, x)
    Vector3 Vector4::GetZZX()
    {
        return Vector3(z, z, x);
    }

    // returns Vector3(z, z, y)
    Vector3 Vector4::GetZZY()
    {
        return Vector3(z, z, y);
    }

    // returns Vector3(z, z, z)
    Vector3 Vector4::GetZZZ()
    {
        return Vector3(z, z, z);
    }

    // returns Vector3(z, z, w)
    Vector3 Vector4::GetZZW()
    {
        return Vector3(z, z, w);
    }

    // returns Vector3(z, w, x)
    Vector3 Vector4::GetZWX()
    {
        return Vector3(z, w, x);
    }

    // returns Vector3(z, w, y)
    Vector3 Vector4::GetZWY()
    {
        return Vector3(z, w, y);
    }

    // returns Vector3(z, w, z)
    Vector3 Vector4::GetZWZ()
    {
        return Vector3(z, w, z);
    }

    // returns Vector3(z, w, w)
    Vector3 Vector4::GetZWW()
    {
        return Vector3(z, w, w);
    }

    // returns Vector3(w, x, x)
    Vector3 Vector4::GetWXX()
    {
        return Vector3(w, x, x);
    }

    // returns Vector3(w, x, y)
    Vector3 Vector4::GetWXY()
    {
        return Vector3(w, x, y);
    }

    // returns Vector3(w, x, z)
    Vector3 Vector4::GetWXZ()
    {
        return Vector3(w, x, z);
    }

    // returns Vector3(w, x, w)
    Vector3 Vector4::GetWXW()
    {
        return Vector3(w, x, w);
    }

    // returns Vector3(w, y, x)
    Vector3 Vector4::GetWYX()
    {
        return Vector3(w, y, x);
    }

    // returns Vector3(w, y, y)
    Vector3 Vector4::GetWYY()
    {
        return Vector3(w, y, y);
    }

    // returns Vector3(w, y, z)
    Vector3 Vector4::GetWYZ()
    {
        return Vector3(w, y, z);
    }

    // returns Vector3(w, y, w)
    Vector3 Vector4::GetWYW()
    {
        return Vector3(w, y, w);
    }

    // returns Vector3(w, z, x)
    Vector3 Vector4::GetWZX()
    {
        return Vector3(w, z, x);
    }

    // returns Vector3(w, z, y)
    Vector3 Vector4::GetWZY()
    {
        return Vector3(w, z, y);
    }

    // returns Vector3(w, z, z)
    Vector3 Vector4::GetWZZ()
    {
        return Vector3(w, z, z);
    }

    // returns Vector3(w, z, w)
    Vector3 Vector4::GetWZW()
    {
        return Vector3(w, z, w);
    }

    // returns Vector3(w, w, x)
    Vector3 Vector4::GetWWX()
    {
        return Vector3(w, w, x);
    }

    // returns Vector3(w, w, y)
    Vector3 Vector4::GetWWY()
    {
        return Vector3(w, w, y);
    }

    // returns Vector3(w, w, z)
    Vector3 Vector4::GetWWZ()
    {
        return Vector3(w, w, z);
    }

    // returns Vector3(w, w, w)
    Vector3 Vector4::GetWWW()
    {
        return Vector3(w, w, w);
    }

    // returns Vector4(x, x, x, x)
    Vector4 Vector4::GetXXXX()
    {
        return Vector4(x, x, x, x);
    }

    // returns Vector4(x, x, x, y)
    Vector4 Vector4::GetXXXY()
    {
        return Vector4(x, x, x, y);
    }

    // returns Vector4(x, x, x, z)
    Vector4 Vector4::GetXXXZ()
    {
        return Vector4(x, x, x, z);
    }

    // returns Vector4(x, x, x, w)
    Vector4 Vector4::GetXXXW()
    {
        return Vector4(x, x, x, w);
    }

    // returns Vector4(x, x, y, x)
    Vector4 Vector4::GetXXYX()
    {
        return Vector4(x, x, y, x);
    }

    // returns Vector4(x, x, y, y)
    Vector4 Vector4::GetXXYY()
    {
        return Vector4(x, x, y, y);
    }

    // returns Vector4(x, x, y, z)
    Vector4 Vector4::GetXXYZ()
    {
        return Vector4(x, x, y, z);
    }

    // returns Vector4(x, x, y, w)
    Vector4 Vector4::GetXXYW()
    {
        return Vector4(x, x, y, w);
    }

    // returns Vector4(x, x, z, x)
    Vector4 Vector4::GetXXZX()
    {
        return Vector4(x, x, z, x);
    }

    // returns Vector4(x, x, z, y)
    Vector4 Vector4::GetXXZY()
    {
        return Vector4(x, x, z, y);
    }

    // returns Vector4(x, x, z, z)
    Vector4 Vector4::GetXXZZ()
    {
        return Vector4(x, x, z, z);
    }

    // returns Vector4(x, x, z, w)
    Vector4 Vector4::GetXXZW()
    {
        return Vector4(x, x, z, w);
    }

    // returns Vector4(x, x, w, x)
    Vector4 Vector4::GetXXWX()
    {
        return Vector4(x, x, w, x);
    }

    // returns Vector4(x, x, w, y)
    Vector4 Vector4::GetXXWY()
    {
        return Vector4(x, x, w, y);
    }

    // returns Vector4(x, x, w, z)
    Vector4 Vector4::GetXXWZ()
    {
        return Vector4(x, x, w, z);
    }

    // returns Vector4(x, x, w, w)
    Vector4 Vector4::GetXXWW()
    {
        return Vector4(x, x, w, w);
    }

    // returns Vector4(x, y, x, x)
    Vector4 Vector4::GetXYXX()
    {
        return Vector4(x, y, x, x);
    }

    // returns Vector4(x, y, x, y)
    Vector4 Vector4::GetXYXY()
    {
        return Vector4(x, y, x, y);
    }

    // returns Vector4(x, y, x, z)
    Vector4 Vector4::GetXYXZ()
    {
        return Vector4(x, y, x, z);
    }

    // returns Vector4(x, y, x, w)
    Vector4 Vector4::GetXYXW()
    {
        return Vector4(x, y, x, w);
    }

    // returns Vector4(x, y, y, x)
    Vector4 Vector4::GetXYYX()
    {
        return Vector4(x, y, y, x);
    }

    // returns Vector4(x, y, y, y)
    Vector4 Vector4::GetXYYY()
    {
        return Vector4(x, y, y, y);
    }

    // returns Vector4(x, y, y, z)
    Vector4 Vector4::GetXYYZ()
    {
        return Vector4(x, y, y, z);
    }

    // returns Vector4(x, y, y, w)
    Vector4 Vector4::GetXYYW()
    {
        return Vector4(x, y, y, w);
    }

    // returns Vector4(x, y, z, x)
    Vector4 Vector4::GetXYZX()
    {
        return Vector4(x, y, z, x);
    }

    // returns Vector4(x, y, z, y)
    Vector4 Vector4::GetXYZY()
    {
        return Vector4(x, y, z, y);
    }

    // returns Vector4(x, y, z, z)
    Vector4 Vector4::GetXYZZ()
    {
        return Vector4(x, y, z, z);
    }

    // returns Vector4(x, y, w, x)
    Vector4 Vector4::GetXYWX()
    {
        return Vector4(x, y, w, x);
    }

    // returns Vector4(x, y, w, y)
    Vector4 Vector4::GetXYWY()
    {
        return Vector4(x, y, w, y);
    }

    // returns Vector4(x, y, w, z)
    Vector4 Vector4::GetXYWZ()
    {
        return Vector4(x, y, w, z);
    }

    // returns Vector4(x, y, w, w)
    Vector4 Vector4::GetXYWW()
    {
        return Vector4(x, y, w, w);
    }

    // returns Vector4(x, z, x, x)
    Vector4 Vector4::GetXZXX()
    {
        return Vector4(x, z, x, x);
    }

    // returns Vector4(x, z, x, y)
    Vector4 Vector4::GetXZXY()
    {
        return Vector4(x, z, x, y);
    }

    // returns Vector4(x, z, x, z)
    Vector4 Vector4::GetXZXZ()
    {
        return Vector4(x, z, x, z);
    }

    // returns Vector4(x, z, x, w)
    Vector4 Vector4::GetXZXW()
    {
        return Vector4(x, z, x, w);
    }

    // returns Vector4(x, z, y, x)
    Vector4 Vector4::GetXZYX()
    {
        return Vector4(x, z, y, x);
    }

    // returns Vector4(x, z, y, y)
    Vector4 Vector4::GetXZYY()
    {
        return Vector4(x, z, y, y);
    }

    // returns Vector4(x, z, y, z)
    Vector4 Vector4::GetXZYZ()
    {
        return Vector4(x, z, y, z);
    }

    // returns Vector4(x, z, y, w)
    Vector4 Vector4::GetXZYW()
    {
        return Vector4(x, z, y, w);
    }

    // returns Vector4(x, z, z, x)
    Vector4 Vector4::GetXZZX()
    {
        return Vector4(x, z, z, x);
    }

    // returns Vector4(x, z, z, y)
    Vector4 Vector4::GetXZZY()
    {
        return Vector4(x, z, z, y);
    }

    // returns Vector4(x, z, z, z)
    Vector4 Vector4::GetXZZZ()
    {
        return Vector4(x, z, z, z);
    }

    // returns Vector4(x, z, z, w)
    Vector4 Vector4::GetXZZW()
    {
        return Vector4(x, z, z, w);
    }

    // returns Vector4(x, z, w, x)
    Vector4 Vector4::GetXZWX()
    {
        return Vector4(x, z, w, x);
    }

    // returns Vector4(x, z, w, y)
    Vector4 Vector4::GetXZWY()
    {
        return Vector4(x, z, w, y);
    }

    // returns Vector4(x, z, w, z)
    Vector4 Vector4::GetXZWZ()
    {
        return Vector4(x, z, w, z);
    }

    // returns Vector4(x, z, w, w)
    Vector4 Vector4::GetXZWW()
    {
        return Vector4(x, z, w, w);
    }

    // returns Vector4(x, w, x, x)
    Vector4 Vector4::GetXWXX()
    {
        return Vector4(x, w, x, x);
    }

    // returns Vector4(x, w, x, y)
    Vector4 Vector4::GetXWXY()
    {
        return Vector4(x, w, x, y);
    }

    // returns Vector4(x, w, x, z)
    Vector4 Vector4::GetXWXZ()
    {
        return Vector4(x, w, x, z);
    }

    // returns Vector4(x, w, x, w)
    Vector4 Vector4::GetXWXW()
    {
        return Vector4(x, w, x, w);
    }

    // returns Vector4(x, w, y, x)
    Vector4 Vector4::GetXWYX()
    {
        return Vector4(x, w, y, x);
    }

    // returns Vector4(x, w, y, y)
    Vector4 Vector4::GetXWYY()
    {
        return Vector4(x, w, y, y);
    }

    // returns Vector4(x, w, y, z)
    Vector4 Vector4::GetXWYZ()
    {
        return Vector4(x, w, y, z);
    }

    // returns Vector4(x, w, y, w)
    Vector4 Vector4::GetXWYW()
    {
        return Vector4(x, w, y, w);
    }

    // returns Vector4(x, w, z, x)
    Vector4 Vector4::GetXWZX()
    {
        return Vector4(x, w, z, x);
    }

    // returns Vector4(x, w, z, y)
    Vector4 Vector4::GetXWZY()
    {
        return Vector4(x, w, z, y);
    }

    // returns Vector4(x, w, z, z)
    Vector4 Vector4::GetXWZZ()
    {
        return Vector4(x, w, z, z);
    }

    // returns Vector4(x, w, z, w)
    Vector4 Vector4::GetXWZW()
    {
        return Vector4(x, w, z, w);
    }

    // returns Vector4(x, w, w, x)
    Vector4 Vector4::GetXWWX()
    {
        return Vector4(x, w, w, x);
    }

    // returns Vector4(x, w, w, y)
    Vector4 Vector4::GetXWWY()
    {
        return Vector4(x, w, w, y);
    }

    // returns Vector4(x, w, w, z)
    Vector4 Vector4::GetXWWZ()
    {
        return Vector4(x, w, w, z);
    }

    // returns Vector4(x, w, w, w)
    Vector4 Vector4::GetXWWW()
    {
        return Vector4(x, w, w, w);
    }

    // returns Vector4(y, x, x, x)
    Vector4 Vector4::GetYXXX()
    {
        return Vector4(y, x, x, x);
    }

    // returns Vector4(y, x, x, y)
    Vector4 Vector4::GetYXXY()
    {
        return Vector4(y, x, x, y);
    }

    // returns Vector4(y, x, x, z)
    Vector4 Vector4::GetYXXZ()
    {
        return Vector4(y, x, x, z);
    }

    // returns Vector4(y, x, x, w)
    Vector4 Vector4::GetYXXW()
    {
        return Vector4(y, x, x, w);
    }

    // returns Vector4(y, x, y, x)
    Vector4 Vector4::GetYXYX()
    {
        return Vector4(y, x, y, x);
    }

    // returns Vector4(y, x, y, y)
    Vector4 Vector4::GetYXYY()
    {
        return Vector4(y, x, y, y);
    }

    // returns Vector4(y, x, y, z)
    Vector4 Vector4::GetYXYZ()
    {
        return Vector4(y, x, y, z);
    }

    // returns Vector4(y, x, y, w)
    Vector4 Vector4::GetYXYW()
    {
        return Vector4(y, x, y, w);
    }

    // returns Vector4(y, x, z, x)
    Vector4 Vector4::GetYXZX()
    {
        return Vector4(y, x, z, x);
    }

    // returns Vector4(y, x, z, y)
    Vector4 Vector4::GetYXZY()
    {
        return Vector4(y, x, z, y);
    }

    // returns Vector4(y, x, z, z)
    Vector4 Vector4::GetYXZZ()
    {
        return Vector4(y, x, z, z);
    }

    // returns Vector4(y, x, z, w)
    Vector4 Vector4::GetYXZW()
    {
        return Vector4(y, x, z, w);
    }

    // returns Vector4(y, x, w, x)
    Vector4 Vector4::GetYXWX()
    {
        return Vector4(y, x, w, x);
    }

    // returns Vector4(y, x, w, y)
    Vector4 Vector4::GetYXWY()
    {
        return Vector4(y, x, w, y);
    }

    // returns Vector4(y, x, w, z)
    Vector4 Vector4::GetYXWZ()
    {
        return Vector4(y, x, w, z);
    }

    // returns Vector4(y, x, w, w)
    Vector4 Vector4::GetYXWW()
    {
        return Vector4(y, x, w, w);
    }

    // returns Vector4(y, y, x, x)
    Vector4 Vector4::GetYYXX()
    {
        return Vector4(y, y, x, x);
    }

    // returns Vector4(y, y, x, y)
    Vector4 Vector4::GetYYXY()
    {
        return Vector4(y, y, x, y);
    }

    // returns Vector4(y, y, x, z)
    Vector4 Vector4::GetYYXZ()
    {
        return Vector4(y, y, x, z);
    }

    // returns Vector4(y, y, x, w)
    Vector4 Vector4::GetYYXW()
    {
        return Vector4(y, y, x, w);
    }

    // returns Vector4(y, y, y, x)
    Vector4 Vector4::GetYYYX()
    {
        return Vector4(y, y, y, x);
    }

    // returns Vector4(y, y, y, y)
    Vector4 Vector4::GetYYYY()
    {
        return Vector4(y, y, y, y);
    }

    // returns Vector4(y, y, y, z)
    Vector4 Vector4::GetYYYZ()
    {
        return Vector4(y, y, y, z);
    }

    // returns Vector4(y, y, y, w)
    Vector4 Vector4::GetYYYW()
    {
        return Vector4(y, y, y, w);
    }

    // returns Vector4(y, y, z, x)
    Vector4 Vector4::GetYYZX()
    {
        return Vector4(y, y, z, x);
    }

    // returns Vector4(y, y, z, y)
    Vector4 Vector4::GetYYZY()
    {
        return Vector4(y, y, z, y);
    }

    // returns Vector4(y, y, z, z)
    Vector4 Vector4::GetYYZZ()
    {
        return Vector4(y, y, z, z);
    }

    // returns Vector4(y, y, z, w)
    Vector4 Vector4::GetYYZW()
    {
        return Vector4(y, y, z, w);
    }

    // returns Vector4(y, y, w, x)
    Vector4 Vector4::GetYYWX()
    {
        return Vector4(y, y, w, x);
    }

    // returns Vector4(y, y, w, y)
    Vector4 Vector4::GetYYWY()
    {
        return Vector4(y, y, w, y);
    }

    // returns Vector4(y, y, w, z)
    Vector4 Vector4::GetYYWZ()
    {
        return Vector4(y, y, w, z);
    }

    // returns Vector4(y, y, w, w)
    Vector4 Vector4::GetYYWW()
    {
        return Vector4(y, y, w, w);
    }

    // returns Vector4(y, z, x, x)
    Vector4 Vector4::GetYZXX()
    {
        return Vector4(y, z, x, x);
    }

    // returns Vector4(y, z, x, y)
    Vector4 Vector4::GetYZXY()
    {
        return Vector4(y, z, x, y);
    }

    // returns Vector4(y, z, x, z)
    Vector4 Vector4::GetYZXZ()
    {
        return Vector4(y, z, x, z);
    }

    // returns Vector4(y, z, x, w)
    Vector4 Vector4::GetYZXW()
    {
        return Vector4(y, z, x, w);
    }

    // returns Vector4(y, z, y, x)
    Vector4 Vector4::GetYZYX()
    {
        return Vector4(y, z, y, x);
    }

    // returns Vector4(y, z, y, y)
    Vector4 Vector4::GetYZYY()
    {
        return Vector4(y, z, y, y);
    }

    // returns Vector4(y, z, y, z)
    Vector4 Vector4::GetYZYZ()
    {
        return Vector4(y, z, y, z);
    }

    // returns Vector4(y, z, y, w)
    Vector4 Vector4::GetYZYW()
    {
        return Vector4(y, z, y, w);
    }

    // returns Vector4(y, z, z, x)
    Vector4 Vector4::GetYZZX()
    {
        return Vector4(y, z, z, x);
    }

    // returns Vector4(y, z, z, y)
    Vector4 Vector4::GetYZZY()
    {
        return Vector4(y, z, z, y);
    }

    // returns Vector4(y, z, z, z)
    Vector4 Vector4::GetYZZZ()
    {
        return Vector4(y, z, z, z);
    }

    // returns Vector4(y, z, z, w)
    Vector4 Vector4::GetYZZW()
    {
        return Vector4(y, z, z, w);
    }

    // returns Vector4(y, z, w, x)
    Vector4 Vector4::GetYZWX()
    {
        return Vector4(y, z, w, x);
    }

    // returns Vector4(y, z, w, y)
    Vector4 Vector4::GetYZWY()
    {
        return Vector4(y, z, w, y);
    }

    // returns Vector4(y, z, w, z)
    Vector4 Vector4::GetYZWZ()
    {
        return Vector4(y, z, w, z);
    }

    // returns Vector4(y, z, w, w)
    Vector4 Vector4::GetYZWW()
    {
        return Vector4(y, z, w, w);
    }

    // returns Vector4(y, w, x, x)
    Vector4 Vector4::GetYWXX()
    {
        return Vector4(y, w, x, x);
    }

    // returns Vector4(y, w, x, y)
    Vector4 Vector4::GetYWXY()
    {
        return Vector4(y, w, x, y);
    }

    // returns Vector4(y, w, x, z)
    Vector4 Vector4::GetYWXZ()
    {
        return Vector4(y, w, x, z);
    }

    // returns Vector4(y, w, x, w)
    Vector4 Vector4::GetYWXW()
    {
        return Vector4(y, w, x, w);
    }

    // returns Vector4(y, w, y, x)
    Vector4 Vector4::GetYWYX()
    {
        return Vector4(y, w, y, x);
    }

    // returns Vector4(y, w, y, y)
    Vector4 Vector4::GetYWYY()
    {
        return Vector4(y, w, y, y);
    }

    // returns Vector4(y, w, y, z)
    Vector4 Vector4::GetYWYZ()
    {
        return Vector4(y, w, y, z);
    }

    // returns Vector4(y, w, y, w)
    Vector4 Vector4::GetYWYW()
    {
        return Vector4(y, w, y, w);
    }

    // returns Vector4(y, w, z, x)
    Vector4 Vector4::GetYWZX()
    {
        return Vector4(y, w, z, x);
    }

    // returns Vector4(y, w, z, y)
    Vector4 Vector4::GetYWZY()
    {
        return Vector4(y, w, z, y);
    }

    // returns Vector4(y, w, z, z)
    Vector4 Vector4::GetYWZZ()
    {
        return Vector4(y, w, z, z);
    }

    // returns Vector4(y, w, z, w)
    Vector4 Vector4::GetYWZW()
    {
        return Vector4(y, w, z, w);
    }

    // returns Vector4(y, w, w, x)
    Vector4 Vector4::GetYWWX()
    {
        return Vector4(y, w, w, x);
    }

    // returns Vector4(y, w, w, y)
    Vector4 Vector4::GetYWWY()
    {
        return Vector4(y, w, w, y);
    }

    // returns Vector4(y, w, w, z)
    Vector4 Vector4::GetYWWZ()
    {
        return Vector4(y, w, w, z);
    }

    // returns Vector4(y, w, w, w)
    Vector4 Vector4::GetYWWW()
    {
        return Vector4(y, w, w, w);
    }

    // returns Vector4(z, x, x, x)
    Vector4 Vector4::GetZXXX()
    {
        return Vector4(z, x, x, x);
    }

    // returns Vector4(z, x, x, y)
    Vector4 Vector4::GetZXXY()
    {
        return Vector4(z, x, x, y);
    }

    // returns Vector4(z, x, x, z)
    Vector4 Vector4::GetZXXZ()
    {
        return Vector4(z, x, x, z);
    }

    // returns Vector4(z, x, x, w)
    Vector4 Vector4::GetZXXW()
    {
        return Vector4(z, x, x, w);
    }

    // returns Vector4(z, x, y, x)
    Vector4 Vector4::GetZXYX()
    {
        return Vector4(z, x, y, x);
    }

    // returns Vector4(z, x, y, y)
    Vector4 Vector4::GetZXYY()
    {
        return Vector4(z, x, y, y);
    }

    // returns Vector4(z, x, y, z)
    Vector4 Vector4::GetZXYZ()
    {
        return Vector4(z, x, y, z);
    }

    // returns Vector4(z, x, y, w)
    Vector4 Vector4::GetZXYW()
    {
        return Vector4(z, x, y, w);
    }

    // returns Vector4(z, x, z, x)
    Vector4 Vector4::GetZXZX()
    {
        return Vector4(z, x, z, x);
    }

    // returns Vector4(z, x, z, y)
    Vector4 Vector4::GetZXZY()
    {
        return Vector4(z, x, z, y);
    }

    // returns Vector4(z, x, z, z)
    Vector4 Vector4::GetZXZZ()
    {
        return Vector4(z, x, z, z);
    }

    // returns Vector4(z, x, z, w)
    Vector4 Vector4::GetZXZW()
    {
        return Vector4(z, x, z, w);
    }

    // returns Vector4(z, x, w, x)
    Vector4 Vector4::GetZXWX()
    {
        return Vector4(z, x, w, x);
    }

    // returns Vector4(z, x, w, y)
    Vector4 Vector4::GetZXWY()
    {
        return Vector4(z, x, w, y);
    }

    // returns Vector4(z, x, w, z)
    Vector4 Vector4::GetZXWZ()
    {
        return Vector4(z, x, w, z);
    }

    // returns Vector4(z, x, w, w)
    Vector4 Vector4::GetZXWW()
    {
        return Vector4(z, x, w, w);
    }

    // returns Vector4(z, y, x, x)
    Vector4 Vector4::GetZYXX()
    {
        return Vector4(z, y, x, x);
    }

    // returns Vector4(z, y, x, y)
    Vector4 Vector4::GetZYXY()
    {
        return Vector4(z, y, x, y);
    }

    // returns Vector4(z, y, x, z)
    Vector4 Vector4::GetZYXZ()
    {
        return Vector4(z, y, x, z);
    }

    // returns Vector4(z, y, x, w)
    Vector4 Vector4::GetZYXW()
    {
        return Vector4(z, y, x, w);
    }

    // returns Vector4(z, y, y, x)
    Vector4 Vector4::GetZYYX()
    {
        return Vector4(z, y, y, x);
    }

    // returns Vector4(z, y, y, y)
    Vector4 Vector4::GetZYYY()
    {
        return Vector4(z, y, y, y);
    }

    // returns Vector4(z, y, y, z)
    Vector4 Vector4::GetZYYZ()
    {
        return Vector4(z, y, y, z);
    }

    // returns Vector4(z, y, y, w)
    Vector4 Vector4::GetZYYW()
    {
        return Vector4(z, y, y, w);
    }

    // returns Vector4(z, y, z, x)
    Vector4 Vector4::GetZYZX()
    {
        return Vector4(z, y, z, x);
    }

    // returns Vector4(z, y, z, y)
    Vector4 Vector4::GetZYZY()
    {
        return Vector4(z, y, z, y);
    }

    // returns Vector4(z, y, z, z)
    Vector4 Vector4::GetZYZZ()
    {
        return Vector4(z, y, z, z);
    }

    // returns Vector4(z, y, z, w)
    Vector4 Vector4::GetZYZW()
    {
        return Vector4(z, y, z, w);
    }

    // returns Vector4(z, y, w, x)
    Vector4 Vector4::GetZYWX()
    {
        return Vector4(z, y, w, x);
    }

    // returns Vector4(z, y, w, y)
    Vector4 Vector4::GetZYWY()
    {
        return Vector4(z, y, w, y);
    }

    // returns Vector4(z, y, w, z)
    Vector4 Vector4::GetZYWZ()
    {
        return Vector4(z, y, w, z);
    }

    // returns Vector4(z, y, w, w)
    Vector4 Vector4::GetZYWW()
    {
        return Vector4(z, y, w, w);
    }

    // returns Vector4(z, z, x, x)
    Vector4 Vector4::GetZZXX()
    {
        return Vector4(z, z, x, x);
    }

    // returns Vector4(z, z, x, y)
    Vector4 Vector4::GetZZXY()
    {
        return Vector4(z, z, x, y);
    }

    // returns Vector4(z, z, x, z)
    Vector4 Vector4::GetZZXZ()
    {
        return Vector4(z, z, x, z);
    }

    // returns Vector4(z, z, x, w)
    Vector4 Vector4::GetZZXW()
    {
        return Vector4(z, z, x, w);
    }

    // returns Vector4(z, z, y, x)
    Vector4 Vector4::GetZZYX()
    {
        return Vector4(z, z, y, x);
    }

    // returns Vector4(z, z, y, y)
    Vector4 Vector4::GetZZYY()
    {
        return Vector4(z, z, y, y);
    }

    // returns Vector4(z, z, y, z)
    Vector4 Vector4::GetZZYZ()
    {
        return Vector4(z, z, y, z);
    }

    // returns Vector4(z, z, y, w)
    Vector4 Vector4::GetZZYW()
    {
        return Vector4(z, z, y, w);
    }

    // returns Vector4(z, z, z, x)
    Vector4 Vector4::GetZZZX()
    {
        return Vector4(z, z, z, x);
    }

    // returns Vector4(z, z, z, y)
    Vector4 Vector4::GetZZZY()
    {
        return Vector4(z, z, z, y);
    }

    // returns Vector4(z, z, z, z)
    Vector4 Vector4::GetZZZZ()
    {
        return Vector4(z, z, z, z);
    }

    // returns Vector4(z, z, z, w)
    Vector4 Vector4::GetZZZW()
    {
        return Vector4(z, z, z, w);
    }

    // returns Vector4(z, z, w, x)
    Vector4 Vector4::GetZZWX()
    {
        return Vector4(z, z, w, x);
    }

    // returns Vector4(z, z, w, y)
    Vector4 Vector4::GetZZWY()
    {
        return Vector4(z, z, w, y);
    }

    // returns Vector4(z, z, w, z)
    Vector4 Vector4::GetZZWZ()
    {
        return Vector4(z, z, w, z);
    }

    // returns Vector4(z, z, w, w)
    Vector4 Vector4::GetZZWW()
    {
        return Vector4(z, z, w, w);
    }

    // returns Vector4(z, w, x, x)
    Vector4 Vector4::GetZWXX()
    {
        return Vector4(z, w, x, x);
    }

    // returns Vector4(z, w, x, y)
    Vector4 Vector4::GetZWXY()
    {
        return Vector4(z, w, x, y);
    }

    // returns Vector4(z, w, x, z)
    Vector4 Vector4::GetZWXZ()
    {
        return Vector4(z, w, x, z);
    }

    // returns Vector4(z, w, x, w)
    Vector4 Vector4::GetZWXW()
    {
        return Vector4(z, w, x, w);
    }

    // returns Vector4(z, w, y, x)
    Vector4 Vector4::GetZWYX()
    {
        return Vector4(z, w, y, x);
    }

    // returns Vector4(z, w, y, y)
    Vector4 Vector4::GetZWYY()
    {
        return Vector4(z, w, y, y);
    }

    // returns Vector4(z, w, y, z)
    Vector4 Vector4::GetZWYZ()
    {
        return Vector4(z, w, y, z);
    }

    // returns Vector4(z, w, y, w)
    Vector4 Vector4::GetZWYW()
    {
        return Vector4(z, w, y, w);
    }

    // returns Vector4(z, w, z, x)
    Vector4 Vector4::GetZWZX()
    {
        return Vector4(z, w, z, x);
    }

    // returns Vector4(z, w, z, y)
    Vector4 Vector4::GetZWZY()
    {
        return Vector4(z, w, z, y);
    }

    // returns Vector4(z, w, z, z)
    Vector4 Vector4::GetZWZZ()
    {
        return Vector4(z, w, z, z);
    }

    // returns Vector4(z, w, z, w)
    Vector4 Vector4::GetZWZW()
    {
        return Vector4(z, w, z, w);
    }

    // returns Vector4(z, w, w, x)
    Vector4 Vector4::GetZWWX()
    {
        return Vector4(z, w, w, x);
    }

    // returns Vector4(z, w, w, y)
    Vector4 Vector4::GetZWWY()
    {
        return Vector4(z, w, w, y);
    }

    // returns Vector4(z, w, w, z)
    Vector4 Vector4::GetZWWZ()
    {
        return Vector4(z, w, w, z);
    }

    // returns Vector4(z, w, w, w)
    Vector4 Vector4::GetZWWW()
    {
        return Vector4(z, w, w, w);
    }

    // returns Vector4(w, x, x, x)
    Vector4 Vector4::GetWXXX()
    {
        return Vector4(w, x, x, x);
    }

    // returns Vector4(w, x, x, y)
    Vector4 Vector4::GetWXXY()
    {
        return Vector4(w, x, x, y);
    }

    // returns Vector4(w, x, x, z)
    Vector4 Vector4::GetWXXZ()
    {
        return Vector4(w, x, x, z);
    }

    // returns Vector4(w, x, x, w)
    Vector4 Vector4::GetWXXW()
    {
        return Vector4(w, x, x, w);
    }

    // returns Vector4(w, x, y, x)
    Vector4 Vector4::GetWXYX()
    {
        return Vector4(w, x, y, x);
    }

    // returns Vector4(w, x, y, y)
    Vector4 Vector4::GetWXYY()
    {
        return Vector4(w, x, y, y);
    }

    // returns Vector4(w, x, y, z)
    Vector4 Vector4::GetWXYZ()
    {
        return Vector4(w, x, y, z);
    }

    // returns Vector4(w, x, y, w)
    Vector4 Vector4::GetWXYW()
    {
        return Vector4(w, x, y, w);
    }

    // returns Vector4(w, x, z, x)
    Vector4 Vector4::GetWXZX()
    {
        return Vector4(w, x, z, x);
    }

    // returns Vector4(w, x, z, y)
    Vector4 Vector4::GetWXZY()
    {
        return Vector4(w, x, z, y);
    }

    // returns Vector4(w, x, z, z)
    Vector4 Vector4::GetWXZZ()
    {
        return Vector4(w, x, z, z);
    }

    // returns Vector4(w, x, z, w)
    Vector4 Vector4::GetWXZW()
    {
        return Vector4(w, x, z, w);
    }

    // returns Vector4(w, x, w, x)
    Vector4 Vector4::GetWXWX()
    {
        return Vector4(w, x, w, x);
    }

    // returns Vector4(w, x, w, y)
    Vector4 Vector4::GetWXWY()
    {
        return Vector4(w, x, w, y);
    }

    // returns Vector4(w, x, w, z)
    Vector4 Vector4::GetWXWZ()
    {
        return Vector4(w, x, w, z);
    }

    // returns Vector4(w, x, w, w)
    Vector4 Vector4::GetWXWW()
    {
        return Vector4(w, x, w, w);
    }

    // returns Vector4(w, y, x, x)
    Vector4 Vector4::GetWYXX()
    {
        return Vector4(w, y, x, x);
    }

    // returns Vector4(w, y, x, y)
    Vector4 Vector4::GetWYXY()
    {
        return Vector4(w, y, x, y);
    }

    // returns Vector4(w, y, x, z)
    Vector4 Vector4::GetWYXZ()
    {
        return Vector4(w, y, x, z);
    }

    // returns Vector4(w, y, x, w)
    Vector4 Vector4::GetWYXW()
    {
        return Vector4(w, y, x, w);
    }

    // returns Vector4(w, y, y, x)
    Vector4 Vector4::GetWYYX()
    {
        return Vector4(w, y, y, x);
    }

    // returns Vector4(w, y, y, y)
    Vector4 Vector4::GetWYYY()
    {
        return Vector4(w, y, y, y);
    }

    // returns Vector4(w, y, y, z)
    Vector4 Vector4::GetWYYZ()
    {
        return Vector4(w, y, y, z);
    }

    // returns Vector4(w, y, y, w)
    Vector4 Vector4::GetWYYW()
    {
        return Vector4(w, y, y, w);
    }

    // returns Vector4(w, y, z, x)
    Vector4 Vector4::GetWYZX()
    {
        return Vector4(w, y, z, x);
    }

    // returns Vector4(w, y, z, y)
    Vector4 Vector4::GetWYZY()
    {
        return Vector4(w, y, z, y);
    }

    // returns Vector4(w, y, z, z)
    Vector4 Vector4::GetWYZZ()
    {
        return Vector4(w, y, z, z);
    }

    // returns Vector4(w, y, z, w)
    Vector4 Vector4::GetWYZW()
    {
        return Vector4(w, y, z, w);
    }

    // returns Vector4(w, y, w, x)
    Vector4 Vector4::GetWYWX()
    {
        return Vector4(w, y, w, x);
    }

    // returns Vector4(w, y, w, y)
    Vector4 Vector4::GetWYWY()
    {
        return Vector4(w, y, w, y);
    }

    // returns Vector4(w, y, w, z)
    Vector4 Vector4::GetWYWZ()
    {
        return Vector4(w, y, w, z);
    }

    // returns Vector4(w, y, w, w)
    Vector4 Vector4::GetWYWW()
    {
        return Vector4(w, y, w, w);
    }

    // returns Vector4(w, z, x, x)
    Vector4 Vector4::GetWZXX()
    {
        return Vector4(w, z, x, x);
    }

    // returns Vector4(w, z, x, y)
    Vector4 Vector4::GetWZXY()
    {
        return Vector4(w, z, x, y);
    }

    // returns Vector4(w, z, x, z)
    Vector4 Vector4::GetWZXZ()
    {
        return Vector4(w, z, x, z);
    }

    // returns Vector4(w, z, x, w)
    Vector4 Vector4::GetWZXW()
    {
        return Vector4(w, z, x, w);
    }

    // returns Vector4(w, z, y, x)
    Vector4 Vector4::GetWZYX()
    {
        return Vector4(w, z, y, x);
    }

    // returns Vector4(w, z, y, y)
    Vector4 Vector4::GetWZYY()
    {
        return Vector4(w, z, y, y);
    }

    // returns Vector4(w, z, y, z)
    Vector4 Vector4::GetWZYZ()
    {
        return Vector4(w, z, y, z);
    }

    // returns Vector4(w, z, y, w)
    Vector4 Vector4::GetWZYW()
    {
        return Vector4(w, z, y, w);
    }

    // returns Vector4(w, z, z, x)
    Vector4 Vector4::GetWZZX()
    {
        return Vector4(w, z, z, x);
    }

    // returns Vector4(w, z, z, y)
    Vector4 Vector4::GetWZZY()
    {
        return Vector4(w, z, z, y);
    }

    // returns Vector4(w, z, z, z)
    Vector4 Vector4::GetWZZZ()
    {
        return Vector4(w, z, z, z);
    }

    // returns Vector4(w, z, z, w)
    Vector4 Vector4::GetWZZW()
    {
        return Vector4(w, z, z, w);
    }

    // returns Vector4(w, z, w, x)
    Vector4 Vector4::GetWZWX()
    {
        return Vector4(w, z, w, x);
    }

    // returns Vector4(w, z, w, y)
    Vector4 Vector4::GetWZWY()
    {
        return Vector4(w, z, w, y);
    }

    // returns Vector4(w, z, w, z)
    Vector4 Vector4::GetWZWZ()
    {
        return Vector4(w, z, w, z);
    }

    // returns Vector4(w, z, w, w)
    Vector4 Vector4::GetWZWW()
    {
        return Vector4(w, z, w, w);
    }

    // returns Vector4(w, w, x, x)
    Vector4 Vector4::GetWWXX()
    {
        return Vector4(w, w, x, x);
    }

    // returns Vector4(w, w, x, y)
    Vector4 Vector4::GetWWXY()
    {
        return Vector4(w, w, x, y);
    }

    // returns Vector4(w, w, x, z)
    Vector4 Vector4::GetWWXZ()
    {
        return Vector4(w, w, x, z);
    }

    // returns Vector4(w, w, x, w)
    Vector4 Vector4::GetWWXW()
    {
        return Vector4(w, w, x, w);
    }

    // returns Vector4(w, w, y, x)
    Vector4 Vector4::GetWWYX()
    {
        return Vector4(w, w, y, x);
    }

    // returns Vector4(w, w, y, y)
    Vector4 Vector4::GetWWYY()
    {
        return Vector4(w, w, y, y);
    }

    // returns Vector4(w, w, y, z)
    Vector4 Vector4::GetWWYZ()
    {
        return Vector4(w, w, y, z);
    }

    // returns Vector4(w, w, y, w)
    Vector4 Vector4::GetWWYW()
    {
        return Vector4(w, w, y, w);
    }

    // returns Vector4(w, w, z, x)
    Vector4 Vector4::GetWWZX()
    {
        return Vector4(w, w, z, x);
    }

    // returns Vector4(w, w, z, y)
    Vector4 Vector4::GetWWZY()
    {
        return Vector4(w, w, z, y);
    }

    // returns Vector4(w, w, z, z)
    Vector4 Vector4::GetWWZZ()
    {
        return Vector4(w, w, z, z);
    }

    // returns Vector4(w, w, z, w)
    Vector4 Vector4::GetWWZW()
    {
        return Vector4(w, w, z, w);
    }

    // returns Vector4(w, w, w, x)
    Vector4 Vector4::GetWWWX()
    {
        return Vector4(w, w, w, x);
    }

    // returns Vector4(w, w, w, y)
    Vector4 Vector4::GetWWWY()
    {
        return Vector4(w, w, w, y);
    }

    // returns Vector4(w, w, w, z)
    Vector4 Vector4::GetWWWZ()
    {
        return Vector4(w, w, w, z);
    }

    // returns Vector4(w, w, w, w)
    Vector4 Vector4::GetWWWW()
    {
        return Vector4(w, w, w, w);
    }
}
