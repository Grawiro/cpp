#include "pch.h"
#include <iostream>

int main_12 ()
{
	int dec = 100;
	int hex = 0x100;
	int oct = 0100;
	int bin = 0b100;

	std::cout << "dec = " << dec << ", hex = " << hex << ", oct = " << oct << ", bin = " << bin << std::endl;
	std::cout << 22 << ", " << 0x22 << ", " << 022 << ", " << 0b11 << ".\n";

	system ("pause");
	return 0;
}