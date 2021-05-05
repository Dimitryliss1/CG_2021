//
// Created by Павел Жуков on 12.11.2020.
//

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
  Triangle abc(getmaxx()/2-100, getmaxy()/2+100, getmaxx()/2+100, getmaxy()/2+100, getmaxx()/2, getmaxy()/2-150);
  abc.draw();
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
          abc.draw();
          break;
        case 'e':
          setbkcolor(0);
          abc.rotate(5, abc.getPointA());
          abc.draw();
          break;
        case 'z':
          setbkcolor(0);
          abc.scale(0.95, abc.getMid());
          abc.draw();
          break;
        case 'c':
          setbkcolor(0);
          abc.scale(1.05, abc.getPointA());
          abc.draw();
          break;
        case 'w':
          setbkcolor(0);
          abc.move(0, -5);
          abc.draw();
          break;
        case 'a':
          setbkcolor(0);
          abc.move(-5, 0);
          abc.draw();
          break;
        case 's':
          setbkcolor(0);
          abc.move(0, 5);
          abc.draw();
          break;
        case 'd':
          setbkcolor(0);
          abc.move(5, 0);
          abc.draw();
          break;
      }
    }
  }
  closegraph();
  return 0;
}
