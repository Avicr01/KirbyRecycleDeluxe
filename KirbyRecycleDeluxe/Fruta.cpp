#include "Fruta.h"
Fruta::Fruta() { }
Fruta::Fruta(int _x, int _y, int _w, int _h)
	:Base(_x, _y, _w, _h, 5, 1, 0, 0) {
	int tmp = rand() % 5;
	fil = tmp;
}
Fruta::~Fruta() { }
