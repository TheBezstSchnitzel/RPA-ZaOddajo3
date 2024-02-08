#include "stdafx.h"
#include "Game.h"

//Inicializacija
void Game::initVariables(){
	this->window = NULL;

	this->dt = 0.f;

	this->gridSize = 16.f;
}

void Game::initGraphicsSettings(){
	this->gfxSettings.loadFromFile("Config/graphics.ini");
}

void Game::initWindow(){
	//Nardi window
	if(this->gfxSettings.fullscreen)
		this->window = new sf::RenderWindow(
			this->gfxSettings.resolution, 
			this->gfxSettings.title, 
			sf::Style::Fullscreen, 
			this->gfxSettings.contextSettings);
	else
		this->window = new sf::RenderWindow(
			this->gfxSettings.resolution,
			this->gfxSettings.title,
			sf::Style::Titlebar | sf::Style::Close, 
			this->gfxSettings.contextSettings);

	this->window->setFramerateLimit(this->gfxSettings.frameRateLimit);
}

void Game::initKeys(){
	std::ifstream ifs("Config/supported_keys.ini");

	if (ifs.is_open()) {
		if (ifs.fail())initKeys(); //rekurzivna funkcija
		std::string key = "";
		int key_value = 0;

		while (ifs >> key >> key_value) {
			this->supportedKeys[key] = key_value;
		}
	}
	ifs.close();
	/*
	* //DEBUG
	for (auto i : this->supportedKeys){
		std::cout << i.first << " " << i.second << "\n";
	} */
}

void Game::initStateData(){
	this->stateData.window = this->window;
	this->stateData.gfxSettings = &this->gfxSettings;
	this->stateData.supportedKeys = &this->supportedKeys;
	this->stateData.states = &this->states;
	this->stateData.gridSize = this->gridSize;
}

void Game::initStates(){
	this->states.push(new MainMenuState(&this->stateData,this));
}

void Game::initAudio(){
	std::string savePath = "Config/audio.ini";
	std::ifstream saveIFile(savePath);
	bool isPlaying = true;
	if (saveIFile.is_open()) {
		//nalaganje podatkov
		saveIFile >> isPlaying;
		saveIFile >> this->volume;

		saveIFile.close();
	}
	else {
		throw("ERROR::GAME::initAudio::FILE_NOT_OPEN");
	}
	theme.openFromFile("Resources/Audio/themeSong.wav");
	theme.setPitch(1.f);
	theme.setVolume(this->volume);
	theme.setLoop(true);
	if(isPlaying)theme.play();
}

//Konstruktor / Destruktor
Game::Game(){
	this->initVariables();
	this->initGraphicsSettings();
	this->initWindow();
	this->initKeys();
	this->initStateData();
	this->initStates();
	this->initAudio();
}

Game::~Game(){
	delete this->window;

	while (!this->states.empty()){
		delete this->states.top();
		this->states.pop();
	}
}

//Funkcije
void Game::endApplication(){
	//std::cout << "Ending Application!" << "\n";
}

void Game::updateDt(){
	//nastav deltaTime na cas k ga rabs za en frame
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents(){
	while (this->window->pollEvent(this->sfEvent)){
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update(){
	this->updateSFMLEvents();
	if (!this->states.empty()){
		if (this->window->hasFocus()){
			this->states.top()->update(this->dt);

			if (this->states.top()->getQuit()){
				this->states.top()->endState();
				delete this->states.top();
				this->states.pop();
			}
		}
	}
	//Konc aplikacije
	else{
		this->endApplication();
		this->window->close();
	}
}

void Game::playTheme(bool what){
	if (what)
		theme.play();
	else
		theme.pause();
}

void Game::restartTheme(bool go){
	if (go) {
		theme.stop();
		theme.play();
	}
	else
		theme.stop();
}

int Game::getThemeStatus(){
	return (int)this->theme.getStatus();
}

void Game::setThemeVolume(float newVolume){
	this->theme.setVolume(newVolume);
	this->volume = newVolume;
}

float Game::getThemeVolume(){
	return this->volume;
}

void Game::saveAudio(){
	std::string savePath = "Config/audio.ini";
	std::ofstream saveOFile(savePath);
	bool isPlaying = true;
	if (this->theme.getStatus() != 2)isPlaying = false;
	if (saveOFile.is_open()) {
		saveOFile << isPlaying << std::endl;
		saveOFile << this->volume << std::endl;

		saveOFile.close();
	}
	else {
		throw("ERROR::GAME::initAudio::FILE_NOT_OPEN");
	}
}

void Game::render(){
	this->window->clear();

	//Render items
	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();
}

void Game::run(){
	while (this->window->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}

