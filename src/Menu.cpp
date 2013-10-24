#include "Menu.hpp"
#include "Game.hpp"
#include "Global.hpp"

Menu::Menu() {
	//ctor
}

Menu::~Menu() {
	//dtor
}

void Menu::Add(ControlBase* obj) {
	m_Objects.push_back(obj);
}

void Menu::Tick() {
	m_ButtonedFrame = false;
}

bool Menu::ButtonReady() {
	if (m_ButtonedFrame == false) {
		m_ButtonedFrame = true;
		return true;
	}
	return false;
}
