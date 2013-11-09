#ifndef ENTITY_H
#define ENTITY_H

#include "Object.hpp"
#include "AreaCollider.hpp"
#include "Spritesheet.hpp"

class Entity : public lpe::Object, public AreaCollider
{
public:
	Entity();
	virtual ~Entity();
	virtual void Load() = 0;
	Spritesheet* GetSpritesheet() {return &m_Spritesheet;}
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2f CorrectMovement(sf::Vector2f vec);
	virtual void tick();
private:
	Spritesheet m_Spritesheet;
	bool m_Loaded = false;
};

#endif // ENTITY_H
