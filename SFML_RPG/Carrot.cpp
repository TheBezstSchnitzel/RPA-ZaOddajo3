#include "stdafx.h"
#include "Carrot.h"

void Carrot::initValue(){
	this->value = this->amount * 2;
}

Carrot::Carrot(sf::Texture* texture, int amount) : Item(0,"ITEM_VEGISE_CARROT") {
	this->invIcon = texture;
	this->amount = amount;
	this->maxAmount = 60;
	this->initValue();
}

Carrot::~Carrot(){
}

sf::Texture* Carrot::getTexture() {
	return this->invIcon;
}

int Carrot::addAmount(int amount){
	if (this->amount == this->maxAmount) {
		return amount;
	}
	else {
		if (this->amount + amount > this->maxAmount) {
			int off = this->amount + amount - this->maxAmount;
			this->amount = this->maxAmount;
			this->initValue();
			return off;
		}
		else {
			this->amount += amount;
			this->initValue();
			return 0;
		}
	}
}

int Carrot::removeAmount(int amount){
	if (this->amount > amount) {
		this->amount -= amount;
		this->initValue();
		return 0;
	}
	else {
		int off = amount - this->amount;
		this->amount = 0;
		this->value = 0;
		std::cout << off << std::endl;
		return off;
	}
}

int Carrot::getAmount(){
	return this->amount;
}

void Carrot::saveToFile(std::string savePath){
	//std::cout << "Shrani korencke" << std::endl;
	std::ofstream saveOFile(savePath);
	saveOFile << this->amount << std::endl;
	saveOFile.close();
}

void Carrot::loadFromSave(std::string savePath){
	//std::cout << "Nalozi korencke" << std::endl;
	std::ifstream saveIFile(savePath);
	saveIFile >> this->amount;
	saveIFile.close();

	this->initValue();
}
