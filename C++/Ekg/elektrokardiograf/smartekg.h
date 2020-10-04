#include "elektrokardiograf.h"
///Klasa pochodna Elektrokardiografu
class Smartekg :public Elektrokardiograf {
public:
	///konstruktor domyslny
	Smartekg();
	///destruktor domyslny
	~Smartekg();
	///wirtualna metoda wlaczenia przyrzadu
	void wlacz();
	///wirtualna metoda wylaczenia przyrzadu
	void wylacz();
	///metoda "symulujaca" badania
	void zrobbadanie();
	///nadawanie parametrow
	void ustaw(bool, bool, bool);
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
	friend ostream & operator<< (ostream &wyjscie, const Smartekg &s);
	///operatory do zapisu w pliku przyjmujace jego nazwe
	void operator<<(string s);
	///operatory do odczytu z pliku przyjmujace jego nazwe
	void operator>>(string s);
private:
	///>czy wlaczony jest bluetooth
	bool przesyl_bluetooth;
	///>czy wlaczony jest internet
	bool przesyl_internet;
	///>czy wlaczone jest usb
	bool przesyl_usb;

};