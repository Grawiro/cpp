#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mysort (pair<double, double>& x1, pair<double, double>& x2);

int main_2 () {
	vector<pair<double, double>>items = {
		{2.5,4.0}, {12,30.0}, {5,1.0}, {3.2,5.5}, {7,1.5}, {12,19.5}, {0.5,0.08}, {9.5,7.8}, {0.2, 0.003},
		{2.1,2.0}, {16,31.0}, {15,1.0}, {6.2,4.5}, {71,0.5}, {1,0.59}, {0.9,0.9}, {19.5,1.8}, {6.8, 1.05}
	};

	sort (items.begin (), items.end (), mysort);

	for (auto x : items) {
		cout << x.first << "=>" << x.second << " profit=" << x.second / x.first << endl;
	}
	cout << endl;
	cout << "nieskaczona liczba przedmiotow:" << endl;

	double backpack = 100;
	for (auto x : items) {
		int nr = 0;
		while (backpack >= x.first) {
			backpack -= x.first;
			nr++;
		}
		if (nr) cout << "put in " << x.first << "/" << x.second << " items x" << nr << endl;
	}
	cout << "Backpack size is " << 100 - backpack << "/100\n";

	cout << endl;
	cout << "Tylko po 1 przedmiocie:" << endl;

	backpack = 100;
	for (auto x : items) {
		int nr = 0;
		while (backpack >= x.first) {
			backpack -= x.first;
			nr++;
			break;
		}
		if (nr) cout << "put in " << x.first << "/" << x.second << " items x" << nr << endl;
	}
	cout << "Backpack size is " << 100 - backpack << "/100";

	return 0;
}

bool mysort (pair<double, double>& x1, pair<double, double>& x2)
{
	return (x1.second / x1.first > x2.second / x2.first);
}