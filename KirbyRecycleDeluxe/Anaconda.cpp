#include "Anaconda.h"

Anaconda::Anaconda() { }
Anaconda::Anaconda(int _x, int _y, int _w, int _h)
	:Base(_x, _y, _w, _h, 1, 6, 0, 0) {
	dy = 15;
}
Anaconda::~Anaconda() { }
