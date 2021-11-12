#pragma once
#include <iostream>
using namespace System::Drawing;
public enum dir { up, down, left, right, none };
class Base
{
protected:
	int x, y, w, h, dx, dy;
	bool eliminar;
	int max_fil, max_col, fil, col; // Sprites
	dir direc;
	dir hor_direc;
	int fracMovY, fracMovX;
	int color;
	bool nada;
public:
	Base();
	Base(int _x, int _y, int _w, int _h);
	Base(int _x, int _y, int _w, int _h, int _max_fil, int _max_col, int _fil, int _col);
	~Base();
	int getX();
	int getY();
	int getdX();
	int getdY();
	int getW();
	int getH();
	int getFil();
	int getCol();
	int getMaxFil();
	int getMaxCol();
	int getFracMovY();
	int getFracMovX();
	bool getEliminar();
	void setX(int n);
	void setY(int n);
	void setdX(int n);
	void setdY(int n);
	void setW(int n);
	void setH(int n);
	void setFil(int n);
	void setCol(int n);
	void setMaxFil(int n);
	void setMaxCol(int n);
	void setFracMovX(int n);
	void setFracMovY(int n);
	void setEliminar(bool n);
	Rectangle getRectangle();
	virtual void Mover(Graphics^ g);
	void Dibujar(Graphics^ g, Bitmap^ bmp);
	void Borrar(Graphics^ g);
	void Dibujar_Imagen(Graphics^ g, Bitmap^ bmp);
	int getColor();
	// Desplazar - Kirby nada
	void Nadar(dir n);
	// Desplazar - Kirby vuela
	void Volar(dir n);
	void setNada();
};