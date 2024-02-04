#include "stdafx.h"
#include "Player.h"

//Inicializacija
void Player::initVariables(){
	this->initAttack = false;
	this->attacking = false;
	//this->weapon = new Sword(1, 2, 5, 100, 20, "Resources/Images/Sprites/Player/sword.png");
	//this->weapon->generate(1, 3);
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->damageTimerMax = 500;
}

void Player::initComponents(sf::Texture& texture_sheet){
	//this->createHitboxComponent(this->sprite, 16.f, 26.f, 32.f, 38.f, true, 9.f, 47.f, 23.f, 10.f);
	//this->createHitboxComponent(this->sprite, 9.f, 47.f, 23.f, 10.f, false);
	this->createHitboxComponent(this->sprite, 8.5f, 24.5f, 15.f, 7.5f);
	this->createMovementComponent(140.f, 1400.f, 1000.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(1,15,20);
	//this->createSkillComponent();
}

void Player::initAnimations(){
	this->animationComponent->addAnimation("IDLE", 15.f, 0, 0, 8, 0, 64, 64);
	this->animationComponent->addAnimation("WALK_DOWN", 11.f, 0, 1, 3, 1, 64, 64);
	this->animationComponent->addAnimation("WALK_LEFT", 11.f, 4, 1, 7, 1, 64, 64);
	this->animationComponent->addAnimation("WALK_RIGHT", 11.f, 8, 1, 11, 1, 64, 64);
	this->animationComponent->addAnimation("WALK_UP", 11.f, 12, 1, 15, 1, 64, 64);
	this->animationComponent->addAnimation("ATTACK", 5.f, 0, 2, 1, 2, 64, 64);
}

void Player::initInventory(){
	this->inventory = new Inventory(100);
}

//Konstruktor / Destruktor
Player::Player(float x, float y, sf::Texture& texture_sheet,bool fromSave){
	this->initVariables();

	this->initComponents(texture_sheet);

	this->setPosition(x, y);
	this->initAnimations();

	this->initInventory();
}

Player::~Player(){
	delete this->inventory;
	//delete this->weapon;
}

void Player::save(std::string savePath){
	//shranjuje podatke o playerju
	//not zapisuj brez da brises kar je ze v datoteki ce dajes v player.txt
	//std::cout << "save od playerja dela" << std::endl; //debug
}

//Dostop
AttributeComponent * Player::getAttributeComponent(){
	return this->attributeComponent;
}

Weapon * Player::getWeapon() const{
	return this->weapon;
}

const std::string Player::toStringCharacterTab() const{
	std::stringstream ss;
	const AttributeComponent* ac = this->attributeComponent;
	//const Weapon* w = this->weapon;

	ss << "Level: " << ac->level << "\n"
		<< "Exp: " << ac->exp << "\n"
		<< "Exp next: " << ac->expNext << "\n";
		/*
		<< "Weapon Level: " << w->getLevel() << "\n"
		<< "Weapon Type: " << w->getType() << "\n"
		<< "Weapon Value: " << w->getValue() << "\n"
		<< "Weapon Range: " << w->getRange() << "\n"
		<< "Weapon Damage Min: " << w->getDamageMin() + this->attributeComponent->damageMin << " (" << this->attributeComponent->damageMin << ")" << "\n"
		<< "Weapon Damage Max: " << w->getDamageMax() + this->attributeComponent->damageMax << " (" << this->attributeComponent->damageMax << ")" << "\n";*/

	return ss.str();
}

const bool& Player::getInitAttack() const{
	return this->initAttack;
}

const bool Player::getDamageTimer(){
	if(this->damageTimer.getElapsedTime().asMilliseconds() >= this->damageTimerMax){ 
		this->damageTimer.restart();
		return true;
	}

	return false;
}

const unsigned Player::getDamage() const{
	return rand() % (
	(this->attributeComponent->damageMax + this->weapon->getDamageMax()) 
	- (this->attributeComponent->damageMin + this->weapon->getDamageMin()) + 1)
	+ (this->attributeComponent->damageMin + this->weapon->getDamageMin());
}

void Player::setInitAttack(const bool initAttack){
	this->initAttack = initAttack;
}

//Funkcije
void Player::loseHP(const int hp){
	this->attributeComponent->loseHP(hp);
}

void Player::gainHP(const int hp){
	this->attributeComponent->gainHP(hp);
}

void Player::loseEXP(const int exp){
	this->attributeComponent->loseEXP(exp);
}

void Player::gainEXP(const int exp){
	this->attributeComponent->gainExp(exp);
}

void Player::updateAnimation(const float & dt){
	if (this->attacking){
		
	}
	if (this->movementComponent->getState(IDLE)){
		this->animationComponent->play("IDLE", dt);
	}
	else if (this->movementComponent->getState(MOVING_LEFT)){
		this->animationComponent->play("WALK_LEFT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_RIGHT)){
		this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_UP)){
		this->animationComponent->play("WALK_UP", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_DOWN)){
		this->animationComponent->play("WALK_DOWN", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
}

void Player::update(const float & dt, sf::Vector2f& mouse_pos_view, const sf::View& view){
	this->movementComponent->update(dt);

	this->updateAnimation(dt);
	
	this->hitboxComponent->update();

	//this->weapon->update(mouse_pos_view, sf::Vector2f(this->getSpriteCenter().x, this->getSpriteCenter().y + 5.f));
}

void Player::render(sf::RenderTarget & target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox){
	if (shader){
		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", light_position);
		target.draw(this->sprite, shader);
		/*
		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", light_position);
		this->weapon->render(target, shader);*/
	}
	else {
		target.draw(this->sprite);
		//this->weapon->render(target);
	}
	
	if(show_hitbox)
		this->hitboxComponent->render(target);
}
