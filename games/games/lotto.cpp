#include "pch.h"
#include <iostream>
#include <chrono>
#include <random>

#pragma warning (disable : 4996)

int main_2 () {

	std::mt19937 generator (static_cast<unsigned int>(std::chrono::system_clock::now ().time_since_epoch ().count ()));
	std::uniform_int_distribution<int> compartment (1, 49);

	int randomNumber[6]{};
	int choose[6]{};
	int point{};

	std::cout << "Lotto / 6 number 1 to 49\n\n";

	for (int i = 0; i < 6; i++) {
	choose_number:
		std::cout << "Please choose your " << i + 1 << " numer: ";
		std::cin >> choose[i];

		if (choose[i] < 1 || choose[i]>49) {
			std::cout << "this number is incorrect. please choose number again.\n";
			goto choose_number;
		}

		for (int j = 0; j < i; j++) {
			if (choose[i] == choose[j]) {
				std::cout << "you choose this number. please choose number again.\n";
				goto choose_number;
			}
		}
	}

	for (int i = 0; i < 6; i++) {
	rand_number:
		randomNumber[i] = (compartment (generator));

		for (int j = 0; j < i; j++) {
			if (randomNumber[i] == randomNumber[j]) {
				goto rand_number;
			}
		}
		std::cout << randomNumber[i] << "\t";
		_sleep (1000);
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (choose[i] == randomNumber[j]) {
				point++;
			}
		}
	}

	std::cout << "\nyou earn " << point << " point.\n";

	system ("pause");

	return 0;
}