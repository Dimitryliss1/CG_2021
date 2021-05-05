//
// Created by Павел Жуков on 12.11.2020.
//

#include <graphics.h>
#include "matrix.h"
#include "line.h"
#include "pyramid.h"
#include <iostream>

using namespace std;

int main() {
    int gd = DETECT, gm;
    initwindow(800, 600);
    sdlbgiauto();
    Pyramid a(300, 400, 100,
              500, 400, 100,
              400, 400, 300,
              400, 200, 166);
    Pyramid b(300, 400, 100,
              500, 400, 100,
              400, 400, 300,
              400, 200, 166);
    float **zBuf = new float *[getmaxy() + 1];
    int **frameBuf = new int *[getmaxy() + 1];
    float tmpZ = max(a.getMaxZ(), b.getMaxZ());
    for (int i = 0; i < getmaxy() + 1; i++) {
        frameBuf[i] = new int[getmaxx() + 1];
        zBuf[i] = new float[getmaxx() + 1];
        for (int j = 0; j < getmaxx() + 1; j++) {
            frameBuf[i][j] = 0;
            zBuf[i][j] = tmpZ * 10;
        }
    }

    a.draw(zBuf, frameBuf);
    b.draw(zBuf, frameBuf);

    for (int i = 0; i < getmaxy() + 1; i++) {
        frameBuf[i] = new int[getmaxx() + 1];
        zBuf[i] = new float[getmaxx() + 1];
        for (int j = 0; j < getmaxx() + 1; j++) {
            frameBuf[i][j] = 0;
            zBuf[i][j] = tmpZ * 10;
        }
    }
    cout << "Done building";
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
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 'd':
                    a.move(5, 0, 0);
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 'w':
                    a.move(0, -5, 0);
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 's':
                    a.move(0, 5, 0);
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 'q':
                    a.move(0, 0, -5);
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 'e':
                    a.move(0, 0, 5);
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 'z':
                    a.scale(0.95, a.getMid());
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 'c':
                    a.scale(1.05, a.getMid());
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 'r':
                    a.rotate(-5, a.getMid(), 'z');
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 't':
                    a.rotate(5, a.getMid(), 'z');
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 'f':
                    a.rotate(5, a.getMid(), 'x');
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 'g':
                    a.rotate(-5, a.getMid(), 'x');
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 'v':
                    a.rotate(5, a.getMid(), 'y');
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
                case 'b':
                    a.rotate(-5, a.getMid(), 'y');
                    setbkcolor(0);
                    a.draw(zBuf, frameBuf);
                    b.draw(zBuf, frameBuf);
                    break;
            }
            tmpZ = max(a.getMaxZ(), b.getMaxZ());
            for (int i = 0; i < getmaxy() + 1; i++){
                for (int j = 0; j < getmaxx() + 1; j++){
                    zBuf[i][j] = tmpZ * 10;
                    frameBuf[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < getmaxy() + 1; i++){
        delete [] zBuf[i];
        delete [] frameBuf[i];
    }
    delete [] zBuf;
    delete [] frameBuf;
    closegraph();
    return 0;
}
