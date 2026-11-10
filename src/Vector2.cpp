#include "Vector2.h"

struct Vector2 vector2;

Vector2::Vector2()
{
    x = 0;
    y = 0;
}

Vector2::Vector2(float xx, float yy)
{
    x = xx;
    y = yy;
}

Vector2::Vector2(int xx, int yy)
{
    x = (float)xx;
    y = (float)yy;
}

Vector2::Vector2(Vector2 &right)
{
    x = right.x;
    y = right.y;
}

const std::ostream &Vector2::operator<<(std::ostream &os)
{
    os << "x: " << x << "y: " << y;

    return os;
}

const Vector2 &Vector2::operator+=(Vector2 right)
{
    x += right.x;
    y += right.y;

    return *this;
}

Vector2 Vector2::operator+(Vector2 right)
{
    Vector2 temp(*this);

    temp.x += right.x;
    temp.y += right.y;

    return temp;
}

Vector2 Vector2::operator-(Vector2 right)
{
    Vector2 temp(*this);

    temp.x -= right.x;
    temp.y -= right.y;

    return temp;
}

const Vector2 Vector2::operator=(Vector2 right)
{
    x = right.x;
    y = right.y;

    return *this;
}