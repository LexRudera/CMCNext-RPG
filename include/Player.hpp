#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <Character.hpp>


class Player : public Character
{
public:
	Player(const sf::Vector2f& pos);
	virtual ~Player();

	void Load();

protected:
	void tick();
private:
};

#endif // PLAYER_HPP
