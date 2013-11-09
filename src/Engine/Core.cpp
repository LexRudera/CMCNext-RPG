#include "Game.hpp"
#include "InputManager.hpp"
#include <iostream>
#include "Utilities.hpp"

namespace lpe {
//sf::Time Core::sm_frameTime;
//Core* Core::sm_Instance;

Core::Core() {
	//Core::m_Instance = this;
	m_ResManager = new ResourceManager();
	m_InputMan = new InputManager(this);
	GetResourceManager()->LoadFont("Gentium", "Gentium-R.ttf",Global);
}

Core::Core(Settings* conf) : Core() {
	m_config = conf;
}

Core::~Core() {
	delete m_activeScene;
	delete m_InputMan;
	delete m_config;
	delete m_ResManager;
	delete m_window;
}

int Core::Run(Scene* scn) {
	//Log("Initializing");
	m_frameTime = m_clk.restart();
	//m_window = new sf::RenderWindow(sf::VideoMode(800,600),"Some Game",sf::Style::Fullscreen/*sf::Style::Titlebar*/);
	m_window = new sf::RenderWindow(sf::VideoMode(800,600),"Some Game", sf::Style::Titlebar);
	m_window->setFramerateLimit(60);

	ChangeScene(scn);

	sf::Event event;
	sf::Text FpsTxt;
	FpsTxt.setCharacterSize(20);
	FpsTxt.setFont(*GetResourceManager()->GetFont("Gentium"));
	Log("Initialized");
	while (m_window->isOpen()) {
		// Scene Management
		//------------------
		if (m_nextscene != 0) {
			Log("Changing Scene");
			// Destroy the scene
			delete m_activeScene;
			m_activeScene = m_nextscene;
			m_nextscene = 0;
			// Destroy resources acordingly to level change message
			GetResourceManager()->Clear(m_LvlChngMsg);
			m_LvlChngMsg = Level;
			// Load and apply next scene
			m_activeScene->Load();
			Log("Scene Changed");
		}

		// Input/events
		//--------------
		//Log("Input");
		m_InputMan->Clear();
		while (m_window->pollEvent(event)) {
			// Close window : exit
			if (event.type == sf::Event::Closed)
				m_window->close();
			// Feed the InputManager
			m_InputMan->ProcessInput(event);
		}
		if (GetInputManager()->IsKeyDown(sf::Keyboard::Key::Escape))
			m_window->close();
		//Log("Inputed?");

		// Logic
		//-------
		//Log("Tick");
		GetActiveScene()->DoTick();
		//Log("Ticked");

		// Render
		//--------
		//Log("Render");
		m_window->clear( );
		GetActiveScene()->Render(*m_window);
		//Log("Rendering FPS");
		if (GetConfiguration()->ShowFps() && m_window->isOpen()) { // Why it matters if the window is open or not, I don't know.
			FpsTxt.setString(to_string(1/m_frameTime.asSeconds()));
			m_window->draw(FpsTxt);
		}
		m_window->display();
		//Log("Rendered");

		// After frame stuff
		//-------------------
		//Log("After");
		m_frameTime = m_clk.restart();
		//Log("Aftered");
	}
	return 0;
}
void Core::ChangeScene(Scene* scn, const Persistence& depth) {
	/*if (m_activeScene != 0)
	{
	    delete m_activeScene;
	    //m_activeScene = 0;
	}
	Log("Changing scene");
	m_activeScene = scn;
	Log("Changed scene");
	return;*/

	m_LvlChngMsg = depth;
	m_nextscene = scn;
}
}
