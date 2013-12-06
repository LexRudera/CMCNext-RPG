#include "Area.hpp"
#include "Game.hpp"
#include "MainMenu.hpp"

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

void Area::SetPlayer(Entity* ent) {
	m_Player = ent;
}

void Area::Tick() {
	// Collision Calculations
	for (std::vector<lpe::Object*>::iterator i = m_Objects.begin(); i != m_Objects.end(); i++) {
	static_cast<Entity*>(*i)->ApplyMovement();

	}
	// Apply Movement
	if (m_Player) {
		sf::Vector2f cent = m_Player->getPosition();

		if (m_Player->getPosition().x - Game::Get()->GetView()->getSize().x/2 < 0)
			cent.x = Game::Get()->GetView()->getSize().x/2;
		else if (m_Player->getPosition().x + Game::Get()->GetView()->getSize().x/2 > Game::Get()->GetActiveScene()->GetBackground()->GetSize().x)
			cent.x = Game::Get()->GetActiveScene()->GetBackground()->GetSize().x - Game::Get()->GetView()->getSize().x/2;

		if (m_Player->getPosition().y - Game::Get()->GetView()->getSize().y/2 < 0)
			cent.y = Game::Get()->GetView()->getSize().y/2;
		else if (m_Player->getPosition().y + Game::Get()->GetView()->getSize().y/2 > Game::Get()->GetActiveScene()->GetBackground()->GetSize().y)
			cent.y = Game::Get()->GetActiveScene()->GetBackground()->GetSize().y - Game::Get()->GetView()->getSize().y/2;
		Game::Get()->GetView()->setCenter(cent);
	}
}

void Area::Render(sf::RenderTarget& target) {
	if (Game::Get()->GetSettings()->DebugHitboxes()) {
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

void Area::OnClose() {
	Game::Get()->ChangeScene(new MainMenu());
}
