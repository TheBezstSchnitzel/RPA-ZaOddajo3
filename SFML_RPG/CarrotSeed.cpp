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

}

void CarrotSeed::loadFromSave(std::string savePath){

}
