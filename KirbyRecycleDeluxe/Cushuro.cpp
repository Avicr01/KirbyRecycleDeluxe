#include "Cushuro.h"
Cushuro::Cushuro() { }
Cushuro::Cushuro(int _x, int _y, int _w, int _h) : Base(_x, _y, _w, _h) {
    System::Random^ r = gcnew System::Random();
    dy = r->Next(3, 10);
    delete r;
}
Cushuro::~Cushuro() { }
void Cushuro::Mover(Graphics^ g) {
    if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height) {
        dy = 0;
        setEliminar(true);
    }
    y += dy;
}
