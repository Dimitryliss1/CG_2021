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

Matrix Triangle::getPointB(){
  return b.getPos1();
}

Matrix Triangle::getPointC(){
  return c.getPos1();
}

void fillSpace(int x, int y, int color){
  while(x < 0){
    x += (getmaxx() + 1);
  }
  if (x != (getmaxx() + 1)) x %= (getmaxx() + 1);
  while (y < 0){
    y += (getmaxy() + 1);
  }
  if (y != (getmaxy() + 1))
  y %= (getmaxy() + 1);
  putpixel(x, y, color);
  // if (x >= 0 && x < getmaxx() + 1 && y >= 0 && y < getmaxy() + 1){
    x += 1;
    if (x == (getmaxx() + 1)) x -= (getmaxx() + 1);
    if (getpixel(x, y) != 14 && getpixel(x, y) != color){
      fillSpace(x, y, color);
    }
    x -= 1;
    if (x == -1) x += (getmaxx() + 1);

    y -= 1;
    if (y == -1) y += (getmaxy() + 1);
    if (getpixel(x, y) != 14 && getpixel(x, y) != color){
      fillSpace(x, y, color);
    }
    y += 1;
    if (y == (getmaxy() + 1)) y -= (getmaxy() + 1);
    x -= 1;
    if (x == -1) x += (getmaxx() + 1);
    if (getpixel(x, y) != 14 && getpixel(x, y) != color){
      fillSpace(x, y, color);
    }
    x += 1;
    if (x == (getmaxx() + 1)) x -= (getmaxx() + 1);

    y += 1;
    if (y == (getmaxy() + 1)) y -= (getmaxy() + 1);
    if (getpixel(x, y) != 14 && getpixel(x, y) != color){
      fillSpace(x, y, color);
    }
    y -= 1;
    if (y == -1) y += (getmaxy() + 1);
  // }
}

void Triangle::fill(int color){
  this->draw();
  Matrix tmp = getMid();
  int x = tmp.getByRowCol(0,0);
  int y = tmp.getByRowCol(0,1);
  fillSpace(x, y, color);
}
