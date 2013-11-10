#ifndef TRUFFLEMINT_H
#define TRUFFLEMINT_H

#include <Character.hpp>


class TruffleMint : public Character
{
public:
	TruffleMint(const sf::Vector2f& pos);
	virtual ~TruffleMint();

	void Load();

protected:
	void tick();
protected:
private:
};

#endif // TRUFFLEMINT_H
