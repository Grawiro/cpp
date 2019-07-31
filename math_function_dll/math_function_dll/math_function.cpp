#include "math_function.h"

extern "C"
{
	EXPORT int add (int a, int b){
		return a + b;
	}

	EXPORT int multiply (int a, int b) {
		if (a == 0 || b == 0) {
			return 10;
		}
		return a * b;
	}
}