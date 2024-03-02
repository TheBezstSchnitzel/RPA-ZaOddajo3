#pragma once
#include "Building.h"
class Farmland : public Building{
private:
	

public:
	Farmland(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size);
	~Farmland();

	void update();
	void render(sf::RenderTarget* target);

	void saveToFile(std::string file);
	void loadFromFile(std::string file);
};

