#include "pch.h"
#include <iostream>

using namespace std;

unsigned long long int step = 0;

void hanoi (int n, char a, char b, char c) {
	if (n != 0) {

		hanoi (n - 1, a, c, b);
		cout << a << c << " ";
		step++;
		hanoi (n - 1, b, a, c);
	}
}

int main_3 () {

	hanoi (8, 'A', 'B', 'C'); cout << "  |" << step << endl; step = 0;

	return 0;
}