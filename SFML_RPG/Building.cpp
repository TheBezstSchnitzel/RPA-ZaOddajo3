#include "stdafx.h"
#include "Building.h"

sf::Texture* Building::textureSheet = nullptr;

Building::Building(sf::Vector2f pos, sf::Vector2f size, std::string type, sf::RectangleShape hitbox, bool hasHitBox) :
	Structure(textureSheet, pos, size, type, hitbox, true){
	this->isAvailable = false;
}

Building::~Building(){
}

bool Building::checkIfPlayerBehind(Player* player){
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

bool Building::isInteractable(Player* player, bool day){
	if (day) {
		sf::FloatRect playerPos = player->getGlobalBounds();
		sf::FloatRect pos = this->interactZone.getGlobalBounds();
		if (pos.intersects(playerPos)) {
			return true;
		}
	}
	return false;
}

void Building::updateTextureRect(int season, bool day, Player* player){
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
	this->renderRect.setTextureRect(this->textureRect);
}

void Building::update(int season, bool day, Player* player){
	this->updateTextureRect(season,day,player);
}
