#include "DebugRoom.hpp"
#include "Game.hpp"

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
}
