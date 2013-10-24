#ifndef GAMEMENU_HPP
#define GAMEMENU_HPP

#include <Menu.hpp>
#include <boost\filesystem.hpp>
#include "MenuControls.hpp"

class GameMenu : public Menu {
	struct GameSlot {
		StaticBox* Box;
		Label* NameLbl;
		Button* Btn;
		boost::filesystem::path Path;
	};

public:
	GameMenu();
	virtual ~GameMenu();

	void Load();
protected:
	void Tick();
private:
	void ScanGameFolder();

	void m_BackBtn_OnClick();

	Button* m_BackBtn;

	std::vector<GameSlot> m_AvailableGames;
};
#endif // GAMEMENU_HPP
