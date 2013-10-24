#include "Game.hpp"
#include "InputManager.hpp"
#include <iostream>
#include "Global.hpp"

sf::Time Game::sm_frameTime;
Game* Game::sm_Instance;

Game::Game() {
	Game::sm_Instance = this;
	m_ResManager = new ResourceManager();
	m_InputMan = new InputManager();
	GetResourceManager()->LoadFont("Gentium", "Gentium-R.ttf",Global);
}

Game::Game(Settings* conf) : Game() {
	m_config = conf;
}

Game::~Game() {
	delete m_activeScene;
	delete m_InputMan;
	delete m_config;
	delete m_ResManager;
	delete m_window;
}

void Game::Run(std::string& EndMessage, Scene* scn) {
	//Log("Initializing");
	Game::sm_frameTime = m_clk.restart();
	//m_window = new sf::RenderWindow(sf::VideoMode(800,600),"Some Game",sf::Style::Fullscreen/*sf::Style::Titlebar*/);
	m_window = new sf::RenderWindow(sf::VideoMode(800,600),"Some Game", sf::Style::Titlebar);

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
			FpsTxt.setString(to_string(1/Game::sm_frameTime.asSeconds()));
			m_window->draw(FpsTxt);
		}
		m_window->display();
		//Log("Rendered");

		// After frame stuff
		//-------------------
		//Log("After");
		Game::sm_frameTime = m_clk.restart();
		//Log("Aftered");
	}
	return;
}
void Game::ChangeScene(Scene* scn, const Persistence& depth) {
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
