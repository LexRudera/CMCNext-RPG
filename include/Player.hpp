#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <Character.hpp>


class Player : public Character
{
public:
	Player();
	virtual ~Player();

	void Load();


protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
};

#endif // PLAYER_HPP
