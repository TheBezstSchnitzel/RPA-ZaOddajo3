#include "stdafx.h"
#include "Building.h"


void Building::initRect(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size){
	this->renderRect.setTexture(texture);
	this->renderRect.setPosition(pos);
	this->renderRect.setSize(size);
}


Building::Building(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size, std::string type){
	this->initRect(texture, pos, size);
	this->type = type;
}

Building::~Building(){

}

sf::Vector2f Building::getPos(){
	return this->renderRect.getPosition();
}

std::string Building::getType(){
	return this->type;
}

void Building::setPos(sf::Vector2f pos){
	this->renderRect.setPosition(pos);
}

void Building::update(){
}

void Building::render(sf::RenderTarget* target){
	target->draw(this->renderRect);
}
