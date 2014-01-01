#include "Utilities.hpp"
#include "Core.hpp"
#include <sstream>
void Error(const std::string& err) {
	std::cerr << err << std::endl;
}
void CriticalError(const std::string& err) {
	std::cerr << err << std::endl;
	int i;
	std::cin >> i;
	lpe::Core::Get()->Quit();
}
void Log(const std::string& txt) {
	std::cout << txt << std::endl;
}


std::string IntToString(int i) {
	bool negative = false;
	if (i < 0) {
		negative = true;
		i = -i;
	}

	int digits = 0;// Count digits
	for (int t = i; t > 0; t/=10) {
		digits++;
	}
	if (!digits)// In case of int is zero, it's still one digit
		digits++;

	char num[digits+1+negative]; // Char array and null terminator
	num[digits+negative] = '\0';
	if (negative)
		num[0] = '-';
	for (int j = 0; j < digits; j++) { // Fills the array
		int divider = 1; // Divider algorithm since I can't do a 10 in the power of 'i'
		for (int k = 0; k < j; k++)
			divider *= 10;
		num[digits-1-i+negative] = i/divider%10+48;
		// a is divided with the calculated divider,
		// eleminates numbers on the right side, where the modulus 10
		// removes all numbers from the tenths and upward, leaving a single desired number.
		// add 48 on top of it, to allign the number with the ASCII character scheme.
	}
	return std::string(num);
}

float DotProduct(const sf::Vector2f& a, const sf::Vector2f& b) {
	return a.x*b.x + a.y*b.y;
}

