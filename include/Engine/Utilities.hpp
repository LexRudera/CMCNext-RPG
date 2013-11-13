// The Global Functions
//------------------------------------------------------------------
// Functions and stuff that is globally accessible to the entire
// architecture of the game. Logging and error stuff for instance.

#ifndef GLOBAL_HPP_INCLUDED
#define GLOBAL_HPP_INCLUDED

#include <iostream>
#include <sstream>
#include <SFML\System.hpp>

namespace lpe{
void Error(const std::string& err);
void CriticalError(const std::string& err);
void Log(const std::string& txt);

template<typename T>
inline std::string to_string(const T& t) {
	std::stringstream ss;
	ss << t;
	return ss.str();
}

std::string IntToString(int i);

template <typename T>
float DotProduct(const sf::Vector2<T>& a, const sf::Vector2<T>& b) {
	return a.x*b.x + a.y*b.y;
}
}

#endif // GLOBAL_HPP_INCLUDED
