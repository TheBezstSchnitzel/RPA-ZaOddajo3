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
}

void CarrotPlant::loadFromFile(std::string file){

}
