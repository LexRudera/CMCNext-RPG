//---------------------------------------------
// CMC Next
// LPEngine based on SFML
// Programmed by Lex Rudera - lex@pulsewave.co
//---------------------------------------------

#include "Game.hpp"
//#include "Settings.hpp"
#include "Utilities.hpp"
#include <iostream>

int main() {
	lpe::Log("");
	lpe::Log("Running");
	lpe::Log("Setting up game instance");
	Game CmcNext;
	lpe::Log("Firing up the game.");

	int ErrorCode = CmcNext.Launch();
	if (ErrorCode != 0) {
		lpe::Error(lpe::IntToString(ErrorCode));
	}
		return ErrorCode;
}
