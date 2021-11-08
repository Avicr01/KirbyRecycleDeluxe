#include "Basura.h"
Basura::Basura() { }
Basura::Basura(int _x, int _y, int _w, int _h)
	:Base(_x, _y, _w, _h, 7, 1, 0, 0) {
	int tmp = rand() % 7;
	fil = tmp;
}
Basura::~Basura() { }
