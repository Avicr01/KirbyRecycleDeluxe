#include "Selva.h"
Selva::Selva() : Nivel() {
	int tmp = rand() % 4 + 1;
	for (int i = 0; i < tmp; i++)
		arrPir.push_back(new Pirana(rand() % 500 + 80, rand() % 200 + 20, 200, 200));
	tmp = rand() % 4 + 1;
	for (int i = 0; i < tmp; i++)
		arrAna.push_back(new Anaconda(rand() % 500 + 80, rand() % 200 + 20, 200, 200));
	tmp = rand() % 4 + 1;
	for (int i = 0; i < tmp; i++)
		arrAr.push_back(new Arana(rand() % 500 + 80, rand() % 200 + 20, 200, 200));
	for (int i = 0; i < 3; i++)
		arrFr.push_back(new Fruta(rand() % 500 + 80, rand() % 200 + 20, 200, 200));
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
