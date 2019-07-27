#include "pch.h"
#include <iostream>

int multiplyV1 (int a, int b) {
	return a * b;
}

int multiplyV2 (int (*pointer)(int, int), int a, int b) {
	return pointer (a, b);
}

int __fastcall multiplyV3 (int a, int b) {
	return a * b;
}

int main_8 () {

	int (*pointerToMultiplyV1) (int, int);
	pointerToMultiplyV1 = multiplyV1;	//& is not a compulsory

	std::cout << multiplyV1 (3, 4) << "\n";
	std::cout << pointerToMultiplyV1 (3, 4) << "\n";
	std::cout << (*pointerToMultiplyV1) (3, 4) << "\n";

	std::cout << "\n";

	std::cout << multiplyV2 (multiplyV1, 3, 4) << "\n";


	std::cout << "\n";

	int (__fastcall *pointerToMultiplyV3) (int, int);
	pointerToMultiplyV3 = multiplyV3;

	std::cout << multiplyV3 (3, 4) << "\n";
	std::cout << pointerToMultiplyV3 (3, 4) << "\n";
	std::cout << (*pointerToMultiplyV3) (3, 4) << "\n";

	return 0;
}