#include "Game.hpp"
#include "MainMenu.hpp"

Game* Game::m_Instance;

Game::Game()
{
	m_GameCore = new lpe::Core(new lpe::Settings());
	//ctor
}

Game::~Game()
{
	//dtor
}

int Game::Run() {
	return m_GameCore->Run(new MainMenu);
}
