#ifndef SELECTEDGAMEMENU_H
#define SELECTEDGAMEMENU_H

#include <Menu.hpp>
#include <boost\filesystem.hpp>
#include "MenuControls.hpp"

class SelectedGameMenu : public Menu {
public:
	SelectedGameMenu(const boost::filesystem::path& path);
	virtual ~SelectedGameMenu();

	void Load();
protected:
private:
	// Misc. Info
	boost::filesystem::path m_Path;

	// Controls
	StaticBox* m_Box;
	Label* m_Title;
	Label* m_SubTitle;
	Label* m_Author;
	Label* m_Email;
	Label* m_Website;
	Label* m_Description;
	Selector* m_Saves;
	Button* m_Back;
	Button* m_Load;
	Button* m_Delete;
	Button* m_Play;

	// Control Eventfunctions
	void m_Back_OnClick();
	void m_Load_OnClick();
	void m_Delete_OnClick();
	void m_Play_OnClick();
};

#endif // SELECTEDGAMEMENU_H
