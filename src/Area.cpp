#include "Area.hpp"

Area::Area()
{
	//ctor
}

Area::~Area()
{
	//dtor
}

Entity* Area::AddEntity(Entity* ent) {
	m_Objects.push_back(ent);
	return ent;
}

void Area::Tick() {
	// Collision Calculations
	for (std::vector<lpe::Object*>::iterator i = m_Objects.begin(); i != m_Objects.end(); i++) {
	//static_cast<Entity>(*i).Collision
	}
	// Apply Movement
}
