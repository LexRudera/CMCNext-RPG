#ifndef ENTITY_H
#define ENTITY_H

#include "Object.hpp"
#include "AreaCollider.hpp"

class Entity : public lpe::Object, public AreaCollider
{
	public:
		Entity();
		virtual ~Entity();
	protected:
	private:
};

#endif // ENTITY_H
