#pragma once
#include <iostream>

class Vector2
{
public:
    // variables
    float x;
    float y;

    // constructors and destructor
    Vector2();
    Vector2(float newX, float newY);
    Vector2(int newX, int newY);
    ~Vector2();

    // functions
    float getMagnitude();
    float getSquaredMagnitude();
    void Normalize();
    Vector2 normalized();
    static float getAngle(const Vector2& lhs, const Vector2& rhs);

    // static Vector3 shortcuts
    static Vector2 Up();
    static Vector2 Down();
    static Vector2 Left();
    static Vector2 Right();
    static Vector2 Zero();

    // operator overloads
    bool operator == (const Vector2& rhs);
    void operator = (const Vector2& vec);
    Vector2 operator + (const Vector2& rhs);
    Vector2 operator - (const Vector2& rhs);
    void operator += (const Vector2& vec);
    void operator -= (const Vector2& vec);
    friend std::ostream& operator << (std::ostream& stream, const Vector2& vector);
};