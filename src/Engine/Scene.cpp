#include "Scene.hpp"
#include "Core.hpp"
#include "Utilities.hpp"
#include "InputManager.hpp"

namespace lpe{
Scene::Scene() {
	//ctor
}

Scene::~Scene() {
	delete m_Background;
	for (unsigned int i = 0; i < m_Objects.size(); i++) {
		delete m_Objects[i];
	}
}

void Scene::DoTick() {
	if (Core::Get()->GetInputManager()->IsKeyDown(Key::Escape))
		OnClose();
	//for (unsigned int i = 0; i < m_Objects.size(); i++)
	for (std::vector<Object*>::reverse_iterator i = m_Objects.rbegin(); i != m_Objects.rend(); i++) {
		//Log("Render loop: " + *((Label)m_Objects[i]).GetString());
		//m_Objects[i]->DoTick();
		(*i)->DoTick();
	}
	Tick();
}

float Scene::GetWidth() {
	if (!m_Background)
		return Core::Get()->GetWindow()->getSize().x;
}
float Scene::GetHeight() {
	if (!m_Background)
		return Core::Get()->GetWindow()->getSize().y;
}

void Scene::Tick() {

}

void Scene::DoRender(sf::RenderTarget& target) {
	if (m_Background != 0) {
		target.draw(*m_Background, sf::RenderStates::Default);

	}
	Render(target);
	for (unsigned int i = 0; i < m_Objects.size(); i++) {
		//Log("Render loop: " + *((Label)m_Objects[i]).GetString());
		target.draw(*m_Objects[i], sf::RenderStates::Default);
	}
	if (Core::Get()->GetSettings()->DebugLines()) {
		sf::Vertex hort[] = {sf::Vertex(sf::Vector2f(Core::Get()->GetView()->getCenter().x-Core::Get()->GetWindow()->getSize().x/2, Core::Get()->GetView()->getCenter().y)),
							 sf::Vertex(sf::Vector2f(Core::Get()->GetView()->getCenter().x+Core::Get()->GetWindow()->getSize().x/2, Core::Get()->GetView()->getCenter().y))};
		sf::Vertex vert[] = {sf::Vertex(sf::Vector2f(Core::Get()->GetView()->getCenter().x, Core::Get()->GetView()->getCenter().y-Core::Get()->GetWindow()->getSize().y/2)),
							 sf::Vertex(sf::Vector2f(Core::Get()->GetView()->getCenter().x, Core::Get()->GetView()->getCenter().y+Core::Get()->GetWindow()->getSize().y/2))};
		target.draw(hort,2,sf::PrimitiveType::Lines);
		target.draw(vert,2,sf::PrimitiveType::Lines);
	}
}

void Scene::Render(sf::RenderTarget& target) {

}

void Scene::OnClose() {
	Core::Get()->Quit();
}
}
