#include "wyswietlacz.h"

void Wyswietlacz::uzupelnij_dane(int a, int b, int c, bool d, string e)
{
	szer_pix = a;
	dl_pix = b;
	cale_przekatna = c;
	jest_3d = d;
	producent = e;
}
Wyswietlacz::Wyswietlacz() {
	szer_pix = 1366;
	dl_pix = 760;
	cale_przekatna = 5;
	jest_3d = 1;
	producent = "Fujitsu";
#ifdef _DEBUG
	cout << "DEBUG! - Konstruktor bez parametrow Wyswietlacz" << endl;
#endif
}

ostream & operator<< (ostream &wyjscie, const Wyswietlacz &s) {
	return wyjscie <<
		"Szerokosc ekranu: " << s.szer_pix << endl <<
		"Dlugosc ekranu: " << s.dl_pix << endl <<
		"Cale: " << s.cale_przekatna << endl <<
		"CZy jest 3d?: " << s.jest_3d << endl <<
		"Marka: " << s.producent << endl;
}

Wyswietlacz::~Wyswietlacz() {
#ifdef _DEBUG
	cout << "DEBUG! - Destruktor bez parametrow Wyswietlacz" << endl;
#endif
}

void Wyswietlacz::zapisz_do_pliku(string s,int zapis) {
	ofstream strim;
	if (zapis == 0)
		strim.open(s, ios::out);
	if (zapis == 1)
		strim.open(s, ios::app);
	if (strim.good() == true) {
		strim << szer_pix << endl;
		strim << dl_pix << endl;
		strim << cale_przekatna << endl;
		strim << jest_3d << endl;
		strim << producent << endl;
		cout << "zapis udal sie" << endl;

	}
	else {
		cout << "blad otwierania pliku" << endl;
	}
	strim.close();

}

void Wyswietlacz::odczyt_z_pliku(string s) {
	ifstream strim;
	strim.open(s, ios::in);
	if (strim.good() == true) {
		strim >> szer_pix;
		strim >> dl_pix;
		strim >> cale_przekatna;
		strim >> jest_3d;
		strim.ignore();
		getline(strim, producent);
		cout << "czytanie z plku powiod³o siê" << endl;
	}
	else {
		cout << "Czytanie z pliku nie powiod³o siê" << endl;
	}
	strim.close();
}

void Wyswietlacz::operator<<(string s) {
	this->zapisz_do_pliku(s, 0);
}
void Wyswietlacz::operator>>(string s) {
	this->odczyt_z_pliku(s);
}