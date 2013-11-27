#ifndef GAME_H
#define GAME_H

#include "Core.hpp"
#include "Party.hpp"

//using namespace lpe;
class Game : public lpe::Core {
public:
	// Generic con/destructors
	Game();
	virtual ~Game();
	// Static stuff
	static Game* Get() {return Game::m_Instance;}
	// Accessors
	Party* GetParty() {return m_Party;}
	// Actual functions
	int StartNewGame();
protected:
private:
	static Game* m_Instance;

	Party* m_Party;
};

#endif // GAME_H
