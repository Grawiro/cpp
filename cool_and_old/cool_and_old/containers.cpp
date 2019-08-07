#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <queue>
#include <unordered_map>
#include <array>

int main_7 () {

	std::vector<double> arrayFirst;
	std::vector<int> arraySecond{ 2,4,5,6,7,8,9 };

	arrayFirst.push_back (12.3);
	arrayFirst.push_back (3);
	arrayFirst.push_back (1.5);

	arraySecond.push_back (0);

	arrayFirst.pop_back ();

	std::cout << arrayFirst[0] << "\n";
	std::cout << arrayFirst[1] << "\n";
	std::cout << arrayFirst.size () << "\n";

	/*------------------------------------------------------*/

	std::vector<char> arrayChar (3, '.');	//array of 3 char in all value is a .
	std::vector<int> arrayInt (10);		//array 10 elements

	arrayChar[1] = '*';

	std::vector<std::string> arrayString;
	arrayString.push_back ("Hello");
	arrayString.push_back ("Bye");

	arrayChar.erase (arrayChar.begin (), arrayChar.end ());		//clear all vector
	arrayChar.resize (3);		//set size to 3

	arrayString.clear ();

	/*------------------------------------------------------*/

	std::vector<std::pair<double, int>> doubleTable{ {1.3,1},{4.3,4},{3.4,5} };

	doubleTable[2].first = 0;	//first value or second value i this row
	doubleTable[0].second = 99;

	std::cout << "\n";

	for (auto& element : doubleTable) {		//this work on the orginal doubleTable
		std::cout << element.first << " " << element.second << "\n";
		element.first = 1;
	}

	std::cout << "\n";

	for (auto element : doubleTable) {		//this work on the copy doubleTable
		std::cout << element.first << " " << element.second << "\n";
	}

	/*-----------------------------------------------------------------*/

	std::cout << "\n";

	std::stack<int> stackOfNubers;

	stackOfNubers.push (132);
	stackOfNubers.push (1);
	stackOfNubers.pop ();
	stackOfNubers.push (90);

	std::cout << stackOfNubers.size () << "\n";
	std::cout << stackOfNubers.top () << "\n";

	/*-----------------------------------------------------------------*/

	std::cout << "\n";

	std::list<double> listOfNumbers;

	listOfNumbers.emplace (listOfNumbers.begin (), 10.3);	//add to begin
	listOfNumbers.push_front (4.5);
	listOfNumbers.pop_front ();
	listOfNumbers.push_back (1.23);
	listOfNumbers.emplace_front (4.5);

	std::list<double>::iterator listOfNumbersMove = listOfNumbers.begin ();
	listOfNumbersMove++;
	listOfNumbersMove++;

	listOfNumbers.emplace (listOfNumbersMove, 99);	//add to 3 place

	std::cout << listOfNumbers.front () << " " << listOfNumbers.back () << "\n";

	listOfNumbers.sort ();
	listOfNumbers.remove (99);		//remove this value
	listOfNumbers.erase (listOfNumbers.begin ());		//remove first value
	listOfNumbers.clear ();		//remove all value

	/*-----------------------------------------------------------------*/

	std::cout << "\n";

	std::queue<std::string> queueOfString;
	queueOfString.push ("Hello");
	queueOfString.emplace ("Bye");
	queueOfString.pop ();
	queueOfString.push ("Good bye");
	std::cout << queueOfString.front () << " / " << queueOfString.back () << "\n";

	/*-----------------------------------------------------------------*/

	std::cout << "\n";

	std::deque<int> twoTail;	//two ends
	twoTail.push_back (1);
	twoTail.push_front (1);
	twoTail.pop_front ();
	twoTail.insert (twoTail.begin () + 1, 4);	//add to 2 place value 4

	/*-----------------------------------------------------------------*/

	std::priority_queue<int, std::vector<int>, std::greater<int>> priorityNumberG;	//sort by greater
	priorityNumberG.push (15);
	priorityNumberG.push (5);
	priorityNumberG.push (0);
	priorityNumberG.push (50);

	std::priority_queue<int, std::vector<int>, std::less<int>> priorityNumberL;	//sort by less
	priorityNumberL.push (15);
	priorityNumberL.push (5);
	priorityNumberL.push (0);
	priorityNumberL.push (50);

	/*-----------------------------------------------------------------*/

	std::unordered_map<std::string, int> map = { {"Hello",4}, {"Bye",5} };
	map.emplace ("Good bye", 1);
	map.emplace ("Good morning", 3);
	map.emplace ("Good morning", 20);	//this is not work
	map["Good morning"] = 30;	//good morning = 30;

	std::cout << map.count ("Bye") << "\n";	//exists?

	map.erase ("Hello");	//delete hello and his value
	map.clear ();		//delete all value;

	/*-----------------------------------------------------------------*/

	std::cout << "\n";

	std::array<int, 10> array;	//this is normal array but more expanded
	array[0] = 3;
	array[9] = 0;
	std::cout << array.size () << "\n";

	return 0;
}