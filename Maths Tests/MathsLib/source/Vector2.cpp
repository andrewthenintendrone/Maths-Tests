#include "Vector2.h"

/*##################################################
Vector2 constructor and destructor
##################################################*/
Vector2::Vector2()
{
    x = 0.0f;
    y = 0.0f;
}

Vector2::Vector2(float newX, float newY)
{
    x = newX;
    y = newY;
}

Vector2::Vector2(int newX, int newY)
{
    x = (float)newX;
    y = (float)newY;
}

Vector2::~Vector2()
{

}

/*##################################################
Vector2 Functions
##################################################*/
float Vector2::getMagnitude()
{
    return (float)sqrt(x * x + y * y);
}

float Vector2::getSquaredMagnitude()
{
    return(x * x + y * y);
}

void Vector2::Normalize()
{
    float magnitude = getMagnitude();
    x /= magnitude;
    y /= magnitude;
}

Vector2 Vector2::normalized()
{
    Vector2 temp = *this;
    float magnitude = getMagnitude();
    temp.Normalize();
    return temp;
}

float Vector2::getAngle(const Vector2& lhs, const Vector2& rhs)
{
    float dx = rhs.x - lhs.x;
    float dy = rhs.y - lhs.y;

    return atan(dy / dx) * 57.2958f;
}

/*##################################################
Vector2 shortcuts for commonly used Vector2s
##################################################*/
Vector2 Vector2::Up()
{
    return{ 0.0f, 1.0f };
}

Vector2 Vector2::Down()
{
    return{ 0.0f, -1.0f };
}

Vector2 Vector2::Left()
{
    return{ -1.0f, 0.0f };
}

Vector2 Vector2::Right()
{
    return{ -1.0f, 0.0f };
}

Vector2 Vector2::Zero()
{
    return{ 0.0f, 0.0f };
}

/*##################################################
Vector2 overloaded operators
##################################################*/
bool Vector2::operator == (const Vector2& rhs)
{
    return (x == rhs.x && y == rhs.y);
}

void Vector2::operator = (const Vector2& vec)
{
    x = vec.x;
    y = vec.y;
}

Vector2 Vector2::operator + (const Vector2& rhs)
{
    Vector2 temp = { x, y };
    temp += rhs;
    return temp;
}

Vector2 Vector2::operator - (const Vector2& rhs)
{
    Vector2 temp = { x, y };
    temp -= rhs;
    return temp;
}

void Vector2::operator += (const Vector2& vec)
{
    x += vec.x;
    y += vec.y;
}

void Vector2::operator -= (const Vector2& vec)
{
    x -= vec.x;
    y -= vec.y;
}

std::ostream& operator << (std::ostream& stream, const Vector2& vector)
{
    stream << "(" << vector.x << ", " << vector.y << ")";
    return stream;
}
