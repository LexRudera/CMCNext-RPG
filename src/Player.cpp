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
	Game::Get()->GetResourceManager()->LoadTexture("Mortem Debug", "mortem-d.png");
	lpe::Log("Texture Loaded");
	GetSpritesheet()->AddSheet(Game::Get()->GetResourceManager()->GetTexture("Mortem Debug"),7,5,100,100);
	lpe::Log("Texture Sheet Added");
	unsigned int idleleft[][3] = 	{{0,0,0}};
	unsigned int idleright[][3] = 	{{0,1,0}};
	unsigned int trotleft[][3] = 	{{0,2,0}, {0,3,0}, {0,4,0}, {0,5,0},
									 {0,6,0}, {0,0,1}, {0,1,1}, {0,2,1},
									 {0,3,1}, {0,4,1}, {0,5,1}, {0,6,1},
									 {0,0,2}, {0,1,2}, {0,2,2}, {0,3,2}};
	unsigned int trotright[][3] =	{{0,4,2}, {0,5,2}, {0,6,2}, {0,0,3},
									 {0,1,3}, {0,2,3}, {0,3,3}, {0,4,3},
									 {0,5,3}, {0,6,3}, {0,0,4}, {0,1,4},
									 {0,2,4}, {0,3,4}, {0,4,4}, {0,5,4}};
	GetSpritesheet()->AddSequence("Idle Left",idleleft,1,0);
	GetSpritesheet()->AddSequence("Idle Right",idleright,1,0);
	GetSpritesheet()->AddSequence("Trot Left",trotleft,16,24);
	GetSpritesheet()->AddSequence("Trot Right",trotright,16,24);
	lpe::Log("Sequence Added");
	lpe::Log("Player Loaded!");
}

void Player::tick() {
	Entity::tick();

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
	if (movement.x != 0 || movement.y != 0) {
		IsMoving(true);
		if (movement.x > 2 && movement.y == 0) {
			GetSpritesheet()->ActivateSequence("Trot Right");
			SetDirection(Direction::Right);
		}
		else if (movement.x > 2 && movement.y > 2) {
			GetSpritesheet()->ActivateSequence("Trot DownRight");
			SetDirection(Direction::DownRight);
		}
		else if (movement.x == 0 && movement.y > 2) {
			GetSpritesheet()->ActivateSequence("Trot Down");
			SetDirection(Direction::Down);
		}
		else if (movement.x < -2 && movement.y > 2) {
			GetSpritesheet()->ActivateSequence("Trot DownLeft");
			SetDirection(Direction::DownLeft);
		}
		else if (movement.x < -2 && movement.y == 0) {
			GetSpritesheet()->ActivateSequence("Trot Left");
			SetDirection(Direction::Left);
		}
		else if (movement.x < -2 && movement.y < -2) {
			GetSpritesheet()->ActivateSequence("Trot UpLeft");
			SetDirection(Direction::UpLeft);
		}
		else if (movement.x == 0 && movement.y < -2) {
			GetSpritesheet()->ActivateSequence("Trot Up");
			SetDirection(Direction::Up);
		}
		else if (movement.x > 2 && movement.y < -2) {
			GetSpritesheet()->ActivateSequence("Trot UpRight");
			SetDirection(Direction::UpRight);
		}
	}
	else {
		if (IsMoving()) {
			switch (GetDirection()) {
			case Direction::Up:
				GetSpritesheet()->ActivateSequence("Idle Up");
				break;
			case Direction::UpRight:
				GetSpritesheet()->ActivateSequence("Idle UpRight");
				break;
			case Direction::Right:
				GetSpritesheet()->ActivateSequence("Idle Right");
				break;
			case Direction::DownRight:
				GetSpritesheet()->ActivateSequence("Idle DownRight");
				break;
			case Direction::Down:
				GetSpritesheet()->ActivateSequence("Idle Down");
				break;
			case Direction::DownLeft:
				GetSpritesheet()->ActivateSequence("Idle DownLeft");
				break;
			case Direction::Left:
				GetSpritesheet()->ActivateSequence("Idle Left");
				break;
			case Direction::UpLeft:
				GetSpritesheet()->ActivateSequence("Idle UpLeft");
				break;
			}
			IsMoving(false);
		}
	}

	move(CorrectMovement(movement));

}
