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
