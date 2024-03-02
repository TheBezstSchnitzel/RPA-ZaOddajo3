#include "stdafx.h"
#include "Hoe.h"


Hoe::Hoe(sf::Texture* icon, int durability, bool isBroken) : Tool(1,120,durability,isBroken){
	this->invIcon = icon;
} 

Hoe::~Hoe(){
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

