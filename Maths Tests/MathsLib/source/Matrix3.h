#pragma once
#include <iostream>
#include "Vector3.h"

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
            float m[3][3];
        };
    };

    // constructors and destructors
    Matrix3();
    Matrix3(const float& new11, const float& new12, const float& new13, const float& new21, const float& new22, const float& new23, const float& new31, const float& new32, const float& new33);
    Matrix3(Vector3& newAxis1, Vector3& newAxis2, Vector3& newAxis3);
    Matrix3(const Matrix3& newMatrix);
    ~Matrix3();

    // functions
    static Matrix3 identity();
    float determinant();
    void setRotateX(const float& angle);
    void setRotateY(const float& angle);
    void setRotateZ(const float& angle);
    Matrix3 transposed();

    // overloads
    friend std::ostream& operator << (std::ostream& stream, const Matrix3& matrix);
    operator float *();
    Vector3 operator [] (const int& index);
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