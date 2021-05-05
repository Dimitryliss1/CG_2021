#include "triangle.h"
#include "line.h"
#include "matrix.h"

Triangle::Triangle(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3) {
    a = Line(x1, y1, z1, x2, y2, z2);
    b = Line(x2, y2, z2, x3, y3, z3);
    c = Line(x3, y3, z3, x1, y1, z1);
}

Triangle::Triangle() {
    a = Line(0, 0, 0, 0, 0, 0);
    b = Line(0, 0, 0, 0, 0, 0);
    c = Line(0, 0, 0, 0, 0, 0);
}

void Triangle::rotate(int angle, Matrix rotPoint, char axis) {
    a.rotate(angle, rotPoint, axis);
    b.rotate(angle, rotPoint, axis);
    c.rotate(angle, rotPoint, axis);
}

void Triangle::scale(float scale, Matrix scalePoint) {
    a.scale(scale, scalePoint);
    b.scale(scale, scalePoint);
    c.scale(scale, scalePoint);
}

void Triangle::move(int x, int y, int z) {
    a.move(x, y, z);
    b.move(x, y, z);
    c.move(x, y, z);
}

void Triangle::draw() {
    a.draw();
    b.draw();
    c.draw();
}

Matrix Triangle::getMid() {
    float x1 = a.getMid().getByRowCol(0, 0), x2 = b.getMid().getByRowCol(0, 0), x3 = c.getMid().getByRowCol(0, 0);
    float y1 = a.getMid().getByRowCol(0, 1), y2 = b.getMid().getByRowCol(0, 1), y3 = c.getMid().getByRowCol(0, 1);
    float z1 = a.getMid().getByRowCol(0, 2), z2 = b.getMid().getByRowCol(0, 2), z3 = c.getMid().getByRowCol(0, 2);

    Matrix res(1, 4);
    float *tmp = new float[4];
    tmp[0] = (x1 + x2 + x3) / 3;
    tmp[1] = (y1 + y2 + y3) / 3;
    tmp[2] = (z1 + z2 + z3) / 3;
    tmp[3] = 1;
    res.fill(tmp, 4);
    delete[] tmp;
    return res;
}
