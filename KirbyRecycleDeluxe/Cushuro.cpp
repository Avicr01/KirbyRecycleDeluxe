#include "Cushuro.h"
Cushuro::Cushuro() { }
Cushuro::Cushuro(int _x, int _y, int _w, int _h) : Base(_x, _y, _w, _h) {
    System::Random^ r = gcnew System::Random();
    dy = r->Next(3, 10);
    delete r;
}
Cushuro::~Cushuro() { }
