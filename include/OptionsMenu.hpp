#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include <Menu.hpp>
#include "MenuControls.hpp"

using namespace lpe;
class OptionsMenu : public Menu {
public:
	OptionsMenu();
	virtual ~OptionsMenu();
	void Load();
protected:
private:
	Button* BackBtn;
	Button* VsyncBtn;
	Button* FpsBtn;

	void BackBtn_OnClick();
	void FpsBtn_OnClick();
};

#endif // OPTIONSMENU_H
