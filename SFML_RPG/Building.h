#pragma once
class Building{
private:
	sf::RectangleShape renderRect;
	std::string type;


	void initRect(sf::Texture* texture, sf::Vector2f pos, sf::Vector2f size);

public:

	Building(sf::Texture* texture,sf::Vector2f pos, sf::Vector2f size, std::string type);
	~Building();

	sf::Vector2f getPos();
	std::string getType();

	virtual void update();
	virtual void render(sf::RenderTarget* target);

	virtual void saveToFile(std::string file) = 0;
	virtual void loadFromFile(std::string file) = 0;
};