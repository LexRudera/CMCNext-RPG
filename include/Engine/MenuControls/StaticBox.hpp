#ifndef STATICBOX_H
#define STATICBOX_H

#include <MenuControls\ControlBase.hpp>
#include "MenuControls\ControlsShared.hpp"

namespace lpe {
class StaticBox : public ControlBase {
public:
	StaticBox(const sf::Vector2f& size = sf::Vector2f(100,100), const sf::Vector2f& pos = sf::Vector2f(), const float& rot = 0);
	virtual ~StaticBox();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setSize(const sf::Vector2f& size) {
		m_Box.setSize(size);
	}
	void setSize(const float& x, const float& y) {
		m_Box.setSize(sf::Vector2f(x,y));
	}
	sf::Vector2f getSize() {
		return m_Box.getSize();
	}
	void getSize(float* x, float* y) const {
		*x = m_Box.getSize().x;
		*y = m_Box.getSize().y;
	}

	void ApplyStyle(const BoxStyle& style);
	BoxStyle GetStyle();
protected:
private:
	sf::RectangleShape m_Box;
};
}
#endif // STATICBOX_H
