#include "stdafx.h"
#include "GameState.h"
#include "Game.h"
#include <filesystem>

void GameState::initBuildings(){
	//iz save nalozi
}

void GameState::initVariables(){
	this->isZoomedOut = false;
}

//Inicializacija
void GameState::initDeferredRender(){
	this->renderTexture.create(
		this->stateData->gfxSettings->resolution.width,
		this->stateData->gfxSettings->resolution.height
	);

	this->renderSprite.setTexture(this->renderTexture.getTexture());
	this->renderSprite.setTextureRect(
		sf::IntRect(
			0, 
			0, 
			this->stateData->gfxSettings->resolution.width, 
			this->stateData->gfxSettings->resolution.height
		)
	);
}

void GameState::initView(){
	this->view.setSize(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width / 2),
			static_cast<float>(this->stateData->gfxSettings->resolution.height / 2)
		)
	);

	this->view.setCenter(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width) / 2.f,
			static_cast<float>(this->stateData->gfxSettings->resolution.height) / 2.f
		)
	);
	if (!this->isZoomedOut) {
		this->view.zoom(0.5f);
	}
	else {
		this->player->setNewMaxVelocity(140.f);
	}
}

void GameState::initKeybinds(){
	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open()){
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2){
			this->keybinds[key] = this->supportedKeys->at(key2);
			if(key == "ZOOM")this->keybindsTimes[key] = sf::Clock();
			if (key == "INVENTORY")this->keybindsTimes[key] = sf::Clock();
		}
	}

	ifs.close();
}

