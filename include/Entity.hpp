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
protected:
private:
	Spritesheet m_spritesheet;
};

#endif // ENTITY_H
