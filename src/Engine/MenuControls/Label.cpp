#include "Utilities.hpp"
#include "MenuControls/Label.hpp"
#include "Game.hpp"

namespace lpe {
Label::Label(const sf::String& text, unsigned int size, const sf::Vector2f& pos, float rot) {
	LoadFont();
	m_Text.setString(text);
	m_Text.setCharacterSize(size);
	setPosition(pos);
	setRotation(rot);
}

Label::~Label() {
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(m_Text, states);
	// Bounding box of the text
	/*sf::RectangleShape boundings(sf::Vector2f(m_Text.getLocalBounds().width, m_Text.getLocalBounds().height));
	boundings.setFillColor(sf::Color(0,0,0,0));
	boundings.setOutlineColor(sf::Color(255,255,255));
	boundings.setOutlineThickness(1);
	target.draw(boundings,states);*/
}

bool Label::LoadFont(const sf::String& font) {
	const sf::Font* t = Core::Get()->GetResourceManager()->GetFont(font);
	if (t == 0) {
		//delete t;
		return false;
	}
	m_Text.setFont(*t);
	return true;
}
}
