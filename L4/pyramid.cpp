#include "line.h"
#include "matrix.h"
#include "pyramid.h"
#include <iostream>

Pyramid::Pyramid(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4) {
    a = Triangle(x1, y1, z1, x2, y2, z2, x3, y3, z3);
    b = Triangle(x1, y1, z1, x2, y2, z2, x4, y4, z4);
    c = Triangle(x2, y2, z2, x3, y3, z3, x4, y4, z4);
    d = Triangle(x3, y3, z3, x1, y1, z1, x4, y4, z4);
}

void Pyramid::rotate(int angle, Matrix rotPoint, char axis) {
    a.rotate(angle, rotPoint, axis);
    b.rotate(angle, rotPoint, axis);
    c.rotate(angle, rotPoint, axis);
    d.rotate(angle, rotPoint, axis);
}

void Pyramid::scale(float size, Matrix scalePoint) {
    a.scale(size, scalePoint);
    b.scale(size, scalePoint);
    c.scale(size, scalePoint);
    d.scale(size, scalePoint);
}

void Pyramid::move(int x, int y, int z) {
    a.move(x, y, z);
    b.move(x, y, z);
    c.move(x, y, z);
    d.move(x, y, z);
}

void Pyramid::draw() {
    a.draw();
    b.draw();
    c.draw();
    d.draw();
}

Matrix Pyramid::getMid() {
    float x1 = a.getMid().getByRowCol(0, 0), x2 = b.getMid().getByRowCol(0, 0), x3 = c.getMid().getByRowCol(0, 0);
    float x4 = d.getMid().getByRowCol(0, 0);

    float y1 = a.getMid().getByRowCol(0, 1), y2 = b.getMid().getByRowCol(0, 1), y3 = c.getMid().getByRowCol(0, 1);
    float y4 = d.getMid().getByRowCol(0, 1);

    float z1 = a.getMid().getByRowCol(0, 2), z2 = b.getMid().getByRowCol(0, 2), z3 = c.getMid().getByRowCol(0, 2);
    float z4 = d.getMid().getByRowCol(0, 2);

    Matrix res(1, 4);
    float *tmp = new float[4];
    tmp[0] = (x1 + x2 + x3 + x4) / 4;
    tmp[1] = (y1 + y2 + y3 + y4) / 4;
    tmp[2] = (z1 + z2 + z3 + z4) / 4;
    tmp[3] = 1;
    res.fill(tmp, 4);
    delete[] tmp;
    return res;
}
