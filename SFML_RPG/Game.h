#pragma once

#include "MainMenuState.h"

class Game{
private:
	//Lastnosti
	GraphicsSettings gfxSettings;
	StateData stateData;
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	float gridSize;

	//Tematska pesem
	sf::Music theme;

	//Inicializacija
	void initVariables();
	void initGraphicsSettings();
	void initWindow();
	void initKeys();
	void initStateData();
	void initStates();

public:
	//Konstuktor / destruktor
	Game();
	virtual ~Game();

	//Funkcije

	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Zvok
	void playTheme(bool what=true);
	void restartTheme(bool go=true);
	int getThemeStatus();

	//Render
	void render();

	//Core
	void run();
};