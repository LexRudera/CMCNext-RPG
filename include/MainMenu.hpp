#ifndef MAINMENU_H
#define MAINMENU_H

#include <Menu.hpp>
#include "MenuControls.hpp"

using namespace lpe;
class MainMenu : public Menu {
public:
	MainMenu();
	virtual ~MainMenu();
	void Load();
protected:
private:
	//Label* Title;
	Image* Title;
	Label* Subtitle;
	Image* ComplementaryPicture;
	Button* PlayBtn;
	Button* LoadBtn;
	Button* OptionsBtn;
	Button* QuitBtn;

	void PlayBtn_OnClick();
	void OptionsBtn_OnClick();
	void QuitBtn_OnClick();
	void LoadBtn_OnClick();
};

#endif // MAINMENU_H
