#ifndef MAINMENU_H
#define MAINMENU_H

#include <Menu.hpp>
#include "MenuControls.hpp"

class MainMenu : public Menu {
public:
	MainMenu();
	virtual ~MainMenu();
	void Load();
protected:
private:
	Label* Title;
	Image* ComplementaryPicture;
	Button* PlayBtn;
	Button* OptionsBtn;
	Button* QuitBtn;

	void PlayBtn_OnClick();
	void OptionsBtn_OnClick();
	void QuitBtn_OnClick();
};

#endif // MAINMENU_H
