#pragma once
#include "Buildings.h"


class Market : public Building{
private:

	sf::RectangleShape interactZone;
	sf::IntRect textureRect;

	void initHitbox();
	void initTextureRect();
	void initInteractZone();
public:
	Market(sf::Texture* texture, sf::Vector2f pos);
	~Market();

	bool checkIfPlayerBehind(Player* player);
	bool isInteractable(Player* player, bool day);

	void updateTextureRect(int season, bool day,Player* player);

	void update(int season, bool day, Player* player);
	void render(sf::RenderTarget* target);

	void saveToFile(std::string file);
	void loadFromFile(std::string file);
};

