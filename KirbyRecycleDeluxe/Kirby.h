#pragma once
#include "Base.h"
class Kirby :
    public Base
{
private:
    int vidas;
	dir hor_dir;
public:
    Kirby();
    Kirby(int _x, int _y, int _w, int _h);
    void Mover(Graphics^ g);
    ~Kirby();
    int getVidas();
    void setVidas();
    void Dibujar_Congelado(Graphics^ g, Bitmap^ bmp);
};
