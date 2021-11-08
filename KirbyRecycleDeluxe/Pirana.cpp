#include "Pirana.h"

Pirana::Pirana() { }
Pirana::Pirana(int _x, int _y, int _w, int _h)
	:Base(_x, _y, _w, _h, 2, 7, 0, 0) {
	// Por mientras va a la izquierda nomas
	dx = -15;
}
Pirana::~Pirana() { }
