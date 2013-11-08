#include "Entity.hpp"
#include "Utilities.hpp"

Entity::Entity()
{
	//ctor
}

Entity::~Entity()
{
	//dtor
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	//Spritesheet* ss = GetSpritesheet();
	target.draw(m_Spritesheet, states);
}
