#ifndef TRIANGLE_H
#define TRIANGLE_H

#ifndef MATRIX_H
#include "matrix.h"
#endif

#ifndef LINE_H
#include "line.h"
#endif


class Triangle{
  Line a, b, c;
  int color;
  Matrix equation;
public:
  Triangle(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int color = 0);
  Triangle();
  void rotate(int angle, Matrix rotPoint, char axis);
  void scale(float size, Matrix scalePoint);
  void move(int x, int y, int z);
  void draw();
  void drawInBuf(int** array);
  float getMaxZ();
  Matrix getMid();
  Matrix getEquation();
  int getColor();
};
#endif
