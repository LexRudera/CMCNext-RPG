#ifndef MENU_H
#define MENU_H

#include "Scene.hpp"
#include "MenuControls/ControlBase.hpp"

//---------------------------------------------------------
// The virtual menu class.
// A menu is not just a menu. It's always a specific type
// of menu, like a main menu or options menu.
//---------------------------------------------------------
namespace lpe {
class Menu : public Scene {
public:
	/** Default constructor */
	Menu();
	/** Default destructor */
	virtual ~Menu();
	bool ButtonReady();
protected:
	void Add(ControlBase* obj);
	void Tick();
private:
	bool m_ButtonedFrame = false;
};
}
#endif // MENU_H
