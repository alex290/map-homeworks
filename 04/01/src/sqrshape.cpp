#include "sqrshape.h"

SqrShape::SqrShape(int _x[4], int _y[4])
{

    type = TypeShape::SQR;

    // заполн¤ем координаты фигуры
    x[0] = _x[0];
    y[0] = _y[0];
    x[1] = _x[1];
    y[1] = _y[1];
    x[2] = _x[2];
    y[2] = _y[2];
    x[3] = _x[3];
    y[3] = _y[3];

     // стороны фигуры
	int a = abs(x[0] - x[1]);
	int b = abs(y[0] - y[1]);

    // считаем площадь фигуры
    square = a * b;

    // считаем объем фигуры
    volume = 0;
}
