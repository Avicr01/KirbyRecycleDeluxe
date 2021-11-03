#pragma once
#include "Base.h"
class Kirby :
    public Base
{
private:
    int vidas;
public:
    Kirby();
    Kirby(int _x, int _y, int _w, int _h);
    ~Kirby();
    int getVidas();
    void setVidas();
};
