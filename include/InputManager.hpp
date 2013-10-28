#ifndef INPUT_H
#define INPUT_H

#include "Core.hpp"

//class Game;
class InputManager {
public:
	/*class Keyboard
	{
	    public:
	        static bool IsKeyPressed(sf::Keyboard::Key k) { return sf::Keyboard::isKeyPressed(k); }
	    protected:
	    private:
	};

	class Mouse
	{
	    public:
	        static bool isButtonPressed(sf::Mouse::Button b) { return sf::Mouse::isButtonPressed(b); }
	        static sf::Vector2i getPosition() { return sf::Mouse::getPosition(); }
	        static sf::Vector2i getPosition(const sf::Window &relativeTo) { return sf::Mouse::getPosition(relativeTo); }
	        static void setPosition (const sf::Vector2i &position) { sf::Mouse::setPosition(position); }
	        static void setPosition (const sf::Vector2i &position, const sf::Window &relativeTo) { sf::Mouse::setPosition(position, relativeTo); }
	    protected:
	    private:
	};*/
	InputManager();
	virtual ~InputManager();

	void ProcessInput(const sf::Event& event);
	void Clear();

	// Keyboard
	bool IsKeyPressed(const sf::Keyboard::Key& key) {
		return KeysPressed[key];
	}
	bool IsKeyDown(const sf::Keyboard::Key& key) {
		return KeysDown[key];
	}
	bool IsKeyUp(const sf::Keyboard::Key& key) {
		return KeysUp[key];
	}
	// Mouse
	bool IsButtonPressed(const sf::Mouse::Button& key) {
		return ButtonsPressed[key];
	}
	bool IsButtonDown(const sf::Mouse::Button& key) {
		return ButtonsDown[key];
	}
	bool IsButtonUp(const sf::Mouse::Button& key) {
		return ButtonsUp[key];
	}
	sf::Vector2i GetMousePos() {
		return sf::Mouse::getPosition(*Core::Get()->GetWindow());
	}
	sf::Vector2i GetAbsoluteMousePos() {
		return sf::Mouse::getPosition();
	}
protected:
private:
	// Keyboard
	bool KeysPressed[sf::Keyboard::Key::KeyCount];
	bool KeysDown[sf::Keyboard::Key::KeyCount];
	bool KeysUp[sf::Keyboard::Key::KeyCount];
	// Mouse
	bool ButtonsPressed[sf::Mouse::Button::ButtonCount];
	bool ButtonsDown[sf::Mouse::Button::ButtonCount];
	bool ButtonsUp[sf::Mouse::Button::ButtonCount];
};

#endif // INPUT_H
