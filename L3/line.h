#ifndef LINE_H
#define LINE_H

#ifndef MATRIX_H
#include "matrix.h"
#endif


class Line{
  Matrix pos1;
  Matrix pos2;
public:
  Line(int x1, int y1, int x2, int y2);
  Line(const Matrix& coord1, const Matrix& coord2);
  Line();
  void draw();
  void drawBresenham();
  void rotate(int angle, Matrix rotPoint);
  void scale(float size, Matrix scalePoint);
  void move(int x, int y);
  Matrix getMid();
  Matrix getPos1();
};

Matrix generate2DRotationMatrix(int angle);
Matrix generate2DScaleMatrix(float scale);
Matrix generate2DMoveMatrix(int x, int y);

#endif
