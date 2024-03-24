#pragma once
#include "Structures.h"

class CarrotPlant : public Plant{
private:

	void initTextureRect();

public:
	static sf::Texture* possible;

	CarrotPlant(sf::Vector2f pos, sf::Vector2f size);
	~CarrotPlant();

	void update();
	void render(sf::RenderTarget* target);
};

