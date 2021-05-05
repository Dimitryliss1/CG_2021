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
public:
  Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
  void rotate(int angle, Matrix rotPoint);
  void scale(float scale, Matrix scalePoint);
  void move(int dx, int dy);
  void draw();
  Matrix getMid();
  Matrix getPointA();
};


#endif
