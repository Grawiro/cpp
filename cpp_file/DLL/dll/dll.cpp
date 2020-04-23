#include "dll.h"

extern "C"
{
	EXPORT int Sum (int x, int y)
	{
		return x + y;
	}
}