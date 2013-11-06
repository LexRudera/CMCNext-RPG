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
private:
	Spritesheet m_Spritesheet;
	bool m_Loaded = false;
};

#endif // ENTITY_H
