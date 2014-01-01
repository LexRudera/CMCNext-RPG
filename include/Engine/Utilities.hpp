// The Global Functions
//------------------------------------------------------------------
// Functions and stuff that is globally accessible to the entire
// architecture of the game. Logging and error stuff for instance.

#ifndef GLOBAL_HPP_INCLUDED
#define GLOBAL_HPP_INCLUDED

#include <iostream>
#include <sstream>
#include <SFML\System.hpp>
#include <cmath>

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

//template <typename T>
//float DotProduct(const sf::Vector2<T>& a, const sf::Vector2<T>& b) {
float DotProduct(const sf::Vector2f& a, const sf::Vector2f& b);

template<typename T>
float Magnitude(const sf::Vector2<T>& val) {
	return std::sqrt(val.x*val.x+val.y*val.y);
}
template<typename T>
sf::Vector2<T> Normalize(const sf::Vector2<T>& val) {
	float mag = Magnitude(val);
	return sf::Vector2<T>(val.x/mag, val.y/mag);
}
template<typename T>
void NormalizeRef(sf::Vector2<T>& val) {
	float mag = Magnitude(val);
	val.x /= mag;
	val.y /= mag;
}

#endif // GLOBAL_HPP_INCLUDED
