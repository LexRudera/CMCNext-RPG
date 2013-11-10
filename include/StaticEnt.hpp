#ifndef STATICENTITY_HPP
#define STATICENTITY_HPP

#include "Entity.hpp"

class StaticEnt : public Entity
{
	public:
		StaticEnt(const sf::Vector2f& pos);
		virtual ~StaticEnt();
	protected:
	private:
};

#endif // STATICENTITY_HPP
