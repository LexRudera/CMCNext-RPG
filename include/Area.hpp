#ifndef AREA_H
#define AREA_H

#include "Scene.hpp"
#include "Entity.hpp"

class Area : public lpe::Scene, public Collider
{
public:
	Area();
	virtual ~Area();
	Entity* AddEntity(Entity* ent);
	void SetPlayer(Entity* ent);
protected:
	virtual void Tick();
	virtual void Render(sf::RenderTarget& target);
	virtual void OnClose();
private:
	Entity* m_Player = 0;
};

#endif // AREA_H
