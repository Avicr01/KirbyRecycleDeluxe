#include "Arana.h"

Arana::Arana() { }
Arana::Arana(int _x, int _y, int _w, int _h)
	:Base(_x, _y, _w, _h, 1, 4, 0, 0) {
	dy = 15;
}
Arana::~Arana() { }
