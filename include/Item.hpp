#ifndef ITEM_H
#define ITEM_H

#include "Entity.hpp"

class Item : public Entity
{
public:
	Item(const sf::Vector2f& pos);
	virtual ~Item();
protected:
private:
};

#endif // ITEM_H
