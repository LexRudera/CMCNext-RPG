#ifndef INPUT_H
#define INPUT_H

#include "Core.hpp"


typedef sf::Keyboard::Key Key;
typedef sf::Mouse::Button Button;
namespace lpe {
class InputManager {
public:
	InputManager(Core* parent);
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
		return sf::Mouse::getPosition(*m_Root->GetWindow());
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

	Core* m_Root;
};
}

#endif // INPUT_H
