#pragma once
#include <math.h>
#include <iostream>
#include "Vector2.h"
#include <glm\glm.hpp>
#include <glm\ext.hpp>

namespace AFMaths
{
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
        Vector3(const Vector3& vector);
        Vector3(const Vector2& vector);
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
        void operator = (const Vector3& rhs);
        void operator = (const Vector2& rhs);
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
    };
}
