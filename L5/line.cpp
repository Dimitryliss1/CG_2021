#include "line.h"
#include "matrix.h"
#include <graphics.h>
#include <cmath>
#include <iostream>


Line::Line(int x1, int y1, int z1, int x2, int y2, int z2) {
    pos1 = Matrix(1, 4);
    pos2 = Matrix(1, 4);

    float *tmp = new float[4];
    tmp[0] = x1;
    tmp[1] = y1;
    tmp[2] = z1;
    tmp[3] = 1;
    pos1.fill(tmp, 4);

    tmp[0] = x2;
    tmp[1] = y2;
    tmp[2] = z2;
    tmp[3] = 1;
    pos2.fill(tmp, 4);
    delete[] tmp;
}

Line::Line(const Matrix &coord1, const Matrix &coord2) {
    pos1 = coord1;
    pos2 = coord2;
}

Line::Line() {
    pos1 = Matrix(1, 4);
    pos2 = Matrix(1, 4);

    float *tmp = new float[3];
    tmp[0] = 0;
    tmp[1] = 0;
    tmp[2] = 0;
    tmp[3] = 1;
    pos1.fill(tmp, 4);

    tmp[0] = 0;
    tmp[1] = 0;
    tmp[2] = 0;
    tmp[3] = 1;
    pos2.fill(tmp, 4);
    delete[] tmp;
}

void Line::drawInBuf(int **array, int color) {
    Matrix projection(4, 4);
    Matrix tmp1 = pos1;
    Matrix tmp2 = pos2;
//    float data[16] = {1, 0, 0, 0, 0, 1, 0, 0, (float) 1 / 2, (float) -1 / 2, 1, 0, 0, 0, 0, 1};
//    projection.fill(data, 16);
//    tmp1 = tmp1 * projection;
//    tmp2 = tmp2 * projection;
    int x0 = tmp1.getByRowCol(0, 0), x1 = tmp2.getByRowCol(0, 0);
    int y0 = tmp1.getByRowCol(0, 1), y1 = tmp2.getByRowCol(0, 1);

    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2 = err;
    for (;;) {
        // putpixel(x0, y0, 14);
        if (x0 >= 0 && x0 <= getmaxx() && y0 >= 0 && y0 <= getmaxy()) {
            array[y0][x0] = color;
        }
        if (x0 == x1 && y0 == y1) break;
        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy) {
            err += dx;
            y0 += sy;
        }
    }
}

void Line::draw() {
    Matrix tmp1 = pos1;
    Matrix tmp2 = pos2;

    // Упоротые проекции
//   Matrix move = generate3DMoveMatrix(-getmaxx()/2, -getmaxy()/2, 0);
//   Matrix negMove = generate3DMoveMatrix(getmaxx()/2, getmaxy()/2, 0);
//   tmp1 = tmp1*move;
//   tmp2 = tmp2*move;
//   int scale = 1000;
//   Matrix projection(4, 4);
//   float data[16] = {scale/tmp1.getByRowCol(0,2), 0, 0, 0,
//                     0, scale/tmp1.getByRowCol(0,2), 0, 0,
//                     0, 0, 1, 0,
//                     0, 0, static_cast<float>(-scale), 1};
//   projection.fill(data, 16);
//   tmp1 = tmp1*projection*negMove;
//
//   data[0] = scale/tmp2.getByRowCol(0,2);
//   data[5] = scale/tmp2.getByRowCol(0,2);
//   projection.fill(data, 16);
//   tmp2 = tmp2*projection*negMove;

    Matrix projection(4, 4);
    float data[16] = {1, 0, 0, 0, 0, 1, 0, 0, (float) 1 / 2, (float) -1 / 2, 1, 0, 0, 0, 0, 1};
    projection.fill(data, 16);
    tmp1 = tmp1 * projection;
    tmp2 = tmp2 * projection;
    line(tmp1.getByRowCol(0, 0), tmp1.getByRowCol(0, 1),
         tmp2.getByRowCol(0, 0), tmp2.getByRowCol(0, 1));
}

