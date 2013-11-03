#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.hpp"

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

class Character : public Entity
{
public:
	Character();
	virtual ~Character();
	// Accessors
	bool IsAutonomous() {return m_Autonomous;}

	void IsAutonomous(bool a) {m_Autonomous = a;}
protected:
private:
	Direction m_Facing;
	bool m_Autonomous = false;
};

#endif // CHARACTER_H
