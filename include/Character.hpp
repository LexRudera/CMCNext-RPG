#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.hpp"


class Character : public Entity
{
protected:
	enum Direction {
	Up,
	UpRight,
	Right,
	DownRight,
	Down,
	DownLeft,
	Left,
	UpLeft,
	};

public:
	Character(const sf::Vector2f& pos);
	virtual ~Character();
	// Accessors
	bool IsAutonomous() {return m_Autonomous;}
	bool IsMoving() {return m_Moving;}
	Direction GetDirection() {return m_Facing;}

	void IsAutonomous(bool a) {m_Autonomous = a;}
	void IsMoving(bool a) {m_Moving = a;}
	void SetDirection(Direction a) {m_Facing = a;}

protected:
private:
	Direction m_Facing;
	bool m_Moving = false;
	bool m_Autonomous = false;
};

#endif // CHARACTER_H
