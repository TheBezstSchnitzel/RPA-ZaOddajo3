#include "stdafx.h"
#include "Farmland.h"

Farmland::Farmland(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size) :
Building(texture,pos,size,"farmland") {

}

Farmland::~Farmland(){
}

void Farmland::update(){
}

void Farmland::render(sf::RenderTarget* target){
	Building::render(target);
}

void Farmland::saveToFile(std::string file){
	//std::cout << file << std::endl;
	std::ofstream saveOFile(file);
	sf::Vector2f tempPos = this->getPos();
	saveOFile << tempPos.x << "  " << tempPos.y << std::endl;
}

void Farmland::loadFromFile(std::string file){
	//std::cout << file << std::endl;
	std::ifstream saveIFile(file);
	float x;
	float y;
	saveIFile >> x >> y;
	this->setPos(sf::Vector2f(x,y));
}
