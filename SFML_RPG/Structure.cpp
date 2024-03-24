#include "stdafx.h"
#include "Structure.h"


void Structure::initRect(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size){
	this->renderRect.setTexture(texture);
	this->renderRect.setPosition(pos);
	this->renderRect.setSize(size);
}


Structure::Structure(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size, std::string type, sf::RectangleShape hitbox ,bool hasHitBox){
	this->initRect(texture, pos, size);
	this->type = type;
	this->hasHitBox = hasHitBox;
	this->hitbox = hitbox;
}

Structure::~Structure(){

}

sf::Vector2f Structure::getPos(){
	return this->renderRect.getPosition();
}

std::string Structure::getType(){
	return this->type;
}

sf::RectangleShape* Structure::getHitbox(){
	return this->hasHitBox ? &this->hitbox : nullptr;
}

void Structure::setPos(sf::Vector2f pos){
	this->renderRect.setPosition(pos);
}

void Structure::checkCollisionPlayer(Entity* player, const float& dt){
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

void Structure::update(){
}

void Structure::render(sf::RenderTarget* target){
	target->draw(this->renderRect);
}
