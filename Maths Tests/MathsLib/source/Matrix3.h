#pragma once
#include <iostream>
#include "Vector3.h"

namespace AFMaths
{
    class Matrix3
    {
    public:
        union
        {
            struct
            {
                Vector3 vecs[3];
            };
            struct
            {
                float mm[3][3];
            };
            struct
            {
                float m[9];
            };
            struct
            {
                float x1;
                float x2;
                float x3;

                float y1;
                float y2;
                float y3;

                float z1;
                float z2;
                float z3;
            };
        };

        // constructors and destructors
        Matrix3();
        Matrix3(const float& newValue);
        Matrix3(const float& newx1, const float& newx2, const float& newx3, const float& newy1, const float& newy2, const float& newy3, const float& newz1, const float& newz2, const float& newz3);
        Matrix3(Vector3& newAxis1, Vector3& newAxis2, Vector3& newAxis3);
        Matrix3(const Matrix3& newMatrix);
        ~Matrix3();

        // functions
        float determinant();
        static Matrix3 identity();
        static Matrix3 zero();
        void setRotateX(const float& angle);
        void setRotateY(const float& angle);
        void setRotateZ(const float& angle);
        Matrix3 transposed();

        // overloads
        friend std::ostream& operator << (std::ostream& stream, const Matrix3& matrix);
        operator float *();
        Vector3& operator [] (const int& index);
        bool operator == (const Matrix3& rhs);
        void operator = (const Matrix3& newMatrix);
        Matrix3 operator + (const Matrix3& rhs);
        void operator += (const Matrix3& rhs);
        Matrix3 operator - (const Matrix3& rhs);
        void operator -= (const Matrix3& rhs);
        Matrix3 operator * (Matrix3& rhs);
        void operator *= (Matrix3& rhs);
        Vector3 operator * (Vector3& rhs);
        void operator *= (Vector3& rhs);
        Matrix3 operator + (const float& scalar);
        void operator += (const float& scalar);
        Matrix3 operator - (const float& scalar);
        void operator -= (const float& scalar);
        Matrix3 operator * (const float& scalar);
        void operator *= (const float& scalar);
        Matrix3 operator / (const float& scalar);
        void operator /= (const float& scalar);
    };
}
