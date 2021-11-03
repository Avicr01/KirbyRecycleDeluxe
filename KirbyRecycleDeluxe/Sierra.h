#pragma once
#include "Nivel.h"
#include "Condor.h"
#include "Granizo.h"
#include "Cushuro.h"
#include <vector>
using namespace std;
class Sierra :
    public Nivel
{
private:
    Condor* objC;
    vector<Base*> arrGr;
    vector<Base*> arrCsh;
public:
};

