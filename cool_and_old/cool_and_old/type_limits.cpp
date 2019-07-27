#include "pch.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

template <typename T>
void type_information (string type)
{
	cout << setw (18)
		<< type << ":"
		<< setw (2) << sizeof (T)
		<< "|"
		<< setw (2)
		<< numeric_limits<T>::digits
		<< (numeric_limits<T>::is_signed ? "|s|" : "|u|")
		<< "[" << numeric_limits<T>::min ()
		<< ", " << numeric_limits<T>::max ()
		<< "]\n";
}

int main_11 ()
{
	cout << "int: "
		<< numeric_limits<int>::digits
		<< " bits, "
		<< (numeric_limits<int>::is_signed ? "signed " : "unsigned ")
		<< " bytes: "
		<< sizeof (int)
		<< " [" << numeric_limits<int>::min ()
		<< ", " << numeric_limits<int>::max ()
		<< "]\n";

	cout << "\nInformation of type:\n";

	cout << "               char: "
		<< sizeof (char)
		<< "|"
		<< numeric_limits<char>::digits
		<< (numeric_limits<char>::is_signed ? "|s|" : "|u|")
		<< "[" << (int)numeric_limits<char>::min ()
		<< ", " << (int)numeric_limits<char>::max ()
		<< "]\n";

	cout << " \nTemplate:\n";

	type_information<short int> ("short int");
	type_information<signed short int> ("signed short int");
	type_information<unsigned short int> ("unsigned short int");
	type_information<int> ("int");
	type_information<signed int> ("signed int");
	type_information<unsigned int> ("unsigned int");

	cout << "\n";

	type_information<long int> ("long int");
	type_information<signed long int> ("signed long int");
	type_information<unsigned long int> ("unsigned long int");

	cout << "\n";

	type_information<long long int> ("long long int");
	type_information<signed long long int> ("signed long long int");
	type_information<unsigned long long int> ("unsigned long long int");

	cout << "\n";

	type_information<float> ("float");
	type_information<double> ("double");
	type_information<long double> ("long double");

	cout << "\n";

	type_information<bool> ("bool");

	cout << "\n";

	type_information<char> ("char");
	type_information<signed char> ("signed char");
	type_information<unsigned char> ("unsigned char");
	type_information<wchar_t> ("wchar_t");
	type_information<char16_t> ("char16_t");
	type_information<char32_t> ("char32_t");

	cout << "\n";

	type_information<int8_t> ("int8_t");
	type_information<uint8_t> ("uint8_t");
	type_information<int16_t> ("int16_t");
	type_information<uint16_t> ("uint16_t");
	type_information<int32_t> ("int32_t");
	type_information<uint32_t> ("uint32_t");
	type_information<int64_t> ("int64_t");
	type_information<uint64_t> ("uint64_t");

	cout << "\n";

	type_information<int_least8_t> ("int_least8_t");
	type_information<uint_least8_t> ("uint_least8_t");
	type_information<int_least16_t> ("int_least16_t");
	type_information<uint_least16_t> ("uint_least16_t");
	type_information<int_least32_t> ("int_least32_t");
	type_information<uint_least32_t> ("uint_least32_t");
	type_information<int_least64_t> ("int_least64_t");
	type_information<uint_least64_t> ("uint_least64_t");

	cout << "\n";

	type_information<int_fast8_t> ("int_fast8_t");
	type_information<uint_fast8_t> ("uint_fast8_t");
	type_information<int_fast16_t> ("int_fast16_t");
	type_information<uint_fast16_t> ("uint_fast16_t");
	type_information<int_fast32_t> ("int_fast32_t");
	type_information<uint_fast32_t> ("uint_fast32_t");
	type_information<int_fast64_t> ("int_fast64_t");
	type_information<uint_fast64_t> ("uint_fast64_t");

	cout << "\n";

	type_information<intmax_t> ("intmax_t");
	type_information<uintmax_t> ("uintmax_t");

	cout << "\n";

	type_information<intptr_t> ("intptr_t");
	type_information<uintptr_t> ("uintptr_t");

	cout << "\n";

	system ("pause");
	return 0;
}