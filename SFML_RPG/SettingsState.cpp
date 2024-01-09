#include "stdafx.h"
#include "SettingsState.h"

void SettingsState::initVariables(){
	this->modes = sf::VideoMode::getFullscreenModes();
	if (!this->buffer.loadFromFile("Resources/Audio/click.wav")) {
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_CLICK_SOUND";
	}
	this->click.setBuffer(this->buffer);
}

void SettingsState::initFonts(){
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")){
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void SettingsState::initKeybinds(){
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open()){
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2){
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void SettingsState::initGui(){
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;

	this->fullscreen = false;

	//Ozadje
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(vm.width),
			static_cast<float>(vm.height)
		)
	);

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->backgroundTexture);

	//Ozadje za Gumbe
	this->btnBackground.setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 1.34f),
			static_cast<float>(vm.height)
		)
	);
	this->btnBackground.setPosition(gui::p2pX(11.5f, vm), 0.f);
	this->btnBackground.setFillColor(sf::Color(10, 10, 10, 220));

	//Gumbi
	this->buttons["BACK"] = new gui::Button(
		gui::p2pX(72.f, vm), gui::p2pY(81.5f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Back", gui::calcCharSize(vm),
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["APPLY"] = new gui::Button(
		gui::p2pX(60.f, vm), gui::p2pY(81.5f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Apply", gui::calcCharSize(vm),
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["SOUND_SWITCH"] = new gui::Button(
		gui::p2pX(68.5f, vm), gui::p2pY(10.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Sound: ON", gui::calcCharSize(vm),
		sf::Color(255, 255, 255, 255), sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 150),
		sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0));

	this->buttons["FULLSCREEN_SWITCH"] = new gui::Button(
		gui::p2pX(42.f, vm), gui::p2pY(34.2f, vm),
		gui::p2pX(10.4f, vm), gui::p2pY(4.5f, vm),
		&this->font, "OFF", gui::calcCharSize(vm),
		sf::Color(255, 255, 255, 255), sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 150),
		sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0), sf::Color(0, 0, 0, 0));

	//Modi
	std::vector<std::string> modes_str;
	for (auto &i : this->modes){
		modes_str.push_back(std::to_string(i.width) + 'x' + std::to_string(i.height));
	}

	//Spustni seznam
	this->dropDownLists["RESOLUTION"] = new gui::DropDownList(
		gui::p2pX(42.f, vm), gui::p2pY(25.f, vm),
		gui::p2pX(10.4f, vm), gui::p2pY(4.5f, vm),
		font, modes_str.data(), modes_str.size()
	);

	//Inicializacija teksta
	this->optionsText.setFont(this->font);
	this->optionsText.setPosition(sf::Vector2f(gui::p2pX(18.f, vm), gui::p2pY(25.f, vm)));
	this->optionsText.setCharacterSize(gui::calcCharSize(vm, 70));
	this->optionsText.setFillColor(sf::Color(255, 255, 255, 200));

	this->optionsText.setString(
		"Resolution \n\nFullscreen \n\nVsync \n\nAntialiasing \n\n "
	);
}

void SettingsState::resetGui(){
	//resetira gui
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it){
		delete it->second;
	}
	this->buttons.clear();

	auto it2 = this->dropDownLists.begin();
	for (it2 = this->dropDownLists.begin(); it2 != this->dropDownLists.end(); ++it2){
		delete it2->second;
	}
	this->dropDownLists.clear();
	this->initGui();
}

SettingsState::SettingsState(StateData* state_data, Game* game) : State(state_data){
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
	this->sound = 1;
	//this->rel = 1;
	this->game=game;
}

SettingsState::~SettingsState(){
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it){
		delete it->second;
	}
	
	auto it2 = this->dropDownLists.begin();
	for (it2 = this->dropDownLists.begin(); it2 != this->dropDownLists.end(); ++it2){
		delete it2->second;
	}
}

//Funkcije
void SettingsState::updateInput(const float & dt){
}

void SettingsState::updateGui(const float & dt){
	/*Updata ceu gui.*/
	//Gumbi
	for (auto &it : this->buttons){
		it.second->update(this->mousePosWindow);
	}

	//Delovanje gumbou
	//Zapre game
	if (this->buttons["BACK"]->isPressed()){
		this->click.play();
		this->endState();
	}
	//Sound switch
	if (this->buttons["SOUND_SWITCH"]->isPressed()) { // ne dela lih najbuls
		if (sound) {
			this->game->playTheme(false);
			this->buttons["SOUND_SWITCH"]->setText("Sound: OFF");
			sound = !sound;
			this->click.play();
		}
		else {
			this->game->playTheme(true);
			this->buttons["SOUND_SWITCH"]->setText("Sound: ON");
			sound = !sound;
			this->click.play();
		}
	}
	if (this->buttons["FULLSCREEN_SWITCH"]->isPressed()) {
		if (this->fullscreen)this->buttons["FULLSCREEN_SWITCH"]->setText("OFF");
		else this->buttons["FULLSCREEN_SWITCH"]->setText("ON");
		this->fullscreen = !this->fullscreen;
	}
	//Applya settinge
	if (this->buttons["APPLY"]->isPressed()){
		this->click.play();
		this->stateData->gfxSettings->resolution = this->modes[this->dropDownLists["RESOLUTION"]->getActiveElementId()];

		this->stateData->gfxSettings->fullscreen = this->fullscreen;

		this->window->create(this->stateData->gfxSettings->resolution, this->stateData->gfxSettings->title, this->stateData->gfxSettings->fullscreen ? sf::Style::Fullscreen : sf::Style::Default);
		this->resetGui();
	}

	//Spustni seznam
	for (auto &it : this->dropDownLists){
		it.second->update(this->mousePosWindow, dt);
	}
}

void SettingsState::update(const float& dt){
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateGui(dt);
}

void SettingsState::renderGui(sf::RenderTarget& target){
	for (auto &it : this->buttons){
		it.second->render(target);
	}

	for (auto &it : this->dropDownLists){
		it.second->render(target);
	}
}

void SettingsState::render(sf::RenderTarget* target){
	if (!target)
		target = this->window;

	target->draw(this->background);
	target->draw(this->btnBackground);

	this->renderGui(*target);

	target->draw(this->optionsText);

	/*  //SAM DEBUG ZA ODSTRANT POL
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());
	target->draw(mouseText);*/
}