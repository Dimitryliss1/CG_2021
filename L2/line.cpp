#include "line.h"
#include "matrix.h"
#include <graphics.h>
#include <cmath>

Line::Line(int x1, int y1, int x2, int y2){
  pos1 = Matrix(1, 3);
  pos2 = Matrix(1, 3);

  float* tmp = new float [3];
  tmp[0] = x1; tmp[1] = y1; tmp[2] = 1;
  pos1.fill(tmp, 3);

  tmp[0] = x2; tmp[1] = y2; tmp[2] = 1;
  pos2.fill(tmp, 3);
  delete [] tmp;
}

Line::Line(const Matrix& coord1, const Matrix& coord2){
  pos1 = coord1;
  pos2 = coord2;
}

Line::Line(){
  pos1 = Matrix(1, 3);
  pos2 = Matrix(1, 3);

  float* tmp = new float [3];
  tmp[0] = 0; tmp[1] = 0; tmp[2] = 1;
  pos1.fill(tmp, 3);

  tmp[0] = 0; tmp[1] = 0; tmp[2] = 1;
  pos2.fill(tmp, 3);
  delete [] tmp;
}

void Line::draw(){
  int x1 = pos1.getByRowCol(0,0), x2 = pos2.getByRowCol(0,0);
  int y1 = pos1.getByRowCol(0,1), y2 = pos2.getByRowCol(0,1);

  line(x1, y1, x2, y2);
}

void Line::drawBresenham(){
  int x0 = pos1.getByRowCol(0,0), x1 = pos2.getByRowCol(0,0);
  int y0 = pos1.getByRowCol(0,1), y1 = pos2.getByRowCol(0,1);

  int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = (dx > dy ? dx : -dy)/2;
  int e2 = err;
  for(;;){
    putpixel(x0, y0, 14);
    if (x0 == x1 && y0 == y1) break;
    e2 = err;
    if (e2 > -dx) {err -= dy; x0 += sx;}
    if (e2 < dy) {err += dx; y0 += sy;}
  }
}

void Line::rotate(int angle, Matrix rotPoint){
  float rotX = rotPoint.getByRowCol(0,0);
  float rotY = rotPoint.getByRowCol(0,1);
  Matrix move = generate2DMoveMatrix(-rotX, -rotY);
  Matrix negMove = generate2DMoveMatrix(rotX, rotY);
  Matrix rot = generate2DRotationMatrix(angle);

  pos1 = pos1 * move * rot * negMove;
  pos2 = pos2 * move * rot * negMove;
}

void Line::scale(float size, Matrix scalePoint){
  float rotX = scalePoint.getByRowCol(0,0);
  float rotY = scalePoint.getByRowCol(0,1);
  Matrix move = generate2DMoveMatrix(-rotX, -rotY);
  Matrix negMove = generate2DMoveMatrix(rotX, rotY);
  Matrix scale = generate2DScaleMatrix(size);

  pos1 = pos1 * move * scale * negMove;
  pos2 = pos2 * move * scale * negMove;
}

void Line::move(int x, int y){
  Matrix move = generate2DMoveMatrix(x, y);
  pos1 = pos1 * move;
  pos2 = pos2 * move;
}

Matrix Line::getMid(){
  float x1 = pos1.getByRowCol(0,0), x2 = pos2.getByRowCol(0,0);
  float y1 = pos1.getByRowCol(0,1), y2 = pos2.getByRowCol(0,1);

  Matrix res(1, 3);

  float* tmp = new float [3];
  tmp[0] = (x1+x2)/2; tmp[1] = (y1+y2)/2; tmp[2] = 1;
  res.fill(tmp, 3);
  delete [] tmp;
  return res;
}

Matrix Line::getPos1(){
  return pos1;
}

Matrix generate2DRotationMatrix(int angle){
  Matrix res(3, 3);
  float* data = new float[9];
  for(int i = 0; i < 9; i++) data[i] = 0;
  data[8] = 1;
  data[0] = cos(M_PI * angle / 180); data[4] = cos(M_PI * angle / 180);
  data[1] = sin(M_PI * angle / 180); data[3] = -sin(M_PI * angle / 180);
  res.fill(data, 9);
  delete [] data;
  return res;
}

Matrix generate2DScaleMatrix(float scale){
  Matrix res(3, 3);
  float* data = new float[9];
  for(int i = 0; i < 9; i++) data[i] = 0;
  data[8] = 1;
  data[0] = scale; data[4] = scale;
  res.fill(data, 9);
  delete [] data;
  return res;
}

Matrix generate2DMoveMatrix(int x, int y){
  Matrix res(3, 3);
  float* data = new float[9];
  for(int i = 0; i < 9; i++) data[i] = 0;
  data[0] = 1; data[4] = 1; data[8] = 1;
  data[6] = x; data[7] = y;
  res.fill(data, 9);
  delete [] data;
  return res;
}
