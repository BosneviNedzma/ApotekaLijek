#pragma once
#include <iostream>

using namespace std;

enum class Vrsta{ bezRecepta=1, saReceptom};

class Lijek {
private:
	char ime[50], proizvodjac[80];
	int jacina;
	float cijena;
	Vrsta vrsta;

public:
	Lijek();
	Lijek(const Lijek&);
	void setIme();
	void setProizvodjac();
	void setJacina();
	void setCijena();
	void promijeniVrstu();
	char* getIme();
	char* getProizvodjac();
	int getJacina();
	float getCijena();
	Vrsta getVrsta();
	string nazivVrste();
	friend istream& operator>>(istream& stream, Lijek& lijek);
	friend ostream& operator<<(ostream& stream, Lijek& lijek);
	~Lijek() = default;


};
