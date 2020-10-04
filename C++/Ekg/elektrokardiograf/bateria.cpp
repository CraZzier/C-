#include "bateria.h"

Bateria::Bateria() {
	pojemnosc = 1000;
	cena = 3;
	napiecie = 1.5;
	producent = "Energizer";
#ifdef _DEBUG
	cout << "DEBUG! - Konstruktor bez parametrow Bateria" << endl;
#endif
}

ostream & operator<< (ostream &wyjscie, const Bateria &s) {
	return wyjscie <<
		"Pojemnosc: " << s.pojemnosc << endl <<
		"Cena: " << s.cena << endl <<
		"Napiecie: " << s.napiecie << endl <<
		"Marka: " << s.producent << endl;
}

void Bateria::zdefiniuj_baterie(int p, int cen, double nap, string pro)
{
	pojemnosc = p;
	cena = cen;
	napiecie = nap;
	producent = pro;
}

Bateria::~Bateria() {
#ifdef _DEBUG
	cout << "DEBUG! - Destruktor bez parametrow Bateria" << endl;
#endif
}

void Bateria::zapisz_do_pliku(string s,int zapis) {
	ofstream strim;
	if (zapis == 0)
		strim.open(s, ios::out);
	if (zapis == 1)
		strim.open(s, ios::app);
	if (strim.good() == true) {
		strim << "Bateria:" << endl;
		strim << pojemnosc << endl;
		strim << cena << endl;
		strim << napiecie << endl;
		strim << producent << endl;
		cout << "zapisywanie powiodlo sie" << endl;
	}
	else {
		cout << "blad otwierania pliku" << endl;
	}
	strim.close();

}

void Bateria::odczyt_z_pliku(string s) {
	ifstream strim;
	strim.open(s, ios::in);
	if (strim.good() == true) {
		strim >> pojemnosc;
		strim >> cena;
		strim >> napiecie;
		strim.ignore();
		getline(strim, producent);
		cout << "czytanie z plku powiod³o siê" << endl;
	}
	else {
		cout << "Czytanie z pliku nie powiod³o siê" << endl;
	}
	strim.close();
}
void Bateria::operator<<(string s) {
	this->zapisz_do_pliku(s, 0);
}
void Bateria::operator>>(string s) {
	this->odczyt_z_pliku(s);
}
