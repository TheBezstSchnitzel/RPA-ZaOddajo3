#pragma once

class GraphicsSettings{
public:
	GraphicsSettings();
	//Lastnosti
	std::string title;
	sf::VideoMode resolution;
	bool fullscreen;
	unsigned frameRateLimit;
	sf::ContextSettings contextSettings;
	std::vector<sf::VideoMode> videoModes;

	//Funkcije
	void saveToFile(const std::string path);
	void loadFromFile(const std::string path);
};