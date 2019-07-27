#include "pch.h"
#include <iostream>
#include <ctime>

#pragma warning (disable : 4996)

enum BIORHYTHM {
	BIO_PHYSICAL = 23,
	BIO_EMOTIONAL = 28,
	BIO_INTELECTUAL = 33
};

const double PI = 3.1415926538;

double biorhythm (double fDni, BIORHYTHM Cykl)
{
	return 100 * sin ((2 * PI / Cykl) * fDni);
}

int main_15 (){
	int choose{};

	std::cout << "Choose one\n"
		"1.Biorhythm\n"
		"2.Time to the year end\n"
		"what you choose: ";
	std::cin >> choose;

	system ("cls");

	switch (choose)
	{
	case 1: {
		tm birthday = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		tm today_is = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		tm time_difference = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

		std::cout << "Set your birth date:" << std::endl;
		std::cout << "- day: ";
		std::cin >> birthday.tm_mday;
		std::cout << "- month: ";
		std::cin >> birthday.tm_mon;

		birthday.tm_mon--;

		std::cout << "- year: ";
		std::cin >> birthday.tm_year;

		birthday.tm_year -= 1900;


		time_t time_1 = time (NULL);
		today_is = *localtime (&time_1);

		time_difference.tm_mday = today_is.tm_mday - birthday.tm_mday;
		time_difference.tm_mon = today_is.tm_mon - birthday.tm_mon;
		time_difference.tm_year = today_is.tm_year - birthday.tm_year;

		double life_days = time_difference.tm_year * 365.25
			+ time_difference.tm_mon * 30.4375
			+ time_difference.tm_mday;

		system ("cls");

		std::cout << "Your biorhythm" << std::endl;
		std::cout << "- physical: " << biorhythm (life_days, BIO_PHYSICAL)
			<< std::endl;
		std::cout << "- emotional: " << biorhythm (life_days,
			BIO_EMOTIONAL) << std::endl;
		std::cout << "- intellectual: " << biorhythm (life_days,
			BIO_INTELECTUAL) << std::endl;

		break;
	}

	case 2: {
		tm year_ends = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		tm actual_time = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		tm time_difference_2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

		time_t time_2 = time (NULL);
		actual_time = *localtime (&time_2);

		year_ends.tm_mday = 1;
		year_ends.tm_mon = 0;
		year_ends.tm_year = actual_time.tm_year + 1;

		time_difference_2.tm_mday = year_ends.tm_mday - actual_time.tm_mday;
		time_difference_2.tm_mon = year_ends.tm_mon - actual_time.tm_mon;
		time_difference_2.tm_year = year_ends.tm_year - actual_time.tm_year;

		double ends = time_difference_2.tm_year * 365.25
			+ time_difference_2.tm_mon * 30.4375
			+ time_difference_2.tm_mday;

		std::cout << "To the year end: " << round (ends) << " days left.\n";

		break;
	}
	}

	system ("pause");

	return 0;
}