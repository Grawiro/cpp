#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>	//to transform

class Quiz {
public:
	std::string title, a, b, c, d, good, answer;
	int number, point;

	void get ();
	void ask ();
	void check ();
};

class Tom {
public:
	int a, b;
};

struct Term {
	double p;
	std::string s;
};

int main_6 () {
	int x = 3;
	int y{};

	Tom tomek, bob;
	tomek.a = 1;
	tomek.b = 2;

	Term termy, ter;
	termy.p = 32.4;
	termy.s = "hello";

	int sizeStr = termy.s.size ();

	std::ofstream out ("file.dat", std::ios::binary);
	if (out.is_open ()) {
		out.write ((char*)&x, sizeof (x));
		out.write ((char*)&tomek, sizeof (Tom));
		out.write ((char*)&termy.p, sizeof (termy.p));
		out.write ((char*)&sizeStr, sizeof (int));
		out.write (termy.s.c_str (), sizeStr);
		out.close ();
	}

	int sizeString{};	//aby zapisac i odczytac stringa

	std::ifstream in ("file.dat", std::ios::binary);
	if (in.is_open ()) {
		in.read ((char*)&y, sizeof (y));
		in.read ((char*)&bob, sizeof (Tom));
		in.read ((char*)&ter.p, sizeof (ter.p));
		in.read ((char*)&sizeString, sizeof (int));
		ter.s.resize (sizeString);
		in.read ((char*)&ter.s[0], sizeString);

		in.close ();
	}
	std::cout << y << "\t" << ter.p << "\t" << sizeString <<"\t"<< ter.s << std::endl;
	/*--------------------------------------------------------------------*/

	//write file with the out extension
	std::ofstream piOut ("pi.out");
	piOut << 3.14159 << std::endl;
	piOut.close ();

	/*--------------------------------------------------------------------*/
	double pi{ 0 };
	std::ifstream piIn ("pi.out");
	piIn >> pi;
	piIn.close ();

	std::cout << pi << "\n";
	std::cin.get ();
	system ("cls");

	/*--------------------------------------------------------------------*/

	std::string namesOut[]{ "Bartek","Ala","Kuba","Mateusz","Kamil","Arutr" };
	int namesSizeOut = namesOut->size ();

	//write file with the txt extension
	std::ofstream nameOut ("name.txt");
	if (nameOut.is_open ()) {
		nameOut << namesSizeOut << "\n";
		for (int i = 0; i < namesSizeOut; i++) {
			nameOut << namesOut[i] << "\n";
		}

		nameOut.close ();
	}

	/*--------------------------------------------------------------------*/

	std::string namesIn[15];
	int nameSizeIn;

	//read file with the txt extension
	std::ifstream nameIn ("name.txt");
	if (nameIn.is_open ()) {
		nameIn >> nameSizeIn;
		for (int i = 0; i < nameSizeIn; i++) {
			nameIn >> namesIn[i];
			//std::cout << namesIn[i] << "\n";					//this working to
		}

		nameIn.close ();
	}

	/*--------------------------------------------------------------------*/

	std::string lines[10];
	int index{ 0 };

	//eof												//another method
	std::fstream showNames ("name.txt", std::ios::in);
	if (showNames.good ()) {
		while (!showNames.eof ()) {
			std::getline (showNames, lines[index]);
			std::cout << lines[index] << "\n";
			index++;
		}

		showNames.close ();
	}

	/*--------------------------------------------------------------------*/

	std::cin.get ();
	system ("cls");

	Quiz quiz[5];
	int allPoint = 0;

	for (int i = 0; i <= 4; i++)
	{
		quiz[i].number = i + 1;
		quiz[i].get ();
		quiz[i].ask ();
		quiz[i].check ();
		allPoint += quiz[i].point;
	}

	std::cout << "You earned : " << allPoint << " points.";

	/*--------------------------------------------------------------------*/

	//write file with the csv (excel) extension
	std::ofstream arrayOut ("dane.csv");
	if (arrayOut.is_open ()) {
		for (int column = 1; column <= 20; column++) {
			for (int row = 1; row <= 6; row++) {
				arrayOut << column * row;
				if (row != 6) arrayOut << ',';
			}
			if (column != 20) arrayOut << std::endl;
		}

		arrayOut.close ();
	}

	/*--------------------------------------------------------------------*/

	std::cin.ignore ();
	std::cin.get ();
	system ("cls");

	//read file with the csv (excel) extension
	std::ifstream arrayIn ("dane.csv");
	if (arrayIn.is_open ()) {
		int temp;
		for (int column = 1; column <= 20; column++) {
			for (int row = 1; row <= 6; row++) {
				arrayIn >> temp;
				std::cout << temp;
				if (row != 6) {
					std::cout << "\t";
					arrayIn.ignore (1, ',');
				}
			}
			if (column != 20) std::cout << std::endl;
		}

		arrayIn.close ();
	}

	/*--------------------------------------------------------------------*/

	std::cin.ignore ();
	std::cin.get ();
	system ("cls");

	std::string playerName;
	int playerMoney;

	//write the some information to the file
	std::ofstream dataOut ("playerData.txt");
	if (dataOut.is_open ()) {
		std::cout << "Enters the players name and money\n"
			"Press Ctrl+Z to quit\n";

		while (std::cin >> playerName >> playerMoney) {
			dataOut << playerName << " " << playerMoney << std::endl;
		}

		dataOut.close ();
	}

	/*--------------------------------------------------------------------*/

	//read the some information to the file
	std::ifstream dataIn ("playerData.txt");
	if (dataIn.is_open ()) {

		while (dataIn >> playerName >> playerMoney) {
			std::cout << playerName << '/' << playerMoney << "\n";
		}

		dataIn.close ();
	}

	return 0;
}

void Quiz::get ()
{
	std::fstream quiz;
	quiz.open ("quiz.txt", std::ios::in);
	if (quiz.good () == true) {

		int lineNumber = (number - 1) * 6 + 1;
		int now = 1;
		std::string line;

		while (getline (quiz, line))
		{
			if (now == lineNumber) title = line;
			if (now == lineNumber + 1) a = line;
			if (now == lineNumber + 2) b = line;
			if (now == lineNumber + 3) c = line;
			if (now == lineNumber + 4) d = line;
			if (now == lineNumber + 5) good = line;

			now++;
		}
		quiz.close ();
	}
}

void Quiz::ask ()
{
	std::cout << title << "\n";
	std::cout << "A." << a << "\n";
	std::cout << "B." << b << "\n";
	std::cout << "C." << c << "\n";
	std::cout << "D." << d << "\n";
	std::cout << "------------------------------------" << "\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	system ("cls");
}

void Quiz::check ()
{
	transform (answer.begin (), answer.end (), answer.begin (), ::tolower);
	if (answer == good) point = 1;
	else point = 0;
}