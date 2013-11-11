#include "MenuControls/Image.hpp"
#include "Game.hpp"

namespace lpe {
sf::Vector2i Image::DefaultSize;

Image::Image(const sf::String& image, const sf::Vector2f& pos, const sf::Vector2i& size, float rot) {
	if (!LoadTexture(image)) {
		m_Img.setTexture(*Core::Get()->GetResourceManager()->GetFallbackTexture());
	}
	setPosition(pos);
	setRotation(rot);
	if (size != Image::DefaultSize) {
		sf::Vector2u imgsize = GetTexture()->getSize();
		float x = ((float)1)/imgsize.x * size.x;
		float y = ((float)1)/imgsize.y * size.y;
		setScale(x, y);
	}
}

Image::~Image() {

}

void Image::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(m_Img, states);
}

bool Image::LoadTexture(const sf::String& strng) {
	const sf::Texture* t = Core::Get()->GetResourceManager()->GetTexture(strng);
	if (t == 0) {
		// If shit fails, load the texture into the Resource Manager beforehand,
		// This function doesn't know shit about what file we're actually
		// playing around with.

		//delete t; No, there is no data to delete, so stop wasting time and lines.
		return false;
	}
	m_Img.setTexture(*t);
	return true;
}
}
