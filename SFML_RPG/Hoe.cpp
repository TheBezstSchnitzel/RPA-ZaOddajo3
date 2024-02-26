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

