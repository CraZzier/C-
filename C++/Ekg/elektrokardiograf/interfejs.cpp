#include <conio.h>
#include "interfejs.h"


using namespace std;
//interfejs

void interfejs() {
	vector <Aparatmedyczny*> aparat;
	vector <Elektrokardiograf> ekg;
	vector <Smartekg> smartekg;
	vector <Termometr> termometr;
	int x;
	char decision;
	while (1) {
		int q, e, r, t, yy;
		double  y, u, i, o;
		string a, s;
		bool zz, xx, cc;
		cout << "1 - Dodaj obiekt" << endl;
		cout << "2 - Zadzialaj na obiekcie" << endl;
		cout << "3 - Demonstracja poliformizmu" << endl << endl;
		cout << "Wczytaj: ";
		while (!(cin >> x)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
		cin.ignore(999, '\n');
		if (x == 1) {
			system("cls");
			cout << "Jaki obiekt" << endl << endl;
			cout << "1 - EKG" << endl;
			cout << "2 - SmartEKG" << endl;
			cout << "3 - Termometr" << endl << endl;
			cout << "Wczytaj: ";
			while (!(cin >> x)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
			cin.ignore(999, '\n');
			cout << endl;
			if (x == 1) {
				Elektrokardiograf ek;
				ekg.push_back(ek);
				cout << ekg[ekg.size() - 1] << endl;
				cout << "Czy chcesz zmienic parametry?(Jesli tak wpisz t, jesli nie - cokolwiek)" << endl;
				cout << "Wczytaj: ";
				cin >> decision;
				if (decision == 't') {
					system("cls");
					cout << "Podaj cene: ";
					while (!(cin >> q)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj czas pomiaru: ";
					while (!(cin >> y)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj wage: "; 
					while (!(cin >> u)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj dlugosc: ";
					while (!(cin >> i)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj szerokosc: ";
					while (!(cin >> o)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj marke: "; 
					while (!(cin >> a)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj model: ";
					while (!(cin >> s)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					ekg[ekg.size() - 1].nadaj_Wartosci(q, y, u, i, o, a, s);
				}
			}
			else if (x == 2) {
				Smartekg ek;
				smartekg.push_back(ek);
				cout << smartekg[smartekg.size() - 1] << endl;
				cout << "Czy chcesz zmienic parametry?(Jesli tak wpisz t, jesli nie - cokolwiek)" << endl;
				cout << "Wczytaj: ";
				cin >> decision;
				if (decision == 't') {
					system("cls");
					cout << "Podaj cene: ";
					while (!(cin >> q)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj czas pomiaru: ";
					while (!(cin >> y)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj wage: ";
					while (!(cin >> u)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj dlugosc: ";
					while (!(cin >> i)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj szerokosc: ";
					while (!(cin >> o)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj marke: ";
					while (!(cin >> a)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj model: ";
					while (!(cin >> s)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Bluetooth(1 - wlaczony,0 - wylaczony): ";
					while (!(cin >> zz)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Internet(1 - wlaczony,0 - wylaczony):  ";
					while (!(cin >> xx)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "USB(1 - wlaczony,0 - wylaczony): ";
					while (!(cin >> cc)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					smartekg[smartekg.size() - 1].nadaj_Wartosci(q, y, u, i, o, a, s);
					smartekg[smartekg.size() - 1].ustaw(zz, xx, cc);
				}
			}
			else if (x == 3) {
				Termometr ek;
				termometr.push_back(ek);
				cout << termometr[termometr.size() - 1] << endl;
				cout << "Czy chcesz zmienic parametry?(Jesli tak wpisz t, jesli nie - cokolwiek)" << endl;
				cout << "Wczytaj: ";
				cin >> decision;
				if (decision == 't') {
					system("cls");
					cout << "Podaj cene: ";
					while (!(cin >> q)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj czas pomiaru: ";
					while (!(cin >> y)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj wage: ";
					while (!(cin >> u)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj dlugosc: ";
					while (!(cin >> i)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj szerokosc: ";
					while (!(cin >> yy)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					cout << "Podaj model: ";
					while (!(cin >> s)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
					cin.ignore(999, '\n');
					termometr[termometr.size() - 1].uzupelnij_dane(q, y, u, i, yy, s);
				}
			}
		}
		else if (x == 2) {
			cout << "Lista obiektow" << endl << endl;
			cout << "Ilosc EKG: " << ekg.size() << endl;
			cout << "Ilosc SmartEKG: " << smartekg.size() << endl;
			cout << "Ilosc Termometrow: " << termometr.size() << endl << endl;
			cout << "Wpisz numer klasy obiektu(1 - EKG, 2 - SmartEkg,3 - Termometr)" << endl << ": ";
			while (!(cin >> r)) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
			cin.ignore(999, '\n');
			cout << "Wpisz numer indeksu obiektu(0 siê liczy)" << endl << ": ";
			if (r == 1) {
				while (!(cin >> t) || !(t>=0 && t < (int)ekg.size())) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
				cin.ignore(999, '\n');
				system("cls");
				cout << "Uchwyciles obiekt! Co chesz zrobic?" << endl << endl;
				cout << "1. Zniszcz obiekt" << endl;
				cout << "2. Zapisz dane do pliku" << endl;
				cout << "3. Odczytaj dane z pliku" << endl;
				cout << "4. Uruchom urzadzenie" << endl;
				cout << "5. Wypisz cechy" << endl << endl;
				cout << "Wczytaj: ";
				while (!(cin >> e) || !(t>=0 && t < (int)ekg.size())) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
				cin.ignore(999, '\n');
				if (e == 1) {
					ekg.erase(ekg.begin()+t);
				}
				else if (e == 2) {
					system("cls");
					cout << "Podaj nazwe pliku:" << endl;
					cin >> a;
					ekg[t].zapisz_do_pliku(a, 0);
				}
				else if (e == 3) {
					system("cls");
					cout << "Podaj nazwe pliku:" << endl;
					cin >> a;
					ekg[t].odczyt_z_pliku(a);
				}
				else if (e == 4) {
					ekg[t].wlacz();
				}
				else if (e == 5) {
					cout << ekg[t];
					_getch();
				}
				else {
					cout << "Zostala uzyty nieprawidlowy numer . Wpisz cokolwiek by kontynuuowac" << endl;
					if (cin >> a) {
						continue;
					}

				}
			}
			else if (r == 2) {
				while (!(cin >> t) || !(t >= 0 && t < (int)smartekg.size())) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
				cin.ignore(999, '\n');
				system("cls");
				cout << "Uchwyciles obiekt! Co chesz zrobic?" << endl << endl;
				cout << "1. Zniszcz obiekt" << endl;
				cout << "2. Zapisz dane do pliku" << endl;
				cout << "3. Odczytaj dane z pliku" << endl;
				cout << "4. Uruchom urzadzenie" << endl;
				cout << "5. Wypisz cechy" << endl << endl;
				cout << "Wczytaj: ";
				while (!(cin >> e) || !(t >= 0 && t < (int)smartekg.size())) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
				cin.ignore(999, '\n');
				if (e == 1) {
					smartekg.erase(smartekg.begin() + t);
				}
				else if (e == 2) {
					system("cls");
					cout << "Podaj nazwe pliku:" << endl;
					cin >> a;
					smartekg[t].zapisz_do_pliku(a, 0);
				}
				else if (e == 3) {
					system("cls");
					cout << "Podaj nazwe pliku:" << endl;
					cin >> a;
					smartekg[t].odczyt_z_pliku(a);
				}
				else if (e == 4) {
					smartekg[t].wlacz();
				}
				else if (e == 5) {
					cout << smartekg[t];
					_getch();
				}
				else {
					cout << "Zostala uzyty nieprawidlowy numer . Wpisz cokolwiek by kontynuuowac" << endl;
					if (cin >> a) {
						continue;
					}

				}
			}
			else if (r == 3) {
				while (!(cin >> t) || !(t >= 0 && t < (int)termometr.size())) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
				cin.ignore(999, '\n');
				system("cls");
				cout << "Uchwyciles obiekt! Co chesz zrobic?" << endl << endl;
				cout << "1. Zniszcz obiekt" << endl;
				cout << "2. Zapisz dane do pliku" << endl;
				cout << "3. Odczytaj dane z pliku" << endl;
				cout << "4. Uruchom urzadzenie" << endl;
				cout << "5. Wypisz cechy" << endl << endl;
				cout << "Wczytaj: ";
				while (!(cin >> e) || !(t >= 0 && t < (int)termometr.size())) { cout << "nieprawidlowe dane. sprobuj jeszcze raz" << endl; cin.clear(); cin.ignore(999, '\n'); }
				cin.ignore(999, '\n');
				if (e == 1) {
					termometr.erase(termometr.begin() + t);
				}
				else if (e == 2) {
					system("cls");
					cout << "Podaj nazwe pliku:" << endl;
					cin >> a;
					termometr[t].zapisz_do_pliku(a, 0);
				}
				else if (e == 3) {
					system("cls");
					cout << "Podaj nazwe pliku:" << endl;
					cin >> a;
					termometr[t].odczyt_z_pliku(a);
				}
				else if (e == 4) {
					termometr[t].wlacz();
				}
				else if (e == 5) {
					cout << termometr[t];
					_getch();
				}
				else {
					cout << "Zostala uzyty nieprawidlowy numer . Wpisz cokolwiek by kontynuuowac" << endl;
					if (cin >> a) {
						continue;
					}

				}
			}
			else {
				cout << "Zostala uzyty nieprawidlowy numer klasy. Wpisz cokolwiek by kontynuuowac" << endl;
				if (cin >> a) {
					continue;
				}
			}
		}
		else if (x == 3) {
			cout << "Uruchamiam funkcje wirtualne na elementach pochodnych Klasy Aparatmedyczny poprzez rzutowanie" << endl << endl;
			Elektrokardiograf e;
			Smartekg et;
			Termometr ety;
			aparat.push_back(&e);
			aparat.push_back(&et);
			aparat.push_back(&ety);
			aparat[0]->wlacz();
			aparat[1]->wlacz();
			aparat[2]->wlacz();
			cout << endl;
			aparat[0]->wylacz();
			aparat[1]->wylacz();
			aparat[2]->wylacz();
			cout << endl;
			aparat[0]->zrobbadanie();
			aparat[1]->zrobbadanie();
			aparat[2]->zrobbadanie();
			cout << endl;


			_getch();

		}
		system("cls");
	}
}