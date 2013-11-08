#include "Player.hpp"
#include "Game.hpp"

Player::Player()
{
	//ctor
}

Player::~Player()
{
	//dtor
}

void Player::Load() {
	Game::Get()->GetResourceManager()->LoadTexture("Morty Idle Left", "mortem_idle_left.png");
	GetSpritesheet()->AddSheet(Game::Get()->GetResourceManager()->GetTexture("Morty Idle Left"));
	unsigned int a[][3] = {{0,0,0}};
	GetSpritesheet()->AddSequence("Morty Idle Left",a,1,0);
}

