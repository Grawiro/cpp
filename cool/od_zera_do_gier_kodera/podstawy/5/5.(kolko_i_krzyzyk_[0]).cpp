#include <iostream>
#include <conio.h>
#include "5.(kolko_i_krzyzyk_[0]).h"

void main ()
{
	StartGry ();

	for (;;)
	{
		RysujPlansze ();

		if (g_StanGry == GS_MOVE)
		{
			unsigned uNumerPola;

			std::cin >> uNumerPola;

			Ruch (uNumerPola);
		}
		else if (g_StanGry == GS_WON || g_StanGry == GS_DRAW) break;
	}
	_getch ();
}