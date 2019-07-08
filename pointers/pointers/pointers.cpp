#include "pch.h"
#include <iostream>

int main ()
{
	int *pointer{ reinterpret_cast<int*>(0xa2ff4) };
	std::cout << "pointer = " << reinterpret_cast<int>(pointer);

	pointer = nullptr;
	if (!pointer) 	//if (pointer == nullptr) //it's the same //pointer is 0
	{
		std::cout << "\npointer = " << reinterpret_cast<int>(pointer);
	}
}