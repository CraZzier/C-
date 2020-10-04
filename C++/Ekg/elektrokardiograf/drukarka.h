#include <string>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

/// Podobiekt Elektrokardiografu
class Drukarka {
public:
	///kosntruktor domyœ³ny
	Drukarka();
	///ustawianie parametrow drukarki odpowiednio w kolejnosci
	void ustaw_drukarke(int, int, int, double, string, int);
	///funkcja dodajaca kartke do kolejki
	void dodaj_kartke(string kolor);
	///funkcja drukujaca kartke
	void wydrukuj_kartke();
	///funkcja sprawdzajaca czy jest jakas kartka /return zwraca 1 jesli brak kartek, 0 - jesli jakies sa
	bool czypusta() { return kartki.empty(); };
	///destruktor
	~Drukarka();
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
private:
	///> szerokosc wydruku
	int szer_wydruku;
	///> dlugosc wydruku
	int dl_wydruku;
	///> pojemnosc tuszu w ml
	int pojemnosc_tuszu;//w ml
	///>czas drukowania
	double czas_drukowania;
	///>producent
	string producent;
	///>kolejka przechowujaca kartki
	queue <string> kartki;
	///>jakosc wydruku w skali od 1- 10
	int jakosc_wydruku;//1-10
};
