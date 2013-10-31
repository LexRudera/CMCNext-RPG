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
	/*Game::Get()->GetCore()->GetResourceManager()->LoadTexture("Background 1", "bg1.png");
	Game::Get()->GetCore()->GetResourceManager()->LoadTexture("Background 2", "bg2.png");
	Game::Get()->GetCore()->GetResourceManager()->LoadTexture("Background 3", "bg3.png");
	Game::Get()->GetCore()->GetResourceManager()->LoadTexture("Background 4", "bg4.png");
	Game::Get()->GetCore()->GetResourceManager()->LoadTexture("Pretty Texture","Pretty Texture.png");*/

	// Create background
	/*Background* Bg = new Background();
	Bg->Add(Game::Get()->GetCore()->GetResourceManager()->GetTexture("Background 1"),sf::Vector2f(0,0));
	Bg->Add(Game::Get()->GetCore()->GetResourceManager()->GetTexture("Background 2"),sf::Vector2f(50,50));
	Bg->Add(Game::Get()->GetCore()->GetResourceManager()->GetTexture("Background 3"),sf::Vector2f(100,100));
	Bg->Add(Game::Get()->GetCore()->GetResourceManager()->GetTexture("Background 4"),sf::Vector2f(150,150));
	ApplyBackground(Bg);*/

	// Create controls
	Add(Title = new Label("CMC Next",50,sf::Vector2f(50,70)));
	Add(Subtitle = new Label("Developer Version",20,sf::Vector2f(90,120)));
	//Add(ComplementaryPicture = new Image("Pretty Texture",sf::Vector2f(150,75)));
	int windowWidth = Game::Get()->GetCore()->GetWindow()->getSize().x;
	int windowHeight = Game::Get()->GetCore()->GetWindow()->getSize().y;
	int btnWidth = 100;
	int spacing = 50;
	Add(PlayBtn = 		new Button(this,"Pleh", 	sf::Vector2f(btnWidth,30), sf::Vector2f(windowWidth/2 - (4*btnWidth+3*spacing)/2 + 0*btnWidth+0*spacing, windowHeight-30-50)));
	Add(LoadBtn = 		new Button(this,"Load", 	sf::Vector2f(btnWidth,30), sf::Vector2f(windowWidth/2 - (4*btnWidth+3*spacing)/2 + 1*btnWidth+1*spacing, windowHeight-30-50)));
	Add(OptionsBtn = 	new Button(this,"Options", 	sf::Vector2f(btnWidth,30), sf::Vector2f(windowWidth/2 - (4*btnWidth+3*spacing)/2 + 2*btnWidth+2*spacing, windowHeight-30-50)));
	Add(QuitBtn = 		new Button(this,"Quit", 	sf::Vector2f(btnWidth,30), sf::Vector2f(windowWidth/2 - (4*btnWidth+3*spacing)/2 + 3*btnWidth+3*spacing, windowHeight-30-50)));

	// Event Function Delegation
	PlayBtn->SetOnClickFunction(static_cast<MenuEvent>(&MainMenu::PlayBtn_OnClick));
	LoadBtn->SetOnClickFunction(static_cast<MenuEvent>(&MainMenu::LoadBtn_OnClick));
	OptionsBtn->SetOnClickFunction(static_cast<MenuEvent>(&MainMenu::OptionsBtn_OnClick));
	QuitBtn->SetOnClickFunction(static_cast<MenuEvent>(&MainMenu::QuitBtn_OnClick));
}

void MainMenu::PlayBtn_OnClick() {
	Log("Pleh");
//	Game::Get()->GetCore()->ChangeScene(new GameMenu());
	//Core::Quit();
}
void MainMenu::LoadBtn_OnClick() {
	Log("Load");
//	Game::Get()->GetCore()->ChangeScene(new GameMenu());
	//Core::Quit();
}
void MainMenu::OptionsBtn_OnClick() {
	Log("Options");
	Game::Get()->GetCore()->ChangeScene(new OptionsMenu());
	//Core::Quit();
}
void MainMenu::QuitBtn_OnClick() {
	Log("Quit");
	Game::Get()->GetCore()->Quit();
}
