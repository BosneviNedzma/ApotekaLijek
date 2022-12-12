#pragma once
#include <vector>
#include "Lijek.h"
#include <iostream>

using namespace std;

class Apoteka {
private:
	char ime[50];
	vector<Lijek>lijekovi;
	static float pdv;
	static float popust;
	const static char separator = ' ';
	const static int sirina = 15;
	float cijenaBezPDV(Lijek& lijek);
	float cijenaSaPDV(Lijek& lijek);

public:
	Apoteka();
	static void setPopust();
	static float getPopust();
	void setIme();
	void setLijek();
	char* getIme();
	vector<Lijek>& getLijekovi();
	void pretragaLijeka(char* p);
	void ispisLijekovaUslov(float c1, float c2);
	void ispisiLijekoveOsnovno();
	void izbrisiLijek();
	void operator!();
	void operator++(int);
	~Apoteka() = default;

};