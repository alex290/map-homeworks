#include "transform.h"

transform::transform(const Shape &sh)
{
    shape = sh;
    if (shape.getType() == Shape::SQR)
    {
        count = 3;
    } else if ( shape.getType() == Shape::CUBE)
    {
        count = 7;
    }
}

Shape transform::shift(int m, int n, int k)
{

    for (size_t i = 0; i < count; i++)
    {
        shape.x[i] += m;
        shape.y[i] += n;
        if (shape.getType() == Shape::CUBE)
        {
            shape.z[i] += k;
        }
    }
    
    return shape;
}

Shape transform::scaleX(int a)
{
    for (size_t i = 0; i < count; i++)
    {
        shape.x[i] *= a;
    }

    return shape;
}

Shape transform::scaleY(int d)
{
    for (size_t i = 0; i < count; i++)
    {
        shape.y[i] *= d;
    }

    return shape;
}

Shape transform::scaleZ(int e)
{
    for (size_t i = 0; i < count; i++)
    {
        shape.z[i] *= e;
    }

    return shape;

}

Shape transform::scale(int s)
{
    for (size_t i = 0; i < count; i++)
    {
        shape.x[i] /= s;
        shape.y[i] /= s;
        if (shape.getType() == Shape::CUBE)
        {
            shape.z[i] /= s;
        }
    }
    
    return shape;
}
