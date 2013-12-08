#include "Game.hpp"
#include "InputManager.hpp"
#include <iostream>
#include "Utilities.hpp"

namespace lpe {
//sf::Time Core::sm_frameTime;
//Core* Core::sm_Instance;
Core* Core::m_Instance;

Core::Core() {
	Core::m_Instance = this;

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
	m_window = new sf::RenderWindow(sf::VideoMode(800,600),"CMC Next", sf::Style::Titlebar);
	//m_window->setFramerateLimit(58);
	VerticalSync(1);
	m_view = m_window->getDefaultView();

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
			m_activeScene->DoLoad();
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
		//Log("Inputed?");

		// Logic
		//-------
		//Log("Tick");
		GetActiveScene()->DoTick();
		//Log("Ticked");

		// Render
		//--------
		//Log("Render");
		m_window->setView(m_view);
		m_window->clear( );
		GetActiveScene()->DoRender(*m_window);
		//Log("Rendering FPS");
		if (GetSettings()->ShowFps() && m_window->isOpen()) { // Why it matters if the window is open or not, I don't know.
			FpsTxt.setPosition(m_view.getCenter()-sf::Vector2f(m_view.getSize().x/2, m_view.getSize().y/2));
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

void Core::VerticalSync(short a) {
	switch(a) {
	case 0: //Off
		m_window->setFramerateLimit(0);
		m_window->setVerticalSyncEnabled(false);
		m_VerticalSync = a;
		break;
	case 1: //On
		m_window->setFramerateLimit(0);
		m_window->setVerticalSyncEnabled(true);
		m_VerticalSync = a;
		break;
	case 2: //Frame Limter
		m_window->setFramerateLimit(60);
		m_window->setVerticalSyncEnabled(false);
		m_VerticalSync = a;
		break;
	}
	m_window->setVerticalSyncEnabled(a);
	m_VerticalSync = a;
}
}
