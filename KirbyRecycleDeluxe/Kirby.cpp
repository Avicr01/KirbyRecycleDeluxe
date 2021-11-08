#include "Kirby.h"

Kirby::Kirby() { }
Kirby::Kirby(int _x, int _y, int _w, int _h)
	:Base(_x, _y, _w, _h, 4, 2, 0, 0) {
	direc = dir::down;
	vidas = 3;
	fracMovX = 4;
	fracMovY = 4;
	dy = y / fracMovY;
	dx = 0;
	dir hor_dir = dir::right;
}
Kirby::~Kirby() { }
int Kirby::getVidas() { return vidas; }
void Kirby::setVidas() { vidas -= 1; }
