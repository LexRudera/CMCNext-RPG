#ifndef ENTITY_H
#define ENTITY_H

#include "Object.hpp"
#include "Collider.hpp"
#include "Spritesheet.hpp"

class Entity : public lpe::Object, public Collider
{
public:
	Entity(const sf::Vector2f& pos);
	virtual ~Entity();
	virtual void Load() = 0;
	Spritesheet* GetSpritesheet() {return &m_Spritesheet;}
	sf::Vector2f GetVelocity() {return m_velocity;}
	void SetVelocity(sf::Vector2f& vel) {m_velocity = vel;}
	void CalcFrameVelocity();
	void ApplyMovement();
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void CorrentFrameVelocity();
	virtual void tick();
private:
	Spritesheet m_Spritesheet;
	bool m_Loaded = false;
	sf::Vector2f m_velocity; //Pixels per second
	sf::Vector2f m_frameMovement; //Pixels this frame
};

#endif // ENTITY_H
