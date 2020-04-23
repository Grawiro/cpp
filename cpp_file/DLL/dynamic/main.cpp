#include <Windows.h>	//potrzebne funkcje
#include <iostream>	//to tylko do pokazania wyniku

typedef int (*Sum_fun )(int, int);	//typ funkcyjny //musi miec takie same parametry jak nasza funkcja w dll

int main () {

	Sum_fun sum;		//tworzymy obiekt ktory bedzie nasza funkcja
	HINSTANCE hInstLibrary = LoadLibrary (L"DLL.dll");		//uchwyt do instanci (do biblioteki dll)

	if (hInstLibrary) {		//sprawdzamy czy istnieje
		sum = (Sum_fun)GetProcAddress (hInstLibrary, "Sum");	//zrzutuj wynik wyciganiecia adresu z funkcji o nazwie Sum
		if (sum) {		//czy udalo sie odtworzyc
			std::cout << sum (1, 3);	//wywolanie funkcji

			std::cin.get ();
		}
		FreeLibrary (hInstLibrary);		//zwalnia pamiec z naszego uchwytu 
	}

	return 0;
}