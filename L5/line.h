#ifndef LINE_H
#define LINE_H

#ifndef MATRIX_H
#include "matrix.h"
#endif


class Line{
  Matrix pos1;
  Matrix pos2;
public:
  Line(int x1, int y1, int z1, int x2, int y2, int z2);
  Line(const Matrix& coord1, const Matrix& coord2);
  Line();
  void draw();
  void drawInBuf(int** array, int color);
  void rotate(int angle, Matrix rotPoint, char axis);
  void scale(float size, Matrix scalePoint);
  void move(int x, int y, int z);
  Matrix getMid();
  Matrix getPos1();
};

Matrix generate3DRotationMatrix(int angle, char axis);
Matrix generate3DScaleMatrix(float scale);
Matrix generate3DMoveMatrix(int x, int y, int z);

#endif
