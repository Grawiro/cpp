#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

unsigned int decyzja{ 0 };
unsigned int trafione{ 0 };
unsigned int proby{ 0 };
unsigned int trafione_zawsze{ 0 };
unsigned int nagroda{ 0 };
unsigned int nagroda_zawsze{ 0 };

unsigned int losowanie_tablica [6];
unsigned int wybor_tablica [6];

void gra ();

void menu ();
void wybor (unsigned int wybor);

void start ();

void clear ();
void liczby ();
void losowanie ();
void porownanie ();
void wyniki ();

void statystyki ();
void instrukcja ();
void koniec ();

int main()
{
	gra ();
}

void gra ()
{
	srand (time (NULL));

	for (;;) {
		menu ();
		wybor (decyzja);
	}
}

void menu ()
{
	system ("cls");
	cout << "Menu Glowne\n"
		"1.Start\n"
		"2.Statystyki\n"
		"3.Instrukcja\n"
		"4.Koniec\n"
		"Dokonaj wyboru: ";

	cin >> decyzja;
}

void wybor (unsigned int wybor)
{
	switch (wybor) {
	case 1: start (); break;
	case 2: statystyki (); break;
	case 3: instrukcja (); break;
	case 4: koniec (); break;
	default: cout << "Nieznana opcja!"; Sleep (1000); break;
	}
}

void start ()
{
	for (;;) {
		clear ();
		liczby ();
		losowanie ();
		porownanie ();
		wyniki ();
	}
}

void clear ()
{
	for (int i = 0; i < 6; i++){
		losowanie_tablica[i] = 0;
		wybor_tablica[i] = 0;
	}
	trafione = 0;
	nagroda = 0;
}

void liczby ()
{
	system ("cls");

	cout << "Wybierz 6 liczb od 1 od 49:\n";
	for (int i = 0; i < 6; i++) {
		cout << "Liczba " << i+1 << ": ";
		cin >> wybor_tablica[i];

		if (wybor_tablica[i] < 1 || wybor_tablica[i]>49) { cout << "Zla wartosc!\n"; --i; continue; }

		for (int m = 0; m < i; m++) {
			if (wybor_tablica[i] == wybor_tablica[m]) { cout << "Wybrales taka juz ta wartosc!\n"; --i; break; }
		}
	}
}

void losowanie ()
{
	for (int i = 0; i < 6; i++) {
		losowanie_tablica[i] = static_cast<unsigned int>(rand () % 49 + 1);
		Sleep (100);

		for (int m = 0; m < i; m++) {
			if (losowanie_tablica[i] == losowanie_tablica[m]) { --i; break; }
		}
	}

	for (int i = 0; i < 6; i++) {
		cout << "\a" << losowanie_tablica[i] << "\t";
		Sleep (1000);
	}
}

void porownanie ()
{
	for (int i = 0; i < 6; i++) {
		for (int m = 0; m < 6; m++) {
			if (losowanie_tablica[i] == wybor_tablica[m]) { trafione++; }
		}
	}
}

void wyniki ()
{
	nagroda = (trafione == 0 ? 0 : (trafione == 1 ? 0 : (trafione == 2 ? 100 :
		(trafione == 3 ? 1000 : (trafione == 4 ? 10000 : 10000000)))));

	trafione_zawsze += trafione;
	nagroda_zawsze += nagroda;
	proby++;

	for (;;) {
	cout << "\nTrafiles " << (trafione == 0 ? "0" : (trafione == 1 ? "1" : (trafione == 2 ? "2" : 
		(trafione == 3 ? "3" : (trafione == 4 ? "4" : "5")))));
	cout << "\tNagroda " << nagroda;


	Sleep (5000);

		cout << "\nNacisnij 1, by zagrac ponownie."
			"\nNacisnij 2, by wrocic do menu: ";
		cin >> decyzja;

		if (decyzja == 1) { start (); }
		else if (decyzja == 2) { gra (); }
		else { cout << "\nWybierz jeszcze raz!"; Sleep (1000); system ("cls"); }
	}
}

void statystyki ()
{
	for (;;) {
		system ("cls");

		cout << "Statystyki\n"
			"Proby = "<<proby<<
			"\nTrafienia = "<<trafione_zawsze<<
			"\nNagroda = "<<nagroda_zawsze<<

			"\nNacisnij 1, aby zresetowac statystyki. "
			"\nNacisnij 2, aby powrocic od Menu Glownego: ";
		cin >> decyzja;

		if (decyzja == 2) break;
		else if (decyzja == 1) { 
			proby = 0;
			trafione_zawsze = 0;
			nagroda_zawsze = 0;
			
			cout << "Statystyki zostaly zresetowane!";
			Sleep (1000);
			break;
		}
		else { cout << "Nieznana wartosc "; Sleep (1000); }
	}
}

void instrukcja ()
{
	for (;;) {
		system ("cls");
		cout << "Gra polega na podaniu 6 liczb, po czym nastepuje losowanie takze 6 liczb.\n"
			"Liczby musza byc w przedziale od 1 do 49.\n"
			"Liczby nie moga sie powtarzac.\n"
			"Nagroda zalezy od liczby trafinych liczb.\n"
			"\nNacisnij 1, aby powrocic od Menu Glownego: ";
		cin >> decyzja;
		if (decyzja == 1) break;
		else { cout << "Nieznana wartosc "; Sleep (1000); }
	}
}

void koniec ()
{
	system ("cls");
	cout << "Koniec programu...";
	Sleep (1000);
	exit (4);
}
