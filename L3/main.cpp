//
// Created by Павел Жуков on 12.11.2020.
//
//Можно тащить за треугольником четырехугольник,
#include <graphics.h>
#include "matrix.h"
#include "line.h"
#include "triangle.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
  int gd = DETECT, gm;
  // initgraph (&gd, &gm, "");
  initwindow(800,600);
  sdlbgiauto();
  Triangle abc(getmaxx()/2-100, getmaxy()/2+100, getmaxx()/2+100, getmaxy()/2+100, 200, 200);
  abc.draw();
  int color = 0;
  while(true){
  if (kbhit()){
      char c = getch();
      if (c == ' '){
        break;
      }
      switch(c){
        case 'q':
          setbkcolor(0);
          abc.rotate(-5, abc.getMid());
          abc.fill(color);
          break;
        case 'e':
          setbkcolor(0);
          abc.rotate(5, abc.getPointA());
          abc.fill(color);
          break;
        case 'z':
          setbkcolor(0);
          abc.scale(0.95, abc.getMid());
          abc.fill(color);
          break;
        case 'c':
          setbkcolor(0);
          abc.scale(1.05, abc.getPointA());
          abc.fill(color);
          break;
        case 'w':
          setbkcolor(0);
          abc.move(0, -5);
          abc.fill(color);
          break;
        case 'a':
          setbkcolor(0);
          abc.move(-5, 0);
          abc.fill(color);
          break;
        case 's':
          setbkcolor(0);
          abc.move(0, 5);
          abc.fill(color);
          break;
        case 'd':
          setbkcolor(0);
          abc.move(5, 0);
          abc.fill(color);
          break;
        case 'f':
          setbkcolor(0);
          abc.draw();
          color++;
          if (color == 16){
            color = 0;
          }
          abc.fill(color);
          break;
      }
    }
  }
  closegraph();
  return 0;
}
