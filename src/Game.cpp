#include "Game.hpp"
#include "MainMenu.hpp"

Game* Game::m_Instance;

Game::Game()
{
	//ctor
}

Game::~Game()
{
	//dtor
}

int Game::Run() {
	return m_GameCore->Run(new MainMenu);
}
