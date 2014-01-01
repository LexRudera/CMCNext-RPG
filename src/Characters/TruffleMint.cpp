#include "Characters\TruffleMint.hpp"
#include "Game.hpp"
#include "Utilities.hpp"

TruffleMint::TruffleMint(const sf::Vector2f& pos) : Character(pos)
{
	//ctor
}

TruffleMint::~TruffleMint()
{
	//dtor
}

void TruffleMint::Load() {
	Log("Truffle Loading...");

	Game::Get()->GetResourceManager()->LoadTexture("TruffleMint Idle Battle", "TruffleMint_idle_battle.png");
	Log("Texture Loaded");

	GetSpritesheet()->AddSheet(Game::Get()->GetResourceManager()->GetTexture("TruffleMint Idle Battle"),4,4);
	Log("Texture Sheet Added");

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
	idlebattle.push_back(Spritesheet::Frame(0,0,3, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,3,2, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,2,2, 3));
	idlebattle.push_back(Spritesheet::Frame(0,1,2, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,1,3, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,3,1, 0.5));
	idlebattle.push_back(Spritesheet::Frame(0,0,0));
	GetSpritesheet()->AddSequence("Idle Left",idlebattle, 6);
	Log("Sequence Added");

AddHitboxVertex(0,0);
AddHitboxVertex(100,0);
AddHitboxVertex(100,100);
AddHitboxVertex(0,100);
CalculateHitboxes();

	Log("Truffle Loaded!");
}

void TruffleMint::tick() {
	Entity::tick();
}
