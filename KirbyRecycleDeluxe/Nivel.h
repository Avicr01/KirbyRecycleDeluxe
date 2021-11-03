#pragma once
#include "Kirby.h"
#include "Basura.h"

class Nivel
{
public:
	bool esFin;
	int contador;
	bool rapidez;
	time_t time_init_app;
	time_t time_rapidez;
	Kirby* objK;
	vector<Base*> arrB;
private:
	Nivel();
	~Nivel();
	void Dezplazar(dir mover);
	bool Colision_Enemigos();
	bool Colision_PowerUp();
	void Dibujar_Kirby(Graphics^ g, Bitmap^ bmp);
	virtual void Dibujar_Enemigos(Graphics^ g, Bitmap^ bmp);
	virtual void Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp);
	bool getFin();
	bool getTiempo();
	int getVidas();
	void Resumen(Graphics^ g);
};
