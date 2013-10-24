#include "GameMenu.hpp"
#include "Game.hpp"
#include "MainMenu.hpp"
#include "SelectedGameMenu.hpp"
#include "Global.hpp"
#include "InputManager.hpp"
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/case_conv.hpp>

GameMenu::GameMenu() {
	//ctor
}

GameMenu::~GameMenu() {
	//dtor
}

void GameMenu::Load() {
	Log("--GAMEMENU START--");
	ScanGameFolder();
	Add(m_BackBtn = new Button(this,"<-",sf::Vector2f(100,Game::Get()->GetWindow()->getSize().y-30),sf::Vector2f(15,15)));

	// Create the slots
	const unsigned int& Slots = m_AvailableGames.size();
	const unsigned int height = 80;
	const unsigned int width = Game::Get()->GetWindow()->getSize().x-(m_BackBtn->getSize().x+m_BackBtn->getPosition().x*3);
	const unsigned int space = 25;
	for (unsigned int i = 0; i < Slots; i++) {
		Log("Slot no. " + to_string(i+1));
		sf::Vector2f TopLeftPos = sf::Vector2f(m_BackBtn->getSize().x+m_BackBtn->getPosition().x*2, Game::Get()->GetWindow()->getSize().y/2 +(height+space)*i - (height*Slots + space* (Slots-1))/2 );
		// Set Box
		m_AvailableGames[i].Box->setSize(sf::Vector2f(width, height));
		m_AvailableGames[i].Box->setPosition(TopLeftPos);
		// Set Button
		m_AvailableGames[i].Btn->setSize(sf::Vector2f(170, 30));
		m_AvailableGames[i].Btn->setPosition(TopLeftPos + sf::Vector2f(width-m_AvailableGames[i].Btn->getSize().x-100, height-m_AvailableGames[i].Btn->getSize().y-10));
		m_AvailableGames[i].Btn->DeactivateLogic();
		// Set Label
		m_AvailableGames[i].NameLbl->setPosition(TopLeftPos + sf::Vector2f(100, 5));
	}

	m_BackBtn->SetOnClickFunction(static_cast<MenuEvent>(&GameMenu::m_BackBtn_OnClick));
	Log("--GAMEMENU END--");
}

void GameMenu::ScanGameFolder() {
	// Scan game folder
	boost::filesystem::path GameDir = boost::filesystem::current_path();
	GameDir += "\\games";

	// Iterate through them to find games
	unsigned int counter = 0; // We need to know how many games there actually are
	boost::filesystem::directory_iterator end; // End iterator. Weird.

	// Scanning GameFolder
	for (boost::filesystem::directory_iterator i = boost::filesystem::directory_iterator(GameDir); i != end; ++i) {
		// Is it a directory?
		if(boost::filesystem::is_directory(i->path())) {
			Log("  Folder found");
			//Scanning the directory
			bool valid = false;
			for (boost::filesystem::directory_iterator o = boost::filesystem::directory_iterator(i->path()); o != end; ++o) {
				// Is it the GameInfo.txt file?
				if (boost::algorithm::to_lower_copy(o->path().filename().string()) == "gameinfo.txt") {
					Log("    GameInfo Found");
					valid = true;

					GameSlot a;
					Add(a.Box = new StaticBox());
					Add(a.Btn = new Button(this,"Play"));
					Add(a.NameLbl = new Label(i->path().filename().string()));
					a.Path = i->path();

					m_AvailableGames.push_back(a);

					counter++;
					break;
				}
			}
			// Is it a valid directory? Ie. did it find a GameInfo.txt in the folder?
			if (!valid) {
				Log("    GameInfo not found. Invalid Game Folder");
			}
		}
	}
}

void GameMenu::Tick() {
	// Sense the mouse and react accordingly.
	const sf::Vector2i& MPos = Game::Get()->GetInputManager()->GetMousePos();
	for(unsigned int i = 0; i < m_AvailableGames.size(); i++) {
		if (MPos.x > m_AvailableGames[i].Btn->getPosition().x // Below the x pos
		        && MPos.x < m_AvailableGames[i].Btn->getPosition().x + m_AvailableGames[i].Btn->getSize().x // Above the lower box bounds
		        && MPos.y > m_AvailableGames[i].Btn->getPosition().y // Past the y pos
		        && MPos.y < m_AvailableGames[i].Btn->getPosition().y + m_AvailableGames[i].Btn->getSize().y) { // Before the right box bounds
			//On Click
			if (Game::Get()->GetInputManager()->IsButtonUp(sf::Mouse::Button::Left)) {
				Log(to_string(i));
				Game::Get()->ChangeScene(new SelectedGameMenu(m_AvailableGames[i].Path));
				//Game::Get()->ChangeScene(new SelectedGameMenu(m_AvailableGames[i].Path));
				// If there is an assigned function or not.
				//if (OnClick != 0)
				//{
				//    (m_Parent->*OnClick)();
				//}
			}
		}
	}
}

void GameMenu::m_BackBtn_OnClick() {
	Game::Get()->ChangeScene(new MainMenu());
}
