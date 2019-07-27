#include "pch.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

int main_23 () {
	short c = 0;
	char znak;
	for (;;) {
		if (_kbhit ()) {
			znak = _getch ();
			if (znak == 'a')break;
		}

		c++;
		std::cout << c;

		Sleep (10);
		system ("cls");
	}

	return 0;
}