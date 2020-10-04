
#include "bateria.h"
#include "drukarka.h"
#include "aparatmedyczny.h"
#include "wyswietlacz.h"

///klasa Elektrokardiograf obiekt glowny dziedziczaca po Aparatmedyczny
class Elektrokardiograf:public Aparatmedyczny{
public:
	///konstruktor domyslny
	Elektrokardiograf();
	///konstruktor kopiujacy
	Elektrokardiograf(const Elektrokardiograf &obs);
	///konstruktor z parametrami
	/**
	/param a to cena
	/param c to waga
	/param d to dlugosc
	/param e to szerokosc
	/param f to czas mierzenia
	/param nazwa to producent
	/param model1 to model
	*/
	Elektrokardiograf(int a, double c, double d, double e, double f, string nazwa, string model1);
	///wirtualna metoda wlaczenia przyrzadu
	void wlacz();
	///wirtualna metoda wylaczenia przyrzadu
	void wylacz();
	///metoda "symulujaca" badania
	void zrobbadanie();
	///funkcja nadajaca wartosci
	/**
	/param a to cena
	/param c to waga
	/param d to dlugosc
	/param e to szerokosc
	/param f to czas mierzenia
	/param nazwa to producent
	/param model1 to model
	*/
	void nadaj_Wartosci(int a, double c, double d, double e, double f, string nazwa, string model1);
	///statyczna skladowa /return Zwraca iloœæ obiektow
	static int zwroc_Liczbe_Obiektow() { return liczba_obiektow; }
	///funkcja zwraca powierzchnie /return zwraca wynik w double
	double zwroc_Powierzchnie() { return dlugosc * szerokosc; }
	///funkcja zwraca wage /return zwraca wynik w double
	double zwroc_Wage() { return waga;  }
	///zwraca wyswietlacz podobiekt Elektrokardiografu /return zwraca wskaznik na drukarke
	Wyswietlacz* zwroc_Wyswietlacz() { return &wyswietlacz; }
	///zwraca drukarke podobiekt Elektrokardiografu /return zwraca wskaznik na drukarke
	Drukarka* zwroc_Drukarke(){ return &drukarka; } 
	///wklada baterie do urzadzenia
	void wloz_Baterie(int sztuki);
	///destruktor Elektrokardiorafu
	~Elektrokardiograf(); 
	///zaprzyjazniona funkcja do wypisania obiektu za pomoca cout
	friend ostream & operator<< (ostream &wyjscie, const Elektrokardiograf &s);
	///operator porownania
	bool operator==(const Elektrokardiograf &s);
	///operator pzypisania
	void operator=(const Elektrokardiograf &s);
	///operator indeksowania /return zwraca wskaznik na baterie
	Bateria& operator[](int a);
	///operator konwersji
	operator int() const{return cena;}
	///operator inkrementacji /return zwraca ten sam obiekt z powiekszonym czasem
	Elektrokardiograf* operator++(int n) { czas_pomiaru += 1; return this; }
	///operatory do zapisu w pliku przyjmujace jego nazwe
	void operator<<(string s);
	///operatory do odczytu z pliku przyjmujace jego nazwe
	void operator>>(string s);
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

protected:
	///>czas pomiaru
	double czas_pomiaru;
	///>producent
	string producent;
	///>model
	string model;
	///>podobiekt bateria
	vector <Bateria*> bateria;
	///>podobiekt wyswietlacz
	Wyswietlacz wyswietlacz;
	///>podobiekt drukarka
	Drukarka drukarka;
	///>czy ekg wlaczone
	bool dziala;
private:
	///>ilosc utworzonyhc obiektow klasy Elektrokardiograf nie dziedziczona przez Smartekg
	static int liczba_obiektow;
};