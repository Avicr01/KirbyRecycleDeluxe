#pragma once
#include "Nivel.h"
#include "Pirana.h" 
#include "Anaconda.h"
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
};
