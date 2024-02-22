#pragma once

#include"Item.h"
#include "Gui.h"

class Inventory{
private:
	Item** itemArray;
	unsigned nrOfItems;
	unsigned capacity;

	sf::Texture inventoryGUI;
	sf::RectangleShape textRectINV;

	sf::Texture hotbarGUI;
	sf::RectangleShape textRectHB;

	//Privatne funkcije
	void initialize();
	void nullify(const unsigned from = 0);
	void freeMemory();

public:
	Inventory(unsigned capacity);
	virtual ~Inventory();

	//Dostop
	const unsigned& size() const;
	const unsigned& maxSize() const;

	void makeInventoryTexture(const sf::VideoMode& vm);

	//Funkcije
	void clear();
	const bool isEmpty() const;

	const bool add(Item* item);
	const bool remove(const unsigned index);

	const bool saveToFile(const std::string fileName);
	const bool loadFromFile(const std::string fileName);

	void updateINV();
	void renderINV(sf::RenderTarget& target);

	void updateHB();
	void renderHB(sf::RenderTarget& target);
};

