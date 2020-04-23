#include "tic_tac_toe.h"


using namespace System;
[STAThreadAttribute]

int main () {
	Windows::Forms::Application::Run (gcnew My9TicTacToe::tic_tac_toe ());

	return 0;

}