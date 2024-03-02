#include "stdafx.h"
#include "Building.h"


void Building::initRect(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size){
	this->renderRect.setTexture(texture);
	this->renderRect.setPosition(pos);
	this->renderRect.setSize(size);
}


Building::Building(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size, std::string type, sf::RectangleShape hitbox ,bool hasHitBox){
	this->initRect(texture, pos, size);
	this->type = type;
	this->hasHitBox = hasHitBox;
	this->hitbox = hitbox;
}

Building::~Building(){

}

sf::Vector2f Building::getPos(){
	return this->renderRect.getPosition();
}

std::string Building::getType(){
	return this->type;
}

void Building::setPos(sf::Vector2f pos){
	this->renderRect.setPosition(pos);
}

void Building::checkCollisionPlayer(Entity* player, const float& dt){
	if (hasHitBox) {
		sf::FloatRect buildingBounds = sf::FloatRect(this->hitbox.getPosition(), this->hitbox.getSize());
		sf::FloatRect nextPositionBounds = player->getNextPositionBounds(dt);
		if (buildingBounds.intersects(nextPositionBounds)) {
			//player dol collision ,,,,, zgorna stran tila
			if (nextPositionBounds.top < buildingBounds.top
				&& nextPositionBounds.top + nextPositionBounds.height < buildingBounds.top + buildingBounds.height
				&& nextPositionBounds.left < buildingBounds.left + buildingBounds.width
				&& nextPositionBounds.left + nextPositionBounds.width > buildingBounds.left
				) {
				player->stopVelocityY();
			}
			else if (nextPositionBounds.top > buildingBounds.top
				&& nextPositionBounds.top + nextPositionBounds.height > buildingBounds.top + buildingBounds.height
				&& nextPositionBounds.left < buildingBounds.left + buildingBounds.width
				&& nextPositionBounds.left + nextPositionBounds.width > buildingBounds.left
				) { //player gor collision ,,, spodna stran tila
				player->stopVelocityY();
			}
			//Player desnu collison ,,, leva stran tila
			if (nextPositionBounds.left < buildingBounds.left
				&& nextPositionBounds.left + nextPositionBounds.width < buildingBounds.left + buildingBounds.width
				&& nextPositionBounds.top < buildingBounds.top + buildingBounds.height
				&& nextPositionBounds.top + nextPositionBounds.height > buildingBounds.top
				) {
				player->stopVelocityX();
			}

			//Player Levu collision  ,,, desna stran tila
			else if (nextPositionBounds.left > buildingBounds.left
				&& nextPositionBounds.left + nextPositionBounds.width > buildingBounds.left + buildingBounds.width
				&& nextPositionBounds.top < buildingBounds.top + buildingBounds.height
				&& nextPositionBounds.top + nextPositionBounds.height > buildingBounds.top
				) {
				player->stopVelocityX();
			}
		}
	}
}

void Building::update(){
}

void Building::render(sf::RenderTarget* target){
	target->draw(this->renderRect);
}
