#pragma once
#include <iostream>
#include "Vector4.h"

class Matrix4
{
public:
    union
    {
        struct
        {
            float m[4][4];
        };
        struct
        {
            float Xx;
            float Xy;
            float Xz;
            float Xw;
            float Yx;
            float Yy;
            float Yz;
            float Yw;
            float Zx;
            float Zy;
            float Zz;
            float Zw;
            float Wx;
            float Wy;
            float Wz;
            float Ww;
        };
    };

    // constructors and destructors
    Matrix4();
    Matrix4(const float& newXx, const float& newXy, const float& newXz, const float& newXw, const float& newYx, const float& newYy, const float& newYz, const float& newYw, const float& newZx, const float& newZy, const float& newZz, const float& newZw, const float& newWx, const float& newWy, const float& newWz, const float& newWw);
    Matrix4(Vector4& newxAxis, Vector4& newyAxis, Vector4& newzAxis, Vector4& newwAxis);
    Matrix4(const Matrix4& newMatrix);
    ~Matrix4();

    // functions
    static Matrix4 identity();
    float determinant();
    void setRotateX(const float& angle);
    void setRotateY(const float& angle);
    void setRotateZ(const float& angle);
    Matrix4 transposed();

    // overloads
    friend std::ostream& operator << (std::ostream& stream, const Matrix4& matrix);
    operator float *();
    Vector4 operator [] (const int& index);
    void operator = (const Matrix4& newMatrix);
    Matrix4 operator + (const Matrix4& rhs);
    void operator += (const Matrix4& rhs);
    Matrix4 operator - (const Matrix4& rhs);
    void operator -= (const Matrix4& rhs);
    Matrix4 operator * (const Matrix4& rhs);
    void operator *= (const Matrix4& rhs);
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