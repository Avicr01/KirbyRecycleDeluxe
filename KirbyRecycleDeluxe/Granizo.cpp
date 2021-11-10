#include "Granizo.h"
Granizo::Granizo() {}

Granizo::Granizo(int _x, int _y, int _w, int _h) : Base(_x, _y, _w, _h, 1, 8, 0, 0) {
    System::Random^ r = gcnew System::Random();
    dy = r->Next(3, 10);
    delete r;
}
void Granizo::Mover(Graphics^ g) {
    if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height) {
        dy = 0;
        setEliminar(true);
    }
    y += dy;
}
Granizo::~Granizo() {}
