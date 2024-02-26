#pragma once
#include "Tool.h"
class Hoe : public Tool{
private:
	sf::Texture* invIcon;

	void initTextures();

public:
	Hoe(sf::Texture* icon, int durability, bool isEquipped, bool isBroken = false);
	~Hoe();
	
	Item* clone();

	//dostop

	bool use();

	void update();
	sf::Texture* getTexture();
};