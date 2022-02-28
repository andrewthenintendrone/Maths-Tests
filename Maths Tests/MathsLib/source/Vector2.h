#pragma once
#include <math.h>
#include <iostream>
#include <glm\glm.hpp>
#include <glm\ext.hpp>

namespace AMMaths
{
    class Vector3;
    class Vector4;

    class Vector2
    {
    public:
        // variables
        union
        {
            struct
            {
                float v[2];
            };
            struct
            {
                float x;
                float y;
            };
        };

        // constructors and destructor
        Vector2();
        Vector2(const float& value);
        Vector2(float newX, float newY);
        Vector2(const Vector2& newVector);
        Vector2(const Vector3& newVector);
        Vector2(const Vector4& newVector);
        ~Vector2();

        // functions
        float dot(Vector2& rhs);
        Vector2 cross(Vector2& rhs);
        float magnitude();
        float squaremagnitude();
        void normalise();
        Vector2 normalized();
        glm::vec2 toGLM();

        // shortcuts
        static Vector2 Up();
        static Vector2 Down();
        static Vector2 Left();
        static Vector2 Right();
        static Vector2 Zero();

        // overloads
        friend std::ostream& operator << (std::ostream& stream, const Vector2& vector);
        operator float *();
        float& operator [] (const int& index);
        bool operator == (const Vector2& rhs);
        void operator = (const Vector2& newVector);
        void operator = (const Vector3& newVector);
        void operator = (const Vector4& newVector);
        Vector2 operator + (const Vector2& rhs);
        void operator += (const Vector2& rhs);
        Vector2 operator - (const Vector2& rhs);
        void operator -= (const Vector2& rhs);
        Vector2 operator * (const Vector2& rhs);
        void operator *= (const Vector2& rhs);
        Vector2 operator * (const float& scalar);
        void operator *= (const float& scalar);
        friend Vector2 operator * (const float& scalar, Vector2& vector);
        Vector2 operator / (const float& scalar);
        void operator /= (const float& scalar);

        // swizzling
        Vector2 GetXX();
        Vector2 GetYX();
        Vector2 GetYY();

        Vector3 GetXXX();
        Vector3 GetXXY();
        Vector3 GetXYX();
        Vector3 GetXYY();
        Vector3 GetYXX();
        Vector3 GetYXY();
        Vector3 GetYYX();
        Vector3 GetYYY();

        Vector4 GetXXXX();
        Vector4 GetXXXY();
        Vector4 GetXXYX();
        Vector4 GetXXYY();
        Vector4 GetXYXX();
        Vector4 GetXYXY();
        Vector4 GetXYYX();
        Vector4 GetXYYY();
        Vector4 GetYXXX();
        Vector4 GetYXXY();
        Vector4 GetYXYX();
        Vector4 GetYXYY();
        Vector4 GetYYXX();
        Vector4 GetYYXY();
        Vector4 GetYYYX();
        Vector4 GetYYYY();
    };
}
