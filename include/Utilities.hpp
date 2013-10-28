// The Global Functions
//------------------------------------------------------------------
// Functions and stuff that is globally accessible to the entire
// architecture of the game. Logging and error stuff for instance.

#ifndef GLOBAL_HPP_INCLUDED
#define GLOBAL_HPP_INCLUDED

#include <iostream>
#include <sstream>

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

#endif // GLOBAL_HPP_INCLUDED
