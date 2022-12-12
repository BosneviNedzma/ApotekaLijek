#include "Lijek.h"
Lijek::Lijek() {
	strcpy(this.ime, "Novi");
	strcpy(this->proizvodjac, "Farmacija");
	this->jacina = 100;
	this->cijena = 1;
	this->vrsta = Vrsta::bezRecepta;
}

Lijek::Lijek(const Lijek& lijek) {
	strcpy(this->ime, lijek.ime);
	strcpy(this->proizvodjac, lijek.proizvodjac);
	this->cijena = lijek.cijena;
	this->jacina = lijek.jacina;
	this->vrsta = lijek.vrsta;
}

void Lijek::setIme() {
	cout << "Unesite ime lijeka: \n";
	cin.getline(this->ime, 50);
}

char* Lijek::getIme() {
	return this->ime;
}

void Lijek::setProizvodjac() {
	cout << "Unesite naziv proizvodjaca: \n";
	cin.getline(this->proizvodjac, 80);
}

char* Lijek::getProizvodjac() {
	return this->proizvodjac;
}

void Lijek::setJacina() {
	cout << "Unesite jacinu: \n";
	cin >> this->jacina;
	cin.ignore();
}

int Lijek::getJacina() {
	return this->jacina;
}

void Lijek::setCijena() {
	cout << "Unesite cijenu: \n";
	cin >> this->cijena;
	cin.ignore();
}

float Lijek::getCijena() {
	return this->cijena;
}

void Lijek::promijeniVrstu() {
	cout << "Promijenite vrstu 1 za bez recepta i 2 za sa receptom: \n";
	int broj;
	cin >> broj;
	if (broj == 1) {
		this->vrsta = Vrsta::bezRecepta;
	}

	if (broj == 2) {
		this->vrsta = Vrsta::saReceptom;
	}
	cin.ignore();
}

Vrsta Lijek::getVrsta() {
	return this->vrsta;
}
string Lijek::nazivVrste() {
	switch (this->getVrsta()) {
	case Vrsta::bezRecepta:
		return "Bez recepta";
	case Vrsta::saReceptom:
		return "Sa receptom";
	default:
		return "Nepoznata vrsta";
	}
}
istream& operator>>(istream& stream, Lijek& lijek) {
	lijek.setIme();
	lijek.setProizvodjac();
	lijek.setJacina();
	lijek.setCijena();
	lijek.promijeniVrstu();
	return stream;
 }
ostream& operator<<(ostream& stream, Lijek& lijek) {
	string vrsta = lijek.getVrsta() == Vrsta::bezRecepta ? "Bez recepta" : "Sa receptom";
	stream << "Lijek: " << lijek.getIme() << endl;
	stream << "Proizvodjac: " << lijek.getProizvodjac << endl;
	stream << "Jacina: " << lijek.getJacina() << endl;
	stream << "Cijena: " << lijek.getCijena() << endl;
	stream << "Vrsta: " << lijek.getVrsta() << endl;
	return stream;
 }