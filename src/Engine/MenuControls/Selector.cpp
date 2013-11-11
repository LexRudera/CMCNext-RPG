#include "MenuControls\Selector.hpp"
#include "Game.hpp"
#include "InputManager.hpp"
#include "Utilities.hpp"

namespace lpe {
Selector::Selector(unsigned int charSize, const sf::Vector2f& size, const sf::Vector2f& pos, float rot)
	: m_Box(size),
	  m_Selected("none", charSize, sf::Vector2f(10,size.y/2-charSize/4*3)) {
	setPosition(pos);

	if (size.x == 0) {
		m_Box.setSize(sf::Vector2f(150,m_Box.getSize().y));
	}
	if (size.y == 0) {
		m_Box.setSize(sf::Vector2f(m_Box.getSize().x, charSize));
	}
	m_Selected.setPosition(sf::Vector2f(((m_Box.getSize().y-6)/4*3)+10, m_Box.getSize().y/2-charSize/4*3));//-m_Text.getLocalBounds().height/2));

	//m_Box.setSize(sf::Vector2f(150, 25));
	m_Box.ApplyStyle(BoxStyle(0, sf::Color(128,128,128), sf::Color(85,85,85), 2));

	// Arrow Creation
	m_ArrowLeft.setPointCount(3);
	m_ArrowLeft.setPoint(0, sf::Vector2f((m_Box.getSize().y-6)/4*3, 0));
	m_ArrowLeft.setPoint(1, sf::Vector2f((m_Box.getSize().y-6)/4*3, m_Box.getSize().y-6));
	m_ArrowLeft.setPoint(2, sf::Vector2f(0, (m_Box.getSize().y-6)/2));
	m_ArrowLeft.setFillColor(sf::Color(255, 255, 255));
	m_ArrowLeft.setOutlineColor(sf::Color(0, 0, 0));
	m_ArrowLeft.setOutlineThickness(1);
	m_ArrowLeft.setPosition(sf::Vector2f(m_Box.GetStyle().OutlineThickness+m_ArrowLeft.getOutlineThickness()+1, 3));

	m_ArrowRight.setPointCount(3);
	m_ArrowRight.setPoint(0, sf::Vector2f(0, 0));
	m_ArrowRight.setPoint(1, sf::Vector2f((m_Box.getSize().y-6)/4*3, (m_Box.getSize().y-6)/2));
	m_ArrowRight.setPoint(2, sf::Vector2f(0, m_Box.getSize().y-6));
	m_ArrowRight.setFillColor(sf::Color(255, 255, 255));
	m_ArrowRight.setOutlineColor(sf::Color(0, 0, 0));
	m_ArrowRight.setOutlineThickness(1);
	m_ArrowRight.setPosition(sf::Vector2f(m_Box.getSize().x-m_Box.GetStyle().OutlineThickness-m_ArrowRight.getOutlineThickness()-1-((m_Box.getSize().y-6)/4*3), 3));
}

Selector::~Selector() {
	//dtor
}

void Selector::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(m_Box, states);
	target.draw(m_Selected, states);
	target.draw(m_ArrowLeft, states);
	target.draw(m_ArrowRight, states);
}

void Selector::tick() {
	// Sense the mouse and save it's position
	const sf::Vector2i& MPos = Core::Get()->GetInputManager()->GetMousePos();

	/*if (MPos.x > getPosition().x // Below the x pos
	    && MPos.x < getPosition().x + m_Box.GetSize().x // Above the lower box bounds
	    && MPos.y > getPosition().y // Past the y pos
	    && MPos.y < getPosition().y + m_Box.GetSize().y) // Before the right box bounds
	{
	    // On Click
	    if (Core::Get()->GetInputManager()->IsButtonUp(sf::Mouse::Button::Left))
	    {
	        // Shit got clicked!
	        OnClick();
	    }
	}*/
	if (MPos.x > getPosition().x - m_ArrowRight.getOutlineThickness()*2+2 // Below the x pos
	        && MPos.x < getPosition().x + m_ArrowLeft.getPosition().x + m_ArrowLeft.getLocalBounds().width- m_ArrowRight.getOutlineThickness()*2 // Above the lower box bounds
	        && MPos.y > getPosition().y // Past the y pos
	        && MPos.y < getPosition().y + m_ArrowLeft.getPosition().y + m_ArrowLeft.getLocalBounds().height) { // Before the right box bounds
		// On Click
		if (Core::Get()->GetInputManager()->IsButtonDown(sf::Mouse::Button::Left)) {
			if(m_Entries.size() != 0) {
				if (m_CurrentEntry == 0)
					m_CurrentEntry = m_Entries.size()-1;
				else
					m_CurrentEntry--;
				m_Selected.SetString(m_Entries[m_CurrentEntry]);
			}
		}
	}
	if (MPos.x > getPosition().x + m_ArrowRight.getPosition().x - m_ArrowRight.getOutlineThickness()*2-2 // Below the x pos
	        && MPos.x < getPosition().x + m_Box.getSize().x //+ m_ArrowRight.getPosition().x + m_ArrowRight.getLocalBounds().width - m_ArrowRight.getOutlineThickness()*2 // Above the lower box bounds
	        && MPos.y > getPosition().y + m_ArrowRight.getPosition().y // Past the y pos
	        && MPos.y < getPosition().y + m_ArrowRight.getPosition().y + m_ArrowRight.getLocalBounds().height) { // Before the right box bounds
		// On Click
		if (Core::Get()->GetInputManager()->IsButtonDown(sf::Mouse::Button::Left)) {
			if(m_Entries.size() != 0) {
				if (m_CurrentEntry == m_Entries.size()-1)
					m_CurrentEntry = 0;
				else
					m_CurrentEntry++;
				m_Selected.SetString(m_Entries[m_CurrentEntry]);
			}
		}
	}
}

void Selector::Add(const sf::String& entry) {
	m_Entries.push_back(entry);
}
}
