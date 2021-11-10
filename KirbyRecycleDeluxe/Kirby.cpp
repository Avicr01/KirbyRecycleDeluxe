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
void Kirby::Mover(Graphics^ g) {
	if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height)
		dy = 0;
	if (x + dx < 1 || x + dx + w > g->VisibleClipBounds.Width)
		dx = 0;

	y += dy;
	x += dx;
}
void Kirby::Dibujar_Congelado(Graphics^ g, Bitmap^ bmp) {
	// Imagen animada
	w = bmp->Width / 1;
	h = bmp->Height / 3;
	Rectangle porcion = Rectangle(0 * w, 1 * h, w, h);
	Rectangle zoom = Rectangle(x, y, w * 1.2, h * 1.2);

	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
}
