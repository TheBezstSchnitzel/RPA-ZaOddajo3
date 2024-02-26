#pragma once

#include"Item.h"
#include "Gui.h"

class Inventory{
private:
	Item* inventory[36];
	unsigned nrOfItems;
	unsigned capacity;

	unsigned short idSelectedHotbar; //0-8

	//Privatne funkcije
	void initialize();
	void freeMemory();

public:
	Inventory();
	virtual ~Inventory();

	//Dostop
	const unsigned& size() const;
	const unsigned& maxSize() const;
	void setSelectedHB(unsigned short id);
	unsigned short getIDSelectedHB();
	sf::Texture* getItemIcon(int itemPlace);
	bool hasItem(int itemPlace); //ce ma item na tistmu indexu

	//Funkcije
	void clear();
	const bool isEmpty() const;

	const bool add(Item* item, int place = -1);
	const bool remove(int place);
	Item* getItem(int place);

	const bool saveToFile(const std::string fileName);
	const bool loadFromFile(const std::string fileName);
};