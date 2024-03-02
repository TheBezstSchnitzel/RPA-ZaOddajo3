#pragma once
#include "Building.h"
class CarrotPlant : public Building{
private:

public:
	CarrotPlant(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size);
	~CarrotPlant();

	void update();
	void render(sf::RenderTarget* target);

	void saveToFile(std::string file);
	void loadFromFile(std::string file);
};

