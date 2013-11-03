#include "Game.hpp"
#include "MainMenu.hpp"

Game* Game::m_Instance;

Game::Game()
{
	m_Instance = this;
	m_GameCore = new lpe::Core(new lpe::Settings());
	m_Party = new Party();
	//ctor
}

Game::~Game()
{
	//dtor
}

int Game::Launch() {
	return m_GameCore->Run(new MainMenu);
}

int Game::StartNewGame() {
	return 1;
}
