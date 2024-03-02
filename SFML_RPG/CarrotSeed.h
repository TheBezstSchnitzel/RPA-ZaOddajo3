#pragma once
#include "Items.h"


class CarrotSeed : public Tool{
private:
	sf::Texture* invIcon;


public:
	CarrotSeed(sf::Texture* icon, int durability, bool isBroken);
	~CarrotSeed();

	void update();
	sf::Texture* getTexture();

	void saveToFile(std::string savePath);
	void loadFromSave(std::string savePath);
};

