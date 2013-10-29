#ifndef GAME_H
#define GAME_H

#include "Core.hpp"

//using namespace lpe;
class Game {
public:
	Game();
	virtual ~Game();

	static Game* Get() {return Game::m_Instance;}

	lpe::Core* GetCore() {return m_GameCore;}
	int Run();
protected:
private:
	static Game* m_Instance;

	lpe::Core* m_GameCore;
};

#endif // GAME_H
