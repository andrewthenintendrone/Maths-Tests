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
            Vector2 xAxis;
            Vector2 yAxis;
        };
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

    // overloads
    friend std::ostream& operator << (std::ostream& stream, const Matrix2& matrix);
    operator float *();
    void operator = (const Matrix2& newMatrix);
    Matrix2 operator + (const Matrix2& rhs);
    Matrix2 operator + (const float& scalar);
    Matrix2 operator - (const Matrix2& rhs);
    Matrix2 operator - (const float& scalar);
    Matrix2 operator * (const Matrix2& rhs);
    void operator *= (const Matrix2& rhs);
    Matrix2 operator * (const float& scalar);
    Matrix2 operator / (const float& scalar);
};