#include "Apoteka.h"
#include <cstring>
#include <iomanip>

float Apoteka::pdv = (float)0.17;
float Apoteka::popust = 0;

Apoteka::Apoteka() {
	strcpy(this->ime, "Apotekarna");
}

void Apoteka::setPopust() {
	cout << "Unesite popust:\n";
	int popust;
	cin >> popust;
	if (popust < 1 || popust>90) {
		throw "Nedozvoljeni unos popusta. Popust moze biti od 1 do 90%";
	}

	Apoteka::popust = (float)popust / 100;
}

float Apoteka::getPopust() {
	return Apoteka::popust;
}

void Apoteka::setIme() {
	cout << "Unesite ime apoteke: \n";
	cin.getline(this->ime, 50);
}

void Apoteka::setLijek() {
	Lijek lijek;
	cout << "Dodajte lijek: \n";
	cin >> lijek;
	this->lijekovi.push_back(lijek);
}

char* Apoteka::getIme() {
	return this->ime;
}

vector<Lijek>& Apoteka::getLijekovi() {
	return this->lijekovi;
}

void Apoteka::pretragaLijeka(char* p) {
	shared_ptr<Apoteka>apoteka = make_shared<Apoteka>();
	for (auto& lijek : this->getLijekovi()) {
		if (strcmpi(lijek.getProizvodjac(), p) == 0) {
			apoteka->getLijekovi().push_back(lijek);
		}
	}

	if (apoteka->getLijekovi().size() == 0) {
		cout << "Nema lijekova za uneseni upit";
	}
	else {
		apoteka->ispisiLijekoveOsnovno();
	}
}

void Apoteka::ispisLijekovaUslov(float c1, float c2) {
	shared_ptr<Apoteka>apoteka = make_shared<Apoteka>();
	for (auto& lijek : this->getLijekovi()) {
		if (lijek.getCijena() >= c1 && lijek.getCijena() <= c2) {
			apoteka->getLijekovi().push_back(lijek);
		}
	}
	if (apoteka->getLijekovi().size() == 0) {
		cout << "Nema lijekova u definisanom cjenovnom rangu\n";
	}
	else {
		!*apoteka();
	}
}

void Apoteka::izbrisiLijek() {
	cout << "Izaberi lijek koji zelis izbrisati po rednom broju\n";
	this->ispisiLijekoveOsnovno();
	cout << "Izaberi lijek: \n";
	auto broj = make_shared<int>();
	cin >> *broj;

	if (*broj < 1 || *broj>static_cast<int>(this->getLijekovi().size())) {
		throw "Ne postoji lijek na tom broju";
	}

	this->getLijekovi().erase(this->getLijekovi().begin() + *broj - 1);
}

void Apoteka::ispisiLijekoveOsnovno() {
	int i = 1;
	cout << "R. br\tIme - Proizvodjac\tVrsta\n";
	cout << "---------------------------------\n";
	for (auto& lijek : this->getLijekovi()) {
		cout << i << "\t" << lijek.getIme() << " - " << lijek.getProizvodjac() << "\t";
		cout << lijek.getJacina() << "\t";
		cout << setprecision(2) << this->cijenaBezPDV(lijek) << "\t";
		cout << setprecision(2) << this->cijenaSaPDV(lijek) << endl;
		i++;
	}
}

void Apoteka::operator++(int) {
	if (Apoteka::popust == 0.9) {
		throw "Nije moguce vise povecati popust";
	}

	Apoteka::popust = Apoteka::popust + (float).05;
}
float Apoteka::cijenaBezPDV(Lijek& lijek) {
	float cijenaPopust = lijek.getCijena() * (1 - Apoteka::popust);
	if (lijek.getVrsta() == Vrsta::saReceptom) {
		cijenaPopust = cijenaPopust * (float).5;
	}

	return cijenaPopust;
}

float Apoteka::cijenaSaPDV(Lijek& lijek) {
	float cijenaPopust = this->cijenaBezPDV(lijek);
	float pdvCijene = cijenaPopust * Apoteka::pdv;
	return cijenaPopust + pdvCijene;
}