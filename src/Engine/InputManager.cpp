#include "InputManager.hpp"
#include "Utilities.hpp"

namespace lpe {
InputManager::InputManager(Core* parent) {
	// Set the root core
	m_Root = parent;

	// Clear the arrays, just to be safe.
	for (unsigned int i = 0; i < sf::Keyboard::Key::KeyCount; i++) {
		KeysPressed[i] = false;
		KeysDown[i] = false;
		KeysUp[i] = false;
	}
	for (unsigned int i = 0; i < sf::Mouse::Button::ButtonCount; i++) {
		ButtonsPressed[i] = false;
		ButtonsDown[i] = false;
		ButtonsUp[i] = false;
	}
}
InputManager::~InputManager() {

}

//Array clearing
void InputManager::Clear() {
	// Reset KeysDown and KeysUp, since there are only supposed
	// to be true for a single tick. Run this before the eventloop
	// Keyboard
	for (unsigned int i = 0; i < sf::Keyboard::Key::KeyCount; i++) {
		KeysDown[i] = false;
		KeysUp[i] = false;
	}
	// Mouse
	for (unsigned int i = 0; i < sf::Mouse::Button::ButtonCount; i++) {
		ButtonsDown[i] = false;
		ButtonsUp[i] = false;
	}
}

// Input processing.
// Called each event pull.
void InputManager::ProcessInput(const sf::Event& event) {
	switch (event.type) {
	case sf::Event::KeyPressed: {
			// Let's exploit the fact that an enumerated value,
			// actually is a numeric value.
			KeysPressed[event.key.code] = true;
			KeysDown[event.key.code] = true;
			break; // Don't forget your darn breaks!
		}
	case sf::Event::KeyReleased: {
			KeysPressed[event.key.code] = false;
			KeysUp[event.key.code] = true;
			break;
		}
	case sf::Event::EventType::MouseButtonPressed: {
			ButtonsPressed[event.mouseButton.button] = true;
			ButtonsDown[event.mouseButton.button] = true;
			break;
		}
	case sf::Event::EventType::MouseButtonReleased: {
			ButtonsPressed[event.mouseButton.button] = false;
			ButtonsUp[event.mouseButton.button] = true;
			break;
		}
	}
}
}
