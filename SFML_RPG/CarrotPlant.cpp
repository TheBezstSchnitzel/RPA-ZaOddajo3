#include "stdafx.h"
#include "CarrotPlant.h"

void CarrotPlant::initTextureRect() {
	this->textureRect = sf::IntRect(sf::Vector2i(32, 0), sf::Vector2i(16, 16));
}

CarrotPlant::CarrotPlant(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size) :
Plant(pos,size,"carrotPlant"){
	this->initTextureRect();
}

CarrotPlant::~CarrotPlant(){
}

void CarrotPlant::update(){
	Plant::update();
}

void CarrotPlant::render(sf::RenderTarget* target){
	this->renderRect.setTextureRect(this->textureRect);
	Building::render(target);
}
