#include "Selva.h"
Selva::Selva() : Nivel() {
	int tmp = rand() % 4 + 1;
	for (int i = 0; i < tmp; i++)
		arrPir.push_back(new Pirana(rand() % 1400, rand() % 10 + 740, 200, 200));
	tmp = rand() % 4 + 1;
	for (int i = 0; i < tmp; i++)
		arrAna.push_back(new Anaconda(rand() % 1400, rand() % 200 + 20, 200, 200));
	tmp = rand() % 4 + 1;
	for (int i = 0; i < tmp; i++)
		arrAr.push_back(new Arana(rand() % 1400, rand() % 200 + 20, 200, 200));
	for (int i = 0; i < 3; i++)
		arrFr.push_back(new Fruta(rand() % 1400, rand() % 300 + 20, 200, 200));
}
Selva::~Selva() {
	for (int i = 0; i < arrPir.size(); i++)
		delete arrPir.at(i);
	for (int i = 0; i < arrAna.size(); i++)
		delete arrAna.at(i);
	for (int i = 0; i < arrAr.size(); i++)
		delete arrAr.at(i);
	for (int i = 0; i < arrFr.size(); i++)
		delete arrFr.at(i);
}
bool Selva::Colision_Enemigos() {
	bool resultado = false;
	Rectangle r1 = objK->getRectangle();

	// Anaconda 
	for (int i = 0; !resultado && i < arrAna.size(); i++) {
		Rectangle r2 = arrAna.at(i)->getRectangle();

		if (r1.IntersectsWith(r2)) {
			resultado = true;
			// Menos vidas de Kirby
			objK->setVidas();
			// Kirby vuelve a la esquina superior izquierda
			objK->setX(20);
			objK->setY(20);
		}
	}
	// Arana
	for (int i = 0; !resultado && i < arrAr.size(); i++) {
		Rectangle r2 = arrAr.at(i)->getRectangle();

		if (r1.IntersectsWith(r2)) {
			resultado = true;
			// Menos vidas de Kirby
			objK->setVidas();
			// Kirby vuelve a la esquina superior izquierda
			objK->setX(20);
			objK->setY(20);
		}
	}
	// Pirana
	for (int i = 0; !resultado && i < arrPir.size(); i++) {
		Rectangle r2 = arrPir.at(i)->getRectangle();

		if (r1.IntersectsWith(r2)) {
			resultado = true;
			// Menos vidas de Kirby
			objK->setVidas();
			// Kirby vuelve a la esquina superior izquierda
			objK->setX(20);
			objK->setY(20);
		}
	}
	return resultado;
}
bool Selva::Colision_PowerUp() {
	// Fruta
	bool resultado = false;
	Rectangle r1 = objK->getRectangle();

	for (int i = 0; !resultado && i < arrFr.size(); i++) {
		Rectangle r2 = arrFr.at(i)->getRectangle();

		if (r1.IntersectsWith(r2)) {
			resultado = true;
			arrFr.at(i)->setEliminar(true);
			// Empieza la velocidad
			time_rapidez = time(0);
			rapidez = true;
			objK->setFracMovX(2);
			objK->setFracMovY(2);
		}
	}
	return resultado;
}
void Selva::Dibujar_Kirby(Graphics^ g, Bitmap^ bmp) {
	// Kirby Volando
	objK->Dibujar_Imagen(g, bmp);
	Colision_Basura();
	Colision_Enemigos();
	Colision_PowerUp();

	// Previa direccion
	if (rapidez) {
		if (difftime(time(0), time_rapidez) > 5)
			rapidez = false;
			objK->setFracMovX(4);
			objK->setFracMovY(4);
	}
	objK->Mover(g);

	if (objK->getVidas() == 0)
		esFin = true;
	if (contador == 30) {
		esFin = true;
		// Hacer que pase el otro nivel
	}
}
void Selva::Dibujar_Enemigos(Graphics^ g, Bitmap^ bmpAna, Bitmap^ bmpAr, Bitmap^ bmpPir) {
	// Anaconda 
	for (int i = 0; i < arrAna.size(); i++) {
		if (arrAna.at(i)->getdY() + arrAna.at(i)->getY() > 700)
			arrAna.at(i)->setEliminar(true);
		if (arrAna.at(i)->getEliminar())
			arrAna.erase(arrAna.begin() + i);
	}
	for (int i = 0; i < arrAna.size(); i++) {
		arrAna.at(i)->Dibujar_Imagen(g, bmpAna);
		arrAna.at(i)->Mover(g);
	}
	// Arana 
	for (int i = 0; i < arrAr.size(); i++) {
		if (arrAr.at(i)->getdY() + arrAr.at(i)->getY() > 700)
			arrAr.at(i)->setEliminar(true);
		if (arrAr.at(i)->getEliminar())
			arrAr.erase(arrAr.begin() + i);
	}
	for (int i = 0; i < arrAr.size(); i++) {
		arrAr.at(i)->Dibujar_Imagen(g, bmpAr);
		arrAr.at(i)->Mover(g);
	}
	// Pirana 
	for (int i = 0; i < arrPir.size(); i++) {
		if (arrPir.at(i)->getX() + arrPir.at(i)->getdX() < 0)
			arrPir.at(i)->setFil(1);
		if (arrPir.at(i)->getX() + arrPir.at(i)->getdX() > 1530 - arrPir.at(i)->getW())
			arrPir.at(i)->setFil(0);
		arrPir.at(i)->Dibujar_Imagen(g, bmpPir);
		arrPir.at(i)->Mover(g);
	}
		
}
void Selva::Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp) {
	// Fruta
	for (int i = 0; i < arrFr.size(); i++) {
		arrFr.at(i)->Dibujar_Imagen(g, bmp);

		if (arrFr.at(i)->getEliminar())
			arrFr.erase(arrFr.begin() + i);
	}
}
