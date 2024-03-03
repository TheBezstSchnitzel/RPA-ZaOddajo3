#pragma once
#include "Buildings.h"

enum GrowStage { Seed = 0, LowMid, Mid, HighMid, Grown };

class CarrotPlant : public Building{
private:
	sf::Clock growClock;
	int randomGrowTimeMax; //v minutah

	GrowStage growStage;

	sf::IntRect textureRect;

	sf::RectangleShape interactZone;

	void initClock();
	void initGrowStage();
	void initTextureRect();
	void initInteractZone();

public:
	CarrotPlant(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size);
	~CarrotPlant();

	//dostop
	bool isPickable(Player* player);

	void updateClock();
	void updateTextureRect();

	void update();
	void render(sf::RenderTarget* target);

	void saveToFile(std::string file);
	void loadFromFile(std::string file);
};

