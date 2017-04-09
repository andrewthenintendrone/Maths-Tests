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
            Vector4 vecs[4];
        };
        struct
        {
            float m[4][4];
        };
    };

    // constructors and destructors
    Matrix4();
    Matrix4(const float& new11, const float& new12, const float& new13, const float& new14, const float& new21, const float& new22, const float& new23, const float& new24, const float& new31, const float& new32, const float& new33, const float& new34, const float& new41, const float& new42, const float& new43, const float& new44);
    Matrix4(Vector4& newAxis1, Vector4& newAxis2, Vector4& newAxis3, Vector4& newAxis4);
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