#include "Pez.h"
Pez::Pez() { }
Pez::Pez(int _x, int _y, int _h, int _w): Base(_x, _y, _h, _w, 1, 2, 0, 0) { 
	dx = rand() % 5 + 20;
}
Pez::~Pez() { }
void Pez::Mover(Graphics^ g) {
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width)	
		dx = dx * -1;
	x += dx;
}
