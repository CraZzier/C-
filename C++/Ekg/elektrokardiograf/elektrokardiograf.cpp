#include "elektrokardiograf.h"

void Elektrokardiograf::wlacz() {
	if (dziala == 0) {
			dziala = 1;
			cout << "Elektrokardiograf uruchomiony" << endl;
	}
	else {
		cout << "Elektrokardiograf by³ juz wczeœniej uruchmiony" << endl;
	}
}
void Elektrokardiograf::wylacz() {
	if (dziala == 1) {
		dziala = 0;
		cout << "Elektrokardiograf wy³aczony" << endl;
	}
	else {
		cout << "Elektrokardiograf by³ juz wczeœniej wy³aczony" << endl;
	}
}
void Elektrokardiograf::zrobbadanie() {
	cout << "Badanie EKG: Praca serca w normie" << endl;
}

ostream & operator<< (ostream &wyjscie, const Elektrokardiograf &s) {
	wyjscie <<
		"Cena: " << s.cena << endl <<
		"Czas pomiaru: " << s.czas_pomiaru << endl <<
		"Waga: " << s.waga << endl <<
		"Dlugosc: " << s.dlugosc << endl <<
		"Szerokosc: " << s.szerokosc << endl <<
		"Marka: " << s.producent << endl <<
		"Wlaczony: " << s.dziala << endl <<
		"Model: " << s.model << endl << endl << "Wyswietlacz:" << endl;
		wyjscie << s.wyswietlacz;
		return wyjscie;
		
}

bool Elektrokardiograf::operator==(const Elektrokardiograf &s) {
	if (model == s.model && producent == s.producent) {
		return true;
	}
	return false;
}

void Elektrokardiograf::operator=(const Elektrokardiograf &obs) {
	cena = obs.cena;
	czas_pomiaru = obs.czas_pomiaru;
	waga = obs.waga;
	dlugosc = obs.dlugosc;
	szerokosc = obs.szerokosc;
	producent = obs.producent;
	model = obs.model;
	dziala = obs.dziala;
	bateria.resize(obs.bateria.size());
	for (int i = 0; i < (int)obs.bateria.size(); i++) {
		bateria[i] = obs.bateria[i];
	}
	liczba_obiektow++;
}

Bateria & Elektrokardiograf::operator[](int a)
{
	return *(bateria[a]);
}
void Elektrokardiograf::operator<<(string s) {
	this->zapisz_do_pliku(s,0);
}
void Elektrokardiograf::operator>>(string s) {
	this->odczyt_z_pliku(s);
}
int Elektrokardiograf::liczba_obiektow = 0;
Elektrokardiograf::Elektrokardiograf() {
	cena = 1000;
	czas_pomiaru = 10;
	waga = 3;
	dlugosc = 120;
	szerokosc = 100;
	producent = "M4medical";
	model = "P700";
	dziala = 0;
	liczba_obiektow++;
#ifdef _DEBUG
	cout << "DEBUG - Konstruktor domyslny Elektrokardiograf!" << endl;
#endif
}

Elektrokardiograf::Elektrokardiograf(const Elektrokardiograf & obs)
{
	cena = obs.cena;
	czas_pomiaru = obs.czas_pomiaru;
	waga = obs.waga;
	dlugosc = obs.dlugosc;
	szerokosc = obs.szerokosc;
	producent = obs.producent;
	model = obs.model;
	dziala = obs.dziala;
	bateria.resize(obs.bateria.size());
	for (int i = 0; i < (int)obs.bateria.size(); i++) {
		bateria[i] = obs.bateria[i];
	}
	liczba_obiektow++;
}

Elektrokardiograf::Elektrokardiograf(int a, double c, double d, double e, double f, string nazwa, string modelL)
{
	cena = a;
	czas_pomiaru = c;
	waga = d;
	dlugosc = e;
	szerokosc = f;
	producent = nazwa;
	model = modelL;
	dziala = 0;
	liczba_obiektow++;
#ifdef _DEBUG
	cout << "DEBUG! - Konstruktor reczny Elektrokardiograf" << endl;
#endif
}

