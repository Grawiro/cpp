#include "pch.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string PLN (double pln) {
	stringstream ss;
	int zl = (int)pln;
	double gr = (pln - zl) * 100;
	if (zl == 0)ss << gr << " gr";
	else ss << zl << " zl " << gr << " gr";
	return ss.str ();
}

int main_1 () {
	vector<double>coins = { 0.01,0.02,0.05,0.1,0.2,0.5,1.0,2.0,5.0,10.0,20.0,50.0,100.0,200.0 };
	double R = 127.99;

	double r = R;
	cout << "Wariant 1 " << R << ":\n";
	for (int i = coins.size () - 1; i >= 0; i--) {
		while (r - coins[i] >= -0.0001) {
			cout << "\t" << PLN (coins[i]) << endl;
			r = r - coins[i];
		}
	}

	cout << "Wariant 2 " << R << ":\n";
	vector<pair<double, unsigned>> cash = {
		{0.01,10},
		{0.02,5},
		{0.05,0},
		{0.1,20},
		{0.2,20},
		{0.5,20},
		{1.0,1},
		{2.0,3},
		{5.0,0},
		{10.0,5},
		{20.0,5},
		{50.0,0},
		{100.0,1},
		{200.0,1},
	};
	r = R;
	for (int i = coins.size () - 1; i >= 0; i--) {
		while (cash[i].second > 0 && r - coins[i] >= -0.0001) {
			cout << "\t" << PLN (coins[i]) << endl;
			r = r - coins[i];
			cash[i].second--;
		}
	}
	if (r >= 0.01)cout << "Nie mozna wydac reszty. Brak srodkow.\n";

	for (auto x : cash) {
		cout << PLN (x.first) << " " << x.second << endl;
	}

	return 0;
}