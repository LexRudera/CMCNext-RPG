#include "OptionsMenu.hpp"
#include "Game.hpp"
#include "MainMenu.hpp"

OptionsMenu::OptionsMenu() {
}

OptionsMenu::~OptionsMenu() {
	//dtor
}

void OptionsMenu::Load() {
	// Create buttons
	Add(BackBtn = 			new Button(this,"Back",	sf::Vector2f(100,30),	sf::Vector2f(Game::Get()->GetWindow()->getSize().x/2 + 175, Game::Get()->GetWindow()->getSize().y-30-50)));
	Add(VsyncBtn = 			new Button(this,"",		sf::Vector2f(200,30),	sf::Vector2f(Game::Get()->GetWindow()->getSize().x/2 - 350, 50)));
	Add(FpsBtn = 			new Button(this,"",		sf::Vector2f(200,30),	sf::Vector2f(Game::Get()->GetWindow()->getSize().x/2 - 350, 100)));
	Add(DebugLinesBtn =		new Button(this,"",		sf::Vector2f(200,30),	sf::Vector2f(Game::Get()->GetWindow()->getSize().x/2 - 350, 150)));
	Add(DebugHitboxesBtn =	new Button(this,"",		sf::Vector2f(200,30),	sf::Vector2f(Game::Get()->GetWindow()->getSize().x/2 - 350, 200)));

	// Set buttons
	switch (Game::Get()->VerticalSync()) {
	case 0: VsyncBtn->SetString("VSync: Off"); break;
	case 1: VsyncBtn->SetString("VSync: On"); break;
	case 2: VsyncBtn->SetString("VSync: Frame limiter"); break;
	}

	if (Game::Get()->GetSettings()->ShowFps()) FpsBtn->SetString("Show Fps: On");
	else FpsBtn->SetString("Show Fps: Off");

	if (Game::Get()->GetSettings()->DebugLines()) DebugLinesBtn->SetString("Debug Lines: On");
	else DebugLinesBtn->SetString("Debug Lines: Off");

	if (Game::Get()->GetSettings()->DebugHitboxes()) DebugHitboxesBtn->SetString("Render Hitboxes: On");
	else DebugHitboxesBtn->SetString("Render Hitboxes: Off");

	// Click function delegates
	BackBtn->SetOnClickFunction(static_cast<MenuEvent>(&OptionsMenu::BackBtn_OnClick));
	VsyncBtn->SetOnClickFunction(static_cast<MenuEvent>(&OptionsMenu::VsyncBtn_OnClick));
	FpsBtn->SetOnClickFunction(static_cast<MenuEvent>(&OptionsMenu::FpsBtn_OnClick));
	DebugLinesBtn->SetOnClickFunction(static_cast<MenuEvent>(&OptionsMenu::DebugLinesBtn_OnClick));
	DebugHitboxesBtn->SetOnClickFunction(static_cast<MenuEvent>(&OptionsMenu::DebugHitboxesBtn_OnClick));
}

void OptionsMenu::BackBtn_OnClick() {
	Game::Get()->ChangeScene(new MainMenu());
}

void OptionsMenu::VsyncBtn_OnClick() {
	switch (Game::Get()->VerticalSync()) {
	case 0:
		VsyncBtn->SetString("VSync: On");
		Game::Get()->VerticalSync(1);
		break;
	case 1:
		VsyncBtn->SetString("VSync: Frame limiter");
		Game::Get()->VerticalSync(2);
		break;
	case 2:
		VsyncBtn->SetString("VSync: Off");
		Game::Get()->VerticalSync(0);
		break;
	}
}

void OptionsMenu::FpsBtn_OnClick() {
	if (Game::Get()->GetSettings()->ShowFps()) {
		FpsBtn->SetString("Show Fps: Off");
		Game::Get()->GetSettings()->ShowFps(false);
	} else {
		FpsBtn->SetString("Show Fps: On");
		Game::Get()->GetSettings()->ShowFps(true);
	}
}

void OptionsMenu::DebugLinesBtn_OnClick() {
	if (Game::Get()->GetSettings()->DebugLines()) {
		DebugLinesBtn->SetString("Debug Lines: Off");
		Game::Get()->GetSettings()->DebugLines(false);
	} else {
		DebugLinesBtn->SetString("Debug Lines: On");
		Game::Get()->GetSettings()->DebugLines(true);
	}
}

void OptionsMenu::DebugHitboxesBtn_OnClick() {
	if (Game::Get()->GetSettings()->DebugHitboxes()) {
		DebugHitboxesBtn->SetString("Render Hitboxes: Off");
		Game::Get()->GetSettings()->DebugHitboxes(false);
	} else {
		DebugHitboxesBtn->SetString("Render Hitboxes: On");
		Game::Get()->GetSettings()->DebugHitboxes(true);
	}
}
