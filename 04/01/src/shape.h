#pragma once

#define _USE_MATH_DEFINES
#include <string>
#include <cmath>
class Shape
{
public:
    enum TypeShape
    {
        LINE,
        SQR,
        CUBE,
        CIRCLE,
        CYLINDER,
        UNKNOWN
    };

    Shape() = default;
    Shape(int _x[7], int _y[7], int _z[7]);
    virtual int getType() { return type; }

    TypeShape type{TypeShape::UNKNOWN};
    int x[7]{0}, y[7]{0}, z[7]{0};

    double volume{0};
    double square{0};
    double height{0};
    double radius{0};
};
