#include "DebugRoom.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Characters\TruffleMint.hpp"

DebugRoom::DebugRoom() {
	//ctor
}

DebugRoom::~DebugRoom() {
	//dtor
}

void DebugRoom::Load() {
	Game::Get()->GetResourceManager()->LoadTexture("Debug Background","droom.png");

	lpe::Background* bg = new lpe::Background();
	bg->Add(Game::Get()->GetResourceManager()->GetTexture("Debug Background"));
	ApplyBackground(bg);

    AddEntity(new Player(sf::Vector2f()))->Load();

    AddEntity(new TruffleMint(sf::Vector2f(300, 300)))->Load();
}
