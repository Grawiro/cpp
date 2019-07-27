#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm> //to transform
#include <regex>
#include <sstream> //to stringstream

using namespace std;

string odwrot (string);
unsigned int inside (string, string);
bool pali (string);

int main_9 () {

	string loop ("omgwtfbbg");
	cout << loop.at (3) << endl;

	string ham ("ham is spam oh yes i am!");
	cout << ham.find ("am") << endl;
	cout << ham.rfind ("am") << endl;

	string Ala_ma_kota = "Ala ma kota";
	transform (Ala_ma_kota.begin (), Ala_ma_kota.end (), Ala_ma_kota.begin (), ::toupper);
	cout << Ala_ma_kota << "\n";

	transform (Ala_ma_kota.begin (), Ala_ma_kota.end (), Ala_ma_kota.begin (), ::tolower);
	cout << Ala_ma_kota << "\n";

	string napis_na_cala_linie{};
	cout << "Napisz tekst i nacisnij enter: ";
	cin.ignore ();
	getline (cin, napis_na_cala_linie);
	cout << napis_na_cala_linie<<"\n";

	//**********************************************************************************************************

	std::string input;
	int age;
	getline (cin, input);
	stringstream (input) >> age;	//convertuje stringa na inta
	cout << age << "\n";

	//**********************************************************************************************************

	string address = "os. Brzozowe 150/333, 11-700 Mragowo, Polska";

	smatch matches;

	cout << "======================dopasowanie=====================\n";
	regex pattern ("(.*?)([0-9]+)(.*)");
	if (regex_match (address, matches, pattern)) {
		cout << "Find " << matches.size () << " matches!\n";
		for (unsigned int i = 0; i < matches.size (); i++) {
			cout << matches[i] << endl;
		}
	}

	cout << "======================przeszukiwanie1=====================\n";
	pattern = "[0-9]+([, -//]+)";
	while (regex_search (address, matches, pattern)) {
		for (auto x : matches) cout << "[" << x << "]";
		address = matches.suffix ().str ();
		cout << " ->  " << address << endl;
	}

	cout << "======================przeszukiwanie2=====================\n";
	address = "os. Brzozowe 150/333, 11-700 Mragowo, Polska";
	pattern = "[0-9]{2}";
	while (regex_search (address, matches, pattern)) {
		for (auto x : matches) cout << "[" << x << "]";
		address = matches.suffix ().str ();
		cout << " ->  " << address << endl;
	}

	cout << "======================przeszukiwanie3=====================\n";
	address = "os. Brzozowe 150/333, 11-700 Mragowo, Polska";
	pattern = "[a-zA-Z]+";
	while (regex_search (address, matches, pattern)) {
		for (auto x : matches) cout << x << "   ->  ";
		address = matches.suffix ().str ();
		cout << address << endl;
	}

	cout << "======================przeszukiwanie4=====================\n";
	address = "os. Brzozowe 150/333, 11-700 Mragowo, Polska";
	pattern = ".*?,";
	while (regex_search (address, matches, pattern)) {
		for (auto x : matches) cout << x << "   ->  ";
		address = matches.suffix ().str ();
		cout << address << endl;
	}

	cout << "======================przeszukiwanie5=====================\n";
	address = "os. Brzozowe 150/333, 11-700 Mragowo, Polska";
	pattern = "^.{10}";
	while (regex_search (address, matches, pattern)) {
		for (auto x : matches) cout << x << "   ->  ";
		address = matches.suffix ().str ();
		cout << address << endl;
	}

	cout << "======================przeszukiwanie6=====================\n";
	address = "os. Brzozowe 150/333, 11-700 Mragowo, Polska";
	pattern = "^.{1,5}";
	while (regex_search (address, matches, pattern)) {
		for (auto x : matches) cout << x << "   ->  ";
		address = matches.suffix ().str ();
		cout << address << endl;
	}

	cout << "======================podmiana1=====================\n";
	address = "os. Brzozowe 150/333, 11-700 Mragowo, Polska";
	cout << "Orginal: " << address << endl;

	pattern = "[a-zA-Z]{2}";
	address = regex_replace (address, pattern, ":-)");
	cout << "Changed: " << address;

	cout << "\n======================podmiana2=====================\n";
	address = "os. Brzozowe 150/333, 11-700 Mragowo, Polska";
	cout << "Orginal: " << address << endl;

	pattern = "[a-zA-Z]{2}(...)";
	address = regex_replace (address, pattern, "$1");
	cout << "Changed: " << address;

	cout << "\n======================podmiana2=====================\n";
	address = "os. Brzozowe 150/333, 11-700 Mragowo, Polska";
	cout << "Orginal: " << address << endl;

	pattern = "([0-9]{2})-([0-9]{3})";
	address = regex_replace (address, pattern, "$2-$1");
	cout << "Changed: " << address;

	//*************************************************************************************

	std::string s1 = "Tekst pierwszy.";
	string s2 = "Tekst drugi.";
	string s3 = s1 + "\t" + s2 + "\n";
	cout << "\n" <<s3;
	cout << s1[0] << s3[1] << endl;

	cout << endl;
	s1.append (s2);
	cout << s1 << endl;
	s1.append (s2, 6, 5);
	cout << s1 << endl;
	s1.append (10, '#');
	cout << s1 << endl;
	s1.append (5, 0x41);
	cout << s1 << endl;

	cout << endl;
	s1.assign ("Nowy tekst.");
	cout << s1 << endl;
	s1.assign (s2);
	cout << s1 << endl;
	s1.assign (s2, 6, 5);
	cout << s1 << endl;

	cout << endl;
	cout << s1.back () << endl;
	s1.back () = '!';
	cout << s1 << endl;

	cout << endl;
	for (string::iterator i = s1.begin (); i != s1.end (); i++) {
		cout << *i << " ";
	}
	cout << endl;
	for (auto i = s1.cbegin (); i != s1.cend (); i++) {
		cout << *i << " ";
	}
	cout << endl;
	for (auto i = s1.crbegin (); i != s1.crend (); i++) {
		cout << *i << " ";
	}
	cout << endl;

	cout << endl;
	cout << s1.capacity () << endl;
	cout << s1.size () << endl;
	cout << s1.length () << endl;
	cout << s1.max_size () << endl;

	cout << endl;
	s1.reserve (256);
	cout << s1.capacity () << endl;

	cout << endl;
	s1.clear ();
	cout << s1.capacity () << " " << s1.size () << endl;

	cout << endl;
	s1 = "Krowa";
	s2 = "Krowa i Byk";
	cout << s1.compare (s2) << " " << s2.compare (s1) << " ";
	s1 = 'A'; s2 = 'b';
	cout << s1.compare (s2) << " " << s2.compare (s1) << " ";
	s1 = s2 = "los";
	cout << s1.compare (s2) << " " << s2.compare (s1) << " ";

	cout << endl;
	cout << s1.c_str () << endl;

	cout << endl;
	cout << s1.empty () << endl;
	s1.clear ();
	cout << s1.empty () << endl;

	cout << endl;
	s1 = "Kocimietka";
	s1.erase (0, 4);
	s1.erase (4, 1);
	cout << s1 << endl;

	cout << endl;
	cout << s1.capacity () << " ";
	s1.shrink_to_fit ();
	cout << s1.capacity () << endl;

	cout << endl;
	s2 = "cytryna";
	s1.swap (s2);
	cout << s1 << " " << s2 << endl;


	cout << endl;
	s1 = "Chrzaszcz lata.";
	s2 = "Dzdzownica drazy.";
	cout << "s1 >" << s1 << endl;
	cout << "s2 >" << s2 << endl;

	cout << endl;
	s1.insert (10, s2);
	cout << s1 << endl;
	s1 = "Chrzaszcz lata.";
	s1.insert (10, "sobie ");
	cout << s1 << endl;
	s1 = "Chrzaszcz lata.";
	s1.insert (10, s2, 2, 8);
	cout << s1 << endl;
	s1 = "Chrzaszcz lata.";
	s1.insert (10, 5, '#');
	cout << s1 << endl;
	s1 = "Chrzaszcz lata.";
	s1.insert (s1.begin () + 10, s2.begin () + 2, s2.begin () + 6);
	cout << s1 << endl;

	cout << endl;
	s1 = "Chrzaszcz lata.";
	s2 = "Bak";
	s1.replace (0, 9, s2);
	cout << s1 << endl;
	s1 = "Chrzaszcz lata.";
	s2 = "Kostucha";
	s1.replace (0, 9, s2, 0, 3);
	cout << s1 << endl;
	s1.replace (s1.size () - 1, 1, 3, '!');
	cout << s1 << endl;
	s1.replace (s1.begin (), s1.begin () + 3, "Papuga");
	cout << s1 << endl;

	cout << endl;
	s1 = "Pan Nowak przejechal traktorem na czerwonym swietle.";
	cout << s1.substr (4, 5) << endl;

	cout << endl;
	cout << s1 << endl;
	s1.pop_back ();
	cout << s1 << endl;
	s1.push_back ('!');
	cout << s1 << endl;

	cout << endl;
	string txt = "Nowak";
	size_t found_index;
	found_index = s1.find (txt);
	cout << s1 << endl << found_index << endl;
	found_index = s1.find ("rabarbar");
	cout << found_index << endl;

	cout << endl;
	found_index = -1;
	while ((found_index = s1.find ('a', found_index + 1)) != string::npos) {
		cout << "a = " << found_index << endl;
	}

	cout << endl;
	s1 = "Pan Nowak przejechal traktorem na czerwonym swietle.";
	txt = "prc";
	found_index = -1;
	cout << s1 << endl;
	while ((found_index = s1.find_first_of (txt, found_index + 1)) != string::npos) {
		s1[found_index] = '*';
	}
	cout << s1 << endl;

	cout << endl;
	s1 = "Pan Nowak przejechal traktorem na czerwonym swietle.";
	txt = "prc";
	found_index = -1;
	while ((found_index = s1.find_last_of (txt, found_index - 1)) != string::npos) {
		s1[found_index] = '*';
	}
	cout << s1 << endl;

	cout << endl;
	s1 = "Pan Nowak przejechal traktorem na czerwonym swietle.";
	txt = "prc";
	found_index = -1;
	while ((found_index = s1.find_first_not_of (txt, found_index + 1)) != string::npos) {
		s1[found_index] = '*';
	}
	cout << s1 << endl;

	cout << endl;
	char napis[20] = "Ptak";
	cout << strlen (napis) << " " << sizeof (napis) << " " << napis << endl;

	cout << endl;
	for (int i = 0; i < sizeof (napis); i++) {
		cout << napis[i] << " " << (int)napis[i] << endl;
	}

	cout << endl;
	char txt1[] = "Grzyb";
	cout << sizeof (txt1) << " " << strlen (txt1) << " " << txt1 << endl;
	for (unsigned int i = 0; i <= strlen (txt1); i++) {
		cout << txt1[i] << " " << (int)txt1[i] << endl;
	}
	cout << endl;
	char txt2[] = { 'A','B','C','\0' };
	for (int i = 0; i < sizeof (txt2); i++) {
		cout << txt2[i];
	}
	cout << endl;

	cout << endl;
	const char* t = "Rabarbar";

	char txt3[] = "Batonik!";
	printf ("\n%s", txt3);
	printf ("\n%s %s", txt3, txt2);
	printf ("\n%s %s %d %.2f %020d \n", txt3, txt2, 100, 12.123345, -10);

	string txt4 = "Rower";
	printf ("\n%s \n", txt4.c_str ());

	int v1;
	float v2;
	scanf_s ("%d %f", &v1, &v2);
	cout << v1 << " " << v2 << endl;

	cout << endl;
	char txt5[10] = "rak";
	char txt6[10] = "czapla";
	cout << txt5 << " " << txt6 << endl;
	cout << strcmp (txt5, txt6) << endl;

	cout << endl;
	strcpy_s (txt5, "zaba");
	strcpy_s (txt6, "zaba");
	cout << txt5 << " " << txt6 << endl;
	cout << strcmp (txt5, txt6) << endl;

	cout << endl;
	strcat_s (txt5, txt6);
	cout << txt5 << " " << txt6 << endl;
	printf ("%s %s\n", txt5, txt6);

	cout << endl;
	cout << strchr (txt5, 'a') << endl;
	if (strchr (txt6, 'y') == NULL) cout << "NULL" << endl;

	cout << endl;
	char txt7[] = "rok2019";
	char txt8[] = "1234567890";
	size_t z = strcspn (txt7, txt8);
	cout << txt7 << " " << z << " " << txt7[z] << endl;

	cout << endl;
	char txt9[] = "Alibaba i 40 rozbojnikow";
	char* p = strstr (txt9, "40");
	cout << p << endl;

	cout << endl;
	string samo = "aeiouy", napis1 = "to jest dowolny napis";
	int ile = 0;
	size_t found_index_1 = -1;
	while ((found_index_1 = napis1.find_first_of (samo, found_index_1 + 1)) != string::npos) {
		ile++;
	}
	cout << ile;


	cout << endl;
	cout << endl;
	string als = "elo pamelo";
	cout << odwrot (als) << endl;

	cout << endl;
	cout << inside ("ba", "to jest bardzo fajny tekst do badan nad balansem barometru na bance mydlanej") << endl;

	cout << endl;
	cout << pali ("kajak") << " " << pali ("zaba") << " " << pali ("frghgrf") << endl;

	cout << endl;
	string s = "w tym bob tekscie powinnonniwop byc ze trzy, moze czterery palindromy";
	int maks = s.size ();
	for (int len = maks; len >= 3; len--) {
		int r = maks - len;
		for (int i = 0; i + len < maks; i++) {
			if (pali (s.substr (i, len))) cout << "Znaleziono palindrom: [" << s.substr (i, len) << "]\n";
		}
	}

	cout << endl;
	s = "ul. Kwiatow 8/3a, 11-700 Gora Wiatrow-przyplywow";
	size_t is = -1;
	while ((is = s.find ("-", is + 1)) != string::npos) {
		string temp = s.substr (is - 2, 6);
		if (temp.find_first_of ("0123456789") == 0)
			cout << "Prawdopodobny kod pocztowy: " << temp << "\n";
	}

	cout << endl;
	size_t pointer = 0;
	string temp3 = "210 2A 100011 0xff";
	cout << temp3 << endl;
	int a = stoi (temp3, &pointer, 10);
	cout << a << " " << pointer << endl;
	int b = stoi (temp3.erase (0, pointer), &pointer, 16);
	cout << b << " " << pointer << endl;
	int c = stoi (temp3.erase (0, pointer), &pointer, 2);
	cout << c << " " << pointer << endl;
	int d = stoi (temp3.erase (0, pointer), &pointer, 0);
	cout << d << " " << pointer << endl;

	cout << endl;
	cout << to_string (0xFF) + to_string (0101) + to_string (0b111) << endl;




	string info = " NIE DZIALA antena satelitarna ";
	int szer = info.size () + 6;
	string kreska (szer, '*');
	string alarm = kreska + "\n";
	alarm += "*!*" + info + "*!*\n";
	alarm += kreska;

	cout << alarm << endl;









	return 0;
}

string odwrot (string s) {

	string se = s;

	for (unsigned int i = 0; i < s.size (); i++) {
		se[i] = s[(s.size () - 1) - i];
		if (se[i] == ' ') {
			se[i] = '_';
		}
	}

	return se;
}

unsigned int inside (string s1, string s2) {
	unsigned int ile = 0;
	size_t is = -1;
	while ((is = s2.find (s1, is + 1)) != string::npos) ile++;
	return ile;
}

bool pali (string s) {
	string news = "";
	for (int i = s.size () - 1; i >= 0; i--) {
		news += s[i];
	}
	if (s.compare (news) == 0) return true;
	return false;
}