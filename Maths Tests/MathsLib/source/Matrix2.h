#pragma once
#include <iostream>
#include "Vector2.h"

namespace AFMaths
{
    class Matrix3;
    class Matrix4;

    class Matrix2
    {
    public:
        union
        {
            struct
            {
                Vector2 vecs[2];
            };
            struct
            {
                float mm[2][2];
            };
            struct
            {
                float m[4];
            };
            struct
            {
                float x1;
                float x2;

                float y1;
                float y2;
            };
        };

        // constructors and destructors
        Matrix2();
        Matrix2(const float& newValue);
        Matrix2(const float& newx1, const float& newx2, const float& newy1, const float& newy2);
        Matrix2(Vector2& newAxis1, Vector2& newAxis2);
        Matrix2(const Matrix2& newMatrix);
        Matrix2(const Matrix3& newMatrix);
        Matrix2(const Matrix4& newMatrix);
        ~Matrix2();

        // functions
        float determinant();
        static Matrix2 identity();
        static Matrix2 zero();
        void setRotate(const float& angle);
        void transpose();
        Matrix2 transposed();

        // overloads
        friend std::ostream& operator << (std::ostream& stream, const Matrix2& matrix);
        operator float *();
        Vector2& operator [] (const int& index);
        bool operator == (const Matrix2& rhs);
        void operator = (const Matrix2& newMatrix);
        void operator = (const Matrix3& newMatrix);
        void operator = (const Matrix4& newMatrix);
        Matrix2 operator + (const Matrix2& rhs);
        void operator += (const Matrix2& rhs);
        Matrix2 operator - (const Matrix2& rhs);
        void operator -= (const Matrix2& rhs);
        Matrix2 operator * (Matrix2& rhs);
        void operator *= (Matrix2& rhs);
        Vector2 operator * (Vector2& rhs);
        void operator *= (Vector2& rhs);
        Matrix2 operator + (const float& scalar);
        void operator += (const float& scalar);
        Matrix2 operator - (const float& scalar);
        void operator -= (const float& scalar);
        Matrix2 operator * (const float& scalar);
        void operator *= (const float& scalar);
        Matrix2 operator / (const float& scalar);
        void operator /= (const float& scalar);
    };
}
