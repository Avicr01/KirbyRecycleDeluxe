#include "Juego.h"
Juego::Juego() {
	// Test de nivel selva
	nivel = 3;
	time_init_app = time(0);
	contador = 0;
	nvCosta = new Costa();
	nvSierra = new Sierra();
	nvSelva = new Selva();
}
Juego::~Juego() {
	delete nvCosta, nvSierra, nvSelva;
}
void Juego::Jugar_Costa() {

}
void Juego::Jugar_Sierra() {
	
}
void Juego::Jugar_Selva(Graphics^ g,
	Bitmap^ bmpFruta, Bitmap^ bmpAnaconda, Bitmap^ bmpArana, Bitmap^ bmpPirana,
	Bitmap^ bmpKirbyVuela, Bitmap^ bmpKirbyNada, Bitmap^ bmpBasura) {
	// Todo esta con lo de selva
	nvSelva->Dibujar_Kirby(g, bmpKirbyVuela);
	nvSelva->Dibujar_Basura(g, bmpBasura);
	nvSelva->Dibujar_PowerUp(g, bmpFruta);
	nvSelva->Dibujar_Enemigos(g, bmpAnaconda, bmpArana, bmpPirana);
	nvSelva->Insertar_Basura();
	nvSelva->Insertar_Enemigos();
}
int Juego::getNivel() {
	return nivel;
}
void Juego::Desplazar(dir mover) {
	if (nivel == 1)
		nvCosta->Desplazar(mover);
	if (nivel == 2)
		nvSierra->Desplazar(mover);
	if (nivel == 3)
		nvSelva->Desplazar(mover);
}
int Juego::getVidas() {
	int n;
	if (nivel == 1)
		n = nvCosta->getVidas();
	if (nivel == 2)
		n = nvSierra->getVidas();
	if (nivel == 3)
		n = nvSelva->getVidas(); 
	return n;
}
int Juego::getTiempo() {
	return int(difftime(time(0), time_init_app));
}
int Juego::getContador() {
	return contador;
}
bool Juego::getFin() {
	bool n;
	if (nivel == 1)
		n = nvCosta->getFin();
	if (nivel == 2)
		n = nvSierra->getFin();
	if (nivel == 3)
		n = nvSelva->getFin();
	return n;
}
bool Juego::getGanador() {
	bool n;
	if (nivel == 1)
		n = nvCosta->getGanador();
	if (nivel == 2)
		n = nvSierra->getGanador();
	if (nivel == 3)
		n = nvSelva->getGanador();
	return n;
}
void Juego::Resumen(Graphics^ g) {
	if (nivel == 1)
		nvCosta->Resumen(g);
	if (nivel == 2)
		nvSierra->Resumen(g);
	if (nivel == 3)
		nvSelva->Resumen(g);
}
void Juego::setNivel() {
	++nivel;
}
