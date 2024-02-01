#pragma once

#include "GameState.h"
#include "EditorState.h"
#include "SettingsState.h"
#include "TutorialState.h"
#include "Gui.h"
#include "PlayGameState.h"

class Game;

class MainMenuState : public State{
private:
	Game* game;
	//Lastnosti
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	sf::RectangleShape btnBackground;
	std::map<std::string, gui::Button*> buttons;

	//refreshanje
	bool isTrueRes;

	//Privatne funkcije
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initGui();
	void resetGui();

public:
	//konstruktor / destruktor
	MainMenuState(StateData* state_data,Game*game);
	virtual ~MainMenuState();

	//Funkcije
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};