#include "MainMenu.hpp"
#include "Core.hpp"
#include "Utilities.hpp"
#include "OptionsMenu.hpp"
#include "MenuControls\Selector.hpp"

MainMenu::MainMenu() {
}

MainMenu::~MainMenu() {
	//dtor
}

void MainMenu::Load() {
	// Load Resources
	Core::Get()->GetResourceManager()->LoadTexture("Background 1", "bg1.png");
	Core::Get()->GetResourceManager()->LoadTexture("Background 2", "bg2.png");
	Core::Get()->GetResourceManager()->LoadTexture("Background 3", "bg3.png");
	Core::Get()->GetResourceManager()->LoadTexture("Background 4", "bg4.png");
	Core::Get()->GetResourceManager()->LoadTexture("Pretty Texture","Pretty Texture.png");

	// Create background
	Background* Bg = new Background();
	Bg->Add(Core::Get()->GetResourceManager()->GetTexture("Background 1"),sf::Vector2f(0,0));
	Bg->Add(Core::Get()->GetResourceManager()->GetTexture("Background 2"),sf::Vector2f(50,50));
	Bg->Add(Core::Get()->GetResourceManager()->GetTexture("Background 3"),sf::Vector2f(100,100));
	Bg->Add(Core::Get()->GetResourceManager()->GetTexture("Background 4"),sf::Vector2f(150,150));
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
//	Core::Get()->ChangeScene(new GameMenu());
	//Core::Quit();
}
void MainMenu::OptionsBtn_OnClick() {
	//Log("Options");
	Core::Get()->ChangeScene(new OptionsMenu());
	//Core::Quit();
}
void MainMenu::QuitBtn_OnClick() {
	//Log("Quit");
	Core::Quit();
}
