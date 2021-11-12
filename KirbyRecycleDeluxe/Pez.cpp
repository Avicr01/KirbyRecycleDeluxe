#include "Pez.h"
Pez::Pez() { }
Pez::Pez(int _x, int _y, int _h, int _w): Base(_x, _y, _h, _w, 2, 1, 0, 0) { 
	des_pow = time(0);
	int a = rand() % 2;
	if (a == 0) {
		Desplazar(right);
		dx = 20;
	}
	if (a == 1) {
		Desplazar(left);
		dx = -20;
	}
}
Pez::~Pez() { }
void Pez::Mover(Graphics^ g) {
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) {
		dx = dx * -1;
	}
	if (dx > 0)
		Desplazar(right);
	if (dx < 0)
		Desplazar(left);
	x += dx;
}
