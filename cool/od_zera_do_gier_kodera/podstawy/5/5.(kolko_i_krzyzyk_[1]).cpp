#include <iostream>
#include <conio.h>
#include "5.(kolko_i_krzyzyk_[0]).h"

FIELD g_aPlansza[3][3] = { { FLD_EMPTY, FLD_EMPTY, FLD_EMPTY },
{ FLD_EMPTY, FLD_EMPTY, FLD_EMPTY },
{ FLD_EMPTY, FLD_EMPTY, FLD_EMPTY } };

GAMESTATE g_StanGry = GS_NOTSTARTED;

SIGN g_AktualnyGracz;

bool StartGry ()
{
	if (g_StanGry != GS_NOTSTARTED) return false;
	{
		srand (static_cast<unsigned>(time (NULL)));
		g_AktualnyGracz = (rand () % 2 == 0 ? SGN_CIRCLE : SGN_CROSS);
		g_StanGry = GS_MOVE;

		return true;
	}
}

bool Ruch (unsigned uNumerPola)
{
	if (g_StanGry != GS_MOVE) return false;
	if (!(uNumerPola >= 1 && uNumerPola <= 9)) return false;

	unsigned uY = (uNumerPola - 1) / 3;
	unsigned uX = (uNumerPola - 1) % 3;

	if (g_aPlansza[uY][uX] == FLD_EMPTY)
		g_aPlansza[uY][uX] = static_cast<FIELD>(g_AktualnyGracz);
	else
		return false;

	const int LINIE[][3][2] = { 
	{ { 0,0 },{ 0,1 },{ 0,2 } },
	{ { 1,0 },{ 1,1 },{ 1,2 } },
	{ { 2,0 },{ 2,1 },{ 2,2 } },
	{ { 0,0 },{ 1,0 },{ 2,0 } },
	{ { 0,1 },{ 1,1 },{ 2,1 } },
	{ { 0,2 },{ 1,2 },{ 2,2 } },
	{ { 0,0 },{ 1,1 },{ 2,2 } },
	{ { 2,0 },{ 1,1 },{ 0,2 } } };

	FIELD Pole, ZgodnePole;

	unsigned uLiczbaZgodnychPol;

	for (int i = 0; i < 8; ++i)
	{
		Pole = ZgodnePole = FLD_EMPTY;
		uLiczbaZgodnychPol = 0;

		for (int j = 0; j < 3; ++j)
		{
			Pole = g_aPlansza[LINIE[i][j][0]][LINIE[i][j][1]];

			if (Pole != ZgodnePole)
			{
				ZgodnePole = Pole;
				uLiczbaZgodnychPol = 1;
			}
			else
				++uLiczbaZgodnychPol;
		}

		if (uLiczbaZgodnychPol == 3 && ZgodnePole != FLD_EMPTY)
		{
			g_StanGry = GS_WON;

			return true;
		}
	}

	unsigned uLiczbaZapelnionychPol = 0;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (g_aPlansza[i][j] != FLD_EMPTY)
				++uLiczbaZapelnionychPol;

	if (uLiczbaZapelnionychPol == 3 * 3)
	{
		g_StanGry = GS_DRAW;

		return true;
	}

	g_AktualnyGracz = (g_AktualnyGracz == SGN_CIRCLE ? SGN_CROSS : SGN_CIRCLE);

	return true;
}

bool RysujPlansze ()
{
	if (g_StanGry == GS_NOTSTARTED) return false;

	system ("cls");

	std::cout << " KOLKO I KRZYZYK " << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;
	std::cout << " -----" << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << " |";

		for (int j = 0; j < 3; ++j)
		{
			if (g_aPlansza[i][j] == FLD_EMPTY)
				std::cout << i * 3 + j + 1;
			else
				std::cout << static_cast<char>(g_aPlansza[i][j]);
		}

		std::cout << "|" << std::endl;
	}

	std::cout << " -----" << std::endl;
	std::cout << std::endl;

	switch (g_StanGry)
	{
	case GS_MOVE:
		std::cout << "Podaj numer pola, w ktorym" << std::endl;
		std::cout << "chcesz postawic ";
		std::cout << (g_AktualnyGracz == SGN_CIRCLE ? "kolko" : "krzyzyk") << ": "; break;
	case GS_WON:
		std::cout << "Wygral gracz stawiajacy ";
		std::cout << (g_AktualnyGracz == SGN_CIRCLE ? "kolka" : "krzyzyki") << "!"; break;
	case GS_DRAW:
		std::cout << "Remis!"; break;
	}
	return true;
}