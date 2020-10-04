#include <string>
#include <iostream>
#include <fstream>

using namespace std;
///Bateria podobiekt EKG
class Bateria { 
public:
	///konstruktor domyslny
	Bateria();
	///nadanie atrybutow obiektowi
	/**
	Parametry to kolejno atrybuty obiektu tej klasy
	*/
	void zdefiniuj_baterie(int, int, double, string);
	///zaprzyjazniona funkcja do wypisania obiektu za pomoca cout
	friend ostream & operator<< (ostream &wyjscie, const Bateria &s);
	///destruktor Bateria
	~Bateria();
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
	void zapisz_do_pliku(string,int);
	///operatory do zapisu w pliku przyjmujace jego nazwe
	void operator<<(string s);
	///operatory do odczytu z pliku przyjmujace jego nazwe
	void operator>>(string s);
private:
	///>pojemnosc w mAh
	int pojemnosc;//w mAh
	///>cena w zlotowkach
	int cena;
	///>napiecie w woltach
	double napiecie;//w V
	///>nazwa producenta
	string producent;
};
