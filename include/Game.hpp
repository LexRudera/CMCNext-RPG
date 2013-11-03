#ifndef GAME_H
#define GAME_H

#include "Core.hpp"
#include "Party.hpp"

//using namespace lpe;
class Game {
public:
	// Generic con/destructors
	Game();
	virtual ~Game();
	// Static stuff
	static Game* Get() {return Game::m_Instance;}
	// Accessors
	lpe::Core* GetCore() {return m_GameCore;}
	Party* GetParty() {return m_Party;}
	// Actual functions
	int StartNewGame();
	int Launch();
protected:
private:
	static Game* m_Instance;

	lpe::Core* m_GameCore;
	Party* m_Party;
};

#endif // GAME_H
