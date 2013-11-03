#include "Game.hpp"
#include "MainMenu.hpp"
#include "DebugRoom.hpp"

Game* Game::m_Instance;

Game::Game() : lpe::Core(new lpe::Settings()) {
	m_Instance = this;
	m_Party = new Party();
	//ctor
}

Game::~Game() {
	//dtor
}

int Game::StartNewGame() {
	ChangeScene(new DebugRoom);
	return 0;
}
