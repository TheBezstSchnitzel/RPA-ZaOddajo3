#include "stdafx.h"
#include "Market.h"

void Market::initHitbox(){
	sf::RectangleShape* hitbox = this->getHitbox();
	sf::Vector2f temp = this->getPos();
	temp.y += 47.f;
	hitbox->setPosition(temp);
	hitbox->setSize(sf::Vector2f(94.f, 29.f));
	hitbox->setFillColor(sf::Color::Transparent);
	//hitbox->setOutlineThickness(1.f); //debug
	//hitbox->setOutlineColor(sf::Color::Red);
}

void Market::initTextureRect(){
	this->textureRect.width = 94;
	this->textureRect.height = 76;
	this->textureRect.left = 0;
	this->textureRect.top = 0;
}

void Market::initInteractZone(){
	//std::cout << "Hello" << std::endl;
	this->interactZone = sf::RectangleShape(*this->getHitbox());
	sf::Vector2f size = this->interactZone.getSize();
	sf::Vector2f pos = this->interactZone.getPosition();
	size.x += 20.f;
	size.y += 20.f;
	pos.x -= 10.f;
	pos.y -= 10.f;
	this->interactZone.setSize(size);
	this->interactZone.setPosition(pos);
	this->interactZone.setOutlineColor(sf::Color::Red); //DEBUG
	this->interactZone.setOutlineThickness(1.f);
}

Market::Market(sf::Vector2f pos) :
	Building(pos,sf::Vector2f(94.f,76.f),"Market",sf::RectangleShape(),true) {
	this->initHitbox();
	this->initTextureRect();
	this->initInteractZone();
}

Market::~Market(){

}

void Market::update(int season, bool day, Player* player){
	if (day)this->isAvailable = true; //tu se razlikuje pr usakmu buildingu
	else this->isAvailable = false; 
	Building::update(season,day,player);
}

void Market::render(sf::RenderTarget* target) {
	Structure::render(target);
}

void Market::saveToFile(std::string file){
	//ne rabm kr je zmer na istmu mestu in se nc ne spreminja more bit pa deklerirana zarad abstraktou
}

void Market::loadFromFile(std::string file){
	//ne rabm kr je zmer na istmu mestu in se nc ne spreminja more bit pa deklerirana zarad abstraktou
}
