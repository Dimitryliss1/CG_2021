#include "triangle.h"
#include "line.h"
#include "matrix.h"
#include <graphics.h>
#include <cmath>

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3){
  a = Line(x1, y1, x2, y2);
  b = Line(x2, y2, x3, y3);
  c = Line(x3, y3, x1, y1);
}

void Triangle::rotate(int angle, Matrix rotPoint){
  a.rotate(angle, rotPoint);
  b.rotate(angle, rotPoint);
  c.rotate(angle, rotPoint);
}

void Triangle::scale(float scale, Matrix scalePoint){
  a.scale(scale, scalePoint);
  b.scale(scale, scalePoint);
  c.scale(scale, scalePoint);
}

void Triangle::move(int dx, int dy){
  a.move(dx, dy);
  b.move(dx, dy);
  c.move(dx, dy);
}

void Triangle::draw(){
  a.drawBresenham();
  b.drawBresenham();
  c.drawBresenham();
}

Matrix Triangle::getMid(){
  float x1 = a.getMid().getByRowCol(0,0), x2 = b.getMid().getByRowCol(0,0), x3 = c.getMid().getByRowCol(0,0);
  float y1 = a.getMid().getByRowCol(0,1), y2 = b.getMid().getByRowCol(0,1), y3 = c.getMid().getByRowCol(0,1);

  Matrix res(1, 3);

  float* tmp = new float [3];
  tmp[0] = (x1+x2+x3)/3; tmp[1] = (y1+y2+y3)/3; tmp[2] = 1;
  res.fill(tmp, 3);
  delete [] tmp;
  return res;
}

Matrix Triangle::getPointA(){
  return a.getPos1();
}
