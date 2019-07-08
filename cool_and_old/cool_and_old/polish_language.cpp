#include "pch.h"
#include <iostream>
#include <string>
#include <io.h> 
#include <fcntl.h>

int main_4 () {
	//setlocale (LC_ALL, " "); //mayby this is working to

	_setmode (_fileno (stdout), _O_U16TEXT);

	std::wstring hello_1 = L"hello world ółążęźćń ☺☻♥♦♣♠•◘○◙♂♀♪♫☼►◄↕‼¶§▬↨↑↓→←∟↔▲▼";

	std::wcout << L"hello world ółążęźćń ☺☻♥♦♣♠•◘○◙♂♀♪♫☼►◄↕‼¶§▬↨↑↓→←∟↔▲▼\n";
	std::wcout << hello_1 << "\n";

	return 0;
}