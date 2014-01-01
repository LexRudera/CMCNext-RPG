//---------------------------------------------
// CMC Next
// LPEngine based on SFML
// Programmed by Lex Rudera - lex@pulsewave.co
//---------------------------------------------

#include "Game.hpp"
#include "MainMenu.hpp"
#include "Utilities.hpp"
#include <iostream>

int main(int argc, const char* argv[]) {
	Log("");
	Log("Running");
	Log("Setting up game instance");
	Game CmcNext;
	Log("Firing up the game.");

	int ErrorCode = CmcNext.Run(new MainMenu);
	if (ErrorCode != 0) {
		Error(IntToString(ErrorCode));
	}
		return ErrorCode;
}
