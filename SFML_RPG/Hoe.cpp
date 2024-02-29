#include "stdafx.h"
#include "Hoe.h"

void Hoe::initTextures(){
	/*sf::IntRect textRect;
	textRect.left = 0;
	textRect.top = 0;
	textRect.height = 16;
	textRect.width = 16;
	this->invIcon.loadFromFile("Resources/Images/Sprites/items.png", textRect);*/
}

Hoe::Hoe(sf::Texture* icon, int durability, bool isEquipped, bool isBroken) : Tool(1,120,durability,isEquipped,isBroken){
	//this->initTextures();
	this->invIcon = icon;
} 

Hoe::~Hoe(){
}

Item* Hoe::clone(){
	return this;
}

bool Hoe::use(){
	this->damageDurability(2);
	return true;
}

void Hoe::update(){
}

sf::Texture* Hoe::getTexture(){
	return this->invIcon;
}

void Hoe::saveToFile(std::string savePath){ //path = /game/items/itemX..
	std::ofstream saveOFile(savePath);
	if (saveOFile.is_open()) {
		//shranjevanje
		saveOFile << this->getDurability() << std::endl;
		saveOFile << this->getIsBrooken() << std::endl;

		saveOFile.close();
	}
	else {
		throw("ERROR::Hoe::saveToFile::FILE_NOT_OPEN");
	}
}

void Hoe::loadFromSave(std::string savePath){
	std::ifstream saveIFile(savePath);
	if (saveIFile.is_open()) {
		//shranjevanje
		int dur;
		bool bro;
		saveIFile >> dur;
		saveIFile >> bro;
		this->setDurability(dur);
		this->setIsBrooken(bro);

		saveIFile.close();
	}
	else {
		throw("ERROR::Hoe::saveToFile::FILE_NOT_OPEN");
	}
}

