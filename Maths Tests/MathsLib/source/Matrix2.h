#pragma once
#include <iostream>
#include "Vector2.h"

class Matrix2
{
public:
    union
    {
        struct
        {
            float m[2][2];
        };
        struct
        {
            float Xx;
            float Xy;
            float Yx;
            float Yy;
        };
    };

    // constructors and destructors
    Matrix2();
    Matrix2(const float& newXx, const float& newXy, const float& newYx, const float& newYy);
    Matrix2(Vector2& newxAxis, Vector2& newyAxis);
    Matrix2(const Matrix2& newMatrix);
    ~Matrix2();

    // functions
    static Matrix2 identity();
    float determinant();
    void setRotate(const float& angle);
    Matrix2 transposed();

    // overloads
    friend std::ostream& operator << (std::ostream& stream, const Matrix2& matrix);
    operator float *();
    Vector2 operator [] (const int& index);
    void operator = (const Matrix2& newMatrix);
    Matrix2 operator + (const Matrix2& rhs);
    void operator += (const Matrix2& rhs);
    Matrix2 operator - (const Matrix2& rhs);
    void operator -= (const Matrix2& rhs);
    Matrix2 operator * (const Matrix2& rhs);
    void operator *= (const Matrix2& rhs);
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