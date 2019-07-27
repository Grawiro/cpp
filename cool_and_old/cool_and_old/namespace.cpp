#include "pch.h"
#include <iostream>

namespace level_1 {
	void number_1 () {
		std::cout << "1 in level 1\n";
	}
}
namespace level_2 {
	void number_1 () {
		std::cout << "1 in level 2\n";
	}
	void number_2 () {
		std::cout << "2 in level 2\n";
	}
}
namespace level_3 {
	void number_1 () {
		std::cout << "1 in level 3\n";
	}
	void number_2 () {
		std::cout << "2 in level 3\n";
	}
}
namespace {
	void number_3 () {
		std::cout << "3 in non level\n";
	}
	void number_4() {
		std::cout << "4 in non level\n";
	}
}

using namespace level_2;

int main_17 ()
{
	level_1::number_1 ();
	level_2::number_1 ();
	number_2 ();
	level_3::number_1 ();
	level_3::number_2 ();
	number_3 ();
	number_4 ();

	system ("pause");

	return 0;
}