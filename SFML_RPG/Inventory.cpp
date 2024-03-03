#include "stdafx.h"
#include "Inventory.h"

//Private functions
void Inventory::initialize(){
	this->nrOfItems = 0;
	for (int i = 0; i < this->capacity; i++) {
		this->inventory[i] = nullptr;
	}
}

void Inventory::freeMemory(){
	for (size_t i = 0; i < this->capacity; i++){
		delete this->inventory[i];
	}
}

//Konstruktor / Destruktor
Inventory::Inventory(){
	this->capacity = 36;
	this->money = 100000; //DEBUG
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

sf::Texture* Inventory::getItemIcon(int itemPlace){ //item plac od 0
	//preveri itemplace
	if (itemPlace < 0 || itemPlace >= this->capacity)return nullptr; //preveri veljavnost vnosa 
	if (this->inventory[itemPlace] == nullptr)return nullptr; //ce je prazen
	else return this->inventory[itemPlace]->getTexture(); //ce je poun
}

bool Inventory::hasItem(int itemPlace){
	if (itemPlace < 0 || itemPlace >= this->capacity)return false;
	return (this->inventory[itemPlace] != nullptr);
}

unsigned int Inventory::getMoney(){
	return this->money;
}

void Inventory::addMoney(unsigned int amount){
	this->money += amount;
}

void Inventory::takeMoney(unsigned int amount){
	this->money -= amount;
}

bool Inventory::hasEnoughMoney(unsigned int amount){
	return (this->money >= amount);
}

//Funkcije

void Inventory::clear(){
	this->initialize();
}

const bool Inventory::isEmpty() const{
	return this->nrOfItems == 0;
}

bool Inventory::isFull(){
	return (this->nrOfItems == this->capacity);
}

const bool Inventory::add(Item * item, int place){ //item plac od 0 (ce je negativn najde prvo frej mesto)
	if (this->nrOfItems == this->capacity)return false;//ce je poun inventory
	if (place < 0) {
		//najde prvi frej plac
		for (int i = 0; i < this->capacity; i++) {
			if (this->inventory[i] == nullptr) {
				this->inventory[i] = item;
				this->nrOfItems++;
				return true;
			}
		}
	}
	if (place >= 0 && place < this->capacity) {
		if (this->inventory[place] == nullptr) {
			this->inventory[place] = item;
			this->nrOfItems++;
			return true;
		}
		else return false;
	}
	return false;
}

const bool Inventory::remove(int place){
	if (place < 0 || place >= this->capacity)return false; //preveri veljavnost vnosa 
	if (this->nrOfItems > 0 && this->hasItem(place)) {
		this->inventory[place] = nullptr;
		this->nrOfItems--;
		return true;
	}
	return false;
}

Item* Inventory::getItem(int place){
	if (place < 0 || place >= this->capacity)return nullptr; //preveri veljavnost vnosa 
	if (this->hasItem(place)) {
		return this->inventory[place];
	}
	return nullptr;
}

Item* Inventory::getHBSelectedItem(){
	//27 28 29 30 31 32 33 34 35
	//0  1  2  3  4  5  6  7  8
	int temp = 27 + this->getIDSelectedHB();
	if (this->hasItem(temp))return this->inventory[temp];
	else return nullptr;
}

void Inventory::saveToFile(const std::string fileName){
	//std::cout << "Dela" << std::endl;
	std::ofstream saveOFile(fileName, std::ios::out);
	if (saveOFile.is_open()) {
		//shranjevanje
		//saveOFile << this->nrOfItems << std::endl;
		//saveOFile << this->capacity << std::endl;
		saveOFile << this->money << std::endl;
		saveOFile << this->idSelectedHotbar << std::endl;

		saveOFile.close();
	}
	else {
		throw("ERROR::Inventory::saveToFile::FILE_NOT_OPEN");
	}
}

void Inventory::loadFromFile(const std::string fileName){
	std::ifstream saveIFile(fileName);
	//prebere podatke
	if (saveIFile.is_open()) {
		//Branje in zapisovanje podatkov
		saveIFile >> this->money;
		saveIFile >> this->idSelectedHotbar;
	
		saveIFile.close(); //zapre datoteko 
	}
	else {
		throw("ERROR::Inventory::loadFromSave::FILE_NOT_OPEN");
	}
}
