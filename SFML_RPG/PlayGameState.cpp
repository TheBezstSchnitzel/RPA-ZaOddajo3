#include "stdafx.h"
#include "PlayGameState.h"
#include "Game.h"
#include <filesystem>

void PlayGameState::initFonts(){
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void PlayGameState::initKeybinds(){
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2) {
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void PlayGameState::initTextures(){
	if (!this->textures["MAIN_BACKGROUND"].loadFromFile("Resources/Images/Backgrounds/bg.png")) {
		throw "ERROR::PLAY_GAME_STATE::FAILED_TO_LOAD_MAIN_BACKGROUND_TEXTURE";
	}
	if (!this->textures["SUB_BACKGROUND"].loadFromFile("Resources/Images/Backgrounds/bg16.png")) {
		throw "ERROR::PLAY_GAME_STATE::FAILED_TO_LOAD_SUB_BACKGROUND_TEXTURE";
	}
	//se font
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")) {
		throw("ERROR::PLAY_GAME_STATE::COULD NOT LOAD FONT");
	}
}

void PlayGameState::initBackgrounds(const sf::VideoMode& vm){
	//main background
	this->backgrounds["MAIN_BG"].setSize(
		sf::Vector2f(
			static_cast<float>(vm.width),
			static_cast<float>(vm.height)
		)
	);
	this->backgrounds["MAIN_BG"].setTexture(&this->textures["MAIN_BACKGROUND"]);
	//Ozadje za Gumbe
	this->backgrounds["BTN_BG"].setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 1.5f),
			static_cast<float>(vm.height)
		)
	);
	this->backgrounds["BTN_BG"].setPosition(gui::p2pX(17.5f, vm), 0.f);
	this->backgrounds["BTN_BG"].setFillColor(sf::Color(10, 10, 10, 220));
	//Ozadje za savee
	//1
	this->backgrounds["SAVE_BG_1"].setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 4.5f),
			static_cast<float>(vm.height / 3.5f)
		)
	);
	this->backgrounds["SAVE_BG_1"].setPosition(gui::p2pX(24.f, vm), gui::p2pX(3.5f, vm));
	this->backgrounds["SAVE_BG_1"].setTexture(&this->textures["SUB_BACKGROUND"]);
	//2
	this->backgrounds["SAVE_BG_2"].setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 4.5f),
			static_cast<float>(vm.height / 3.5f)
		)
	);
	this->backgrounds["SAVE_BG_2"].setPosition(gui::p2pX(24.f, vm), gui::p2pX(22.5f, vm));
	this->backgrounds["SAVE_BG_2"].setTexture(&this->textures["SUB_BACKGROUND"]);
	//3
	this->backgrounds["SAVE_BG_3"].setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 4.5f),
			static_cast<float>(vm.height / 3.5f)
		)
	);
	this->backgrounds["SAVE_BG_3"].setPosition(gui::p2pX(55.f, vm), gui::p2pX(22.5f, vm));
	this->backgrounds["SAVE_BG_3"].setTexture(&this->textures["SUB_BACKGROUND"]);
	//4
	this->backgrounds["SAVE_BG_4"].setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 4.5f),
			static_cast<float>(vm.height / 3.5f)
		)
	);
	this->backgrounds["SAVE_BG_4"].setPosition(gui::p2pX(55.f, vm), gui::p2pX(3.5f, vm));
	this->backgrounds["SAVE_BG_4"].setTexture(&this->textures["SUB_BACKGROUND"]);
}

void PlayGameState::initKeyTime() {
	this->keytimeMax = 0.75f;
}

std::string PlayGameState::whatTime(){
	auto time = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(time);
	//std::cout << std::ctime(&end_time) << std::endl;
	return std::string(std::ctime(&end_time));
}

