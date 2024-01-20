#pragma once

#include "GameState.h"
#include "EditorState.h"
#include "SettingsState.h"
#include "Gui.h"

class Game;

class PlayGameState : public State{
private:
	Game* game;
	//Lastnosti
	sf::Font font;

	std::map<std::string, sf::Texture>  textures;
	std::map<std::string, sf::RectangleShape> backgrounds;
	std::map<std::string, gui::Button*> buttons;
	std::map<std::string, sf::Text> texts;

	//Privatne funkcije
	void initFonts();
	void initKeybinds();
	void initTextures();
	void initBackgrounds(const sf::VideoMode& vm);
	void initTexts(const sf::VideoMode& vm);
	void initGui();
	void initKeyTime();
	std::string whatTime();
	void resetGui();

	void deleteSave(short saveNum);

public:
	PlayGameState(StateData* state_data,Game* game);
	virtual ~PlayGameState();

	//funkcije
	void updateTexts(unsigned short i);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void renderBackgrounds(sf::RenderTarget& target);
	void renderTexts(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = nullptr);

	void updateInput(const float& dt); //ker ce ne je abstract
};

