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
}

void Farmland::loadFromFile(std::string file){
}
