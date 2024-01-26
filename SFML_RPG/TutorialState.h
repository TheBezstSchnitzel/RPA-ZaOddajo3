#pragma once
#include "State.h"
#include "Game.h"
class TutorialState : public State{
private:
	Game* game;

	//ozadje
	sf::Texture backgroundTexture;
	//font
	sf::Font font;

	//inicializacija
	void initVariables();
	void initFonts();
	void initTextures();
public:
	TutorialState(StateData* state_data, Game* game);
	virtual ~TutorialState();

	//funkcije
	//update
	void update(const float& dt);
	//render
	void render(sf::RenderTarget* target = NULL);
};

