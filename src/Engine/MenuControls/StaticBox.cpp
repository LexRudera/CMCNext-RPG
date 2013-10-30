#include "MenuControls\StaticBox.hpp"

namespace lpe {
StaticBox::StaticBox(const sf::Vector2f& size, const sf::Vector2f& pos, const float& rot)
	: m_Box(size) {
	setPosition(pos);
	setRotation(rot);


	m_Box.setFillColor(sf::Color(128,128,128));
	m_Box.setOutlineColor(sf::Color(85,85,85));
	m_Box.setOutlineThickness(3);
}

StaticBox::~StaticBox() {
	//dtor
}

void StaticBox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(m_Box, states);
}

void StaticBox::ApplyStyle(const BoxStyle& style) {
	m_Box.setTexture(style.Background);
	m_Box.setFillColor(style.FillColour);
	m_Box.setOutlineColor(style.OutlineColour);
	m_Box.setOutlineThickness(style.OutlineThickness);
}

BoxStyle StaticBox::GetStyle() {
	return BoxStyle(m_Box.getTexture(), m_Box.getFillColor() ,m_Box.getOutlineColor(), m_Box.getOutlineThickness());
}
}
