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
            float Yx;
            float Xy;
            float Yy;
        };
    };

    // constructors and destructors
    Matrix2();
    Matrix2(const float& newValue);
    Matrix2(const float& new11, const float& new12, const float& new21, const float& new22);
    Matrix2(Vector2& newAxis1, Vector2& newAxis2);
    Matrix2(const Matrix2& newMatrix);
    ~Matrix2();

    // functions
    float determinant();
    static Matrix2 identity();
    static Matrix2 zero();
    void setRotate(const float& angle);
    Matrix2 transposed();

    // overloads
    friend std::ostream& operator << (std::ostream& stream, const Matrix2& matrix);
    operator float *();
    Vector2 operator [] (const int& index);
    bool operator == (const Matrix2& rhs);
    void operator = (const Matrix2& newMatrix);
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