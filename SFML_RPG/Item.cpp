#include "stdafx.h"
#include "Item.h"

std::vector<int> Item::takenIDs;

void Item::initVariables(short unsigned type){
	this->findFreeID();
	this->type = type;
}

void Item::findFreeID(){
	std::vector<int>::iterator it = this->takenIDs.begin();
	for (int i = 0;; i++) {
		if (this->takenIDs[i] != i) {
			this->takenIDs.insert(it, i);
			this->id = i;
			break;
		}
		if (it == this->takenIDs.end()) {
			this->takenIDs.push_back(i + 1);
			break;
		}
		else it++;
	}
}

Item::Item(short unsigned type, sf::Texture* inventoryIcon){
	this->initVariables(type);
	this->inventoryIcon = inventoryIcon;
}

Item::~Item(){
	this->takenIDs.erase(this->takenIDs.begin() + this->id);
	delete this->inventoryIcon;
}
