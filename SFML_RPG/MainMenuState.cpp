#include "stdafx.h"
#include "MainMenuState.h"

//Inicializacija
void MainMenuState::initVariables(){
	this->isTrueRes = true;
}

void MainMenuState::initFonts(){
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")){
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initKeybinds(){
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

void MainMenuState::initGui(){
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;

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
			static_cast<float>(vm.width / 5), 
			static_cast<float>(vm.height)
		)
	);

	this->btnBackground.setPosition(gui::p2pX(11.5f, vm), 0.f);
	this->btnBackground.setFillColor(sf::Color(10, 10, 10, 220));

	//Gumbi
	this->buttons["GAME_STATE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(30.f, vm), 
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Play", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["SETTINGS_STATE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(40.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Settings", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["TUTORIAL_STATE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(50.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Tutorial", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["EDITOR_STATE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(60.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Editor", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["EXIT_STATE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(75.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Quit", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void MainMenuState::resetGui(){
	//Resetira GUI	
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it){
		delete it->second;
	}
	this->buttons.clear();

	this->initGui();
	this->isTrueRes = true;
}
//Konstruktor
MainMenuState::MainMenuState(StateData* state_data,Game*game) : State(state_data),game(game){
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
}
//Destruktor
MainMenuState::~MainMenuState(){
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it){
		delete it->second;
	}
}


void MainMenuState::updateInput(const float & dt){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime()) {
		if (!this->paused)
			this->pauseState();
		else
			this->unpauseState();
	}
}

void MainMenuState::updateButtons(){
	//Updata gumbe
	for (auto &it : this->buttons){
		it.second->update(this->mousePosWindow);
	}

	//Nou game
	if (this->buttons["GAME_STATE"]->isPressed()){
		this->buttons["GAME_STATE"]->makeSound();
		this->states->push(new PlayGameState(this->stateData,game));
	}

	//Nastavitve
	if (this->buttons["SETTINGS_STATE"]->isPressed()){
		this->buttons["SETTINGS_STATE"]->makeSound();
		this->states->push(new SettingsState(stateData,game));
		this->isTrueRes = false; //v vsakmu primeru preverja ko prides iz nastavitev
	}

	//Tutorial
	if (this->buttons["TUTORIAL_STATE"]->isPressed()) {
		this->buttons["TUTORIAL_STATE"]->makeSound();
		this->states->push(new TutorialState(stateData, game));
	}
	
	//Editor
	if (this->buttons["EDITOR_STATE"]->isPressed()){
		this->buttons["EDITOR_STATE"]->makeSound();
		this->states->push(new EditorState(this->stateData));
	}

	//Exit
	if (this->buttons["EXIT_STATE"]->isPressed()){
		this->buttons["EXIT_STATE"]->makeSound();
		while (true)if (this->buttons["EXIT_STATE"]->getStatus() == 0)break;
		this->endState();
	}
}

void MainMenuState::update(const float& dt){
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget& target){
	for (auto &it : this->buttons){
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target){
	if (!this->isTrueRes)this->resetGui();
	if (!target)
		target = this->window;

	target->draw(this->background);

	target->draw(this->btnBackground);

	this->renderButtons(*target);

	//DEBUG
	//sf::Text mouseText;
	//mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	//mouseText.setFont(this->font);
	//mouseText.setCharacterSize(12);
	//std::stringstream ss;
	//ss << this->mousePosView.x << " " << this->mousePosView.y;
	//mouseText.setString(ss.str());
	//target->draw(mouseText);
}
