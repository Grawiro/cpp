#include "pch.h"
#include <iostream>
#include <new> //it may be useful in advance chapter

void fun_array (int array[], int size);
void fun_wsk1 (int *wsk, int size);
void fun_wsk2 (int *wsk, int size);

char* strcpy_by_me (char * dis, const char* sou);

int main_1 (int argc, char * argv[])
{
	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
	}

	int *pointer{ reinterpret_cast<int*>(0xa2ff4) };
	std::cout << "pointer = " << reinterpret_cast<int>(pointer);

	pointer = nullptr;
	if (!pointer) 	//if (pointer == nullptr) //it's the same //pointer is 0
	{
		std::cout << "\npointer = " << reinterpret_cast<int>(pointer)<< std::endl;
	}

	char cc{ 'g' }, *wc;
	void *wv = reinterpret_cast<char*>(cc);
	wc = &cc;

	const int size{ 4 };
	int array[size]{ 1,4,5,21 };

	fun_array (array, size);
	fun_wsk1 (array, size);
	fun_wsk2 (array, size);

	int *pointer_to_new_int{ new int {12} };	//it's the same 	int *pointer_to_new_int = new int {12}; //it's the same too		new int (12)
	const int *pointer_to_new_const_int{ new const int (32) };
	delete pointer_to_new_int;
	delete pointer_to_new_const_int;
	pointer_to_new_int = nullptr;
	pointer_to_new_const_int = nullptr;

	int *pointer_array;
	pointer_array = new int[3]{ 1, 2, 4 };	//it's the same		int *pointer_array{ new int[3] };
	pointer_array[1] = 3;
	delete[] pointer_array;
	pointer_array = nullptr;

	int (*pointer_to_3D_array)[2][3]{ new int[4][2][3] }; //it's array 3D but only left size may be varialbles, other must be const variables
	//(*name)[23] it's be pointer to array / *name [23] is array of pointer //it's the same    auto *pointer_to_3D_array { new int[4][2][3] };
	pointer_to_3D_array[1][1][2] = 3;
	delete[] pointer_to_3D_array;
	pointer_to_3D_array = nullptr;

	//advance
	int *big_memory{ new int[1000] {} };
	void *where{ &big_memory[100] };	//pointer to place in memory
	int *pointer_to_memory_int{ new (where) int };	//set pointer on 'where' place
	*pointer_to_memory_int = 32;	//set in this place number 32
	where = &big_memory[103];
	double *pointer_to_memory_double{ new (where) double[3] };
	pointer_to_memory_double[0] = 2.3;	//this is work fine but big_memory not display this value correct
	pointer_to_memory_double[2] = 6.5;
	std::cout << reinterpret_cast<unsigned long long>(&big_memory[108]) << std::endl;	//display address of variable
	unsigned long long where_this_set;
	//std::cin >> where_this_set;	//this work but i dont like write it all the time
	where_this_set = reinterpret_cast<unsigned long long>(&big_memory[108]); //this is it only because i dont write it
	where = reinterpret_cast<void*>(where_this_set);
	char *pointer_to_memory_char{ new (where) char };
	*pointer_to_memory_char = 3;
	delete[] big_memory;
	big_memory = nullptr;
	where = nullptr;
	pointer_to_memory_int = nullptr;
	pointer_to_memory_double = nullptr;
	pointer_to_memory_char = nullptr;


	int a_normal = 1;
	int b_normal = 1;
	const int b_const = 2;
	double c_normal = 3.0;
	const double e_const = 4.0;

	int *a = &a_normal;					//normal pointer
	const int *b = &b_const;			//const pointer
	const double *e = &e_const;			//const pointer
	double* const c = &c_normal;		//no move pointer //must be initialization
	const int* const d = &b_normal;		//const no move pointer //must be initialization

	a = const_cast<int*>(b);	//a now set to address b, but a is no const //a may be change const value now
	a = &a_normal;
	a = reinterpret_cast<int*>(const_cast<double*>(c));		//a now set on c address
	e = const_cast<const double*>(c);						//add const to c

	char text_1[] = "Hello World!";
	char text_2[40];

	strcpy_by_me (text_2, text_1);

	return 0;
}

void fun_array (int array[], int size)
{
	std::cout << "fun_array" << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << "   ";
	}

	std::cout << std::endl;
}

void fun_wsk1 (int * wsk, int size)
{
	std::cout << "fun_wsk1" << std::endl;

	for (int i = 0; i < size; i++, wsk++)
	{
		std::cout << *wsk << "   ";
	}

	std::cout << std::endl;
}

void fun_wsk2 (int * wsk, int size)
{
	std::cout << "fun_wsk2" << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << wsk[i] << "   ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
}

char* strcpy_by_me (char * dis, const char* sou)
{
	char* begin = dis;

	while ((*(dis++) = *(sou++)));

	return begin;
}