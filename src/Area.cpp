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
	//static_cast<Entity*>(i)
	}
	// Apply Movement
}

void Area::Render(sf::RenderTarget& target) {
	if (true) {
		for (unsigned int i = 0; i < GetHitboxCounter(); i++) {
			target.draw(GetHitbox(i));
			const sf::VertexArray& hbox = GetHitbox(i);
			if (hbox.getVertexCount() > 2) {
				sf::Vertex arr[] = {hbox[hbox.getVertexCount()-1],
									hbox[0]};
				target.draw(arr, 2, sf::PrimitiveType::Lines);
			}
		}
	}
}
