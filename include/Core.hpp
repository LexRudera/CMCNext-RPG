#ifndef GAME_H
#define GAME_H

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
	int Run(Scene* scn);
	sf::RenderWindow* GetWindow() const {
		return m_window;
	}
	Scene* GetActiveScene() const {
		return m_activeScene;
	}
	void ChangeScene(Scene* scn, const Persistence& depth = Level);

	sf::Time* GetFrameTime() {return &Core::sm_frameTime;}
	Settings* GetConfiguration() {return m_config;}
	ResourceManager* GetResourceManager() {return m_ResManager;}
	InputManager* GetInputManager() {return m_InputMan;}

	static Core* Get() {return sm_Instance;}
	static void Quit() {
		Core::sm_Instance->GetWindow()->close();
	}
protected:
private:
	Core();

	sf::Clock m_clk;
	Settings* m_config = 0;
	sf::RenderWindow* m_window = 0;
	Scene* m_activeScene = 0;
	Scene* m_nextscene = 0;
	Persistence m_LvlChngMsg = Level;
	ResourceManager* m_ResManager;
	InputManager* m_InputMan;

	static sf::Time sm_frameTime;
	static Core* sm_Instance;
};
}
#endif // GAME_H
