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
	this->textureRect = sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(16,16));
}

void CarrotPlant::initInteractZone(){
	this->interactZone.setPosition(sf::Vector2f(this->getPos().x - 2.f, this->getPos().y - 2.f));
	this->interactZone.setSize(sf::Vector2f(20.f, 20.f));
	this->interactZone.setFillColor(sf::Color::Transparent);
	this->interactZone.setOutlineThickness(1.f); //DEBUG
	this->interactZone.setOutlineColor(sf::Color::Cyan); //DEBUG
}

CarrotPlant::CarrotPlant(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size) :
Building(texture,pos,size,"carrotPlant", sf::RectangleShape(),false){
	this->initClock();
	this->initGrowStage();
	this->initTextureRect();
	this->initInteractZone();
}

CarrotPlant::~CarrotPlant(){
}

bool CarrotPlant::isPickable(Player* player){
	if (static_cast<int>(this->growStage) == 4) {
		sf::FloatRect playerPos = player->getGlobalBounds();
		sf::FloatRect carrotPos = this->interactZone.getGlobalBounds();
		if (carrotPos.intersects(playerPos)) {
			return true;
		}
	}
	return false;
}

void CarrotPlant::updateClock(){
	if (this->growClock.getElapsedTime().asSeconds() >= randomGrowTimeMax) { //DEBUG ZA TIME
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
	if(static_cast<int>(this->growStage) == 4)target->draw(this->interactZone); //DEBUG
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
	this->initInteractZone();
	saveIFile.close();
}
