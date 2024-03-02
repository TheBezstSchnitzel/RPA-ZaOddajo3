#include "stdafx.h"
#include "CarrotPlant.h"

CarrotPlant::CarrotPlant(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size) :
Building(texture,pos,size,"carrotPlant", sf::RectangleShape(),false){
	
}

CarrotPlant::~CarrotPlant(){
}

void CarrotPlant::update(){

}

void CarrotPlant::render(sf::RenderTarget* target){
	Building::render(target);
}

void CarrotPlant::saveToFile(std::string file){
	std::ofstream saveOFile(file);
	sf::Vector2f tempPos = this->getPos();
	saveOFile << tempPos.x << "  " << tempPos.y << std::endl;
}

void CarrotPlant::loadFromFile(std::string file){
	std::ifstream saveIFile(file);
	float x;
	float y;
	saveIFile >> x >> y;
	this->setPos(sf::Vector2f(x, y));
}
