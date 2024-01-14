#pragma once

#include "State.h"
#include "Gui.h"
#include "Game.h"

class Game;

class SettingsState : public State{
private:
	Game* game;
	//Lastnosti
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::RectangleShape btnBackground;
	sf::Font font;

	//Zvok
	bool sound;
	sf::SoundBuffer buffer;
	sf::Sound click;

	std::map<std::string, gui::Button*> buttons;
	std::map<std::string, gui::DropDownList*> dropDownLists;

	sf::Text optionsText;

	std::vector<sf::VideoMode> modes;

	//Settings
	bool fullscreen;

	//Privatne funkcije
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initGui();
	void resetGui();

	int findIndexOfCurrRes();

public:
	SettingsState(StateData* state_data, Game* game);
	virtual ~SettingsState();
	//Funkcije
	void updateInput(const float& dt);
	void updateGui(const float& dt);
	void update(const float& dt);
	void renderGui(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};