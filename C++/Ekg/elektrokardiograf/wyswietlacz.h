#include <string>
#include <iostream>
#include <fstream>

using namespace std;

///Podobiekt Elektrokardigrafu i Smartekg
class Wyswietlacz {
public:
	///konstruktor domyslny
	Wyswietlacz();
	///nadawanie parametrow
	/**
		Parametry to kolejno atrybuty obiektu tej klasy
	*/
	void uzupelnij_dane(int, int, int, bool, string);
	///destruktor wyswietlacza
	~Wyswietlacz();
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
	///operatory do zapisu w pliku przyjmujace jego nazwe
	void operator<<(string s);
	///operatory do odczytu z pliku przyjmujace jego nazwe
	void operator>>(string s);
	///zaprzyjazniona funkcja do wypisania obiektu za pomoca cout
	friend ostream & operator<< (ostream &wyjscie, const Wyswietlacz &s);
private:
	///<szerokosc ekranu
	int szer_pix;
	///<dlugosc ekranu
	int dl_pix;
	///<dlugosc przekatnej
	int cale_przekatna;
	///<czy jest 3d
	bool jest_3d;
	///<kto jest producentem
	string producent;
};
