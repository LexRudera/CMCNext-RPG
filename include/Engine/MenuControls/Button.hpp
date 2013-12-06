#ifndef ME_BUTTON_H
#define ME_BUTTON_H

#include <MenuControls/ControlBase.hpp>
#include "MenuControls/Label.hpp"
#include "MenuControls/StaticBox.hpp"
#include "Menu.hpp"

namespace lpe {
struct BtnStateStyle;
class Button : public ControlBase {
public:


	Button(Menu* parent,
	       const sf::String& text,
	       const sf::Vector2f& size = sf::Vector2f(50,50),
	       const sf::Vector2f& pos = sf::Vector2f(),
	       float rot = 0);
	virtual ~Button();

	void tick();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool LoadTexture(const sf::String& strng);
	void SetOnClickFunction(MenuEvent Func) {OnClick = Func;}
	void SetString(const sf::String& t) {m_Text.SetString(t); CenterText();}
	void setSize(const sf::Vector2f& i) {m_Btn.setSize(i); CenterText();}
	sf::Vector2f getSize() {return m_Btn.getSize();}

protected:
private:
	void ApplyState(BtnStateStyle* Style);
	void CenterText();

	// Elements of a button
	Label m_Text;
	StaticBox m_Btn;

	// Function Delegates
	MenuEvent OnClick = 0;

	// Visual Styles
	BoxStyle* IdleStyle = 0;
	BoxStyle* DownStyle = 0;
	BoxStyle* HoverStyle = 0;
};
}
#endif // ME_BUTTON_H
