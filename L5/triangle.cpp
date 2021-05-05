#include "triangle.h"
#include "line.h"
#include "matrix.h"
#include <graphics.h>
#include <cmath>

Triangle::Triangle(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int color) {
    a = Line(x1, y1, z1, x2, y2, z2);
    b = Line(x2, y2, z2, x3, y3, z3);
    c = Line(x3, y3, z3, x1, y1, z1);
    equation = Matrix(1, 4);
    this->color = color;
    /*
    https://yandex.ru/images/touch/search?text=%D0%BA%D0%B0%D0%BA%20%D0%BF%D0%BE%D0%BB%D1%83%D1%87%D0%B8%D1%82%D1%8C%20%D1%83%D1%80%D0%B0%D0%B2%D0%BD%D0%B5%D0%BD%D0%B8%D0%B5%20%D0%BF%D0%BB%D0%BE%D1%81%D0%BA%D0%BE%D1%81%D1%82%D0%B8%20%D0%BF%D0%BE%20%D1%82%D1%80%D0%B5%D0%BC%20%D1%82%D0%BE%D1%87%D0%BA%D0%B0%D0%BC&source=tabbar&pos=2&img_url=https%3A%2F%2Fds04.infourok.ru%2Fuploads%2Fex%2F050b%2F00050e1a-363fcd83%2Fimg15.jpg&rpt=simage&ts=1619683361342
    */
}

Triangle::Triangle() {
    equation = Matrix(1, 4);
    a = Line(0, 0, 0, 0, 0, 0);
    b = Line(0, 0, 0, 0, 0, 0);
    c = Line(0, 0, 0, 0, 0, 0);
    color = 0;
    float eq[4] = {0, 0, 0, 0};
    equation.fill(eq, 4);
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

float Triangle::getMaxZ() {
    float tmp = a.getPos1().getByRowCol(0, 2);
    if (b.getPos1().getByRowCol(0, 2) > tmp) {
        tmp = b.getPos1().getByRowCol(0, 2);
    }
    if (c.getPos1().getByRowCol(0, 2) > tmp) {
        tmp = c.getPos1().getByRowCol(0, 2);
    }
    return tmp;
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

void Triangle::drawInBuf(int **array) {
    a.drawInBuf(array, this->color);
    b.drawInBuf(array, this->color);
    c.drawInBuf(array, this->color);
    for (int i = 0; i <= getmaxy(); i++) {
        for (int j = 0; j <= getmaxx(); j++) {
            if (array[i][j] == this->color) {
                int tmpJ;
                for (tmpJ = j + 1; tmpJ <= getmaxx() + 1; tmpJ++) {
                    if (tmpJ == getmaxx() + 1) break;
                    if (array[i][tmpJ] == this->color) {
                        break;
                    }
                }
                if (tmpJ == getmaxx() + 1) break;
                for (int tmp = j; tmp <= tmpJ; tmp++) array[i][tmp] = this->color;

            }
        }
    }
}

Matrix Triangle::getEquation() {
    float y1 = a.getPos1().getByRowCol(0,1);
    float y2 = b.getPos1().getByRowCol(0,1);
    float y3 = c.getPos1().getByRowCol(0,1);
    float x1 = a.getPos1().getByRowCol(0,0);
    float x2 = b.getPos1().getByRowCol(0,0);
    float x3 = c.getPos1().getByRowCol(0,0);
    float z1 = a.getPos1().getByRowCol(0,2);
    float z2 = b.getPos1().getByRowCol(0,2);
    float z3 = c.getPos1().getByRowCol(0,2);
    float eq[4] = {(float) (y2 - y1) * (z3 - z1) - (z2 - z1) * (y3 - y1),
                   (float) (-1) * ((x2 - x1) * (z3 - z1) - (z2 - z1) * (x3 - x1)),
                   (float) (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1),
                   0};
    float tmp = 0;
    tmp += (-x1) * ((y2 - y1) * (z3 - z1) - (z2 - z1) * (y3 - y1));
    tmp += y1 * ((x2 - x1) * (z3 - z1) - (z2 - z1) * (x3 - x1));
    tmp += (-z1) * ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
    eq[3] = tmp;
    equation.fill(eq, 4);
    return equation;
}

int Triangle::getColor() {
    return color;
}
