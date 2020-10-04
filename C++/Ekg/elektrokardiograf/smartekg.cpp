#include "smartekg.h"

void Smartekg::wlacz() {
	if (dziala == 0) {
			dziala = 1;
			cout << "Elektrokardiograf(smart) uruchomiony" << endl;
	}
	else {
		cout << "Elektrokardiograf(smart) by³ juz wczeœniej uruchmiony" << endl;
	}
}
ostream & operator<< (ostream &wyjscie, const Smartekg &s) {
	wyjscie <<
		"Cena: " << s.cena << endl <<
		"Czas pomiaru: " << s.czas_pomiaru << endl <<
		"Waga: " << s.waga << endl <<
		"Dlugosc: " << s.dlugosc << endl <<
		"Szerokosc: " << s.szerokosc << endl <<
		"Marka: " << s.producent << endl <<
		"Wlaczony: " << s.dziala << endl <<
		"Model: " << s.model << endl<<
		"Bluetooth: " << s.przesyl_bluetooth << endl <<
		"Internet: " << s.przesyl_internet << endl <<
		"USB: " << s.przesyl_usb << endl << endl << "Wyswietlacz:" << endl;
	wyjscie << s.wyswietlacz;
	return wyjscie;
}
void Smartekg::wylacz() {
	if (dziala == 1) {
		dziala = 0;
		cout << "Elektrokardiograf(smart) wy³aczony" << endl;
	}
	else {
		cout << "Elektrokardiograf(smart) by³ juz wczeœniej wy³¹czony" << endl;
	}
}
void Smartekg::zrobbadanie() {
	if (przesyl_bluetooth)
		cout << "Badanie EKG(smart): Praca serca w normie.Przesylanie danych przez bluetooth" << endl;
	if (przesyl_internet)
		cout << "Badanie EKG(smart): Praca serca w normie.Przesylanie danych przez bluetooth" << endl;
	if (przesyl_usb)
		cout << "Badanie EKG(smart): Praca serca w normie.Przesylanie danych przez bluetooth" << endl;
}

void Smartekg::ustaw(bool blue, bool net, bool usb) {
	przesyl_bluetooth = blue;
	przesyl_internet = net;
	przesyl_usb = usb;
}

Smartekg::Smartekg():Elektrokardiograf() {
	przesyl_bluetooth = 0;
	przesyl_internet = 0;
	przesyl_usb = 1;
}
Smartekg::~Smartekg() {
#ifdef _DEBUG
	cout << "DEBUG! - Destruktor domyœlny Smartekg" << endl;
#endif
}

void Smartekg::zapisz_do_pliku(string s, int zapis) {
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
		strim << przesyl_bluetooth << endl;
		strim << przesyl_internet << endl;
		strim << przesyl_usb << endl;
		for (int i = 0; i < (int)bateria.size(); i++) {
			bateria[i]->zapisz_do_pliku(s, 1);
		}
		strim.close();
		strim.open(s, ios::app);
		strim << "Koniec_Baterii" << endl;
		wyswietlacz.zapisz_do_pliku(s, 1);
		drukarka.zapisz_do_pliku(s, 1);
		cout << "zapis udal sie" << endl;
	}
	else {
		cout << "blad otwierania pliku" << endl;
	}
	strim.close();

}

void Smartekg::odczyt_z_pliku(string s) {
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
		while (!drukarka.czypusta())
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
		strim >> przesyl_bluetooth;
		strim >> przesyl_internet;
		strim >> przesyl_usb;
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
void Smartekg::operator<<(string s) {
	this->zapisz_do_pliku(s, 0);
}
void Smartekg::operator>>(string s) {
	this->odczyt_z_pliku(s);
}