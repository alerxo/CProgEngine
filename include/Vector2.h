#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

struct Vector2
{
    float x;
    float y;

    Vector2();
    Vector2(float, float);
    Vector2(int, int);
    Vector2(Vector2 &);

    const std::ostream &operator<<(std::ostream &);
    const Vector2 &operator+=(Vector2);
    Vector2 operator+(Vector2);
    Vector2 operator-(Vector2);
    const Vector2 operator=(Vector2);
};

#endif