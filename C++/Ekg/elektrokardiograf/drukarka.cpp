#include "drukarka.h"


void Drukarka::ustaw_drukarke(int a, int b, int c, double d, string e, int f)
{
	szer_wydruku = a;
	dl_wydruku = b;
	pojemnosc_tuszu = c;
	czas_drukowania = d;
	producent = e;
	jakosc_wydruku = f;
}

void Drukarka::dodaj_kartke(string kolor) {
	kartki.push(kolor);
}
void Drukarka::wydrukuj_kartke() {
	if (kartki.size() == 0) {
		cout << "Brak kartek" << endl;
	}
	else {
		if(!kartki.empty())
		kartki.pop();
	}
}

Drukarka::Drukarka() {
	szer_wydruku = 11;
	dl_wydruku = 17;
	pojemnosc_tuszu = 50;
	czas_drukowania = 5;
	producent = "HP";
	jakosc_wydruku = 8;
	kartki.push("biala");
	kartki.push("zielona");
#ifdef _DEBUG
	cout << "DEBUG! - Konstruktor bez parametrow Drukarka" << endl;
#endif
}

Drukarka::~Drukarka() {
#ifdef _DEBUG
	cout << "DEBUG! - Destruktor bez parametrow Drukarka" << endl;
#endif
}

void Drukarka::zapisz_do_pliku(string s, int zapis) {
	queue <string> tmp;
	ofstream strim;
	if(zapis==0)
		strim.open(s, ios::out);
	if (zapis == 1) {
		strim.open(s, ios::app);
		cout << "dopisanie";
	}
	if (strim.good() == true) {
		strim << szer_wydruku << endl;
		strim << dl_wydruku << endl;
		strim << pojemnosc_tuszu << endl;
		strim << czas_drukowania<< endl;
		strim << producent << endl;
		strim << jakosc_wydruku << endl;
		while (!kartki.empty()) {
			strim << kartki.front() << endl;
			tmp.push(kartki.front());
			kartki.pop();
		}
		while (!tmp.empty()) {
			kartki.push(tmp.front());
			tmp.pop();
		}
		strim << "Koniec_kartek" << endl;
		cout << "zapis udal sie" << endl;

	}
	else {
		cout << "blad otwierania pliku" << endl;
	}
	strim.close();

}

void Drukarka::odczyt_z_pliku(string s) {
	ifstream strim;
	string tp;
	strim.open(s, ios::in);
	while(!kartki.empty()){
		kartki.pop();
	}
	if (strim.good() == true) {
		strim >> szer_wydruku;
		strim >> dl_wydruku;
		strim >> pojemnosc_tuszu;
		strim >> czas_drukowania;
		strim.ignore();
		getline(strim, producent);
		strim >> jakosc_wydruku;
		strim.ignore();
		while (tp!="Koniec_kartek") {
			getline(strim, tp);
			if (tp == "Koniec_kartek")
				break;
			kartki.push(tp);
		}
		cout << "czytanie z plku powiod³o siê" << endl;
	}
	else {
		cout << "Czytanie z pliku nie powiod³o siê" << endl;
	}
	strim.close();
}
void Drukarka::operator<<(string s) {
	this->zapisz_do_pliku(s, 0);
}
void Drukarka::operator>>(string s) {
	this->odczyt_z_pliku(s);
}