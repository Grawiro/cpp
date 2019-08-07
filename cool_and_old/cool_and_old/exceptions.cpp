#include "pch.h"
#include <iostream>
#include <cassert>		//only assert and abort
#include <exception>	//obsluda wyjatkow
#include <string>
#include <limits>
#include <new>

#pragma warning (disable : 4290)

class Bad {
	int _a;
	int _b;
public:
	Bad (int a, int b) { _a = a; _b = b; }
	void info () {
		std::cout << "Class Bad error " << _a << "/" << _b << "\n";
	}
};

int Sum1 (int, int) throw ();		//function not return exceptions
int Sum2 (int, int) throw (Bad);	//function throw exceptions only Bad class type

void MyTerminate ();
int blad (int x);

constexpr int liczba_butow = 42;
static_assert ((liczba_butow % 2) == 0, "Blad: liczba_butow musi byc parzysta");

class MyException : public std::exception {		//wlasna obsuga pisanych wyjatkow
public:
	MyException (std::string err) {
		Error = err;
	}
	virtual ~MyException () throw () {}

	const char* what () const throw () {
		return Error.c_str ();
	}

private:
	std::string Error;
};

double Devide (double a, double b);
long long int* Alloc ();

extern void command_a ();

void fun_exeption ();

int main_22 () {
	{
		int a = 1;
		assert (a > 0);				//if false return error (good)
		if (a > 2) { abort (); }	//abort is a useless

		Sum1 (1, 1);

		try {
			Sum2 (-1, 1);
		}
		catch (Bad bad) {
			bad.info ();
		}

		std::cout << "Sum 1+1=";
		while (!(std::cin >> a) || a != 2) {	//load as long as a is not equal 2
			std::cin.clear ();					//clear buffor
			std::cin.ignore (1000, '\n');		//ignore 1000 characters
			std::cout << "Sum 1+1=";
		}

		std::cout << "\n";
	}

	{
		int b;

		for (int s = 0; s < 4; s++)
		{
			std::cin >> b;

			blad (b);
		}
	}

	{
		std::cout << "\nPodaj nr [1-2]: ";

		int nr;

		std::cin >> nr;

		switch (nr)
		{
		case 1:
			std::cout << "Opcja 1";
			break;
		case 2:
			if (sizeof (int) == 4)
				std::cout << "Typ int jest wystarczajacy dla tej opcji";
			static_assert(sizeof (int) == 4, "Blad: Typ int nie jest 4-bitowy");
			break;
		default:
			break;
		}

		static_assert(std::numeric_limits<char>::is_signed,"Uwaga: Typ char jest bez znaku");
		static_assert(35000 < std::numeric_limits<int>::max (), "Blad: Typ int jest za maly");
		std::cout << std::endl;
		std::cout << std::endl;
	}

	{
		double result = 0;
		bool ErrFlag = false;

		long long int* alloc;

		try {	//w tym obszaze sprawdzaj czy nastapil wyjatek
			result = Devide (3.5, 2);	//po 1 wyjatku przerywa sie wszystko w bloku try
			alloc = Alloc ();
		}
		catch (MyException& e) {		//lapie blad
			std::cout << "Wystapil blad: " << e.what () << "\n";
			result = 0;
			ErrFlag = true;
		}
		catch (std::bad_alloc) {		//zla alokacja pamieci
			std::cout << "Wystapil blad: alokacji pamieci.\n";
			alloc = nullptr;	//trzeba by bylo zwolnic ta pamiec ale nie dziala mi delete
			ErrFlag = true;
		}
		catch (std::exception&) {		//musi byc pod MyExc poniewaz tamta klasa dziedziczy z tej
			std::cout << "Wystapil blad: std::exception.\n";
			result = 0;
			ErrFlag = true;
		}
		catch (...) {		//lapie wszystkie wyjatki wiec musi byc na samym koncu
			std::cout << "Wystapil blad: nieznany.\n";
			result = 0;
			ErrFlag = true;
		}

		if (!ErrFlag) {
			std::cout << "Wynik dzielnia to: " << result << "\n";
		}

		try {
			std::set_new_handler (fun_exeption);
			alloc = Alloc ();
		}
		catch (MyException& e) {
			std::cout << "Wystapil blad: " << e.what () << "\n";
			alloc = nullptr;
		}
		catch (std::bad_alloc) {
			std::cout << "Wystapil blad: alokacji pamieci.\n";
			alloc = nullptr;
		}

		std::cin.get ();
	}

	{
		char command[100];
		while (std::cin >> command) {
			try {
				if (strcmp (command, "a") == 0) command_a ();
				else    std::cout << "Unknown command: " << command << std::endl;
			}
			catch (const char* const message) {
				std::cout << message << std::endl;
			}
		}

		std::cerr << "Elo, mamy blad!!!";	//strumien bledow

		return EXIT_FAILURE;	//koniec niepowodenie
	}

	return 0;
}

int Sum1 (int a, int b) throw() {
	return a + b;
}

int Sum2 (int a, int b) throw(Bad) {
	if (a < 0) throw Bad (a, b);
	if (b < 0) throw Bad (a, b);

	return a + b;
}

void MyTerminate ()
{
	std::cout << "\n--- UWAGA: blad mechanizmu wyjatkow ---\n";

	system ("pause");

	exit (1);
}

int blad (int x)
{
	try
	{
		set_terminate (MyTerminate);
		try
		{
			if (x <= 9)
				throw 1;

			else
				throw - 1;
		}

		catch (...)
		{
			std::cout << "Przechodzi przez ogol i jest: ";

			throw;
		}
	}

	catch (int a)
	{
		if (a == 1)
			std::cout << "OK\n";
		else
			std::cout << "Zle\n";
	}

	return 0;
}

double Devide (double a, double b) {
	if (b == 0) throw(MyException ("Dzielenie przez 0"));	//jezeli zajdzie to rzuc wyjatek o nazwie("")
	if (b == 1) throw(std::exception ());		//wyjatek bez nazwy
	if (b == 2) throw(2);
	return a / b;
}

long long int* Alloc () {	//alokuje pamiec az jej zabraknie
	long long int* t;
	while (true) {
		t = new (std::nothrow) long long int[1000000];	//() nie rzucaj wyjatkow //a jak tego niema to wyrzuci std::bad_alloc //bez tego zadziala 
																															//funkcja fun_exception
		if (!t) throw(MyException ("Braklo pamieci"));	//samemu wyrzucam blad //tylko z tym w new (std::nothrow)
	}
	return t;
}

void command_a () {
	std::cout << "Doing a" << std::endl;
	float x;
	std::cin >> x;
	if (x < 0) {
		const char bad[] = "Nonnegative input expected in command a";
		throw bad;
	}
}

void fun_exeption () 
{
	std::cout << "set_new_halder work\n";
	throw std::bad_alloc();
}