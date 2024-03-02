#include "stdafx.h"
#include "CarrotSeed.h"

CarrotSeed::CarrotSeed(sf::Texture* icon, int durability, bool isBroken) :
Tool(1,100,durability,isBroken){
	this->invIcon = icon;
}

CarrotSeed::~CarrotSeed(){

}

void CarrotSeed::update()
{
}

sf::Texture* CarrotSeed::getTexture(){
	return this->invIcon;
}

void CarrotSeed::saveToFile(std::string savePath){
	std::ofstream saveOFile(savePath);
	if (saveOFile.is_open()) {
		//shranjevanje
		saveOFile << this->getDurability() << std::endl;
		saveOFile << this->getIsBrooken() << std::endl;

		saveOFile.close();
	}
	else {
		throw("ERROR::CarrotSeed::saveToFile::FILE_NOT_OPEN");
	}
}

void CarrotSeed::loadFromSave(std::string savePath){
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
