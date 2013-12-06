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
	lpe::Log("");
	lpe::Log("Running");
	lpe::Log("Setting up game instance");
	Game CmcNext;
	lpe::Log("Firing up the game.");

	int ErrorCode = CmcNext.Run(new MainMenu);
	if (ErrorCode != 0) {
		lpe::Error(lpe::IntToString(ErrorCode));
	}
		return ErrorCode;
}
