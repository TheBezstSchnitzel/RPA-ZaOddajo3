#pragma once
#include "Tool.h"
class Hoe : public Tool{
private:
	sf::Texture* invIcon;

public:
	Hoe(sf::Texture* icon, int durability, bool isBroken = false);
	~Hoe();
	
	//Item* clone();

	//dostop

	//bool use();

	void update();
	sf::Texture* getTexture();

	void saveToFile(std::string savePath);
	void loadFromSave(std::string savePath);
};