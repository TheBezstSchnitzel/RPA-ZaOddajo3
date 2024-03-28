#pragma once
#include "Building.h"

//class Building;

class Market : public Building {
private:

	void initHitbox();
	void initTextureRect();
	void initInteractZone();

public:

	Market(sf::Vector2f pos);
	~Market();

	void update(int season, bool day, Player* player);
	void render(sf::RenderTarget* target);

	void saveToFile(std::string file);
	void loadFromFile(std::string file);
};

