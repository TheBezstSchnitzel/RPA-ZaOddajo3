#pragma once

#include"Item.h"
#include "Gui.h"

class Inventory{
private:
	Item** itemArray;
	unsigned nrOfItems;
	unsigned capacity;

	Item* hotbar[9];
	unsigned short idSelectedHotbar; //0-8

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
	void setSelectedHB(unsigned short id);
	unsigned short getIDSelectedHB();

	//Funkcije
	void clear();
	const bool isEmpty() const;

	const bool add(Item* item);
	const bool remove(const unsigned index);

	const bool saveToFile(const std::string fileName);
	const bool loadFromFile(const std::string fileName);
};

