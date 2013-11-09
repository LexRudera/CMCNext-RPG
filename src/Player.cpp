#include "Player.hpp"
#include "Game.hpp"
#include "InputManager.hpp"
#include "Utilities.hpp"

Player::Player()
{
	//ctor
}

Player::~Player()
{
	//dtor
}

void Player::Load() {
	lpe::Log("Player Loading...");
	Game::Get()->GetResourceManager()->LoadTexture("Morty Idle Left", "mortem_idle_left.png");
	Game::Get()->GetResourceManager()->LoadTexture("Morty Idle Right", "mortem_idle_right.png");
	lpe::Log("Texture Loaded");
	GetSpritesheet()->AddSheet(Game::Get()->GetResourceManager()->GetTexture("Morty Idle Left"));
	GetSpritesheet()->AddSheet(Game::Get()->GetResourceManager()->GetTexture("Morty Idle Right"));
	lpe::Log("Texture Sheet Added");
	unsigned int idleleft[][3] = {{0,0,0}};
	unsigned int idleright[][3] = {{1,0,0}};
	GetSpritesheet()->AddSequence("Idle Left",idleleft,1,0);
	GetSpritesheet()->AddSequence("Idle Right",idleright,1,0);
	lpe::Log("Sequence Added");
	lpe::Log("Player Loaded!");
}

void Player::tick() {
	sf::Vector2f movement;
	if (Game::Get()->GetInputManager()->IsKeyPressed(Key::D)) {
		movement.x+=200;
	}
	if (Game::Get()->GetInputManager()->IsKeyPressed(Key::A)) {
		movement.x-=200;
	}
	if (Game::Get()->GetInputManager()->IsKeyPressed(Key::S)) {
		movement.y+=200;
	}
	if (Game::Get()->GetInputManager()->IsKeyPressed(Key::W)) {
		movement.y-=200;
	}

	// Sprite Update
	if (movement.x != 0 && movement.y != 0) {
		IsMoving(true);
		if (movement.x > 2) {
			GetSpritesheet()->ActivateSequence("Idle Right");
			SetDirection(Direction::Right);
		}
		else if (movement.x < -2) {
			GetSpritesheet()->ActivateSequence("Idle Left");
			SetDirection(Direction::Left);
		}
	}
	else {
		if (!IsMoving()) {
			switch (GetDirection()) {
			case Direction::Up:
				break;
			case Direction::UpRight:
				break;
			case Direction::Right:
				GetSpritesheet()->ActivateSequence("Idle Right");
				break;
			case Direction::DownRight:
				break;
			case Direction::Down:
				break;
			case Direction::DownLeft:
				break;
			case Direction::Left:
				GetSpritesheet()->ActivateSequence("Idle Left");
				break;
			case Direction::UpLeft:
				break;
			}
		}
	}

	move(CorrectMovement(movement));

}
