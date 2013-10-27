#include "Global.hpp"
#include "Game.hpp"
#include <sstream>

void Error(const std::string& err) {
	std::cerr << err << std::endl;
}
void CriticalError(const std::string& err) {
	std::cerr << err << std::endl;
	int i;
	std::cin >> i;
	Game::Quit();
}
void Log(const std::string& txt) {
	std::cout << txt << std::endl;
}
