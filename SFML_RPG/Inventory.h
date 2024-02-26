#pragma once

#include"Item.h"
#include "Gui.h"

class Inventory{
private:
	//std::map<int, Item*>inventory;
	//std::map<int, Item*>hotbar;
	Item* inventory[27];
	unsigned nrOfItems;
	unsigned capacity;

	Item* hotbar[9];
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
	sf::Texture* getItemIcon(int itemPlace, bool isInHB = false);
	bool hasItem(int itemPlace, bool isInHB = false); //ce ma item na tistmu indexu

	//Funkcije
	void clear();
	const bool isEmpty() const;

	const bool add(Item* item, int place = -1, bool isInHB = false);
	const bool remove(int place, bool isInHB=false);
	Item* getItem(int place, bool isInHB = false);

	const bool saveToFile(const std::string fileName);
	const bool loadFromFile(const std::string fileName);
};