void PlayGameState::initTexts(const sf::VideoMode& vm) {
	//Inicializacija teksta
	// Save1
	this->texts["SAVE1"].setFont(this->font);
	this->texts["SAVE1"].setPosition(sf::Vector2f(gui::p2pX(31.f, vm), gui::p2pY(17.f, vm)));
	this->texts["SAVE1"].setCharacterSize(gui::calcCharSize(vm, 70));
	this->texts["SAVE1"].setFillColor(sf::Color(0, 0, 0, 255));
	this->texts["SAVE1"].setString("  Save #1:");
	//1
	this->texts["SAVE_1"].setFont(this->font);
	this->texts["SAVE_1"].setPosition(sf::Vector2f(gui::p2pX(24.5f, vm), gui::p2pY(22.f, vm)));
	this->texts["SAVE_1"].setCharacterSize(gui::calcCharSize(vm, 70));
	this->texts["SAVE_1"].setFillColor(sf::Color(0, 0, 0, 255));
	if (std::filesystem::exists("Saves/save1/game")) this->texts["SAVE_1"].setString(this->readFromSave("Saves/save1/misc.txt"));
	else this->texts["SAVE_1"].setString("                0-0-0-0");
	// Save2
	this->texts["SAVE2"].setFont(this->font);
	this->texts["SAVE2"].setPosition(sf::Vector2f(gui::p2pX(62.f, vm), gui::p2pY(17.f, vm)));
	this->texts["SAVE2"].setCharacterSize(gui::calcCharSize(vm, 70));
	this->texts["SAVE2"].setFillColor(sf::Color(0, 0, 0, 255));
	this->texts["SAVE2"].setString("  Save #2:");
	//2
	this->texts["SAVE_2"].setFont(this->font);
	this->texts["SAVE_2"].setPosition(sf::Vector2f(gui::p2pX(55.5f, vm), gui::p2pY(22.f, vm)));
	this->texts["SAVE_2"].setCharacterSize(gui::calcCharSize(vm, 70));
	this->texts["SAVE_2"].setFillColor(sf::Color(0, 0, 0, 255));
	if (std::filesystem::exists("Saves/save2/game")) this->texts["SAVE_2"].setString(this->readFromSave("Saves/save2/misc.txt"));
	else this->texts["SAVE_2"].setString("                0-0-0-0");
	// Save3
	this->texts["SAVE3"].setFont(this->font);
	this->texts["SAVE3"].setPosition(sf::Vector2f(gui::p2pX(31.f, vm), gui::p2pY(51.f, vm)));
	this->texts["SAVE3"].setCharacterSize(gui::calcCharSize(vm, 70));
	this->texts["SAVE3"].setFillColor(sf::Color(0, 0, 0, 255));
	this->texts["SAVE3"].setString("  Save #3:");
	//3
	this->texts["SAVE_3"].setFont(this->font);
	this->texts["SAVE_3"].setPosition(sf::Vector2f(gui::p2pX(24.5f, vm), gui::p2pY(56.f, vm)));
	this->texts["SAVE_3"].setCharacterSize(gui::calcCharSize(vm, 70));
	this->texts["SAVE_3"].setFillColor(sf::Color(0, 0, 0, 255));
	if (std::filesystem::exists("Saves/save3/game")) this->texts["SAVE_3"].setString(this->readFromSave("Saves/save3/misc.txt"));
	else this->texts["SAVE_3"].setString("                0-0-0-0");
	// Save4
	this->texts["SAVE4"].setFont(this->font);
	this->texts["SAVE4"].setPosition(sf::Vector2f(gui::p2pX(62.f, vm), gui::p2pY(51.f, vm)));
	this->texts["SAVE4"].setCharacterSize(gui::calcCharSize(vm, 70));
	this->texts["SAVE4"].setFillColor(sf::Color(0, 0, 0, 255));
	this->texts["SAVE4"].setString("  Save #4:");
	//4
	this->texts["SAVE_4"].setFont(this->font);
	this->texts["SAVE_4"].setPosition(sf::Vector2f(gui::p2pX(55.5f, vm), gui::p2pY(56.f, vm)));
	this->texts["SAVE_4"].setCharacterSize(gui::calcCharSize(vm, 70));
	this->texts["SAVE_4"].setFillColor(sf::Color(0, 0, 0, 255));
	if (std::filesystem::exists("Saves/save4/game")) this->texts["SAVE_4"].setString(this->readFromSave("Saves/save4/misc.txt"));
	else this->texts["SAVE_4"].setString("                0-0-0-0");
}

