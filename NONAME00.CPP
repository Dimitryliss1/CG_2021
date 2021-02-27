//#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include "library.h"

void bLine(int x0, int y0, int x1, int y1){
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy)/2;
	int e2 = err;
	for(;;){
		putpixel(x0, y0, 15);
		if (x0 == x1 && y0 == y1) break;
		e2 = err;
		if (e2 > -dx) {err -= dy; x0 += sx;}
		if (e2 < dy) {err += dx; y0 += sy;}
	}
}
int main(){

	int gd = DETECT, gm;
  initgraph (&gd, &gm, "");
	sdlbgiauto();
	getch();
	for (int i = 0; i < getmaxy(); i++){
		bLine(0, i, getmaxx(), getmaxy() - i);
		delay(5);
	}
	getch();
	closegraph();
	return 0;
}