void Line::rotate(int angle, Matrix rotPoint, char axis) {
    float rotX = rotPoint.getByRowCol(0, 0);
    float rotY = rotPoint.getByRowCol(0, 1);
    float rotZ = rotPoint.getByRowCol(0, 2);
    Matrix move = generate3DMoveMatrix(-rotX, -rotY, -rotZ);
    Matrix negMove = generate3DMoveMatrix(rotX, rotY, rotZ);
    Matrix rot = generate3DRotationMatrix(angle, axis);
    pos1 = pos1 * move * rot * negMove;
    pos2 = pos2 * move * rot * negMove;
}

void Line::scale(float size, Matrix scalePoint) {
    float rotX = scalePoint.getByRowCol(0, 0);
    float rotY = scalePoint.getByRowCol(0, 1);
    float rotZ = scalePoint.getByRowCol(0, 2);
    Matrix move = generate3DMoveMatrix(-rotX, -rotY, -rotZ);
    Matrix negMove = generate3DMoveMatrix(rotX, rotY, rotZ);
    Matrix scale = generate3DScaleMatrix(size);

    pos1 = pos1 * move * scale * negMove;
    pos2 = pos2 * move * scale * negMove;
}

void Line::move(int x, int y, int z) {
    Matrix move = generate3DMoveMatrix(x, y, z);
    pos1 = pos1 * move;
    pos2 = pos2 * move;
}

Matrix Line::getMid() {
    float x1 = pos1.getByRowCol(0, 0), x2 = pos2.getByRowCol(0, 0);
    float y1 = pos1.getByRowCol(0, 1), y2 = pos2.getByRowCol(0, 1);
    float z1 = pos1.getByRowCol(0, 2), z2 = pos2.getByRowCol(0, 2);
    Matrix res(1, 4);
    float *tmp = new float[4];
    tmp[0] = (x1 + x2) / 2;
    tmp[1] = (y1 + y2) / 2;
    tmp[2] = (z1 + z2) / 2;
    tmp[3] = 1;
    res.fill(tmp, 4);
    delete[] tmp;
    return res;
}

Matrix Line::getPos1() {
    return pos1;
}


Matrix generate3DRotationMatrix(int angle, char axis) {
    Matrix res(4, 4);
    float *data = new float[16];
    for (int i = 0; i < 16; i++) data[i] = 0;
    if (axis == 'z') {
        data[0] = cos(M_PI * angle / 180);
        data[5] = cos(M_PI * angle / 180);
        data[1] = sin(M_PI * angle / 180);
        data[4] = -sin(M_PI * angle / 180);
        data[10] = 1;
        data[15] = 1;
    } else if (axis == 'x') {
        data[0] = 1;
        data[15] = 1;
        data[5] = cos(M_PI * angle / 180);
        data[6] = sin(M_PI * angle / 180);
        data[9] = -sin(M_PI * angle / 180);
        data[10] = cos(M_PI * angle / 180);
    } else if (axis == 'y') {
        data[5] = 1;
        data[15] = 1;
        data[0] = cos(M_PI * angle / 180);
        data[8] = sin(M_PI * angle / 180);
        data[2] = -sin(M_PI * angle / 180);
        data[10] = cos(M_PI * angle / 180);
    }
    res.fill(data, 16);
    delete[] data;
    return res;
}

Matrix generate3DScaleMatrix(float scale) {
    Matrix res(4, 4);
    float *data = new float[16];
    for (int i = 0; i < 16; i++) data[i] = 0;
    data[15] = 1;
    data[0] = scale;
    data[5] = scale;
    data[10] = scale;
    res.fill(data, 16);
    delete[] data;
    return res;
}

Matrix generate3DMoveMatrix(int x, int y, int z) {
    Matrix res(4, 4);
    float *data = new float[16];
    for (int i = 0; i < 16; i++) data[i] = 0;
    data[0] = 1;
    data[5] = 1;
    data[10] = 1;
    data[15] = 1;
    data[12] = x;
    data[13] = y;
    data[14] = z;
    res.fill(data, 16);
    delete[] data;
    return res;
}
