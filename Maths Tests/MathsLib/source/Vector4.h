#pragma once
#include <math.h>
#include <iostream>
#include <glm\glm.hpp>
#include <glm\ext.hpp>

namespace AFMaths
{
    class Vector2;
    class Vector3;

    class Vector4
    {
    public:
        // variables
        union
        {
            struct
            {
                float v[4];
            };
            struct
            {
                float x;
                float y;
                float z;
                float w;
            };
            struct
            {
                float r;
                float g;
                float b;
                float a;
            };
        };

        // constructors and destructor
        Vector4();
        Vector4(const float& value);
        Vector4(float newX, float newY, float newZ, float newW);
        Vector4(const Vector2& newVector);
        Vector4(const Vector3& newVector);
        Vector4(const Vector4& newVector);
        ~Vector4();

        // functions
        float dot(Vector4& rhs);
        Vector4 cross(Vector4& rhs);
        float magnitude();
        float squaremagnitude();
        void normalise();
        Vector4 normalized();
        glm::vec4 toGLM();
        glm::vec3 toGLM3();

        // shortcuts
        static Vector4 Up();
        static Vector4 Down();
        static Vector4 Left();
        static Vector4 Right();
        static Vector4 Forward();
        static Vector4 Back();
        static Vector4 Zero();

        // overloads
        friend std::ostream& operator << (std::ostream& stream, const Vector4& vector);
        operator float *();
        float& operator [] (const int& index);
        bool operator == (const Vector4& rhs);
        void operator = (const Vector4& rhs);
        void operator = (const Vector3& rhs);
        void operator = (const Vector2& rhs);
        Vector4 operator + (const Vector4& rhs);
        void operator += (const Vector4& rhs);
        Vector4 operator - (const Vector4& rhs);
        void operator -= (const Vector4& rhs);
        Vector4 operator * (const Vector4& rhs);
        void operator *= (const Vector4& rhs);
        Vector4 operator * (const float& scalar);
        void operator *= (const float& scalar);
        friend Vector4 operator * (const float& scalar, Vector4& vector);
        Vector4 operator / (const float& scalar);
        void operator /= (const float& scalar);
    };
}
