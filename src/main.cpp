//---------------------------------------------
// CMC Next
// LPEngine based on SFML
// Programmed by Lex Rudera - lex@pulsewave.co
//---------------------------------------------

#include "Core.hpp"
#include "Settings.hpp"
#include "MainMenu.hpp"
#include "Utilities.hpp"
#include <iostream>

int main() {
	Log("");
	Log("Running");
	Log("Setting up game instance");
	Core Derp(new Settings());
	Log("Firing up the game.");

	int ErrorCode = Derp.Run(new MainMenu());
	if (ErrorCode != 0) {
		Error(IntToString(ErrorCode));
	}
		return ErrorCode;
}
