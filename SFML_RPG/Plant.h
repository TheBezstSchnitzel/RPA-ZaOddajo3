#pragma once

#include "Building.h"

enum GrowStage { Seed = 0, LowMid, Mid, HighMid, Grown };

class Plant : public Building{
private:
	sf::Clock growClock;
	int randomGrowTimeMax; //v minutah

	GrowStage growStage;

	sf::RectangleShape interactZone;

	void initClock();
	void initGrowStage();
	void initInteractZone();

	void updateTextureRect();

protected:
	sf::IntRect textureRect; //da zbere ta prau texture

public:
	static sf::Texture* textureSheet;

	Plant(sf::Vector2f pos, sf::Vector2f size, std::string type, sf::RectangleShape hitbox = sf::RectangleShape(), bool hasHitBox = false);
	~Plant();

	//dostop
	bool isPickable(Player* player);

	void updateClock();

	virtual void update();
	virtual void render(sf::RenderTarget* target) = 0;
	
	virtual void saveToFile(std::string file);
	virtual void loadFromFile(std::string file);

};
