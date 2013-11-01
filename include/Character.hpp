#ifndef CHARACTER_H
#define CHARACTER_H

#include <Object.hpp>

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

class Character : public lpe::Object
{
public:
	Character();
	virtual ~Character();
protected:
private:
	Direction m_Facing;
	bool m_Autonomous = false;
};

#endif // CHARACTER_H
