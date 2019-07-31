#include <Windows.h>
#include <iostream>

typedef int (*add_function)(int, int);
typedef int (*multiply_function)(int, int);

int main()
{
	add_function add_local;
	multiply_function multiply_local;

	HINSTANCE hInstLibrary = LoadLibrary (L"math_function_dll.dll");

	if (hInstLibrary) {
		add_local = (add_function)GetProcAddress (hInstLibrary, "add");
		multiply_local = (multiply_function)GetProcAddress (hInstLibrary, "multiply");

		if (add_local) {
			std::cout << add_local (1, 4) << std::endl;
		}
		if (multiply_local) {
			std::cout << multiply_local (0, 4) << std::endl;
		}

		system ("pause");

		FreeLibrary (hInstLibrary);
	}

	return 0;
}