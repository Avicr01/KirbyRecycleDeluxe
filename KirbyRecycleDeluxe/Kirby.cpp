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
void Kirby::Volar(dir n) {
	if (direc == dir::left)
		hor_dir = direc;
	if (direc == dir::right)
		hor_dir = direc;
	direc = n;
	dx = dy = 0;
	// Tener cuidado a que fila pertenece que
	// Cambiar fila si es que es para otra cosa
	if (direc == dir::up) {
		if(hor_dir == dir::left)
			fil = 3;
		else
			fil = 2;
		dy = -(h / fracMovY);
	}
	if (direc == dir::down) {
		if (hor_dir == dir::left)
			fil = 1;
		else
			fil = 0;
		dy = (2 * h / fracMovY);
	}
	if (direc == dir::left) {
		dx = -(w / fracMovX);
		dy = (h / fracMovY);
		fil = 1;
	}
	if (direc == dir::right) {
		dx = (w / fracMovX);
		dy = (h / fracMovY);
		fil = 0;
	}
}
void Kirby::Mover(Graphics^ g) {
	if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height)
		dy = 0;
	if (x + dx < 1 || x + dx + w > g->VisibleClipBounds.Width)
		dx = 0;

	y += dy;
	x += dx;
}
