#include "pch.h"
#include <iostream>
#include <random>
#include <chrono>

std::mt19937 generator (static_cast<unsigned int>(std::chrono::system_clock::now ().time_since_epoch ().count ()));
std::uniform_int_distribution<int> compartment (1, 10);

int randomNumber = compartment (generator);

int main_3 () {
	for (int i = 0; i < 10; i++) {
		std::cout << randomNumber << "\n";

		randomNumber = compartment (generator);
	}

	return 0;
}