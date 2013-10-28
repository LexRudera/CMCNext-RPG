#include "OptionsMenu.hpp"
#include "Core.hpp"
#include "MainMenu.hpp"

OptionsMenu::OptionsMenu() {
}

OptionsMenu::~OptionsMenu() {
	//dtor
}

void OptionsMenu::Load() {
	Add(BackBtn = new Button(this,"Back",sf::Vector2f(100,50),sf::Vector2f(500,500)));
	Add(FpsBtn = new Button(this,""));

	if (Core::Get()->GetConfiguration()->ShowFps()) {
		FpsBtn->SetString("Show Fps: On");
	} else {
		FpsBtn->SetString("Show Fps: Off");
	}

	BackBtn->SetOnClickFunction(static_cast<MenuEvent>(&OptionsMenu::BackBtn_OnClick));
	FpsBtn->SetOnClickFunction(static_cast<MenuEvent>(&OptionsMenu::FpsBtn_OnClick));
}

void OptionsMenu::BackBtn_OnClick() {
	Core::Get()->ChangeScene(new MainMenu());
}
void OptionsMenu::FpsBtn_OnClick() {
	if (Core::Get()->GetConfiguration()->ShowFps()) {
		FpsBtn->SetString("Show Fps: Off");
		Core::Get()->GetConfiguration()->ShowFps(false);
	} else {
		FpsBtn->SetString("Show Fps: On");
		Core::Get()->GetConfiguration()->ShowFps(true);
	}
}
