#pragma once

#include "HitboxComponent.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"
#include "AttributeComponent.h"
#include "SkillComponent.h"
#include "EllipseShape.h"

class HitboxComponent;
class MovementComponent;
class AnimationComponent;
class AttributeComponent;
class SkillComponent;

class Entity{
private:
	void initVariables();

protected:

	sf::Sprite sprite;

	HitboxComponent* hitboxComponent;
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	AttributeComponent* attributeComponent;
	SkillComponent* skillComponent;

public:
	Entity();
	virtual ~Entity();

	//Komponente
	void setTexture(sf::Texture& texture);
	void createHitboxComponent(sf::Sprite& sprite,
		float offset_x, float offset_y,
		float width, float height);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);
	void createAttributeComponent(const unsigned level, int startHP, int maxHP);
	void createSkillComponent();
	void createAIComponent();

	//Dostop
	virtual MovementComponent* getMovementComponent();
	virtual AnimationComponent* getAnimationComponent();
	virtual AttributeComponent* getAttributeComponent();
	virtual SkillComponent* getSkillComponent();

	virtual const sf::Vector2f& getPosition() const;
	virtual const sf::Vector2f& getSpritePosition() const;
	virtual const sf::Vector2f getCenter() const;
	virtual const sf::Vector2f getSpriteCenter() const;
	virtual const sf::Vector2i getGridPosition(const int gridSizeI) const;
	virtual const sf::FloatRect getGlobalBounds() const;
	virtual const sf::FloatRect getNextPositionBounds(const float& dt) const;

	//Interface
	virtual void setPosition(const float x, const float y);

	//Funkcije
	virtual void move(const float x, const float y, const float& dt);
	virtual void stopVelocity();
	virtual void stopVelocityX();
	virtual void stopVelocityY();

	//Izracuni
	virtual const float getDistance(const Entity& entity) const;
	virtual const float getSpriteDistance(const Entity& entity) const;

	virtual void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view) = 0;
	virtual void render(sf::RenderTarget& target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox) = 0;
};