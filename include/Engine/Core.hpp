#ifndef CORE_H
#define CORE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Settings.hpp"
#include "Scene.hpp"
#include "ResourceManager.hpp"
//#include "InputManager.hpp"
namespace lpe {
class InputManager;
class Core {
public:
	Core(Settings* conf);
	virtual ~Core();

	static Core* Get() {return m_Instance;}

	int Run(Scene* scn);
	sf::RenderWindow* GetWindow() const {
		return m_window;
	}
	Scene* GetActiveScene() const {
		return m_activeScene;
	}
	void ChangeScene(Scene* scn, const Persistence& depth = Level);

	const sf::Time* GetFrameTime() const {return &m_frameTime;}
	Settings* GetConfiguration() {return m_config;}
	ResourceManager* GetResourceManager() {return m_ResManager;}
	InputManager* GetInputManager() {return m_InputMan;}
	sf::View* GetView() {return &m_view;}

	void Quit() {
		GetWindow()->close();
	}
protected:
private:
	Core();

	static Core* m_Instance;

	sf::Clock m_clk;
	sf::View m_view;
	Settings* m_config = 0;
	sf::RenderWindow* m_window = 0;
	Scene* m_activeScene = 0;
	Scene* m_nextscene = 0;
	Persistence m_LvlChngMsg = Level;
	ResourceManager* m_ResManager;
	InputManager* m_InputMan;

	sf::Time m_frameTime;
};
}
#endif // CORE_H
