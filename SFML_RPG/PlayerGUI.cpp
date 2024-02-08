#include "stdafx.h"
#include "PlayerGUI.h"

void PlayerGUI::initFont(){
	this->font.loadFromFile("Fonts/Dosis-Light.ttf");
}

void PlayerGUI::initTextures(){
	if (!this->gameTimeDisplay_Texture.loadFromFile("Resources/Images/Gui/gameTimeSprite.png")) {
		throw "ERROR::PLAYERGUI::COULD_NOT_LOAD_TIMEDISPLAY_TEXTURE";
	}
	if (!this->gameTimeNum_Texture.loadFromFile("Resources/Images/Gui/numbers.png")) {
		throw "ERROR::PLAYERGUI::COULD_NOT_LOAD_TIMEDISPLAYNUMHOUR_TEXTURE";
	}
}

void PlayerGUI::initLevelBar(){
	float width = gui::p2pX(1.6f, this->vm);
	float height = gui::p2pY(2.8f, this->vm);
	float x = gui::p2pX(1.f, this->vm);
	float y = gui::p2pY(1.9f, this->vm);

	this->levelBarBack.setSize(sf::Vector2f(width, height));
	this->levelBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->levelBarBack.setPosition(x, y);

	this->levelBarText.setFont(this->font);
	this->levelBarText.setCharacterSize(gui::calcCharSize(this->vm, 150));
	this->levelBarText.setPosition(
		this->levelBarBack.getPosition().x + gui::p2pX(0.53f, this->vm), 
		this->levelBarBack.getPosition().y + gui::p2pY(0.5f, this->vm)
	);
}

void PlayerGUI::initEXPBar(){
	this->expBar = new gui::ProgressBar(
		1.f, 5.6f, 10.4f, 1.9f,
		sf::Color::Blue, 220,
		this->vm, &this->font);
}

void PlayerGUI::initHPBar(){
	this->hpBar = new gui::ProgressBar(
		1.f, 8.3f, 10.4f, 2.8f,
		sf::Color::Red, 180,
		this->vm, &this->font);
}

void PlayerGUI::initPlayerTabs(sf::VideoMode &vm, sf::Font &font, Player &player){
	this->playerTabs = new PlayerGUITabs(vm, font, player);
}

void PlayerGUI::initGameClockDisplay(sf::VideoMode& vm){
	//this->gameTimeDisplay.setFillColor(sf::Color::Transparent);
	this->gameTimeDisplay.setTexture(&this->gameTimeDisplay_Texture);
	this->gameTimeDisplay.setOutlineColor(sf::Color::Red);
	this->gameTimeDisplay.setOutlineThickness(1.f);
	this->gameTimeDisplay.setSize(sf::Vector2f(gui::p2pX(10.f,vm),gui::p2pY(16.f,vm)));
	this->gameTimeDisplay.setPosition(gui::p2pX(88.f,vm), gui::p2pY(2.f,vm));
}

void PlayerGUI::initGameClockNumbers(sf::VideoMode& vm){
	//hours ===========================
	//texture Rect
	this->gameTimeNum_Hour_TexRect.width = 16;
	this->gameTimeNum_Hour_TexRect.height = 9;
	this->gameTimeNum_Hour_TexRect.left = 0;
	this->gameTimeNum_Hour_TexRect.top = 0;
	//display rect
	//this->gameTimeNum_Hour.setOutlineColor(sf::Color::Blue);
	this->gameTimeNum_Hour.setTexture(&this->gameTimeNum_Texture);
	this->gameTimeNum_Hour.setTextureRect(this->gameTimeNum_Hour_TexRect);
	//this->gameTimeNum_Hour.setOutlineThickness(1.f);
	this->gameTimeNum_Hour.setSize(sf::Vector2f(gui::p2pX(3.f, vm), gui::p2pY(3.f, vm)));
	this->gameTimeNum_Hour.setPosition(gui::p2pX(89.5f, vm), gui::p2pY(8.5f, vm));

	//minute ===========================
	//texture Rect
	this->gameTimeNum_Minute_TexRect.width = 16;
	this->gameTimeNum_Minute_TexRect.height = 9;
	this->gameTimeNum_Minute_TexRect.left = 0;
	this->gameTimeNum_Minute_TexRect.top = 0;
	//display rect
	//this->gameTimeNum_Minute.setOutlineColor(sf::Color::Blue);
	this->gameTimeNum_Minute.setTexture(&this->gameTimeNum_Texture);
	this->gameTimeNum_Minute.setTextureRect(this->gameTimeNum_Minute_TexRect);
	//this->gameTimeNum_Minute.setOutlineThickness(1.f);
	this->gameTimeNum_Minute.setSize(sf::Vector2f(gui::p2pX(3.f, vm), gui::p2pY(3.f, vm)));
	this->gameTimeNum_Minute.setPosition(gui::p2pX(93.7f, vm), gui::p2pY(8.5f, vm));
}

