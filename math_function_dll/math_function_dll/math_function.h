#ifndef MATH_DLL //in C/C++ in Preprocessor in Preprocessor Definitions add DLL_EXPORT;
#define MATH_DLL

#if defined DLL_EXPORT
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif

extern "C"
{
	EXPORT int add (int a, int b);
	EXPORT int multiply (int a, int b);
}

#endif // !MATH_DLL
