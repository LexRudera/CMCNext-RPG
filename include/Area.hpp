#ifndef AREA_H
#define AREA_H

#include "Scene.hpp"
#include "Entity.hpp"

class Area : public lpe::Scene, public AreaCollider
{
public:
	Area();
	virtual ~Area();
	Entity* AddEntity(Entity* ent);
protected:
private:
};

#endif // AREA_H