void PlayGameState::initGui(){
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
	this->initTextures();
	this->initTexts(vm);
	this->initBackgrounds(vm);

	//Gumbi
	this->buttons["GAME_SAVE_1"] = new gui::Button(
		gui::p2pX(28.3f, vm), gui::p2pY(10.3f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Start", gui::calcCharSize(vm),
		sf::Color(0, 0, 0, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["GAME_DELETE_SAVE_1"] = new gui::Button(
		gui::p2pX(28.3f, vm), gui::p2pY(28.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Delete", gui::calcCharSize(vm),
		sf::Color(0, 0, 0, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["GAME_SAVE_2"] = new gui::Button(
		gui::p2pX(59.5f, vm), gui::p2pY(10.3f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Start", gui::calcCharSize(vm),
		sf::Color(0, 0, 0, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["GAME_DELETE_SAVE_2"] = new gui::Button(
		gui::p2pX(59.5f, vm), gui::p2pY(28.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Delete", gui::calcCharSize(vm),
		sf::Color(0, 0, 0, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["GAME_SAVE_3"] = new gui::Button(
		gui::p2pX(28.3f, vm), gui::p2pY(44.3f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Start", gui::calcCharSize(vm),
		sf::Color(0, 0, 0, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["GAME_DELETE_SAVE_3"] = new gui::Button(
		gui::p2pX(28.3f, vm), gui::p2pY(62.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Delete", gui::calcCharSize(vm),
		sf::Color(0, 0, 0, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["GAME_SAVE_4"] = new gui::Button(
		gui::p2pX(59.5f, vm), gui::p2pY(44.3f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Start", gui::calcCharSize(vm),
		sf::Color(0, 0, 0, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["GAME_DELETE_SAVE_4"] = new gui::Button(
		gui::p2pX(59.5f, vm), gui::p2pY(62.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Delete", gui::calcCharSize(vm),
		sf::Color(0, 0, 0, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["EXIT"] = new gui::Button(
		gui::p2pX(43.5f, vm), gui::p2pY(80.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Back", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void PlayGameState::resetGui(){
	//Resetira GUI	
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
	this->buttons.clear();

	this->initGui();
}

void deleteAllItemsInDirectory(const std::string& directoryPath) {
	//izbrise vse datoteke in mape v directoriju specificiranem v vnosu
	for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
		try {
			if (std::filesystem::is_directory(entry.path())) {
				// Recursively delete subdirectories and their contents
				deleteAllItemsInDirectory(entry.path().string());
				std::filesystem::remove(entry.path());
			}
			else if (std::filesystem::is_regular_file(entry.path())) {
				// Delete regular files
				std::filesystem::remove(entry.path());
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Error deleting item: " << entry.path() << " - " << e.what() << std::endl;
		}
	}
}

void PlayGameState::deleteSave(short saveNum){
	//Izbrise save specificriran z saveNum
	switch (saveNum) {
	case 1:
		this->texts["SAVE_1"].setString("                0-0-0-0");
		deleteAllItemsInDirectory("Saves/save1");
		break;
	case 2:
		this->texts["SAVE_2"].setString("                0-0-0-0");
		deleteAllItemsInDirectory("Saves/save2");
		break;
	case 3:
		this->texts["SAVE_3"].setString("                0-0-0-0");
		deleteAllItemsInDirectory("Saves/save3");
		break;
	case 4:
		this->texts["SAVE_4"].setString("                0-0-0-0");
		deleteAllItemsInDirectory("Saves/save4");
		break;
	}
}

std::string PlayGameState::readFromSave(std::string path){
	std::ifstream saveIFile(path);
	std::string tmp;
	if (saveIFile.is_open()) {
		std::getline(saveIFile, tmp);
		saveIFile.close();
	}
	else throw("ERROR::PlayGameState::readFromSave::FILE_NOT_OPEN");
	return tmp;
}

PlayGameState::PlayGameState(StateData* state_data,Game* game) : State(state_data) {
	this->initFonts();
	this->initKeyTime();
	this->initKeybinds();
	this->initGui();
	this->game = game;
}

PlayGameState::~PlayGameState(){
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}

void PlayGameState::updateTexts(unsigned short i){
	std::string tmp=this->whatTime();
	switch (i){
	case 1:
		this->texts["SAVE_1"].setString(tmp);
		break;
	case 2:
		this->texts["SAVE_2"].setString(tmp);
		break;
	case 3:
		this->texts["SAVE_3"].setString(tmp);
		break;
	case 4:
		this->texts["SAVE_4"].setString(tmp);
		break;
	}
}

void PlayGameState::updateButtons() {
	//Updata gumbe
	for (auto& it : this->buttons) {
		it.second->update(this->mousePosWindow);
	}

	//Nou game
	if (this->buttons["GAME_SAVE_1"]->isPressed()) {
		this->buttons["GAME_SAVE_1"]->makeSound();
		this->game->playTheme(false);
		this->states->push(new GameState(this->stateData,this->game,1));
		if(!std::filesystem::exists("Saves/save4/game"))this->updateTexts(1);
	}
	if (this->buttons["GAME_SAVE_2"]->isPressed()) {
		this->buttons["GAME_SAVE_2"]->makeSound();
		this->game->playTheme(false);
		this->states->push(new GameState(this->stateData,this->game,2));
		if (!std::filesystem::exists("Saves/save4/game"))this->updateTexts(2);
	}
	if (this->buttons["GAME_SAVE_3"]->isPressed()) {
		this->buttons["GAME_SAVE_3"]->makeSound();
		this->game->playTheme(false);
		this->states->push(new GameState(this->stateData,this->game,3));
		if (!std::filesystem::exists("Saves/save4/game"))this->updateTexts(3);
	}
	if (this->buttons["GAME_SAVE_4"]->isPressed()) {
		this->buttons["GAME_SAVE_4"]->makeSound();
		this->game->playTheme(false);
		this->states->push(new GameState(this->stateData,this->game,4));
		if (!std::filesystem::exists("Saves/save4/game"))this->updateTexts(4);
	}
	if (this->buttons["GAME_DELETE_SAVE_1"]->isPressed()) {
		this->buttons["GAME_DELETE_SAVE_1"]->makeSound();
		this->deleteSave(1);
	}
	if (this->buttons["GAME_DELETE_SAVE_2"]->isPressed()) {
		this->buttons["GAME_DELETE_SAVE_2"]->makeSound();
		this->deleteSave(2);
	}
	if (this->buttons["GAME_DELETE_SAVE_3"]->isPressed()) {
		this->buttons["GAME_DELETE_SAVE_3"]->makeSound();
		this->deleteSave(3);
	}
	if (this->buttons["GAME_DELETE_SAVE_4"]->isPressed()) {
		this->buttons["GAME_DELETE_SAVE_4"]->makeSound();
		this->deleteSave(4);
	}
	//Exit
	if (this->buttons["EXIT"]->isPressed()) {
		this->buttons["EXIT"]->makeSound();
		while (true)if (this->buttons["EXIT"]->getStatus() == 0)break;
		this->endState();
	}
}

void PlayGameState::update(const float& dt) {
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();
}

void PlayGameState::renderButtons(sf::RenderTarget& target) {
	for (auto& it : this->buttons) {
		it.second->render(target);
	}
}

void PlayGameState::renderBackgrounds(sf::RenderTarget& target){
	target.draw(this->backgrounds["MAIN_BG"]);
	target.draw(this->backgrounds["BTN_BG"]);
	target.draw(this->backgrounds["SAVE_BG_1"]);
	target.draw(this->backgrounds["SAVE_BG_2"]);
	target.draw(this->backgrounds["SAVE_BG_3"]);
	target.draw(this->backgrounds["SAVE_BG_4"]);
}

void PlayGameState::renderTexts(sf::RenderTarget& target){
	for (auto i : texts) {
		target.draw(i.second);
	}
}

void PlayGameState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;
	
	this->renderBackgrounds(*target);
	this->renderTexts(*target);
	this->renderButtons(*target);

	//DEBUG
	/*sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());
	target->draw(mouseText);*/
}

void PlayGameState::updateInput(const float& dt) {
}