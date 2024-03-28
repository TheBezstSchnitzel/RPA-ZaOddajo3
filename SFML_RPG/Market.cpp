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

/*
bool Market::checkIfPlayerBehind(Player* player){
	sf::Vector2f playerPos = player->getPosition();
	sf::Vector2f posHb = this->getHitbox()->getPosition();
	sf::Vector2f sizeHb = this->getHitbox()->getSize();
	sf::Vector2f pos = this->getPos();
	if (playerPos.y < posHb.y) {
		//ce je player nad tm hitboxom
		if (playerPos.y + 5.f >= pos.y) {
			//prever da je tam ker bi ga tekstura motla od spodi
			if (playerPos.x < posHb.x + sizeHb.x) {
				//prever da je desna stran notr
				if (playerPos.x + 15.f > posHb.x) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Market::isInteractable(Player* player, bool day){
	if (day) {
		sf::FloatRect playerPos = player->getGlobalBounds();
		sf::FloatRect pos = this->interactZone.getGlobalBounds();
		if (pos.intersects(playerPos)) {
			return true;
		}
	}
	return false;
}*/

Market::Market(sf::Texture* texture, sf::Vector2f pos) :
	Building(texture,pos,sf::Vector2f(94.f,76.f),"Market",sf::RectangleShape(),true) {
	this->initHitbox();
	this->initTextureRect();
	this->initInteractZone();
}

Market::~Market(){

}

/*
void Market::updateTextureRect(int season, bool day, Player* player){
	sf::RectangleShape* hitbox = this->getHitbox();
	sf::Vector2f size = hitbox->getSize();
	if (day) {
		this->textureRect.top = 0;
	}
	else {
		this->textureRect.top = this->textureRect.height;
	}
	switch (season) {
	case 1:
		this->textureRect.left = 0;
		size.x = 91.f;
		break;
	case 2:
		this->textureRect.left = this->textureRect.width;
		size.x = 91.f;
		break;
	case 3:
		this->textureRect.left = this->textureRect.width * 2;
		size.x = 91.f;
		break;
	case 4:
		this->textureRect.left = this->textureRect.width * 3;
		size.x = 94.f;
		break;
	default:
		break;
	}
	hitbox->setSize(size);
	if (this->checkIfPlayerBehind(player)) {
		this->renderRect.setFillColor(sf::Color(255, 255, 255, 150));
	}
	else {
		this->renderRect.setFillColor(sf::Color(255, 255, 255, 255));
	}
}
*/

void Market::update(int season, bool day, Player* player){
	if (day)this->isAvailable = true; //tu se razlikuje pr usakmu buildingu
	else this->isAvailable = false; 
	//this->updateTextureRect(season, day,player);
	//this->renderRect.setTextureRect(this->textureRect);
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