PlayerGUI::PlayerGUI(Player* player, sf::VideoMode& vm) : vm(vm){
	this->player = player;

	this->initTextures();
	this->initFont();
	this->initLevelBar();
	this->initEXPBar();
	this->initHPBar();
	this->initPlayerTabs(vm, font, *player);
	
	this->initGameClockDisplay(vm);
	this->initGameClockNumbers(vm);
}

PlayerGUI::~PlayerGUI(){
	delete this->hpBar;
	delete this->expBar;
	delete this->playerTabs;
}

const bool PlayerGUI::getTabsOpen() const{
	return this->playerTabs->tabsOpen();
}

void PlayerGUI::toggleCharacterTab(){
	this->playerTabs->toggleTab(PLAYER_TABS::CHARACTER_TAB);
}

//Funkcije
void PlayerGUI::updateLevelBar(){
	this->levelBarString = std::to_string(this->player->getAttributeComponent()->level);
	this->levelBarText.setString(this->levelBarString);
}

void PlayerGUI::updateEXPBar(){
	this->expBar->update(this->player->getAttributeComponent()->exp, this->player->getAttributeComponent()->expNext);
}

void PlayerGUI::updateHPBar(){
	this->hpBar->update(this->player->getAttributeComponent()->hp, this->player->getAttributeComponent()->hpMax);
}

void PlayerGUI::updatePlayerTabs(){
	this->playerTabs->update();
}

void PlayerGUI::updateClockDisplay(int hour, int minute){
	//hour
	int tmpX = 0;
	int tmpY = 0;
	tmpX = ((hour % 10) * this->gameTimeNum_Hour_TexRect.width);
	tmpY = ((hour / 10) * this->gameTimeNum_Hour_TexRect.height);
	this->gameTimeNum_Hour_TexRect.left = tmpX;
	this->gameTimeNum_Hour_TexRect.top = tmpY;
	this->gameTimeNum_Hour.setTextureRect(this->gameTimeNum_Hour_TexRect);
	//minute
	tmpX = ((minute % 10) * this->gameTimeNum_Minute_TexRect.width);
	tmpY = ((minute / 10) * this->gameTimeNum_Minute_TexRect.height);
	this->gameTimeNum_Minute_TexRect.left = tmpX;
	this->gameTimeNum_Minute_TexRect.top = tmpY;
	this->gameTimeNum_Minute.setTextureRect(this->gameTimeNum_Minute_TexRect);
}

void PlayerGUI::update(const float & dt){
	this->updateLevelBar();
	this->updateEXPBar();
	this->updateHPBar();
	this->updatePlayerTabs();
}


void PlayerGUI::renderLevelBar(sf::RenderTarget & target){
	target.draw(this->levelBarBack);
	target.draw(this->levelBarText);
}

void PlayerGUI::renderEXPBar(sf::RenderTarget & target){
	this->expBar->render(target);
}

void PlayerGUI::renderHPBar(sf::RenderTarget & target){
	this->hpBar->render(target);
}

void PlayerGUI::renderPlayerTabs(sf::RenderTarget& target){
	this->playerTabs->render(target);
}

void PlayerGUI::renderGameClock(sf::RenderTarget& target){
	target.draw(this->gameTimeDisplay);
	target.draw(this->gameTimeNum_Hour);
	target.draw(this->gameTimeNum_Minute);
}

void PlayerGUI::render(sf::RenderTarget & target){
	this->renderLevelBar(target);
	this->renderEXPBar(target);
	this->renderHPBar(target);
	this->renderPlayerTabs(target);
	this->renderGameClock(target);
}
