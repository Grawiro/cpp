#include "pch.h"
#include <iostream>

//extern "C" void map (int, float);	//"C" if have to extern a C/assembler or anather language's import a function's

//extern "C" {							//all file's and function's import in C style (not add nothing to name function)
//	int test (int, char);
//	char fooer (const char[]);
//
//#include "my_header_file.h"			//this is work too, for this way 
//}

int fan (int);
int fan (int, double);
int fan (double, int);	//this is overloading function name, function must be have diffrent argument's

int (*overloading_function_return (int))(double, int);	//this function is overloading_function_return(int) and return pointer to
														//int fan (double, int)

char* (*fun (double* (*)(char*), double (*)(int, double)))(char*);

int main ()
{
	//fan (3);
	//fan (3, 4.3);
	//fan (3.4, 4);		//all function is diffrent

	return 0;
}

int fan (double a, int b)
{
	return (int)(a*b);
}

int (*overloading_function_return (int a))(double, int)
{
	a = 3;
	return fan;
}