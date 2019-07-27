#include "pch.h"
#include <iostream>
#include <random>
#include <chrono>

std::mt19937 generator (static_cast<unsigned int>(std::chrono::system_clock::now ().time_since_epoch ().count ()));
std::uniform_int_distribution<int> compartment (1, 100);

int main_3 ()
{
	for (;;)
	{
		int random_1{ compartment (generator) };

		std::cout << "Guess the number from the range 1-100. (-1 Exit.)" << std::endl;

		int chosen;

		std::cout << "Give the number: ";
		std::cin >> chosen;

		if (chosen == -1)
			break;

		int queue = 1;

		while (chosen != random_1)
		{
			queue++;

			if (chosen < random_1)
				std::cout << "too low. ";
			else
				std::cout << "too high. ";

			std::cout << "Please try again: ";
			std::cin >> chosen;
		}

		std::cout << std::endl << "You win!" << std::endl;
		std::cout << "You guessed it for " << queue << " together.";

		system ("pause");
		system ("cls");
	}

	return 0;
}