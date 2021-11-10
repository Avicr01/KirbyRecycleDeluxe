#pragma once
#include "Nivel.h"
#include "Pirana.h" 
#include "Anaconda.h"
#include "Arana.h"
#include "Fruta.h"
#include <vector>
using namespace std;
class Selva :
    public Nivel 
{
private:
    vector<Base*> arrPir;
    vector<Base*> arrAna;
    vector<Base*> arrAr;
    vector<Base*> arrFr;
public:
    Selva();
    ~Selva();
    bool Colision_Enemigos();
    bool Colision_PowerUp();
    void Dibujar_Kirby(Graphics^ g, Bitmap^ bmp);
    void Dibujar_Enemigos(Graphics^ g, Bitmap^ bmpAna, Bitmap^ bmpAr, Bitmap^ bmpPir);
    void Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp);
    void Insertar_Enemigos();
};
