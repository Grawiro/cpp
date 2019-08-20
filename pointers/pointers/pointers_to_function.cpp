#include "pch.h"
#include <iostream>
#include <vector>


int function_1 ();
int function_2 ();
int function_3 (int);
bool function_4 (int);
bool function_4_5 (int);
int function_5 (std::vector<int>, bool (*fun)(int));
int function_5_5 (std::vector<int>, bool (*fun[])(int));

void fan ();
void pendulum ();
void time (int a);

bool arm_bend (double a)		{ std::cout << __func__ << " by " << a << " degrees." << std::endl; return true; }
bool forearm_bend (double a)	{ std::cout << __func__ << " by " << a << " degrees." << std::endl; return true; }
bool wrist_bend (double a)		{ std::cout << __func__ << " by " << a << " degrees." << std::endl; return true; }
bool arm_rotation (double a)	{ std::cout << __func__ << " by " << a << " degrees." << std::endl; return true; }
bool forearm_rotation (double a){ std::cout << __func__ << " by " << a << " degrees." << std::endl; return true; }
bool wrist_rotation (double a)	{ std::cout << __func__ << " by " << a << " degrees." << std::endl; return true; }
											 //__func__ is a name of function

int main_3 ()
{
	{
		int (*pointer_to_function_1)() = &function_1;			//this '&' is not required
		std::cout << pointer_to_function_1 () << std::endl;

		pointer_to_function_1 = &function_2;
		std::cout << pointer_to_function_1 () << std::endl;

		auto auto_pointer_to_function = &function_3;
		std::cout << auto_pointer_to_function (3) << std::endl;

		int (*pointer_to_function_3)(int) = &function_3;
		std::cout << (*pointer_to_function_3)(2) << std::endl; //this "(*pointer_to_function_3)(2)" and this "pointer_to_function_3(2)"
																//is correct 
	}

	std::vector<int> vec{ 0,1,2,3,4,5,6,7,8,9,10 };
	{
		std::cout << function_5 (vec, &function_4) << std::endl;  //this is a pointer to function use in function argument
	}

	{
		bool (*(array_of_function[2]))(int);	//array of pointers to function
		array_of_function[0] = &function_4;
		array_of_function[1] = &function_4_5;
		std::cout << function_5_5 (vec, array_of_function) << std::endl;  //this is a array of pointers to function use in function argument

		using Tpointer_to_func = bool (*)(int);				//name "function_4" change to (*) and this is work
		Tpointer_to_func array_of_pointer_to_function[2];	//it's the best way

		void (*cool_check_function[2])();
		cool_check_function[0] = &fan;
		cool_check_function[1] = &pendulum;
		cool_check_function[0] ();
		cool_check_function[1] ();
	}

	{
		typedef int (*Tpo_1)(int);
		using Tpo_2 = int (*) (int);				//all it's the same
		using Tpo_3 = decltype (&function_3);
		decltype (&function_3) Tpo_4;
		auto *Tpo_5 = &function_3;
	}

	{			
		system ("cls");

		int choose{ 0 };
		double degrees{};

		std::vector<bool (*)(double)> vec_exe;
		std::vector<double> vec_double;

		do
		{
			std::cout << "Menu:\n"
				"0.execute\n"
				"1.arm_bend\n"
				"2.forearm_bend\n"
				"3.wrist_bend\n"
				"4.arm_rotation\n"
				"5.forearm_rotation\n"
				"6.wrist_rotation\n"
				"7.exit\n"
				"choose one: ";
			std::cin >> choose;
						
			switch (choose)
			{
			case 0: 
				system ("cls");

				for(unsigned int i = 0;i<vec_exe.size();i++)
				{
					vec_exe[i] (vec_double[i]);
				}; 
				
				system ("pause"); system ("cls"); 			break;

			case 1: vec_exe.push_back (&arm_bend);			goto degreeses;
			case 2: vec_exe.push_back (&forearm_bend);		goto degreeses;
			case 3: vec_exe.push_back (&wrist_bend);		goto degreeses;
			case 4: vec_exe.push_back (&arm_rotation);		goto degreeses;
			case 5: vec_exe.push_back (&forearm_rotation);	goto degreeses;
			case 6: vec_exe.push_back (&wrist_rotation);	goto degreeses;
			case 7:										 	break;
			default:
degreeses:
				std::cout << "How many degreese: ";
				std::cin >> degrees;

				vec_double.push_back (degrees);

				break;
			}

			system ("cls");

		} while (choose != 7);



	}

	return 0;
}

int function_1 ()
{
	return 1;
}

int function_2 ()
{
	return 2;
}

int function_3 (int a)
{
	return a;
}

bool function_4 (int a)
{
	return (a > 5 ? true : false);
}

bool function_4_5 (int a)
{
	return a < 5;
}

int function_5 (std::vector<int> a, bool (*fun)(int))
{
	int sum{};

	for (int i = 0; i < a.size (); i++)
	{
		if (fun (a[i]))
		{
			sum++;
		}
	}
	return sum;
}

int function_5_5 (std::vector<int> a, bool (*fun[])(int))
{
#define WYBOR 1

	int sum{};

	for (int i = 0; i < a.size (); i++)
	{
		if (fun[WYBOR] (a[i]))
		{
			sum++;
		}
	}
	return sum;
}

void fan ()
{
	std::cout << std::endl;

	char step[]{ '|','/','-','\\' };

	for (int i = 0; i < 100; i++)
	{
		std::cout << "  " << step[i % 4] << "\r";
		time (35000);
	}
}

void pendulum ()
{
	std::cout << std::endl;

	char step[26];

	for (int i = 0; i < 500; i++)
	{
		for (int k = 0; k < 25; k++) step[k] = ' ';
		step[25] = 0;

		int position =(int)(12 * sin (i / 20.0) + 12);
		step[position] = '*';

		std::cout << "  " << step << "\r";
		time (13000);
	}
}

void time (int a)
{
	for (int i = 0; i < a * 1000; i++);
}
