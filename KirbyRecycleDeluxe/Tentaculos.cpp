#include "Tentaculos.h"
Tentaculos::Tentaculos() { }
Tentaculos::~Tentaculos() { }
Tentaculos::Tentaculos(int _x, int _y):Base(_x, _y, 1, 1) {
}
void Tentaculos::Mover(Graphics^ g) {
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) {
		dx = 0;
		setEliminar(true);
	}
	x += dx;
}
