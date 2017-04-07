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
            Vector3 xAxis;
            Vector3 yAxis;
            Vector3 zAxis;
        };
        struct
        {
            Vector3 axis[3];
        };
        struct
        {
            float m[3][3];
        };
        struct
        {
            float Xx;
            float Xy;
            float Xz;
            float Yx;
            float Yy;
            float Yz;
            float Zx;
            float Zy;
            float Zz;
        };
    };

    // constructors and destructors
    Matrix3();
    Matrix3(const float& newXx, const float& newXy, const float& newXz, const float& newYx, const float& newYy, const float& newYz, const float& newZx, const float& newZy, const float& newZz);
    Matrix3(Vector3& newxAxis, Vector3& newyAxis, Vector3& newzAxis);
    Matrix3(const Matrix3& newMatrix);
    ~Matrix3();

    // functions
    static Matrix3 identity();
    float determinant();
    void setRotateX(const float& angle);
    void setRotateY(const float& angle);
    void setRotateZ(const float& angle);

    // overloads
    friend std::ostream& operator << (std::ostream& stream, const Matrix3& matrix);
    operator float *();
    Vector3 operator [] (const int& index);
    void operator = (const Matrix3& newMatrix);
    Matrix3 operator + (const Matrix3& rhs);
    void operator += (const Matrix3& rhs);
    Matrix3 operator - (const Matrix3& rhs);
    void operator -= (const Matrix3& rhs);
    Matrix3 operator * (const Matrix3& rhs);
    void operator *= (const Matrix3& rhs);
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