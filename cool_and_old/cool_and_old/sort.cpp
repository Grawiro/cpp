#include "pch.h"
#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <vector>

#pragma warning (disable : 4244)

using namespace std;

int ile, *zero, *zero1;
clock_t a, b, a1, b1;
double czas, czas1;

void bubble (int *tab, int ile);
void quick (int *tab, int lewy, int prawy);

int main_19 ()
{
	cout << "Porownanie czasow sortowania v.1\n";
	cout << "Ile losowych liczb w tablicy: ";
	cin >> ile;

	int *tablica;
	tablica = new int[ile];
	zero = tablica;
	int *tablica2;
	tablica2 = new int[ile];
	zero1 = tablica2;

	srand (time (NULL));
	for (int i = 0; i < ile; i++)
	{
		tablica[i] = rand () % 100000 + 1;
	}

	for (int i = 0; i < ile; i++)
	{
		tablica2[i] = tablica[i];
	}

	cout << "Teraz sortuje babelkowo.";
	a = clock ();
	bubble (tablica, ile);
	b = clock ();
	czas = (double)(b - a) / CLOCKS_PER_SEC;

	cout << "\nTeraz sortuje szybko.";
	a1 = clock ();
	quick (tablica2, 0, ile - 1);
	b1 = clock ();
	czas1 = (double)(b1 - a1) / CLOCKS_PER_SEC;

	cout << "\nCzas sortowania babelkowego " << czas << "s";
	cout << "\nCzas szybkiego sortowania " << czas1 << "s";

	_getch ();

	tablica = zero;
	delete[] tablica;
	tablica2 = zero1;
	delete[] tablica2;

	return 0;
}

void bubble (int *tab, int ile)
{
	for (int i = 1; i < ile; i++)
	{
		for (int j = ile - 1; j >= 1; j--)
		{
			if (tab[j] < tab[j - 1])
			{
				int zamiana;
				zamiana = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = zamiana;
			}
		}
	}
}

void quick (int *tab, int lewy, int prawy)
{
	int v = tab[(lewy + prawy) / 2];
	int i, j, x;
	i = lewy;
	j = prawy;
	do
	{
		while (tab[i] < v) i++;
		while (tab[j] > v) j--;
		if (i <= j)
		{
			x = tab[i];
			tab[i] = tab[j];
			tab[j] = x;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > lewy) quick (tab, lewy, j);
	if (i < prawy) quick (tab, i, prawy);
}