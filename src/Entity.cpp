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

	if (Game::Get()->GetSettings()->DebugHitboxes()) {
		target.draw(GetHitbox(), states);
		const sf::VertexArray& hbox = GetHitbox();
		if (hbox.getVertexCount() > 2) {
			sf::Vertex arr[] = {hbox[hbox.getVertexCount()-1], hbox[0]};
			target.draw(arr, 2, sf::PrimitiveType::Lines, states);
		}
	}
}

/*sf::Vector2f Entity::CorrectMovement(sf::Vector2f vec) {
	// Correcting speed with framerate
	vec.x *= Game::Get()->GetFrameTime()->asSeconds();
	vec.y *= Game::Get()->GetFrameTime()->asSeconds();
	return vec;
}*/

void Entity::CorrentFrameVelocity() {
	m_frameMovement.x = m_velocity.x * Game::Get()->GetFrameTime()->asSeconds();
	m_frameMovement.y = m_velocity.y * Game::Get()->GetFrameTime()->asSeconds();
}

void Entity::ApplyMovement() {
	if (m_frameMovement == sf::Vector2f())
		CorrentFrameVelocity();
	move(m_frameMovement);
	m_frameMovement = sf::Vector2f();
}

void Entity::tick() {
	m_Spritesheet.tick();
}