void GameState::initFonts(){
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")){
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void GameState::initTextures(){
	//player
	if (!this->textures["PLAYER_SHEET"].loadFromFile("Resources/Images/Sprites/Player/player_sheet.png")) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
	}
	//items
	if (!this->textures["HoeIcon"].loadFromFile("Resources/Images/Gui/hoeIcon.png")) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_HOE_ICON_TEXTURE";
	}
	if (!this->textures["carrot_seed"].loadFromFile("Resources/Images/Mixed/crops_all.png", sf::IntRect(sf::Vector2i(0,0),sf::Vector2i(16,16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_plants_all_TEXTURE";
	}
	//buildings
	if (!this->textures["Farmland"].loadFromFile("Resources/Images/Buildings/farmland.png")) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_Farmland_TEXTURE";
	}
	if (!this->textures["CarrotPlant"].loadFromFile("Resources/Images/Mixed/crops_all.png", sf::IntRect(sf::Vector2i(128, 0), sf::Vector2i(80, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_Farmland_TEXTURE";
	}
	if (!this->textures["CarrotPlantPosible"].loadFromFile("Resources/Images/Mixed/crops_all.png", sf::IntRect(sf::Vector2i(128, 0), sf::Vector2i(16, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_Farmland_TEXTURE";
	}
}

void GameState::initPauseMenu(){
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
	this->pmenu = new PauseMenu(this->stateData->gfxSettings->resolution, this->font);

	this->pmenu->addButton("RESUME", gui::p2pY(30.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Resume");
	this->pmenu->addButton("SAVE", gui::p2pY(60.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Save");
	this->pmenu->addButton("QUIT", gui::p2pY(74.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Quit");
}

void GameState::initShaders(){
	if (!this->core_shader.loadFromFile("vertex_shader.vert", "fragment_shader.frag")){
		std::cout << "ERROR::GAMESTATE::COULD NOT LOAD SHADER." << "\n";
	}
}

void GameState::initKeyTime(){
	this->keyTimeMax = 0.75f;
	this->keyTimer.restart();
}

void GameState::initDebugText(){
	this->debugText.setFont(this->font);
	this->debugText.setFillColor(sf::Color::White);
	this->debugText.setCharacterSize(16);
	this->debugText.setPosition(15.f, this->window->getSize().y / 2.f);
}

void GameState::initTools(){
	//DEBUG
	this->items["Hoe"] = new Hoe(&this->textures["HoeIcon"], 120, false);
	//if (this->items["Hoe"]->getTexture() == nullptr)std::cout << "lol" << std::endl;
	//Hoe tmp = Hoe(&this->textures["HoeIcon"], 120, false, false);
	this->player->getInventory()->add(this->items["Hoe"], 1);
	//if(this->player->getInventory()->getItemIcon(0) == nullptr)std::cout << "lol1" << std::endl; ;
	this->items["CarrotSeed"] = new CarrotSeed(&this->textures["carrot_seed"], 100, false);
	this->player->getInventory()->add(this->items["CarrotSeed"], -1);
}

void GameState::initPlayers() {
	this->player = new Player(300, 220, this->textures["PLAYER_SHEET"],false);
}

void GameState::initPlayerGUI(){
	this->playerGUI = new PlayerGUI(this->player, this->stateData->gfxSettings->resolution, this->font);
}

void GameState::initEnemySystem(){
	//this->enemySystem = new EnemySystem(this->activeEnemies, this->textures, *this->player);
}

void GameState::initTileMap(){
	switch (this->currentSeason) {
	case pomlad:
		this->tileMap = new TileMap("Config/text.slmp", "Resources/Images/Tiles/newFloorTiles_Pomlad.png");
		break;
	case poletje:
		this->tileMap = new TileMap("Config/text.slmp", "Resources/Images/Tiles/newFloorTiles_Poletje.png");
		break;
	case jesen:
		this->tileMap = new TileMap("Config/text.slmp", "Resources/Images/Tiles/newFloorTiles_Jesen.png");
		break;
	case zima:
		this->tileMap = new TileMap("Config/text.slmp","Resources/Images/Tiles/newFloorTiles_Zima.png");
		break;
	}
}

void GameState::initSystems(){
	this->tts = new TextTagSystem("Fonts/PixellettersFull.ttf");
}

void GameState::initInGameTime(){
	//ce ni prejsnega progressa se klice ta funkcija
	this->isDay = true;
	this->gameDaysElapsed = 0;
	this->currentSeason = pomlad;
	
	this->inGameTime_Hours = 6;
	this->inGameTime_Minutes = 0;
}

void GameState::initInGameTimers(){
	//this->dayTimerMax = 5.f; // v minutah
	//this->nightTimerMax = 5.f;//v minutah
	switch (this->currentSeason) {
	case pomlad:this->whenIsNightHour = 18; this->whenIsDayHour = 6; break;
	case poletje:this->whenIsNightHour = 19; this->whenIsDayHour = 5; break;
	case jesen:this->whenIsNightHour = 18; this->whenIsDayHour = 6; break;
	case zima:this->whenIsNightHour = 17; this->whenIsDayHour = 7; break;
	}

	this->minutesTimer.restart();
	this->minutesTimerMax = 1.f; //1s = 1min; 1min = 1h
}

//funkcije za branje shranjenih podatkov
void GameState::loadFromSave_misc(){
	std::string miscPath = this->savePath + "/misc.txt";
	std::ifstream saveIFile(miscPath);

	//prebere podatke
	if (saveIFile.is_open()) {
		//Zapisovanje podatkov
		std::getline(saveIFile, this->creationDate);
		saveIFile >> this->isZoomedOut;
		saveIFile.close();
	}
	else {
		throw("ERROR::GameState::loadFromSave_misc::FILE_NOT_OPEN");
	}
}

void GameState::loadFromSave_inGameTime(){
	std::string timePath = this->savePath + "/game/time.txt";
	std::ifstream saveIFile(timePath);

	//prebere podatke
	if (saveIFile.is_open()) {
		//Zapisovanje podatkov
		std::string seasonTmp = "";
		saveIFile >> this->isDay;
		saveIFile >> this->inGameTime_Hours >> this->inGameTime_Minutes;
		saveIFile >> this->gameDaysElapsed >> seasonTmp;
		this->currentSeason = static_cast<letniCasi>(std::stoi(seasonTmp));
		
		saveIFile.close();
	}
	else {
		throw("ERROR::GameState::loadFromSave_inGameTime::FILE_NOT_OPEN");
	}
}

void GameState::loadFromSave_player(){
	std::string playerPath = this->savePath + "/game/player/info.txt";
	std::ifstream saveIFile(playerPath);

	//prebere podatke
	if (saveIFile.is_open()) {
		//Branje podatkov
		float x, y;
		saveIFile >> x >> y;

		saveIFile.close();
		//zapisovanje podatkov
		this->player = new Player(x, y, this->textures["PLAYER_SHEET"],true);
		this->player->getInventory()->loadFromFile(this->savePath + "/game/player/inventory.txt");
	}
	else {
		throw("ERROR::GameState::loadFromSave_inGameTime::FILE_NOT_OPEN");
	}
}

void GameState::loadFromSave_items(){
	Inventory* inv = this->player->getInventory();
	std::ifstream saveIFile(this->savePath + "/game/items/itemsList.txt");
	std::string className = "";
	int i = 0;
	while (saveIFile >> className) {
		saveIFile >> i;
		if (className == "hoe") {
			this->items["Hoe" + std::to_string(i)] = new Hoe(&this->textures["HoeIcon"], 120, false);
			this->items["Hoe" + std::to_string(i)]->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			this->player->getInventory()->add(this->items["Hoe" + std::to_string(i)], i);
			continue;
		}
		if (className == "carrotSeed") {
			this->items["CarrotSeed" + std::to_string(i)] = new CarrotSeed(&this->textures["carrot_seed"], 100, false);
			this->items["CarrotSeed" + std::to_string(i)]->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			this->player->getInventory()->add(this->items["CarrotSeed" + std::to_string(i)], i); 
			continue;
		}
		std::cout << "mors popraut gamestate loadSaveItems" << std::endl;
	}
	saveIFile.close();
	//this->playerGUI->updateINV(this->mousePosWindow);
}

void GameState::loadFromSave_buildings() {
	std::ifstream saveIFile(this->savePath + "/game/buildings/buildingsList.txt");
	std::string buildingType = "";
	int n = 0;
	while (saveIFile >> buildingType >> n) {
		if (buildingType == "farmland") {
			for (int i = 0; i < n; i++) {
				this->buildings["farmland"][i] = new Farmland(&this->textures["Farmland"], sf::Vector2f(0.f, 0.f), sf::Vector2f(16.f, 16.f));
				this->buildings["farmland"][i]->loadFromFile(this->savePath + "/game/buildings/" + buildingType + std::to_string(i) + ".txt");
			}
			continue;
		}
		if (buildingType == "carrotPlant") {
			for (int i = 0; i < n; i++) {
				this->buildings["carrotPlant"][i] = new CarrotPlant(&this->textures["CarrotPlant"], sf::Vector2f(0.f, 0.f), sf::Vector2f(16.f, 16.f));
				this->buildings["carrotPlant"][i]->loadFromFile(this->savePath + "/game/buildings/" + buildingType + std::to_string(i) + ".txt");
			}
			continue;
		}
		std::cout << "Popravt mors loadFromSave buildings" << std::endl;
	}
	saveIFile.close();
}

void GameState::loadFromSave(){
	//klièe vse funkcije za loudanje iz save
	this->loadFromSave_inGameTime();
	this->loadFromSave_misc();
	this->loadFromSave_player();
	this->loadFromSave_items();
	this->loadFromSave_buildings();
}

void GameState::createSaveDir(){
	//prever ce mapa obstaja (da ni prvoi shranjevanj)
	std::string path = this->savePath + "/game";
	if (!std::filesystem::is_directory(path)) {
		//ustvari novo mapo ce je prvo shranjevanje
		std::filesystem::create_directory(path);
	}
	path = path + "/player";
	if (!std::filesystem::is_directory(path)) {
		//ustvari novo mapo ce je prvo shranjevanje
		std::filesystem::create_directory(path);
	}
	path = this->savePath + "/game/items";
	if (!std::filesystem::is_directory(path)) {
		//ustvari novo mapo ce je prvo shranjevanje
		std::filesystem::create_directory(path);
	}
	path = this->savePath + "/game/buildings";
	if (!std::filesystem::is_directory(path)) {
		//ustvari novo mapo ce je prvo shranjevanje
		std::filesystem::create_directory(path);
	}
}

//funkcije za shranjevanje
void GameState::save_misc(){
	std::string miscPath = this->savePath + "/misc.txt";
	std::ofstream saveOFile(miscPath);
	//shrani podatke
	if (saveOFile.is_open()) {
		//shranjevanje
		saveOFile << this->creationDate << std::endl;
		saveOFile << this->isZoomedOut << std::endl;
		saveOFile.close();
	}
	else {
		throw("ERROR::GameState::save_misc::FILE_NOT_OPEN");
	}
}

void GameState::save_inGameTime(){
	//shrani podatke
	std::string timePath = this->savePath+"/game/time.txt";
	std::ofstream saveOFile(timePath);
	if (saveOFile.is_open()) {
		//Shranjevanje
		saveOFile << this->isDay << std::endl;
		saveOFile << this->inGameTime_Hours << std::endl;
		saveOFile << this->inGameTime_Minutes << std::endl;
		saveOFile << this->gameDaysElapsed << std::endl;
		saveOFile << this->currentSeason << std::endl;

		saveOFile.close();
	}
	else {
		throw("ERROR::GameState::save_inGameTime::FILE_NOT_OPEN");
	}
}

void GameState::save_player(){
	sf::Vector2f playerPosition = this->player->getPosition();
	std::string playerPath = this->savePath + "/game/player/info.txt";
	std::ofstream saveOFile(playerPath);
	if (saveOFile.is_open()) {
		//shranjevanje
		saveOFile << playerPosition.x << std::endl;
		saveOFile << playerPosition.y << std::endl;

		saveOFile.close();
	}
	else {
		throw("ERROR::GameState::save_player::FILE_NOT_OPEN");
	}
	this->player->save(this->savePath + "/game/player");
}

void GameState::save_items(){
	Inventory* inv = this->player->getInventory();
	std::ofstream saveOFile(this->savePath + "/game/items/itemsList.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i < inv->maxSize(); i++) {
		if (inv->hasItem(i)) {
			//ce je tam item ga shrani
			std::string tempSave = this->savePath + "/game/items/item" + std::to_string(i) + ".txt";
			inv->getItem(i)->saveToFile(tempSave);
			if (Hoe* temp = dynamic_cast<Hoe*>(inv->getItem(i))) {
				saveOFile << "hoe" << " " << std::to_string(i) << std::endl;
				continue;
			}
			if (CarrotSeed* temp = dynamic_cast<CarrotSeed*>(inv->getItem(i))) {
				saveOFile << "carrotSeed" << " " << std::to_string(i) << std::endl;
				continue;
			}
			std::cout << "Game state save mors popraut" << std::endl;
		}
	}
	saveOFile.close();
}

void GameState::save_buildings(){
	std::ofstream saveOFile(this->savePath + "/game/buildings/buildingsList.txt");
	int id = 0;
	for (const auto& pair : this->buildings) {
		saveOFile << pair.first << std::endl;
		for (const auto& value : pair.second) {
			value.second->saveToFile(this->savePath + "/game/buildings/"+ pair.first + std::to_string(id) +".txt");
			id++;
		}
		saveOFile << id << std::endl;
		id = 0;
	}
	saveOFile.close();
}

void GameState::save(){
	this->createSaveDir();
	//klièe vse funkcije za shranjevanje
	this->save_inGameTime();
	this->save_misc();
	this->save_player();
	this->save_items();
	this->save_buildings();
}

void GameState::updateHours_Minutes(){
	if (this->minutesTimer.getElapsedTime().asSeconds() >= this->minutesTimerMax) {
		//spreminjanje minut
		if (this->inGameTime_Minutes + 1 == 60) { //ce je poteklu 60min dodaje eno uro
			this->inGameTime_Minutes = 0;
			if (this->inGameTime_Hours + 1 == 24) { //ce potece 24 ur doda en dan
				this->inGameTime_Hours = 0;
				this->gameDaysElapsed++;
			}
			else this->inGameTime_Hours++;
		}
		else this->inGameTime_Minutes++;
		this->minutesTimer.restart();
	}
	//std::cout << this->inGameTime_Hours << " : " << this->inGameTime_Minutes << std::endl;
}

std::string whatTime() {
	auto time = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(time);
	return std::string(std::ctime(&end_time));
}

//Konstruktor / destruktor
GameState::GameState(StateData* state_data,Game*game, unsigned short save) : State(state_data){
	this->initTextures();
	//novo shranjevanje ================================================
	this->savePath = "Saves/save" + std::to_string(save);
	this->game = game;
	std::filesystem::path savefilePath = this->savePath + "/game";
	//preveri ce ze sploh obstaja save
	if (std::filesystem::exists(savefilePath))this->loadFromSave();
	else {
		//save se ne obstaja
		this->initVariables();
		this->initPlayers();
		this->creationDate = whatTime();
		this->initInGameTime();
		this->initTools();
	}
	//te se u sakmu primeru na novo kreairajo
	this->initDeferredRender();
	this->initView();
	this->initKeybinds();
	this->initFonts();
	this->initPauseMenu();
	this->initShaders();
	//this->initDebugText(); // DEBUG
	this->initKeyTime();
	this->initPlayerGUI();
	this->initTileMap();
	this->initInGameTimers();
	this->initSystems();
	/*
	this->theme.openFromFile("Resources/Audio/themeSong2.wav");
	this->theme.setPitch(1.f);
	this->theme.setVolume(40.f);
	this->theme.setLoop(true);
	this->theme.play();*/
	this->isInventoryOpen = false;
	//this->player->getInventory()->makeInventoryTexture(this->stateData->gfxSettings->resolution);
	this->playerGUI->updateINV(this->mousePosWindow); //sam enkrat rabm za hb kazat
	this->hasItemInHand = false;
	this->lastMouseStateR = false;
}

GameState::~GameState(){
	delete this->pmenu;
	delete this->player;
	delete this->playerGUI;
	//delete this->enemySystem;
	delete this->tileMap;
	delete this->tts;
	/*for (size_t i = 0; i < this->activeEnemies.size(); i++) {
		delete this->activeEnemies[i];
	}*/
	this->theme.stop();
	//preverjanje za audio izven gamea
	std::ifstream saveIFile("Config/audio.ini");
	bool isPlaying = false;
	if (saveIFile.is_open()) {
		saveIFile >> isPlaying;
		saveIFile.close();
	}
	if (isPlaying)this->game->playTheme();
}

const bool GameState::getKeyTime(){	
	if (this->keyTimer.getElapsedTime().asSeconds() >= this->keyTimeMax){
		this->keyTimer.restart();
		return true;
	}

	return false;	
}

//Funkcija
void GameState::updateView(const float & dt){
	this->view.setCenter(
		std::floor(this->player->getPosition().x + (static_cast<float>(this->mousePosWindow.x) - static_cast<float>(this->stateData->gfxSettings->resolution.width / 2)) / 10.f),
		std::floor(this->player->getPosition().y + (static_cast<float>(this->mousePosWindow.y) - static_cast<float>(this->stateData->gfxSettings->resolution.height / 2)) / 10.f)
	);

	if (this->tileMap->getMaxSizeF().x >= this->view.getSize().x){
		if (this->view.getCenter().x - this->view.getSize().x / 2.f < 0.f){
			this->view.setCenter(0.f + this->view.getSize().x / 2.f, this->view.getCenter().y);
		}
		else if (this->view.getCenter().x + this->view.getSize().x / 2.f > this->tileMap->getMaxSizeF().x){
			this->view.setCenter(this->tileMap->getMaxSizeF().x - this->view.getSize().x / 2.f, this->view.getCenter().y);
		}
	}

	if (this->tileMap->getMaxSizeF().y >= this->view.getSize().y){
		if (this->view.getCenter().y - this->view.getSize().y / 2.f < 0.f){
			this->view.setCenter(this->view.getCenter().x, 0.f + this->view.getSize().y / 2.f);
		}
		else if (this->view.getCenter().y + this->view.getSize().y / 2.f > this->tileMap->getMaxSizeF().y){
			this->view.setCenter(this->view.getCenter().x, this->tileMap->getMaxSizeF().y - this->view.getSize().y / 2.f);
		}
	}

	this->viewGridPosition.x = static_cast<int>(this->view.getCenter().x) / static_cast<int>(this->stateData->gridSize);
	this->viewGridPosition.y = static_cast<int>(this->view.getCenter().y) / static_cast<int>(this->stateData->gridSize);
}

void GameState::updateInput(const float & dt){
	if (!this->isInventoryOpen) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime()) {
			if (!this->paused)this->pauseState();
			else this->unpauseState();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime() && this->isInventoryOpen) {
		this->isInventoryOpen = false;
		this->paused = false;
	}
	//inventory
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("INVENTORY"))) &&
		this->keybindsTimes.at("INVENTORY").getElapsedTime().asSeconds() >= this->keyTimeMax) {
		this->keybindsTimes.at("INVENTORY").restart();
		//odpre inventory
		this->isInventoryOpen = !this->isInventoryOpen;
		this->paused = this->isInventoryOpen;
	}
}

void GameState::updatePlayerInput(const float & dt){
	//Updata player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))){
		this->player->move(0.f, -1.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))){
		this->player->move(0.f, 1.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("ZOOM"))) && 
		this->keybindsTimes.at("ZOOM").getElapsedTime().asSeconds() >= this->keyTimeMax) {
		//ta drug pogoj sam preverja da ne spemas zooma
		this->keybindsTimes.at("ZOOM").restart();
		if (this->isZoomedOut) {
			//zoom in
			this->view.zoom(0.5f);
			this->player->setNewMaxVelocity(100.f);
		}
		else {
			//zoom out
			this->view.zoom(2.f);
			this->player->setNewMaxVelocity(140.f);
		}
		this->isZoomedOut = !this->isZoomedOut;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB1")))) {
		this->player->getInventory()->setSelectedHB(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB2")))) {
		this->player->getInventory()->setSelectedHB(1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB3")))) {
		this->player->getInventory()->setSelectedHB(2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB4")))) {
		this->player->getInventory()->setSelectedHB(3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB5")))) {
		this->player->getInventory()->setSelectedHB(4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB6")))) {
		this->player->getInventory()->setSelectedHB(5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB7")))) {
		this->player->getInventory()->setSelectedHB(6);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB8")))) {
		this->player->getInventory()->setSelectedHB(7);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB9")))) {
		this->player->getInventory()->setSelectedHB(8);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		if (this->player->getDamageTimer()) {
			if (!this->player->useItem) {
				//uporabi item
				if (this->iteminHand == "hoe")this->useHoe();
				else if (this->iteminHand == "carrotSeed")this->useCarrotSeed();
			}
		}
	}
}

void GameState::useHoe(){
	Item* item = this->player->getInventory()->getHBSelectedItem();
	Tool* tool = static_cast<Tool*>(item);
	if (this->playerGUI->getIsPlaceble() && !tool->getIsBrooken()) {
		//uporabi item ==============================
		this->player->useItem = true;
		//dobi id
		int id = 0;
		if (!this->buildings["farmland"].empty()) {
			auto zadn = this->buildings["farmland"].rbegin();
			id = zadn->first + 1;
		}
		//doda v mapo
		this->buildings["farmland"][id] = new Farmland(&this->textures["Farmland"], this->tileMap->getPosOfRectWithMousOver(this->mousePosView), sf::Vector2f(16.f, 16.f));
		//===========================================
		//mu odbije durability =====
		tool->damageDurability(2);
	}
}

void GameState::useCarrotSeed(){
	Item* item = this->player->getInventory()->getHBSelectedItem();
	Tool* tool = static_cast<Tool*>(item);
	if (this->playerGUI->getIsPlaceble() && !tool->getIsBrooken()) {
		//uporabi item ==============================
		//this->player->useItem = true;
		//dobi id
		int id = 0;
		if (!this->buildings["carrotPlant"].empty()) {
			auto zadn = this->buildings["carrotPlant"].rbegin();
			id = zadn->first + 1;
		}
		//doda v mapo
		this->buildings["carrotPlant"][id] = new CarrotPlant(&this->textures["CarrotPlant"], this->tileMap->getPosOfRectWithMousOver(this->mousePosView), sf::Vector2f(16.f, 16.f));
		//===========================================
		//mu odbije durability =====
		tool->damageDurability(1);
	}
}

void GameState::updatePlayerGUI(const float & dt){
	this->playerGUI->update(dt);
	Item* equipedItem = this->player->getInventory()->getHBSelectedItem();
	if (equipedItem != nullptr) {
		this->hasItemInHand = true;
		if (Hoe* temp = dynamic_cast<Hoe*>(equipedItem)) {
			//item je class hoe
			this->iteminHand = "hoe";
			this->player->itemInHand = this->iteminHand;
		}
		else {
			if (CarrotSeed* temp = dynamic_cast<CarrotSeed*>(equipedItem)) {
				this->iteminHand = "carrotSeed";
				this->player->itemInHand = this->iteminHand;
			}
			else {
				std::cout << "Dodelat gamestate usage" << std::endl;
			}
		}
	}
	else {
		this->hasItemInHand = false;
		this->player->itemInHand = "";
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("TOGGLE_PLAYER_TAB_CHARACTER"))) && this->getKeyTime()) {
		this->playerGUI->toggleCharacterTab();
	}*/
}

void GameState::updatePauseMenuButtons(){
	if (this->pmenu->isButtonPressed("RESUME")) {
		this->pmenu->makeSound("RESUME");
		this->unpauseState();
	}
	if (this->pmenu->isButtonPressed("SAVE")) {
		this->pmenu->makeSound("SAVE");
		this->save();
	}
	if (this->pmenu->isButtonPressed("QUIT")) {
		this->pmenu->makeSound("QUIT");
		this->save();
		while (true)if (this->pmenu->getStatus("QUIT") == 0)break;
		this->endState();
	}
}

void GameState::updateTileMap(const float & dt){
	this->tileMap->updateWorldBoundsCollision(this->player, dt); 
	this->tileMap->updateTileCollision(this->player, dt);
	//this->tileMap->updateTiles(this->player, dt, *this->enemySystem);
}

void GameState::updatePlayer(const float & dt){
	this->player->update(dt, this->mousePosView, this->view);
	if (this->player->getAttributeComponent()->isDead())
		this->endState();
}

void GameState::updateCombatAndEnemies(const float & dt){
	/* //NE TGA ZBRISAT ==============================================
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->getWeapon()->getAttackTimer())
		this->player->setInitAttack(true);

	unsigned index = 0;
	for (auto *enemy : this->activeEnemies){
		enemy->update(dt, this->mousePosView, this->view);

		this->tileMap->updateWorldBoundsCollision(enemy, dt);
		this->tileMap->updateTileCollision(enemy, dt);

	  this->updateCombat(enemy, index, dt);

		if (enemy->isDead()){
			this->player->gainEXP(enemy->getGainExp());
			this->tts->addTextTag(EXPERIENCE_TAG, this->player->getPosition().x - 40.f, this->player->getPosition().y - 30.f, static_cast<int>(enemy->getGainExp()), "+", "EXP");

			this->enemySystem->removeEnemy(index);
			continue;
		}
		else if (enemy->getDespawnTimerDone()){
			this->enemySystem->removeEnemy(index);
			continue;
		}

		++index;
	}

	this->player->setInitAttack(false);*/
}

void GameState::updateCombat(Enemy* enemy, const int index, const float & dt){
	/*
	if (this->player->getInitAttack()
	  && enemy->getGlobalBounds().contains(this->mousePosView)
		&& enemy->getSpriteDistance(*this->player) < this->player->getWeapon()->getRange() 
		&& enemy->getDamageTimerDone()){
		int dmg = static_cast<int>(this->player->getDamage());
		enemy->loseHP(dmg);
		enemy->resetDamageTimer();
		this->tts->addTextTag(DEFAULT_TAG, enemy->getPosition().x, enemy->getPosition().y, dmg, "", "");	
	}*/

	//Checka za enmy damage
	/*
	if (enemy->getGlobalBounds().intersects(this->player->getGlobalBounds()) && this->player->getDamageTimer()){
		int dmg = enemy->getAttributeComp()->damageMax;
		this->player->loseHP(dmg);
		this->tts->addTextTag(NEGATIVE_TAG, player->getPosition().x - 30.f, player->getPosition().y, dmg, "-", "HP");
	}*/
}

void GameState::updateDebugText(const float& dt){
	std::stringstream ss;

	ss << "Mouse Pos View: " << this->mousePosView.x << " " << this->mousePosView.y << "\n"
		<< "Active Enemies: " << 0 << "\n";//this->activeEnemies.size() << "\n";
	this->debugText.setString(ss.str());
}

void GameState::updateInGameTime(){
	this->updateHours_Minutes();
	if (this->isDay && this->inGameTime_Hours == this->whenIsNightHour) {
		//dan se je koncau torej bo zdej noc
		this->isDay = false;
	}
	if (!(this->isDay) && this->inGameTime_Hours == this->whenIsDayHour) {
		this->isDay = true;
	}
	if ((this->gameDaysElapsed % 45) == 0 && this->gameDaysElapsed != 0) {
		//resetira dneve
		this->gameDaysElapsed = 0;
		//spremeni letni cas
		if (static_cast<int>(this->currentSeason) == 4)this->currentSeason = pomlad;
		else this->currentSeason = static_cast<letniCasi>(static_cast<int>(this->currentSeason) + 1);
		//posodobi dolzine dneva in noci in se mapo
		switch (this->currentSeason) {
		case pomlad:
			this->whenIsNightHour = 18; 
			this->whenIsDayHour = 6;
			delete this->tileMap;
			this->tileMap = new TileMap("Config/text.slmp", "Resources/Images/Tiles/newFloorTiles_Pomlad.png");
			break;
		case poletje:
			this->whenIsNightHour = 19; 
			this->whenIsDayHour = 5;
			delete this->tileMap;
			this->tileMap = new TileMap("Config/text.slmp", "Resources/Images/Tiles/newFloorTiles_Poletje.png");
			break;
		case jesen:
			this->whenIsNightHour = 18; 
			this->whenIsDayHour = 6;
			delete this->tileMap;
			this->tileMap = new TileMap("Config/text.slmp", "Resources/Images/Tiles/newFloorTiles_Jesen.png");
			break;
		case zima:
			this->whenIsNightHour = 17; 
			this->whenIsDayHour = 7; 
			delete this->tileMap;
			this->tileMap = new TileMap("Config/text.slmp", "Resources/Images/Tiles/newFloorTiles_Zima.png");
			break;
		}
	}
	this->playerGUI->updateClockDisplay(this->inGameTime_Hours, this->inGameTime_Minutes);
	this->playerGUI->updateSeasonDisplay(static_cast<int>(this->currentSeason));
	this->playerGUI->updateGameTimeDay(this->gameDaysElapsed);
}

void GameState::updateBuildingsColl(const float& dt){
	for (const auto& pair : this->buildings) {
		for (const auto& value : pair.second) {
			value.second->checkCollisionPlayer(this->player, dt);
		}
	}
}

void GameState::updateBuildings(){
	for (const auto& pair : this->buildings) {
		for (const auto& value : pair.second) {
			value.second->update();
		}
	}
}

void GameState::update(const float& dt){
	this->updateMousePositions(&this->view);
	this->updateKeytime(dt);
	this->updateInput(dt);
	//this->updateDebugText(dt); //DEBUG
	if (!this->paused){ //Unpausan update
		this->updateView(dt);

		this->updatePlayerInput(dt);

		this->updateTileMap(dt);

		//buildings
		this->updateBuildingsColl(dt);
		this->updateBuildings();

		this->updatePlayer(dt);

		this->updatePlayerGUI(dt);

		//Updata vse enemye
		//this->updateCombatAndEnemies(dt);

		//Updata systeme
		this->tts->update(dt);

		//updata inGametime
		this->updateInGameTime();


		//Items DEBUG =======================================

		if (this->hasItemInHand) {
			sf::Texture* possibleIcon = nullptr;
			std::string buildingType = "";
			if (this->iteminHand == "hoe") {
				possibleIcon = &this->textures["Farmland"];
				buildingType = "farmland";
			}
			if (this->iteminHand == "carrotSeed") {
				possibleIcon = &this->textures["CarrotPlantPosible"];
				buildingType = "farmland";
			}
			this->playerGUI->updateItemPossibles(this->mousePosView, this->tileMap, possibleIcon, this->iteminHand,&this->buildings[buildingType]);
		}

		//===================================================

	}
	else{ //Pausan update
		if (!this->isInventoryOpen) {
			this->pmenu->update(this->mousePosWindow, dt);
			this->updatePauseMenuButtons();
		}
		else {
			//this->player->getInventory()->updateINV();
			this->playerGUI->updateINV(this->mousePosWindow);
		}
	}
}

void GameState::render(sf::RenderTarget* target){
	if (!target)
		target = this->window;

	this->renderTexture.clear();

	this->renderTexture.setView(this->view);

	this->tileMap->render(
		this->renderTexture, 
		this->viewGridPosition, 
		this->isDay ? &this->temp : &this->core_shader,
		this->player->getCenter(),
		false, this->isZoomedOut
	);

	/*for (auto* enemy : this->activeEnemies) {
		enemy->render(this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter(), true);
	}*/

	this->tileMap->renderDeferred(this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());

	//buildings =======================================

	for (const auto& value : this->buildings["farmland"]) {
		value.second->render(&this->renderTexture);
	}
	for (const auto& value : this->buildings["carrotPlant"]) {
		value.second->render(&this->renderTexture);
	}

	//==============================================

	//Items DEBUG =======================================

	if (this->hasItemInHand) {
		this->playerGUI->renderItemPossibles(this->renderTexture);
	}

	//===================================================


	this->player->render(this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter(), false); // ta zadna je za rendiranje hitboxa k je debug sam

	this->tts->render(this->renderTexture);

	//Rendera GUI
	this->renderTexture.setView(this->renderTexture.getDefaultView());
	this->playerGUI->render(this->renderTexture);

	if (this->isInventoryOpen) {
		//this->player->getInventory()->renderINV(this->renderTexture);
		this->playerGUI->renderINV(this->renderTexture);
	}
	
	if (this->paused && !this->isInventoryOpen){
		//this->renderTexture.setView(this->renderTexture.getDefaultView());
		this->pmenu->render(this->renderTexture);
	}

	//Debug tekst
	//this->renderTexture.draw(this->debugText);

	//Koncni render
	this->renderTexture.display();
	//this->renderSprite.setTexture(this->renderTexture.getTexture());
	target->draw(this->renderSprite);


}