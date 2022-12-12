#include <iostream>
#include "Apoteka.h"
#include "Lijek.h"

using namespace std;

int main() {


	cout << "Aplikacija za apoteku\n";

	Apoteka apoteka;
	int izbor;

	do {
		auto cijenaOd = make_shared<float>();
		auto cijenaDo = make_shared<float>();
		try {
			system("cls");
			cout << "Apoteka: " << apoteka.getIme() << endl;
			cout << "\t1. Unos lijeka\n";
			cout << "\t2. Pregled lijekova\n";
			cout << "\t3. Pretrazivanje lijekova\n";
			cout << "\t4. Ispis lijekova uslov\n";
			cout << "\t5. Povecaj popust\n";
			cout << "\t6. Brisanje lijeka\n";
			cout << "\t7. Kraj\n";
			cout << "\t\tIzbor: ";
			cin >> izbor;
			cin.ignore();
			system("cls");
			switch (izbor) {
			case 1:
				apoteka.setLijek();
				break;
			case 2:
				!apoteka;
				break;
			case 3:
				char pretraga[50];
				cout << "Unesi proizvodjaca:\n";
				cin.getline(pretraga, 50);
				apoteka.pretragaLijeka(pretraga);
				break;
			case 4:
				cout << "Unesite cijene\n";
				cout << "Cijena od: ";
				cin >> *cijenaOd;
				cout << "Cijena do: ";
				cin >> *cijenaDo;
				apoteka.ispisLijekovaUslov(*cijenaOd, *cijenaDo);
				break;
			case 5:
				apoteka++;
				break;
			case 6:
				apoteka.izbrisiLijek();
				break;
			case 7:
				cout << "Hvala i dovidjenja!";
				break;
			}
		}
		catch (const char* Greska) {
			cout << "[GRESKA] " << Greska << endl;
		}
	} while (izbor != 7);


}