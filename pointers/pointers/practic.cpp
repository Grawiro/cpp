#include "pch.h"
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

void array_3x (double * array_1, double * array_2, double * array_3, int elements);
double* create_array (int elements);

char* fun_dopisz (char* napisz, int rozmiar);

void funkcja ();

int main ()
{
	{
		char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		char *pointer_exercise_2 = &alphabet[3];

		int number{};

		while (*pointer_exercise_2)
		{
			if ((number % 4) == 0)
			{
				std::cout << *pointer_exercise_2 << " ";
			}
			number++; pointer_exercise_2++;
		}
		std::cout << std::endl;

		pointer_exercise_2 = alphabet;
		std::cout << *pointer_exercise_2 << " ";
		std::cout << *(pointer_exercise_2 + 6) << " ";
	}

	{
		double* array_1 = create_array (10);
		double* array_2 = create_array (10);
		double* array_3 = create_array (10);

		for (int i = 0; i < 10; i++)
		{
			array_1[i] = i * 0.3;
			array_2[i] = i * 3.4 / 5;
		}

		array_3x (array_1, array_2, array_3, 10);
		std::cout << std::endl;
		std::cout << std::endl;

		for (int i = 0; i < 10; i++)
		{
			std::cout << array_3[i] << "=" << array_1[i] << "*" << array_2[i] << "\n";
		}

		delete[] array_1;
		delete[] array_2;
		delete[] array_3;

		array_1 = nullptr;
		array_2 = nullptr;
		array_3 = nullptr;
	}

	{
		std::cout << std::endl;
		int rozmiar = 8 * 8 * sizeof (long);
		std::cout << "Rozmiar tablicy w bajtach " << rozmiar;
		auto * szachownica = new char[rozmiar];

		long *  figury[10]{};
		int pierwsze_wolne = 0;

		for (int nr_figury = 0; nr_figury < 3; nr_figury++)
		{

			std::cout << "Na jakim polu szachownicy umiescic nowy obiekt"
				" typu long: Podaj symbol literowy [A-H]";
			char litera;
			std::cin >> litera;
			std::cout << "Podaj symbol cyfrowy [1-8]: ";
			int cyfra;
			std::cin >> cyfra;

			int poziomo = 0;
			for (char znak = 'A'; znak != litera; ++znak, ++poziomo);

			int pionowo = cyfra - 1;
			std::cout << "\nPo przeliczeniu na wspolrzedne poziomo = " << poziomo;
			std::cout << ", pionowo = " << pionowo << std::endl;

			int nr_pola = ((pionowo * 8) + poziomo);
			int nr_bajtu = nr_pola * sizeof (long);

			char * gdzie = &szachownica[nr_bajtu];

			std::cout << "nr_pola szachownicy =  " << nr_pola
				<< ", nr_bajtu = " << nr_bajtu << std::endl;

			long* adr = new (gdzie) long;

			figury[pierwsze_wolne++] = adr;
		}

		std::cout << "Po ustawieniu wszystkich figur. \nPoczatek szachownicy to  0x"
			<< std::hex << reinterpret_cast<long> (szachownica) << std::endl;

		for (int nr_figury = 0; figury[nr_figury] != nullptr; nr_figury++)
		{
			std::cout << "Figura " << nr_figury << ") jest na dzialce adresem "
				<< (figury[nr_figury]) << std::endl;
		}

		delete[] szachownica;
	}

	{
		char napis_hello[14] = "Hello World!";
		int rozmiar = sizeof (napis_hello);
		std::cout << std::endl;
		std::cout << fun_dopisz (napis_hello, rozmiar);
		std::cout << std::endl;
	}

	{
		funkcja ();
	}

	return 0;
}

void array_3x (double * array_1, double * array_2, double * array_3, int elements)
{
	for (int i = 0; i < elements; i++, array_1++, array_2++, array_3++)
	{
		*array_3 = (*array_1) * (*array_2);
	}
}

double * create_array (int elements)
{
	return new double[elements] {};
}

char * fun_dopisz (char * napisz, int rozmiar)
{
	char* napisz_poczatek = napisz;

	const char* uwaga = "UWAGA: ";
	int size = sizeof (uwaga) * 2;
	int liczba_znakow{};

	while (*napisz)
	{
		liczba_znakow++;
		napisz++;
	}

	napisz = napisz_poczatek;

	if (liczba_znakow < rozmiar - size)
	{
		char* new_napis = new char[rozmiar] {};
		char* new_napis_poczatek = new_napis;

		while (*uwaga)
		{
			*new_napis = *uwaga;
			new_napis++, uwaga++;
		}

		while (*napisz)
		{
			*new_napis = *napisz;
			new_napis++, napisz++;
		}

		napisz = napisz_poczatek;
		new_napis = new_napis_poczatek;

		for (int i = 0; i < liczba_znakow + size; i++)
		{
			napisz[i] = new_napis[i];
		}
		napisz[liczba_znakow + size] = '\0';

		delete[] new_napis;
	}
	else if (liczba_znakow > rozmiar - size && liczba_znakow > 2)
	{
		for (int i = liczba_znakow - 1; i > liczba_znakow - 4; i--)
		{
			napisz[i] = '.';
		}
	}

	return napisz;
}

void funkcja ()
{
#define	SPOSOB 3
#if(SPOSOB == 1)		
	char * * linijka = new char*[10];
#elif (SPOSOB == 2)	
	using Typ_elementu = char *;
	Typ_elementu * linijka = new Typ_elementu[10];
#elif (SPOSOB == 3)	
	auto * linijka = new char*[10];
#endif

	for (int i = 0; i < 10; i++)
	{
		linijka[i] = new char[80];
		strcpy (linijka[i], "to jest string nr ");

		char liczba[2] = " ";
		liczba[0] = char ('0' + i);

		strcat (linijka[i], liczba);
	}
	for (int i = 0; i < 10; i++) std::cout << "linijka[" << i << "] ma tresc:  " << linijka[i] << std::endl;

	std::cout << "Po zamianie trzeciego tekstu z szostym\n";

	char *tmp = linijka[3];
	linijka[3] = linijka[6];
	linijka[6] = tmp;

	for (int i = 0; i < 10; i++) std::cout << "linijka[" << i << "] ma tresc:  " << linijka[i] << std::endl;

	for (int i = 0; i < 10; i++) delete[] linijka[i];
	delete[] linijka;
}