void Elektrokardiograf::nadaj_Wartosci(int a, double c, double d, double e, double f, string nazwa, string modelL)
{
	cena = a;
	czas_pomiaru = c;
	waga = d;
	dlugosc = e;
	szerokosc = f;
	producent = nazwa;
	model = modelL;
}

void Elektrokardiograf::wloz_Baterie(int sztuki) {
	for (int i = 0; i < sztuki; i++) {
		Bateria *ok = new Bateria();
		bateria.push_back(ok);
	}
}
Elektrokardiograf::~Elektrokardiograf() {
	if (bateria.size()!=0) {
		for(int i =0;i<(int)bateria.size();i++)
			delete bateria[i];
		bateria.resize(0);
	}
#ifdef _DEBUG
	cout << "DEBUG! - Destruktor domyœlny Elektrokardiograf" << endl;
#endif
}

void Elektrokardiograf::zapisz_do_pliku(string s,int zapis) {
	ofstream strim;
	if (zapis == 0)
		strim.open(s, ios::out);
	if (zapis == 1)
		strim.open(s, ios::app);
	if (strim.good() == true) {
		strim << cena << endl;
		strim << czas_pomiaru << endl;
		strim << waga << endl;
		strim << dlugosc << endl;
		strim << szerokosc << endl;
		strim << producent << endl;
		strim << model << endl;
		strim << dziala << endl;
		for (int i = 0; i < (int)bateria.size(); i++) {
			bateria[i]->zapisz_do_pliku(s,1);
		}
		strim.close();
		strim.open(s, ios::app);
		strim << "Koniec_Baterii" << endl;
		wyswietlacz.zapisz_do_pliku(s,1);
		drukarka.zapisz_do_pliku(s,1);
		cout << "zapis udal sie" << endl;
	}
	else {
		cout << "blad otwierania pliku" << endl;
	}
	strim.close();

}

void Elektrokardiograf::odczyt_z_pliku(string s) {
	ifstream strim;
	string tmp;
	int i = 0;
	int bata;
	int batb;
	double batc;
	string batd;
	bool tp;
	int bate;
	int batf;
	strim.open(s, ios::in);
	if (strim.good() == true) {
		bateria.resize(0);
		while(!drukarka.czypusta())
		drukarka.wydrukuj_kartke();
		strim >> cena;
		strim >> czas_pomiaru;
		strim >> waga;
		strim >> dlugosc;
		strim >> szerokosc;
		strim.ignore();
		getline(strim, producent);
		getline(strim, model);
		strim >> dziala;
		strim.ignore();
		while (1 == 1) {
			getline(strim, tmp);
			if (tmp == "Bateria:") {
				this->wloz_Baterie(1);
				strim >> bata;
				strim >> batb;
				strim >> batc;
				strim.ignore();
				getline(strim, batd);
				bateria[i]->zdefiniuj_baterie(bata, batb, batc, batd);
			}
			else {
				break;
			}
			i++;
		}
		strim >> i;
		strim >> bata;
		strim >> batb;
		strim >> tp;
		strim >> batd;
		wyswietlacz.uzupelnij_dane(i, bata, batb, tp, batd);
		strim >> i;
		strim >> bata;
		strim >> batb;
		strim >> bate;
		strim.ignore();
		getline(strim, batd);
		strim >> batf;
		strim.ignore();
		while (1) {
			getline(strim, batd);
			if (batd != "Koniec_kartek") {
				drukarka.dodaj_kartke(batd);
			}
			else {
				break;
			}
		}
		cout << "wczytanie powiod³o sie" << endl;
	}
	else {
		cout << "czytanie z pliku nie powiod³o siê" << endl;
	}
	strim.close();
}