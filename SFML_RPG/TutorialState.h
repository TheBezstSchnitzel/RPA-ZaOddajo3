#pragma once
#include "State.h"
#include "Game.h"

class Slide {
private:
	std::string title;
	std::string text;
public:
	Slide(std::string title);
	~Slide();

	//dostop
	std::string getTitle();

	void setText(std::string text);
	std::string getText();
};

class TutorialState : public State{
private:
	Game* game;

	//ozadje
	sf::RectangleShape background;
	sf::Texture backgroundTexture;
	//font
	sf::Font font;

	//Ozdaje za gumbe
	sf::RectangleShape btnBackground;
	//Gumbi
	std::map<std::string, gui::Button*> buttons;
	
	//ozdaje za info
	sf::RectangleShape infoBackground;
	//slidi
	int currSlide;
	Slide* slides[3];
	sf::Text title;
	sf::Text infoText;

	//inicializacija
	void initFonts();
	void initTextures();
	void initGui();
	void initKeybinds();
	void initSlides();

public:
	TutorialState(StateData* state_data, Game* game);
	virtual ~TutorialState();

	//funkcije
	void updateInput(const float& dt);
	void updateButtons();
	void updateSlides();
	void checkSlidesButtons();
	//update
	void update(const float& dt);
	//render
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

