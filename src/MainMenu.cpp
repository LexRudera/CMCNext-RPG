#include "MainMenu.hpp"
#include "Game.hpp"
#include "Utilities.hpp"
#include "OptionsMenu.hpp"
#include "MenuControls\Selector.hpp"

MainMenu::MainMenu() {
}

MainMenu::~MainMenu() {
	//dtor
}

void MainMenu::Load() {
	lpe::Log("Loading MainMenu");
	// Load Resources
	lpe::Log("MainMenu Resources");
	/*Game::Get()->GetCore()->GetResourceManager()->LoadTexture("Background 1", "bg1.png");
	Game::Get()->GetCore()->GetResourceManager()->LoadTexture("Background 2", "bg2.png");
	Game::Get()->GetCore()->GetResourceManager()->LoadTexture("Background 3", "bg3.png");
	Game::Get()->GetCore()->GetResourceManager()->LoadTexture("Background 4", "bg4.png");
	Game::Get()->GetCore()->GetResourceManager()->LoadTexture("Pretty Texture","Pretty Texture.png");*/

	// Create background
	lpe::Log("MainMenu Background");
	/*Background* Bg = new Background();
	Bg->Add(Game::Get()->GetCore()->GetResourceManager()->GetTexture("Background 1"),sf::Vector2f(0,0));
	Bg->Add(Game::Get()->GetCore()->GetResourceManager()->GetTexture("Background 2"),sf::Vector2f(50,50));
	Bg->Add(Game::Get()->GetCore()->GetResourceManager()->GetTexture("Background 3"),sf::Vector2f(100,100));
	Bg->Add(Game::Get()->GetCore()->GetResourceManager()->GetTexture("Background 4"),sf::Vector2f(150,150));
	ApplyBackground(Bg);*/

	// Create controls
	lpe::Log("MainMenu controls");
	//Add(Title = new Label("CMC Next",30,sf::Vector2f(0,30)));
	//Add(ComplementaryPicture = new Image("Pretty Texture",sf::Vector2f(150,75)));
	//Add(PlayBtn = new Button(this,"Pleh", sf::Vector2f(200,50), sf::Vector2f(300,300)));
	//Add(OptionsBtn = new Button(this,"Options", sf::Vector2f(200,50), sf::Vector2f(300,400)));
	Add(QuitBtn = new Button(this,"Quit", sf::Vector2f(200,50), sf::Vector2f(300,500)));

	// Event Function Delegation
	lpe::Log("MainMenu Function delegation");
	//PlayBtn->SetOnClickFunction(static_cast<MenuEvent>(&MainMenu::PlayBtn_OnClick));
	//OptionsBtn->SetOnClickFunction(static_cast<MenuEvent>(&MainMenu::OptionsBtn_OnClick));
	//QuitBtn->SetOnClickFunction(static_cast<MenuEvent>(&MainMenu::QuitBtn_OnClick));
}

void MainMenu::PlayBtn_OnClick() {
	//Log("Play");
//	Game::Get()->GetCore()->ChangeScene(new GameMenu());
	//Core::Quit();
}
void MainMenu::OptionsBtn_OnClick() {
	//Log("Options");
	Game::Get()->GetCore()->ChangeScene(new OptionsMenu());
	//Core::Quit();
}
void MainMenu::QuitBtn_OnClick() {
	//Log("Quit");
	Game::Get()->GetCore()->Quit();
}
