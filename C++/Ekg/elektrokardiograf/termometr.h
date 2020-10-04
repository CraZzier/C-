#include <iostream>
#include <string>
#include <fstream>

#include "aparatmedyczny.h"
///Termometr ,dziedziczacy po klasie Aparatmedyczny
class Termometr:public Aparatmedyczny {
public:
	///wirtualna metoda wlaczenia przyrzadu
	void wlacz();
	///wirtualna metoda wylaczenia przyrzadu
	void wylacz();
	///metoda "symulujaca" badania
	void zrobbadanie();
	///nadawanie parametrow
	/**
	Parametry to kolejno atrybuty obiektu tej klasy
	*/
	void uzupelnij_dane(int,double,double,double,int, string);
	///konstruktor domyslny
	Termometr();
	///konstruktor z parametrami
	Termometr(int, bool, string);
	///destruktor
	~Termometr();
	///czytanie z pliku
	/**
	\param string - nazwa pliku
	*/
	void odczyt_z_pliku(string);
	///zapisywanie do pliku
	/**
	\param string - nazwa pliku
	\param int - decyduje o dopisaniu do pliku lub nadpisaniu
	*/
	void zapisz_do_pliku(string, int);
	///zaprzyjazniona funkcja do wypisania obiektu za pomoca cout
	friend ostream & operator<< (ostream &wyjscie, const Termometr &s);
	///operatory do zapisu w pliku przyjmujace jego nazwe
	void operator<<(string s);
	///operatory do odczytu z pliku przyjmujace jego nazwe
	void operator>>(string s);
private:
	///< czas mierzenia uzadzenia
	int czas_mierzenia;
	///< model urzadzenia
	string model;
	///> czy jest uruchomiony
	bool dziala;
};