#pragma once

#include"Gui.h"

class Gui;

class PauseMenu{
private:
	sf::Font& font;
	sf::Text menuText;

	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, gui::Button*> buttons;

	std::map<std::string, gui::DropDownList*> dropDownLists;

public:
	PauseMenu(sf::VideoMode& vm, sf::Font& font);
	virtual ~PauseMenu();

	//Dostop
	std::map<std::string, gui::Button*>& getButtons();

	//Funkcije
	void makeSound(const std::string key);
	unsigned short getStatus(const std::string key);
	const bool isButtonPressed(const std::string key);
	void addButton(const std::string key, const float y, const float width,	const float height, const unsigned char_size, const std::string text);
	void addDropDownList(const std::string key, float y, float width, float height, std::string list[],
		unsigned nrOfElements, unsigned default_index = 0);
	gui::DropDownList* getDropDownList(std::string key);
	void update(const sf::Vector2i& mousePosWindow,const float& dt);
	void render(sf::RenderTarget& target);
};