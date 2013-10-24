#include "OptionsMenu.hpp"
#include "Game.hpp"
#include "MainMenu.hpp"

OptionsMenu::OptionsMenu() {
}

OptionsMenu::~OptionsMenu() {
	//dtor
}

void OptionsMenu::Load() {
	Add(BackBtn = new Button(this,"Back",sf::Vector2f(100,50),sf::Vector2f(500,500)));
	Add(FpsBtn = new Button(this,""));

	if (Game::Get()->GetConfiguration()->ShowFps()) {
		FpsBtn->SetString("Show Fps: On");
	} else {
		FpsBtn->SetString("Show Fps: Off");
	}

	BackBtn->SetOnClickFunction(static_cast<MenuEvent>(&OptionsMenu::BackBtn_OnClick));
	FpsBtn->SetOnClickFunction(static_cast<MenuEvent>(&OptionsMenu::FpsBtn_OnClick));
}

void OptionsMenu::BackBtn_OnClick() {
	Game::Get()->ChangeScene(new MainMenu());
}
void OptionsMenu::FpsBtn_OnClick() {
	if (Game::Get()->GetConfiguration()->ShowFps()) {
		FpsBtn->SetString("Show Fps: Off");
		Game::Get()->GetConfiguration()->ShowFps(false);
	} else {
		FpsBtn->SetString("Show Fps: On");
		Game::Get()->GetConfiguration()->ShowFps(true);
	}
}
