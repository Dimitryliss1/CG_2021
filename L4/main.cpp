//
// Created by Павел Жуков on 12.11.2020.
//

#include <graphics.h>
#include "matrix.h"
#include "line.h"
#include "pyramid.h"

using namespace std;

int main() {
    // int gd = DETECT, gm;
    // initgraph (&gd, &gm, "");
    initwindow(800, 600);
    sdlbgiauto();
    Pyramid a(300, 400, 100,
              500, 400, 100,
              400, 400, 300,
              400, 200, 166);
    a.draw();
    while (true) {
        if (kbhit()) {
            char c = getch();
            if (c == ' ') {
                break;
            }
            switch (c) {
                case 'a':
                    a.move(-5, 0, 0);
                    setbkcolor(0);
                    a.draw();
                    break;
                case 'd':
                    a.move(5, 0, 0);
                    setbkcolor(0);
                    a.draw();
                    break;
                case 'w':
                    a.move(0, -5, 0);
                    setbkcolor(0);
                    a.draw();
                    break;
                case 's':
                    a.move(0, 5, 0);
                    setbkcolor(0);
                    a.draw();
                    break;
                case 'q':
                    a.move(0, 0, -5);
                    setbkcolor(0);
                    a.draw();
                    break;
                case 'e':
                    a.move(0, 0, 5);
                    setbkcolor(0);
                    a.draw();
                    break;
                case 'z':
                    a.scale(0.95, a.getMid());
                    setbkcolor(0);
                    a.draw();
                    break;
                case 'c':
                    a.scale(1.05, a.getMid());
                    setbkcolor(0);
                    a.draw();
                    break;
                case 'r':
                    a.rotate(-5, a.getMid(), 'z');
                    setbkcolor(0);
                    a.draw();
                    break;
                case 't':
                    a.rotate(5, a.getMid(), 'z');
                    setbkcolor(0);
                    a.draw();
                    break;
                case 'f':
                    a.rotate(5, a.getMid(), 'x');
                    setbkcolor(0);
                    a.draw();
                    break;
                case 'g':
                    a.rotate(-5, a.getMid(), 'x');
                    setbkcolor(0);
                    a.draw();
                    break;
                case 'v':
                    a.rotate(5, a.getMid(), 'y');
                    setbkcolor(0);
                    a.draw();
                    break;
                case 'b':
                    a.rotate(-5, a.getMid(), 'y');
                    setbkcolor(0);
                    a.draw();
                    break;
            }
        }
    }
    closegraph();
    return 0;
}
