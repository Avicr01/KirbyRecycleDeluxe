#include "Pirana.h"

Pirana::Pirana() { }
Pirana::Pirana(int _x, int _y, int _w, int _h)
	:Base(_x, _y, _w, _h, 2, 7, 0, 0) {
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
Pirana::~Pirana() { }
void Pirana::Mover(Graphics^ g) {

	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) {
		dx = dx * -1;
	}
	if (dx > 0)
		Desplazar(right);
	if (dx < 0)
		Desplazar(left);
	x += dx;
}
