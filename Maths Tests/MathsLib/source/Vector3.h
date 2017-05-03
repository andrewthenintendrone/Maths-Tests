#pragma once
#include <math.h>
#include <iostream>
#include <glm\glm.hpp>
#include <glm\ext.hpp>

namespace AFMaths
{
    class Vector2;
    class Vector4;

    class Vector3
    {
    public:
        // variables
        union
        {
            struct
            {
                float v[3];
            };
            struct
            {
                float x;
                float y;
                float z;
            };
            struct
            {
                float r;
                float g;
                float b;
            };
        };

        // constructors and destructor
        Vector3();
        Vector3(const float& value);
        Vector3(float newX, float newY, float newZ);
        Vector3(const Vector2& newVector);
        Vector3(const Vector3& newVector);
        Vector3(const Vector4& newVector);
        ~Vector3();

        // functions
        float dot(Vector3& rhs);
        Vector3 cross(Vector3& rhs);
        float magnitude();
        float squaremagnitude();
        void normalise();
        Vector3 normalized();
        glm::vec3 toGLM();

        // shortcuts
        static Vector3 Up();
        static Vector3 Down();
        static Vector3 Left();
        static Vector3 Right();
        static Vector3 Forward();
        static Vector3 Back();
        static Vector3 Zero();

        // overloads
        friend std::ostream& operator << (std::ostream& stream, const Vector3& vector);
        operator float *();
        float& operator [] (const int& index);
        bool operator == (const Vector3& rhs);
        void operator = (const Vector2& newVector);
        void operator = (const Vector3& newVector);
        void operator = (const Vector4& newVector);
        Vector3 operator + (const Vector3& rhs);
        void operator += (const Vector3& rhs);
        Vector3 operator - (const Vector3& rhs);
        void operator -= (const Vector3& rhs);
        Vector3 operator * (const Vector3& rhs);
        void operator *= (const Vector3& rhs);
        Vector3 operator * (const float& scalar);
        void operator *= (const float& scalar);
        friend Vector3 operator * (const float& scalar, Vector3& vector);
        Vector3 operator / (const float& scalar);
        void operator /= (const float& scalar);

        // swizzling
        Vector2 GetXX();
        Vector2 GetXY();
        Vector2 GetXZ();
        Vector2 GetYX();
        Vector2 GetYY();
        Vector2 GetYZ();
        Vector2 GetZX();
        Vector2 GetZY();
        Vector2 GetZZ();

        Vector3 GetXXX();
        Vector3 GetXXY();
        Vector3 GetXXZ();
        Vector3 GetXYX();
        Vector3 GetXYY();
        Vector3 GetXZX();
        Vector3 GetXZY();
        Vector3 GetXZZ();
        Vector3 GetYXX();
        Vector3 GetYXY();
        Vector3 GetYXZ();
        Vector3 GetYYX();
        Vector3 GetYYY();
        Vector3 GetYYZ();
        Vector3 GetYZX();
        Vector3 GetYZY();
        Vector3 GetYZZ();
        Vector3 GetZXX();
        Vector3 GetZXY();
        Vector3 GetZXZ();
        Vector3 GetZYX();
        Vector3 GetZYY();
        Vector3 GetZYZ();
        Vector3 GetZZX();
        Vector3 GetZZY();
        Vector3 GetZZZ();

        Vector4 GetXXXX();
        Vector4 GetXXXY();
        Vector4 GetXXXZ();
        Vector4 GetXXYX();
        Vector4 GetXXYY();
        Vector4 GetXXYZ();
        Vector4 GetXXZX();
        Vector4 GetXXZY();
        Vector4 GetXXZZ();
        Vector4 GetXYXX();
        Vector4 GetXYXY();
        Vector4 GetXYXZ();
        Vector4 GetXYYX();
        Vector4 GetXYYY();
        Vector4 GetXYYZ();
        Vector4 GetXYZX();
        Vector4 GetXYZY();
        Vector4 GetXYZZ();
        Vector4 GetXZXX();
        Vector4 GetXZXY();
        Vector4 GetXZXZ();
        Vector4 GetXZYX();
        Vector4 GetXZYY();
        Vector4 GetXZYZ();
        Vector4 GetXZZX();
        Vector4 GetXZZY();
        Vector4 GetXZZZ();
        Vector4 GetYXXX();
        Vector4 GetYXXY();
        Vector4 GetYXXZ();
        Vector4 GetYXYX();
        Vector4 GetYXYY();
        Vector4 GetYXYZ();
        Vector4 GetYXZX();
        Vector4 GetYXZY();
        Vector4 GetYXZZ();
        Vector4 GetYYXX();
        Vector4 GetYYXY();
        Vector4 GetYYXZ();
        Vector4 GetYYYX();
        Vector4 GetYYYY();
        Vector4 GetYYYZ();
        Vector4 GetYYZX();
        Vector4 GetYYZY();
        Vector4 GetYYZZ();
        Vector4 GetYZXX();
        Vector4 GetYZXY();
        Vector4 GetYZXZ();
        Vector4 GetYZYX();
        Vector4 GetYZYY();
        Vector4 GetYZYZ();
        Vector4 GetYZZX();
        Vector4 GetYZZY();
        Vector4 GetYZZZ();
        Vector4 GetZXXX();
        Vector4 GetZXXY();
        Vector4 GetZXXZ();
        Vector4 GetZXYX();
        Vector4 GetZXYY();
        Vector4 GetZXYZ();
        Vector4 GetZXZX();
        Vector4 GetZXZY();
        Vector4 GetZXZZ();
        Vector4 GetZYXX();
        Vector4 GetZYXY();
        Vector4 GetZYXZ();
        Vector4 GetZYYX();
        Vector4 GetZYYY();
        Vector4 GetZYYZ();
        Vector4 GetZYZX();
        Vector4 GetZYZY();
        Vector4 GetZYZZ();
        Vector4 GetZZXX();
        Vector4 GetZZXY();
        Vector4 GetZZXZ();
        Vector4 GetZZYX();
        Vector4 GetZZYY();
        Vector4 GetZZYZ();
        Vector4 GetZZZX();
        Vector4 GetZZZY();
        Vector4 GetZZZZ();
    };
}
