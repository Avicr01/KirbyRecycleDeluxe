#include "Nivel.h"
Nivel::Nivel() {
	esGanador = false;
	esFin = false;
	rapidez = false;
	contador = 0;
	objK = new Kirby(20, 20, 1, 1);
	// La cantidad de Basura puede cambiar despues 
	for (int i = 0; i < 8; i++)
		arrB.push_back(new Basura(rand() % 500 + 80, rand() % 200 + 20, 200, 200));
}
Nivel::~Nivel() {
	delete objK;
	for (int i = 0; i < arrB.size(); i++)
		delete arrB.at(i);
}
void Nivel::Dezplazar(dir mover) {
	objK->Desplazar(mover);
}
bool Nivel::getFin() {
	return esFin;
}
bool Nivel::getTiempo() {
	return int(difftime(time(0), time_init_app));
}
int Nivel::getVidas() {
	return objK->getVidas();
}
void Nivel::Resumen(Graphics^ g) {
	g->Clear(Color::Black);
	Font^ miFont = gcnew Font("Arial", 22);
	SolidBrush^ miBack = gcnew SolidBrush(Color::Bisque);
	int tmp = getTiempo();
	if (esGanador)
		g->DrawString("Completaste el nivel con un tiempo de " + tmp + " segundos", miFont, miBack,
			g->VisibleClipBounds.Width / 4, g->VisibleClipBounds.Height / 2);
	else
		g->DrawString("PERDISTE con un tiempo de " + tmp + " segundos", miFont, miBack,
			g->VisibleClipBounds.Width / 4, g->VisibleClipBounds.Height / 2);
}
bool Nivel::Colision_Basura() {
	bool resultado = false;
	Rectangle r1 = objK->getRectangle();

	for (int i = 0; !resultado && i < arrB.size(); i++) {
		Rectangle r2 = arrB.at(i)->getRectangle();

		if (r1.IntersectsWith(r2)) {
			resultado = true;
			arrB.at(i)->setEliminar(true);
			contador++;
		}
	}
	return resultado;
}
void Nivel::Dibujar_Basura(Graphics^ g, Bitmap^ bmp) {
	for (int i = 0; i < arrB.size(); i++) {
		arrB.at(i)->Dibujar_Imagen(g, bmp);

		if (arrB.at(i)->getEliminar())
			arrB.erase(arrB.begin() + i);
	}
}
// Modulos Virtuales
bool Nivel::Colision_Enemigos() { }
bool Nivel::Colision_PowerUp() { }
void Nivel::Dibujar_Kirby(Graphics^ g, Bitmap^ bmp) { }
void Nivel::Dibujar_Enemigos(Graphics^ g, Bitmap^ bmp) { }
void Nivel::Dibujar_PowerUp(Graphics^ g, Bitmap^ bmp) { }
