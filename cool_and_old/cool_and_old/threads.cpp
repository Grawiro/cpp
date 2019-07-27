#include "pch.h"
#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <time.h>

using namespace std;

int resting (int a) {
	int step = 0;
	int i;
	do {
		step++;
		cout << (char)(i = rand () % 26 + a);
		this_thread::sleep_for (chrono::milliseconds (150));
	} while (i != a + 25 || step < 15);
	return step;
}

void nothingness (char z, unsigned n) {
	cout << "\nthread-> " << this_thread::get_id () << endl;
	while (n--) {
		cout << z;
		this_thread::sleep_for (chrono::milliseconds (250));
	}
}

void setValue (int* a) {
	*a = 100;
}

int main_21 () {
	srand (time (NULL));

	char znak;
	cin >> znak;

	future<int> result1 = async (launch::async, resting, 65);
	int s2 = resting (97);


	cout << endl << result1.get () << endl;
	cout << s2 << endl;

	if (result1.valid ()) cout << "valid"; else cout << "nievalid";
	cout << endl;

	future<int> result2 = (async (resting, 65));
	result2.wait ();
	cout << "\npo wait";

	cout << "\n************************************************\n\n";
	cin >> znak;

	thread thread1 (nothingness, '!', 45);
	this_thread::sleep_for (chrono::milliseconds (1000));

	nothingness ('*', 20);

	//thread1.join ();
	cout << "\n\nEND\n\n";

	thread1.detach ();

	int x;
	thread thread2 (setValue, &x);
	thread2.join ();
	cout << endl << x;

	return 0;
}