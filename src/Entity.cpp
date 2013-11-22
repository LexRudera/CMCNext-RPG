#include "Entity.hpp"
#include "Game.hpp"
#include "Utilities.hpp"
#include "SFML/Graphics.hpp"

Entity::Entity(const sf::Vector2f& pos)
{
	setPosition(pos);
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

	if (true) {
		target.draw(GetHitbox(), states);
	}
}

sf::Vector2f Entity::CorrectMovement(sf::Vector2f vec) {
	// Correcting speed with framerate
	vec.x *= Game::Get()->GetFrameTime()->asSeconds();
	vec.y *= Game::Get()->GetFrameTime()->asSeconds();
	return vec;
}

void Entity::tick() {
	m_Spritesheet.tick();
}
