#pragma once
#include "Pulpo.h"
#include "Pez.h"
#include "Nivel.h"
#include <vector>
using namespace std;
class Costa:
    public Nivel
{
private:
    Pulpo* objP;
    vector<Base*> arrPz;
public:
    Costa();
    ~Costa();
};

