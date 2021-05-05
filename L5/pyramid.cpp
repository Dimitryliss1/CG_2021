#include "line.h"
#include "matrix.h"
#include "pyramid.h"
#include "triangle.h"
#include <graphics.h>
#include <cmath>
#include <iostream>

Pyramid::Pyramid(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4) {
    a = Triangle(x1, y1, z1, x2, y2, z2, x3, y3, z3, 1);
    b = Triangle(x1, y1, z1, x2, y2, z2, x4, y4, z4, 2);
    c = Triangle(x2, y2, z2, x3, y3, z3, x4, y4, z4, 3);
    d = Triangle(x3, y3, z3, x1, y1, z1, x4, y4, z4, 4);
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

float Pyramid::getMaxZ() {
    float tmp = a.getMaxZ();
    if (b.getMaxZ() > tmp) tmp = b.getMaxZ();
    if (c.getMaxZ() > tmp) tmp = c.getMaxZ();
    if (d.getMaxZ() > tmp) tmp = d.getMaxZ();
    return tmp;
}

bool Compare(Triangle a, Triangle b){
    return a.getMid().getByRowCol(0,2) < b.getMid().getByRowCol(0, 2);
}

void Pyramid::draw(float **zBuf, int **frameBuf) {
    int **tmpBuf = new int *[getmaxy() + 1];
    for (int i = 0; i < getmaxy() + 1; i++) {
        tmpBuf[i] = new int[getmaxx() + 1];
        for (int j = 0; j < getmaxx() + 1; j++) {
            tmpBuf[i][j] = 0;
        }
    }

    Matrix eqns[4];
    eqns[0] = a.getEquation();
    eqns[1] = b.getEquation();
    eqns[2] = c.getEquation();
    eqns[3] = d.getEquation();

    Triangle polygons[4] = {a, b, c, d};
    std::sort(polygons, polygons + 4, Compare);
    for (Triangle k: polygons){
        k.drawInBuf(tmpBuf);
        for (int i = 0; i < getmaxy() + 1; i++) {
            for (int j = 0; j < getmaxx() + 1; j++) {
                if (tmpBuf[i][j] != 0){
                    float tmp_Z = - eqns[k.getColor() - 1].getByRowCol(0,0)*j - eqns[k.getColor() - 1].getByRowCol(0, 1)*i - eqns[k.getColor() - 1].getByRowCol(0, 3);
                    tmp_Z /= eqns[k.getColor() - 1].getByRowCol(0, 2);
                    if (zBuf[i][j] > tmp_Z){
                        zBuf[i][j] = tmp_Z;
                        frameBuf[i][j] = k.getColor();
                    }
                    tmpBuf[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < getmaxy() + 1; i++) {
        for (int j = 0; j < getmaxx() + 1; j++) {
            putpixel(j, i, frameBuf[i][j]);
        }
    }
    for (int i = 0; i < getmaxy() + 1; i++) {
//        delete[] zBuf[i];
//        delete[] frameBuf[i];
        delete[] tmpBuf[i];
    }
//    delete[] zBuf;
//    delete[] frameBuf;
    delete[] tmpBuf;
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

