#pragma once

#include"Item.h"

class Inventory{
private:
	Item** itemArray;
	unsigned nrOfItems;
	unsigned capacity;

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


	//Funkcije
	void clear();
	const bool empty() const;

	const bool add(Item* item);
	const bool remove(const unsigned index);

	const bool saveToFile(const std::string fileName);
	const bool loadFromFile(const std::string fileName);
};

