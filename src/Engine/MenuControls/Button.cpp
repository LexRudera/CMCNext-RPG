#include "MenuControls/Button.hpp"
#include "Utilities.hpp"
#include "Game.hpp"
#include "InputManager.hpp"

namespace lpe {
Button::Button(Menu* parent,
               const sf::String& text,
               const sf::Vector2f& size,
               const sf::Vector2f& pos,
               float rot) : m_Text(text), m_Btn(size) {
	m_Parent = parent;
	// Object properties
	setPosition(pos);
	setRotation(rot);

	// Visual Style
	m_Btn.ApplyStyle(BoxStyle(NULL, sf::Color(128,128,128), sf::Color(85,85,85), 3));

	// Alignment
	CenterText();
}

Button::~Button() {
	//dtor
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(m_Btn, states);
	target.draw(m_Text, states);
}

void Button::tick() {
	// Sense the mouse and react accordingly.
	const sf::Vector2i& MPos = Core::Get()->GetInputManager()->GetMousePos();
	if (MPos.x > getPosition().x // Below the x pos
	        && MPos.x < getPosition().x + m_Btn.getSize().x // Above the lower box bounds
	        && MPos.y > getPosition().y // Past the y pos
	        && MPos.y < getPosition().y + m_Btn.getSize().y) { // Before the right box bounds
		//On Click
		if (Core::Get()->GetInputManager()->IsButtonUp(sf::Mouse::Button::Left)) {
			if (m_Parent->ButtonReady()) { // If a button already have been pressed this frame, don't even try anything
				if (OnClick != 0) { // If there is an assigned function or not.
					(m_Parent->*OnClick)();
				}
			}
		}
	}
}

void Button::CenterText() {
	m_Text.setPosition(sf::Vector2f(m_Btn.getSize().x/2-m_Text.getLocalBounds().width/2, m_Btn.getSize().y/2-m_Text.getCharacterSize()/4*3));//-m_Text.getLocalBounds().height/2));
}
}
