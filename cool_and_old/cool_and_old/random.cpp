#include "pch.h"
#include <iostream>
#include <random>
#include <chrono>

std::mt19937 generator_1 (static_cast<unsigned int>(std::chrono::system_clock::now ().time_since_epoch ().count ()));
std::uniform_int_distribution<int> compartment_1 (1, 10);

int main_3 () {

	int randomNumber_1{ compartment_1 (generator_1) };

	srand ((int)time (NULL));
	int randomNumber_2 = rand () % 10 + 1;

	for (int i = 0; i < 10; i++) {
		std::cout << "n-" << randomNumber_1 << "\n";
		std::cout << "s-" << randomNumber_2 << "\n";

		randomNumber_1 = compartment_1 (generator_1);
		randomNumber_2 = rand () % 10 + 1;
	}

	return 0;
}