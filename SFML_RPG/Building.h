#pragma once

#include "Player.h"

class Building{
private:
	std::string type;

	bool hasHitBox;
	sf::RectangleShape hitbox;

	void initRect(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size);

protected:
	sf::RectangleShape renderRect;
public:

	Building(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size, std::string type, sf::RectangleShape hitbox , bool hasHitBox = false);
	~Building();

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