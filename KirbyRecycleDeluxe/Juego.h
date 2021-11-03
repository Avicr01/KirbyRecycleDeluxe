#pragma once
#include "Costa.h"
#include "Sierra.h"
#include "Selva.h"
class Juego
{
private:
	Costa* nvCosta;
	Sierra* nvSierra;
	Selva* nvSelva;
public:
	Juego();
	~Juego();
};

