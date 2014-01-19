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

	AddHitboxVertex(0,		0,		0);
	AddHitboxVertex(60,		0,		0);
	AddHitboxVertex(100,	2000,	0);
	AddHitboxVertex(0,		2000,	0);
	/**//*
	AddHitboxVertex(50,		50,		0);
	AddHitboxVertex(110,	50,		0);
	AddHitboxVertex(150,	2050,	0);
	AddHitboxVertex(50,		2050,	0);
	/**/
	AddHitboxVertex(60,		0,		1);
	AddHitboxVertex(1120,	0,		1);
	AddHitboxVertex(1120,	58,		1);
	AddHitboxVertex(60,		65,		1);

	AddHitboxVertex(1116,	0,		2);
	AddHitboxVertex(1370,	0,		2);
	AddHitboxVertex(1365,	558,	2);
	AddHitboxVertex(1118,	563,	2);
	/**/
	CalculateHitboxes();

    AddEntity(new Player(sf::Vector2f(180, 180)))->Load();
    AddEntity(new TruffleMint(sf::Vector2f(200, 350)))->Load();
    AddEntity(new TruffleMint(sf::Vector2f(350, 200)))->Load();
}
