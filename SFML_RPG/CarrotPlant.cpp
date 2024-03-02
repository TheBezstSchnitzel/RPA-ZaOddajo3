#include "stdafx.h"
#include "CarrotPlant.h"

void CarrotPlant::initClock(){
	this->growClock.restart();
	this->randomGrowTimeMax = std::rand() % 5 + 1;
}

void CarrotPlant::initGrowStage(){
	this->growStage = static_cast<GrowStage>(0);
}

void CarrotPlant::initTextureRect(){
	int tempX = 16 * static_cast<int>(this->growStage);
	this->textureRect = sf::IntRect(sf::Vector2i(tempX,0), sf::Vector2i(16,16));
}

CarrotPlant::CarrotPlant(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size) :
Building(texture,pos,size,"carrotPlant", sf::RectangleShape(),false){
	this->initClock();
	this->initGrowStage();
	this->initTextureRect();
}

CarrotPlant::~CarrotPlant(){
}

void CarrotPlant::updateClock(){
	if (this->growClock.getElapsedTime().asSeconds() / 60 >= randomGrowTimeMax) {
		if (this->growStage != static_cast<GrowStage>(4)) {
			this->growStage = static_cast<GrowStage>(static_cast<int>(this->growStage) + 1); //growa plant
			this->initClock(); //resetira clock
			this->updateTextureRect();
		}
	}
}

void CarrotPlant::updateTextureRect(){
	int tempX = 16 * static_cast<int>(this->growStage);
	this->textureRect.left = tempX;
}


void CarrotPlant::update(){
	this->updateClock();
}

void CarrotPlant::render(sf::RenderTarget* target){
	this->renderRect.setTextureRect(this->textureRect);
	Building::render(target);
}

void CarrotPlant::saveToFile(std::string file){
	std::ofstream saveOFile(file);
	sf::Vector2f tempPos = this->getPos();
	saveOFile << tempPos.x << "  " << tempPos.y << std::endl;
	saveOFile << static_cast<int>(this->growStage) << std::endl;
	saveOFile << this->randomGrowTimeMax << std::endl;
	saveOFile.close();
}

void CarrotPlant::loadFromFile(std::string file){
	std::ifstream saveIFile(file);
	float x;
	float y;
	int tempGrowStage = 0;
	saveIFile >> x >> y >> tempGrowStage >> this->randomGrowTimeMax;
	this->setPos(sf::Vector2f(x, y));
	this->growStage = static_cast<GrowStage>(tempGrowStage);
	this->updateTextureRect();
	saveIFile.close();
}
