#include "stdafx.h"
#include "HitboxComponent.h"

HitboxComponent::HitboxComponent(sf::Sprite& sprite,
	float offset_x, float offset_y, 
	float width, float height, bool hasBetterHitbox) : sprite(sprite), offsetX(offset_x), offsetY(offset_y), hasBetterHitbox(hasBetterHitbox){
	this->nextPosition.left = 0.f;
	this->nextPosition.top = 0.f;
	this->nextPosition.width = width;
	this->nextPosition.height = height;
	
	this->hitbox.setPosition(this->sprite.getPosition().x + offset_x, this->sprite.getPosition().y + offset_y);
	this->hitbox.setSize(sf::Vector2f(width, height));
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(1.f);
	this->hitbox.setOutlineColor(sf::Color::Green);
	/*
	this->hitbox.setPosition(this->sprite.getPosition().x + offset_x, this->sprite.getPosition().y + offset_y);
	this->hitbox.setRadius(sf::Vector2f(width, height));
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(1.f);
	this->hitbox.setOutlineColor(sf::Color::Green); */
}

HitboxComponent::~HitboxComponent(){

}

//Dostop
const sf::Vector2f & HitboxComponent::getPosition() const{
	return this->hitbox.getPosition();
}

const sf::FloatRect HitboxComponent::getGlobalBounds() const{
	//std::cout << this->hitbox.getGlobalBounds().left << "    " << this->hitbox.getGlobalBounds().left << std::endl;
	return this->hitbox.getGlobalBounds();
}

const sf::FloatRect & HitboxComponent::getNextPosition(const sf::Vector2f & velocity){
	this->nextPosition.left = this->hitbox.getPosition().x + velocity.x;
	this->nextPosition.top = this->hitbox.getPosition().y + velocity.y;

	return this->nextPosition;
}

void HitboxComponent::setPosition(const sf::Vector2f& position){
	this->hitbox.setPosition(position);
	this->sprite.setPosition(position.x - this->offsetX, position.y - this->offsetY);
}

void HitboxComponent::setPosition(const float x, const float y){
	this->hitbox.setPosition(x, y);
	this->sprite.setPosition(x - this->offsetX, y - this->offsetY);
}

//Funkcije
bool HitboxComponent::intersects(const sf::FloatRect& frect){
	return this->hitbox.getGlobalBounds().intersects(frect);
}

void HitboxComponent::update(){
	this->hitbox.setPosition(this->sprite.getPosition().x + this->offsetX, this->sprite.getPosition().y + this->offsetY);
}

void HitboxComponent::render(sf::RenderTarget & target){
	//DEBUG!!//
	target.draw(this->hitbox);
}
