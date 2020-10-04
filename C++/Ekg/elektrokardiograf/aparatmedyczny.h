#pragma once
#include <iostream>
#include <string>

using namespace std;
///klasas wirtualna
class Aparatmedyczny{
public:
	///wirtualna metoda wlaczenia
	virtual void wlacz() = 0;
	///wirtualna metoda wylaczenia
	virtual void wylacz() = 0;
	///wirtualna metoda zrobienia badania
	virtual void zrobbadanie() = 0;
	///wirtualny odczyt z pliku
	virtual void odczyt_z_pliku(string) = 0;
	///wirtualny zapis do pliku
	virtual void zapisz_do_pliku(string, int) = 0;

protected:
	///>cena urzadzenia
	int cena;
	///>waga urzadzenia
	double waga;
	///>dlugosc urz¹dzenia
	double dlugosc;
	///>szerokosc urzadzenia
	double szerokosc;
};
