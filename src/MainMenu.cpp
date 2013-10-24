#include "MainMenu.hpp"
#include "Game.hpp"
#include "Global.hpp"
#include "OptionsMenu.hpp"
#include "GameMenu.hpp"
#include "MenuControls\Selector.hpp"

MainMenu::MainMenu() {
}

MainMenu::~MainMenu() {
	//dtor
}

void MainMenu::Load() {
	// Load Resources
	Game::Get()->GetResourceManager()->LoadTexture("Background 1", "bg1.png");
	Game::Get()->GetResourceManager()->LoadTexture("Background 2", "bg2.png");
	Game::Get()->GetResourceManager()->LoadTexture("Background 3", "bg3.png");
	Game::Get()->GetResourceManager()->LoadTexture("Background 4", "bg4.png");
	Game::Get()->GetResourceManager()->LoadTexture("Pretty Texture","Pretty Texture.png");

	// Create background
	Background* Bg = new Background();
	Bg->Add(Game::Get()->GetResourceManager()->GetTexture("Background 1"),sf::Vector2f(0,0));
	Bg->Add(Game::Get()->GetResourceManager()->GetTexture("Background 2"),sf::Vector2f(50,50));
	Bg->Add(Game::Get()->GetResourceManager()->GetTexture("Background 3"),sf::Vector2f(100,100));
	Bg->Add(Game::Get()->GetResourceManager()->GetTexture("Background 4"),sf::Vector2f(150,150));
	ApplyBackground(Bg);

	// Create controls
	Add(Title = new Label("SomeString",30,sf::Vector2f(0,30)));
	Add(ComplementaryPicture = new Image("Pretty Texture",sf::Vector2f(150,75)));
	Add(PlayBtn = new Button(this,"Pleh", sf::Vector2f(200,50), sf::Vector2f(300,300)));
	Add(OptionsBtn = new Button(this,"Options", sf::Vector2f(200,50), sf::Vector2f(300,400)));
	Add(QuitBtn = new Button(this,"Quit", sf::Vector2f(200,50), sf::Vector2f(300,500)));

	// Event Function Delegation
	PlayBtn->SetOnClickFunction(static_cast<MenuEvent>(&MainMenu::PlayBtn_OnClick));
	OptionsBtn->SetOnClickFunction(static_cast<MenuEvent>(&MainMenu::OptionsBtn_OnClick));
	QuitBtn->SetOnClickFunction(static_cast<MenuEvent>(&MainMenu::QuitBtn_OnClick));
}

void MainMenu::PlayBtn_OnClick() {
	//Log("Play");
	Game::Get()->ChangeScene(new GameMenu());
	//Game::Quit();
}
void MainMenu::OptionsBtn_OnClick() {
	//Log("Options");
	Game::Get()->ChangeScene(new OptionsMenu());
	//Game::Quit();
}
void MainMenu::QuitBtn_OnClick() {
	//Log("Quit");
	Game::Quit();
}
