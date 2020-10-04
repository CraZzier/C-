#include "termometr.h"
void Termometr::wlacz() {
	if (dziala == 0) {
		cout << "Termometr uruchomiony" << endl;
		dziala = 1;
	}
	else {
		cout << "Termometr by³ juz wczeœniej uruchmiony" << endl;
	}
}
void Termometr::wylacz() {
	if (dziala == 1) {
		dziala = 0;
		cout << "Termometr wylaczony" << endl;
	}
	else {
		cout << "Termometr by³ juz wczeœniej wy³¹czony" << endl;
	}
}
void Termometr::zrobbadanie() {
	cout << "Mierzenie temperatury: Temperatura wynosi 37 stopni" << endl;
}

Termometr::Termometr() {
	waga = 0.1;
	dziala = 0;
	model = "Siemens M702";
	cena = 10;
	czas_mierzenia = 25;
	dlugosc = 10;
	szerokosc = 2;
}

Termometr::Termometr(int czas, bool  dz, string mod) {
	czas_mierzenia = czas;
	dziala = dz;
	model = mod;
	cena = 10;
	czas_mierzenia = 25;
	dlugosc = 10;
	szerokosc = 2;
}

void Termometr::uzupelnij_dane(int qw, double we, double er, double rt, int a, string c) {
	cena = qw;
	waga = we;
	dlugosc = er;
	szerokosc = rt;
	czas_mierzenia = a;
	model = c;
}
Termometr::~Termometr() {
#ifdef DEBUG
	cout << "Desktruktor Termometru" << endl;
#endif 

}

void Termometr::zapisz_do_pliku(string s,int zapis) {
	ofstream strim;
	if (zapis == 0)
		strim.open(s, ios::out);
	if (zapis == 1)
		strim.open(s, ios::app);
	if (strim.good() == true) {
		strim << czas_mierzenia<< endl;
		strim << dziala << endl;
		strim << model << endl;
		strim << cena << endl;
		strim << waga << endl;
		strim << dlugosc << endl;
		strim << szerokosc << endl;
		cout << "zapis udal sie" << endl;
	}
	else {
		cout << "blad otwierania pliku" << endl;
	}
	strim.close();

}

ostream & operator<< (ostream &wyjscie, const Termometr &s) {
	return wyjscie <<
		"Cena: " << s.cena << endl <<
		"Czas pomiaru: " << s.czas_mierzenia << endl <<
		"Waga: " << s.waga << endl <<
		"Dlugosc: " << s.dlugosc << endl <<
		"Szerokosc: " << s.szerokosc << endl <<
		"Model: " << s.model << endl;
}

void Termometr::odczyt_z_pliku(string s) {
	ifstream strim;
	strim.open(s, ios::in);
	if (strim.good() == true) {
		strim >> czas_mierzenia;
		strim >> dziala;
		strim.ignore();
		getline(strim, model);
		strim >> cena;
		strim >> waga;
		strim >> dlugosc;
		strim >> szerokosc;
		cout << "wczytanie powiod³o sie" << endl;
	}
	else {
		cout << "Czytanie z pliku nie powiod³o siê" << endl;
	}
	strim.close();
}

void Termometr::operator<<(string s) {
	this->zapisz_do_pliku(s, 0);
}
void Termometr::operator>>(string s) {
	this->odczyt_z_pliku(s);
}