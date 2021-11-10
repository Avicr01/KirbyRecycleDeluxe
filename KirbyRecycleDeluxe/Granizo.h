#pragma once
#include "Base.h"
class Granizo :
    public Base
{
public:
    Granizo();
    Granizo(int _x, int _y, int _w, int _h);
    void Mover(Graphics^ g);
    ~Granizo();
};
