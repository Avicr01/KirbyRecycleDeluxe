#pragma once
#include "Kirby.h"
#include "Basura.h"
#include <vector>
using namespace std;

class Nivel
{
private:
	bool esFin;
	bool esGanador;
	int contador;
	bool rapidez;
	time_t time_init_app;
	time_t time_rapidez;
	Kirby* objK;
	vector<Base*> arrB;
public:
	Nivel();
	~Nivel();
	void Dezplazar(dir mover);
	// El virtual de Kirby puede que cambie
	virtual bool Colision_Enemigos();
	virtual bool Colision_PowerUp();
	bool Colision_Basura();
	virtual void Dibujar_Kirby(Graphics^ g, Bitmap^ bmp);
	virtual void Dibujar_Enemigos(Graphics^ g, Bitmap^ bmp);
	virtual void Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp);
	void Dibujar_Basura(Graphics^ g, Bitmap^ bmp);
	bool getFin();
	bool getTiempo();
	int getVidas();
	void Resumen(Graphics^ g);
};
