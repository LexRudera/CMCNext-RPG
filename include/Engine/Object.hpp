// An object that is to be rendered on the screen.
// Empty and pure virtual. This is not meant to be
// actually made into an object and rendered. It is
// to be derived from as the absolute base class
// of all renderable things.

#ifndef OBJECT_H
#define OBJECT_H

#include <SFML\Graphics.hpp>
namespace lpe {
class Object : public sf::Drawable, public sf::Transformable {
public:
	Object();
	virtual ~Object();

	void DoTick();

	sf::Vector2f getPosition() {
		return sf::Transformable::getPosition();
	}
	void getPosition(float* x, float* y) {
		*x = getPosition().x;
		*y = getPosition().y;
	}
	float getRotation() {
		return sf::Transformable::getRotation();
	}
	void getRotation(float* r) {
		*r = sf::Transformable::getRotation();
	}
	void ActivateLogic() {
		m_Logic = true;
	}
	void DeactivateLogic() {
		m_Logic = false;
	}
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual void tick();
private:
	bool m_Logic = true;
};
}
#endif // OBJECT_H
