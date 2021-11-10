#include "Juego.h"
Juego::Juego() {
	// Test de nivel selva
	nivel = 2;
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
void Juego::Jugar_Sierra(Graphics^ g, Bitmap^ bmpCushuro, Bitmap^ bmpGranizo,
	Bitmap^ bmpCondor, Bitmap^ bmpKirbyVuela, Bitmap^ bmpKirbyCong, Bitmap^ bmpBasura) {
	nvSierra->Dibujar_Kirby(g, bmpKirbyVuela, bmpKirbyCong);
	nvSierra->Dibujar_Basura(g, bmpBasura);
	nvSierra->Dibujar_PowerUp(g, bmpCushuro);
	nvSierra->Dibujar_Enemigos(g, bmpGranizo, bmpCondor);
	nvSierra->Insertar_Basura();
	nvSierra->Insertar_PowerUp(g, bmpCushuro);
	nvSierra->Insertar_Enemigos();
}
void Juego::Jugar_Selva(Graphics^ g,
	Bitmap^ bmpFruta, Bitmap^ bmpAnaconda, Bitmap^ bmpArana, 
	Bitmap^ bmpPirana, Bitmap^ bmpKirbyVuela, Bitmap^ bmpBasura) {
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
	int n = 0;
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
	int n = 0;
	if (nivel == 1)
		n = nvCosta->getContador();
	if (nivel == 2)
		n = nvSierra->getContador();
	if (nivel == 3)
		n = nvSelva->getContador();
	return n;
}
bool Juego::getFin() {
	bool n = false;
	if (nivel == 1)
		n = nvCosta->getFin();
	if (nivel == 2)
		n = nvSierra->getFin();
	if (nivel == 3)
		n = nvSelva->getFin();
	return n;
}
bool Juego::getGanador() {
	bool n = false;
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
