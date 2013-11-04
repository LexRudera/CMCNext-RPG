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
protected:
private:
	Spritesheet m_spritesheet;
	bool m_Loaded = false;
};

#endif // ENTITY_H
