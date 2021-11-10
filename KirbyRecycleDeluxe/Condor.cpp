#include "Condor.h"
Condor::Condor() { }
Condor::Condor(int _x, int _y, int _w, int _h) 
	: Base(_x, _y, _w, _h, 2, 16, 0, 0) {
	System::Random^ r = gcnew System::Random();
	dx = -r->Next(30, 45);
	delete r;
}
void Condor::Mover(Graphics^ g) { 
	if (x + dx < 1 || x + dx + w > g->VisibleClipBounds.Width) {
		dx *= -1;

		if (dx > 0)
			fil = 1;
		else
			fil = 0;
	}
	x += dx;
}
Condor::~Condor() { }
