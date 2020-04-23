#include <iostream>
#include <conio.h>
#include <ctime>
#include <Windows.h>

using namespace std;

void main ()
{
	srand ((int)time (NULL));
	for (;;)
	{
		int nWylosowana = rand () % 100 + 1;

		cout << "Wylosowano liczbe z przedzialu 1-100. (-1 Wyjscie.)" << endl;

		int nWprowadzona;

		cout << "Sprawdz czy ja zgadniesz: ";
		cin >> nWprowadzona;

		if (nWprowadzona == -1)
			break;

		int nRuchy = 1;

		while (nWprowadzona != nWylosowana)
		{
			nRuchy++;

			if (nWprowadzona < nWylosowana)
				cout << "Za mala. ";
			else
				cout << "Za duza. ";

			cout << "Sprobuj jeszcze raz: ";
			cin >> nWprowadzona;
		}

		cout << endl << "Super zgadles!" << endl;
		cout << "Zgadles za " << nRuchy << " razem.";

		Sleep (4000);

		system ("cls");
	}
}
