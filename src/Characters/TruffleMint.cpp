#include "Characters\TruffleMint.hpp"
#include "Game.hpp"
#include "Utilities.hpp"

TruffleMint::TruffleMint()
{
	setPosition(300,300);
	//ctor
}

TruffleMint::~TruffleMint()
{
	//dtor
}

void TruffleMint::Load() {
	lpe::Log("Truffle Loading...");

	Game::Get()->GetResourceManager()->LoadTexture("TruffleMint Idle Battle", "TruffleMint_idle_battle.png");
	lpe::Log("Texture Loaded");

	GetSpritesheet()->AddSheet(Game::Get()->GetResourceManager()->GetTexture("TruffleMint Idle Battle"),4,4,128,128);
	lpe::Log("Texture Sheet Added");

	std::vector<Spritesheet::Frame> idlebattle;





	idlebattle.push_back(Spritesheet::Frame(0,0,0));// Section 1
	idlebattle.push_back(Spritesheet::Frame(0,1,0));
	idlebattle.push_back(Spritesheet::Frame(0,2,0));
	idlebattle.push_back(Spritesheet::Frame(0,3,0));
	idlebattle.push_back(Spritesheet::Frame(0,0,0));
	idlebattle.push_back(Spritesheet::Frame(0,1,0));
	idlebattle.push_back(Spritesheet::Frame(0,2,0));
	idlebattle.push_back(Spritesheet::Frame(0,3,0));
	idlebattle.push_back(Spritesheet::Frame(0,0,0));
	idlebattle.push_back(Spritesheet::Frame(0,1,0));
	idlebattle.push_back(Spritesheet::Frame(0,2,0));
	idlebattle.push_back(Spritesheet::Frame(0,3,0));
	idlebattle.push_back(Spritesheet::Frame(0,0,0));// Section 2
	idlebattle.push_back(Spritesheet::Frame(0,1,0, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,0,1, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,1,1));
	idlebattle.push_back(Spritesheet::Frame(0,2,1, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,3,0, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,0,0));// Section 3
	idlebattle.push_back(Spritesheet::Frame(0,1,0));
	idlebattle.push_back(Spritesheet::Frame(0,2,0));
	idlebattle.push_back(Spritesheet::Frame(0,3,0));
	idlebattle.push_back(Spritesheet::Frame(0,0,0));// Section 4
	idlebattle.push_back(Spritesheet::Frame(0,1,0));
	idlebattle.push_back(Spritesheet::Frame(0,2,0));
	idlebattle.push_back(Spritesheet::Frame(0,3,0));
	idlebattle.push_back(Spritesheet::Frame(0,0,0));
	idlebattle.push_back(Spritesheet::Frame(0,1,0));
	idlebattle.push_back(Spritesheet::Frame(0,2,0));
	idlebattle.push_back(Spritesheet::Frame(0,3,1, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,0,2, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,1,2, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,2,2, 3));
	idlebattle.push_back(Spritesheet::Frame(0,3,2, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,1,3, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,3,2, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,2,2, 3));
	idlebattle.push_back(Spritesheet::Frame(0,1,2, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,1,3, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,3,1, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,0,0));


	GetSpritesheet()->AddSequence("Idle Left",idlebattle, 6);
	lpe::Log("Sequence Added");

	lpe::Log("Truffle Loaded!");
}

void TruffleMint::tick() {
	Entity::tick();
}
