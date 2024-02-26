#include "stdafx.h"
#include "Inventory.h"

//Private functions
void Inventory::initialize(){
	this->nrOfItems = 0;
	for (int i = 0; i < this->capacity; i++) {
		this->inventory[i] = nullptr;
	}
	for (int i = 0; i < 9; i++) {
		this->hotbar[i] = nullptr;
	}
}

void Inventory::freeMemory(){
	for (size_t i = 0; i < this->capacity; i++){
		delete this->inventory[i];
	}
	for (size_t i = 0; i < 9; i++) {
		delete this->hotbar[i];
	}
}

//Konstruktor / Destruktor
Inventory::Inventory(){
	this->capacity = 27;
	this->initialize();
	this->idSelectedHotbar = 0;
}

Inventory::~Inventory(){
	this->freeMemory();
}

//Dostop

const unsigned & Inventory::size() const{
	return this->nrOfItems;
}

const unsigned & Inventory::maxSize() const{
	return this->capacity;
}

void Inventory::setSelectedHB(unsigned short id){
	if (id >= 0 && id <= 8) {
		this->idSelectedHotbar = id;
	}
}

unsigned short Inventory::getIDSelectedHB(){
	return this->idSelectedHotbar;
}

sf::Texture* Inventory::getItemIcon(int itemPlace, bool isInHB){ //item plac od 0
	//preveri itemplace
	if (isInHB) {
		if (itemPlace <= 9) {
			if (this->hotbar[itemPlace] == nullptr)return nullptr;
			else return this->hotbar[itemPlace]->getTexture();
		}
		else return nullptr;
	}
	else {
		if (itemPlace <= this->capacity - 1) {
			//if (this->inventory[0] == nullptr)std::cout << "Dela" << std::endl;
			if (this->inventory[itemPlace] == nullptr) {
				//std::cout << "test" << std::endl;
				return nullptr;
			}
			else return this->inventory[itemPlace]->getTexture();
		}
	}
}

bool Inventory::hasItem(int itemPlace, bool isInHB){
	if (itemPlace < 0 || itemPlace > this->capacity - 1)return false;
	if (isInHB) {
		if (itemPlace > 8)return false;
		return (this->hotbar[itemPlace] != nullptr);
	}else {
		return (this->inventory[itemPlace] != nullptr);
	}
}

//Funkcije

void Inventory::clear(){
	this->initialize();
}

const bool Inventory::isEmpty() const{
	return this->nrOfItems == 0;
}

const bool Inventory::add(Item * item, int place, bool isInHB){ //item plac od 0
	if (this->nrOfItems == this->capacity)return false;
	if (place < 0) {
		//doda na prvo prosto mesto
		for (int i = 0; i < 9; i++) {
			if (this->hotbar[i] == nullptr) {
				this->hotbar[i] = item;
				this->nrOfItems++;
				return true;
			}
		}
		for (int i = 0; i < this->capacity; i++) {
			if (this->inventory[i] == nullptr) {
				this->inventory[i] == item;
				this->nrOfItems++;
				return true;
			}
		}
	}
	if (isInHB) {
		if (place > 9)return false;
		if (this->hotbar[place] == nullptr) {
			this->hotbar[place] = item;
			this->nrOfItems++;
			return true;
		}
		return false;
	}
	else {
		if (place > this->capacity - 1)return false;
		if (this->inventory[place] == nullptr) {
			this->inventory[place] = item;
			this->nrOfItems++;
			return true;
		}
		return false;
	}
}

const bool Inventory::remove(int place, bool isInHB){
	if (this->nrOfItems > 0 && this->hasItem(place,isInHB)) {
		if (isInHB) {
			this->hotbar[place] = nullptr;
			this->nrOfItems--;
		}else {
			this->inventory[place] = nullptr;
			this->nrOfItems--;
		}
		return true;
	}
	return false;
}

Item* Inventory::getItem(int place, bool isInHB){
	if (this->hasItem(place, isInHB)) {
		if (isInHB)return this->hotbar[place];
		return this->inventory[place];
	}
	return nullptr;
}

const bool Inventory::saveToFile(const std::string fileName){
	return false;
}

const bool Inventory::loadFromFile(const std::string fileName){
	return false;
}
