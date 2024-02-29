#pragma once

#include"Item.h"
#include "Gui.h"

class Inventory{
private:
	Item* inventory[36];
	unsigned nrOfItems;
	unsigned capacity;

	unsigned int money;

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
	unsigned int getMoney();
	void addMoney(unsigned int amount);
	void takeMoney(unsigned int amount);
	bool hasEnoughMoney(unsigned int amount);

	//Funkcije
	void clear();
	const bool isEmpty() const;

	const bool add(Item* item, int place = -1);
	const bool remove(int place);
	Item* getItem(int place);

	void saveToFile(const std::string fileName);
	void loadFromFile(const std::string fileName);
};