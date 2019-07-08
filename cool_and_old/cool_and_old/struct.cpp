#include "pch.h"
#include <iostream>

struct Level1 {
	int a;
	struct {
		int b;
		struct {
			int c;
		}Level3;

	}Level2;

}level1;	//this is a ready to use structure

Level1* create ();

int main_2 () {
	Level1 level{ 1,2,3 };
	level.Level2.Level3.c = 9;

	level1.Level2.b = 3;	//this is a ready structure

	Level1* level2 = create ();
	level2->a = 3;

	level2 = nullptr;
	delete level2;

	return 0;
}

Level1 * create () {
	return new Level1{ 6,4,2 };
}