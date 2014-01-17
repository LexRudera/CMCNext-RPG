#include "Area.hpp"
#include "Game.hpp"
#include "MainMenu.hpp"
#include "Utilities.hpp"

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
	for (unsigned int i = 0; i < m_Objects.size(); i++) { // Iterate through all the objects.
		if (static_cast<Entity*>(m_Objects[i])->GetVelocity().x != 0 || static_cast<Entity*>(m_Objects[i])->GetVelocity().y != 0) { // If the object moves, run collision detection.
			static_cast<Entity*>(m_Objects[i])->CalcFrameVelocity(); // Calculate movement for this frame
			//Log("Entity #" + to_string(i) +" " + to_string(static_cast<Entity*>(m_Objects[i])->GetColliderVelocity()->x) + ";" + to_string(static_cast<Entity*>(m_Objects[i])->GetColliderVelocity()->y));
			for (unsigned int j = 0; j < m_Objects.size(); j++) { // Iterate through all the objects to collide with.
				if (i == j || !static_cast<Entity*>(m_Objects[j])->GetHitboxCounter()) // Same shit, different variable
					continue;

				static_cast<Entity*>(m_Objects[i])->Collision(static_cast<Entity*>(m_Objects[j]));
			}
			// Background
			static_cast<Entity*>(m_Objects[i])->Collision(this);
		}
		// Apply the final calculated movement
		static_cast<Entity*>(m_Objects[i])->ApplyMovement();
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
