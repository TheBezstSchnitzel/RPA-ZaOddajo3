#pragma once

#include "Player.h"

class Structure{
private:
	std::string type;

	bool hasHitBox;
	sf::RectangleShape hitbox;

	void initRect(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size);

protected:
	sf::RectangleShape renderRect;
public:

	Structure(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size, std::string type, sf::RectangleShape hitbox = sf::RectangleShape(), bool hasHitBox = false);
	~Structure();

	sf::Vector2f getPos();
	std::string getType();

	sf::RectangleShape* getHitbox();

	void setPos(sf::Vector2f pos);

	void checkCollisionPlayer(Entity* player, const float& dt);

	virtual void update();
	virtual void render(sf::RenderTarget* target);

	virtual void saveToFile(std::string file) = 0;
	virtual void loadFromFile(std::string file) = 0;
};