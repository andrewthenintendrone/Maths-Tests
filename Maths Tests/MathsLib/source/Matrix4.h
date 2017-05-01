#pragma once
#include <iostream>
#include "Vector4.h"

class Matrix2;
class Matrix3;

namespace AFMaths
{
    class Matrix4
    {
    public:
        union
        {
            struct
            {
                Vector4 vecs[4];
            };
            struct
            {
                float mm[4][4];
            };
            struct
            {
                float m[16];
            };
            struct
            {
                float x1;
                float x2;
                float x3;
                float x4;

                float y1;
                float y2;
                float y3;
                float y4;

                float z1;
                float z2;
                float z3;
                float z4;

                float w1;
                float w2;
                float w3;
                float w4;
            };
        };

        // constructors and destructors
        Matrix4();
        Matrix4(const float& newValue);
        Matrix4(const float& newx1, const float& newx2, const float& newx3, const float& newx4, const float& newy1, const float& newy2, const float& newy3, const float& newy4, const float& newz1, const float& newz2, const float& newz3, const float& neww1, const float& neww2, const float& neww3, const float& newz4, const float& neww4);
        Matrix4(Vector4& newAxis1, Vector4& newAxis2, Vector4& newAxis3, Vector4& newAxis4);
        Matrix4(const Matrix2& newMatrix);
        Matrix4(const Matrix3& newMatrix);
        Matrix4(const Matrix4& newMatrix);
        ~Matrix4();

        // functions
        float determinant();
        static Matrix4 identity();
        static Matrix4 zero();
        void setRotateX(const float& angle);
        void setRotateY(const float& angle);
        void setRotateZ(const float& angle);
        void transpose();
        Matrix4 transposed();

        // overloads
        friend std::ostream& operator << (std::ostream& stream, const Matrix4& matrix);
        operator float *();
        Vector4& operator [] (const int& index);
        bool operator == (const Matrix4& rhs);
        void operator = (const Matrix4& newMatrix);
        Matrix4 operator + (const Matrix4& rhs);
        void operator += (const Matrix4& rhs);
        Matrix4 operator - (const Matrix4& rhs);
        void operator -= (const Matrix4& rhs);
        Matrix4 operator * (Matrix4& rhs);
        void operator *= (Matrix4& rhs);
        Vector4 operator * (Vector4& rhs);
        void operator *= (Vector4& rhs);
        Matrix4 operator + (const float& scalar);
        void operator += (const float& scalar);
        Matrix4 operator - (const float& scalar);
        void operator -= (const float& scalar);
        Matrix4 operator * (const float& scalar);
        void operator *= (const float& scalar);
        Matrix4 operator / (const float& scalar);
        void operator /= (const float& scalar);
    };
}
