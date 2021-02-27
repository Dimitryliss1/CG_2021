//
// Created by Павел Жуков on 12.11.2020.
//

#include <graphics.h>
#include "matrix.h"
#include "line.h"
#include <iostream>

using namespace std;

int main(){
  int gd = DETECT, gm;
  initgraph (&gd, &gm, "");
  sdlbgiauto();
  Line a(getmaxx()/2 - 200, getmaxy()/2 - 100, getmaxx()/2 - 200, getmaxy()/2 + 100);
  Line b(getmaxx()/2 + 200, getmaxy()/2 - 100, getmaxx()/2 + 200, getmaxy()/2 + 100);
  char c;
  a.draw();
  b.drawBresenham();
  while(true){
    if (kbhit()){
      char c = getch();
      if (c == ' '){
        break;
      }
      switch(c){
        case 'q':
          setbkcolor(0);
          a.rotate(-5, a.getMid());
          a.draw();
          b.drawBresenham();
          break;
        case 'e':
          setbkcolor(0);
          a.rotate(5, a.getMid());
          a.draw();
          b.drawBresenham();
          break;
        case 'z':
          setbkcolor(0);
          a.scale(0.95, a.getMid());
          a.draw();
          b.drawBresenham();
          break;
        case 'c':
          setbkcolor(0);
          a.scale(1.05, a.getMid());
          a.draw();
          b.drawBresenham();
          break;
        case 'w':
          setbkcolor(0);
          a.move(0, -5);
          a.draw();
          b.drawBresenham();
          break;
        case 'a':
          setbkcolor(0);
          a.move(-5, 0);
          a.draw();
          b.drawBresenham();
          break;
        case 's':
          setbkcolor(0);
          a.move(0, 5);
          a.draw();
          b.drawBresenham();
          break;
        case 'd':
          setbkcolor(0);
          a.move(5, 0);
          a.draw();
          b.drawBresenham();
          break;
        case 'u':
          setbkcolor(0);
          b.rotate(-5, b.getMid());
          a.draw();
          b.drawBresenham();
          break;
        case 'o':
          setbkcolor(0);
          b.rotate(5, b.getMid());
          a.draw();
          b.drawBresenham();
          break;
        case 'm':
          setbkcolor(0);
          b.scale(0.95, b.getMid());
          a.draw();
          b.drawBresenham();
          break;
        case '.':
          setbkcolor(0);
          b.scale(1.05, b.getMid());
          a.draw();
          b.drawBresenham();
          break;
        case 'i':
          setbkcolor(0);
          b.move(0, -5);
          a.draw();
          b.drawBresenham();
          break;
        case 'j':
          setbkcolor(0);
          b.move(-5, 0);
          a.draw();
          b.drawBresenham();
          break;
        case 'k':
          setbkcolor(0);
          b.move(0, 5);
          a.draw();
          b.drawBresenham();
          break;
        case 'l':
          setbkcolor(0);
          b.move(5, 0);
          a.draw();
          b.drawBresenham();
          break;
      }
    }
  }
  closegraph();
  return 0;
}
