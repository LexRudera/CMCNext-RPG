#ifndef CONTROLBASE_H
#define CONTROLBASE_H

#include "Object.hpp"
namespace lpe {
class Menu;
typedef void (Menu::* MenuEvent)(); // MenuEvent type definition

class ControlBase : public Object {
public:
	ControlBase();
	virtual ~ControlBase();
	bool IsScrolling() {
		return m_Scrolling;
	}
	void IsScrolling(bool a) {
		m_Scrolling = a;
	}
protected:
	Menu* m_Parent;
private:
	bool m_Scrolling = true;
};
}
#endif // CONTROLBASE_H
