#ifndef PYRAMID_H
#define PYRAMID_H

#ifndef TRIANGLE_H
#include "triangle.h"
#endif

#ifndef MATRIX_H
#include "matrix.h"
#endif

class Pyramid{
    Triangle a, b, c, d;
public:
    Pyramid(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4);
    void rotate(int angle, Matrix rotPoint, char axis);
    void scale(float size, Matrix scalePoint);
    void move(int x, int y, int z);
    void draw();
    Matrix getMid();
};

#endif
