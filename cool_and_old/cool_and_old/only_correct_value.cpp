#include "pch.h"
#include <iostream>

int main_18 () {
	int i{};

	std::cin >> i;
	if (std::cin.good () == false) {
		std::cin.clear ();
		std::cin.ignore (INT_MAX, '\n');
		std::cout << "bledna wartosc\n";
		i = 0;
	}
	else {
		std::cout << i << "\n";
	}


	return 0;
}