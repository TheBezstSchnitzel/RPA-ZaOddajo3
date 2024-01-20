#include "stdafx.h"
#include "GameState.h"
#include "Game.h"
#include <filesystem>

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
}

void GameState::initKeybinds(){
	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open()){
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2){
			this->keybinds[key] = this->supportedKeys->at(key2);
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
	if (!this->textures["PLAYER_SHEET"].loadFromFile("Resources/Images/Sprites/Player/PLAYER_SHEET2.png")){
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
	}

	if(!this->textures["RAT1_SHEET"].loadFromFile("Resources/Images/Sprites/Enemy/rat1_60x64.png")){
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_RAT1_TEXTURE";
	}

	if (!this->textures["BIRD1_SHEET"].loadFromFile("Resources/Images/Sprites/Enemy/bird1_61x57.png")){
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_BIRD1_TEXTURE";
	}
}

void GameState::initPauseMenu(){
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
	this->pmenu = new PauseMenu(this->stateData->gfxSettings->resolution, this->font);

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

void GameState::initPlayers() {
	//novo shranjevanje ================================================
	//std::filesystem::path savefilePathPlayer = this->savePath + "/player/player.txt";
	//preveri ce ze sploh obstaja save
	if (false){//std::filesystem::exists(savefilePathPlayer)) {
		/* //DEBUG
		//save ze obstaja
		std::ifstream saveFile;
		saveFile.open(this->savePath, std::ios::in);
		if (saveFile.is_open()) {
			saveFile.read((char*)&this->player, sizeof(Player));
		}
		else std::cout << "Nalaganje iz save ne dela" << std::endl; */
	}
	else {
		//save se ne obstaja
		this->player = new Player(300, 220, this->textures["PLAYER_SHEET"]);
		std::cout << "File does not exist." << std::endl;
	}
}

void GameState::initPlayerGUI(){
	this->playerGUI = new PlayerGUI(this->player, this->stateData->gfxSettings->resolution);
}

void GameState::initEnemySystem(){
	this->enemySystem = new EnemySystem(this->activeEnemies, this->textures, *this->player);
}

void GameState::initTileMap(){
	this->tileMap = new TileMap("text.slmp");
}

void GameState::initSystems(){
	this->tts = new TextTagSystem("Fonts/PixellettersFull.ttf");
}

void GameState::initInGameTime(){
	this->isDay = true;
	this->gameDaysElapsed = 0;
	this->currentSeason = pomlad;
}

void GameState::initInGameTimers(){
	this->dayTimerMax = 1.f;
	this->nightTimerMax = 0.5f;
	this->dayTimer.restart();
	this->nightTimer.restart();
}

void GameState::loadFromSave(){
	//klièe vse funkcije za loudanje iz save
}

void GameState::save(){
	//klièe vse funkcije za shranjevanje
}

//Konstruktor / destruktor
GameState::GameState(StateData* state_data,Game*game, unsigned short save) : State(state_data){
	//novo shranjevanje ================================================
	this->savePath = "Saves/save" + std::to_string(save);
	this->game = game;
	std::filesystem::path savefilePathPlayer = this->savePath + "/player/player.txt";
	//preveri ce ze sploh obstaja save
	if (false){//std::filesystem::exists(savefilePathPlayer)) {
		/* //DEBUG
		//save ze obstaja
		std::ifstream saveFile;
		saveFile.open(this->savePath, std::ios::in);
		if (saveFile.is_open()) {
			saveFile.read((char*)&this->player, sizeof(Player));
		}
		else std::cout << "Nalaganje iz save ne dela" << std::endl; */
		std::cout << "File exists" << std::endl;
		this->loadFromSave();
	}
	else {
		//save se ne obstaja
		std::cout << "File does not exist." << std::endl;
		this->initPlayers();
		this->initInGameTime();
	}
	//te se u sakmu primeru na novo kreairajo
	this->initDeferredRender();
	this->initView();
	this->initKeybinds();
	this->initFonts();
	this->initTextures();
	this->initPauseMenu();
	//this->initShaders();
	//this->initDebugText(); // DEBUG
	this->initKeyTime();
	this->initPlayerGUI();
	this->initEnemySystem();
	this->initTileMap();
	this->initInGameTimers();
	this->initSystems();
	/*
	this->theme.openFromFile("Resources/Audio/themeSong2.wav");
	this->theme.setPitch(1.f);
	this->theme.setVolume(40.f);
	this->theme.setLoop(true);
	this->theme.play();*/
}

GameState::~GameState(){
	delete this->pmenu;
	delete this->player;
	delete this->playerGUI;
	delete this->enemySystem;
	delete this->tileMap;
	delete this->tts;
	this->game->playTheme(true);
	for (size_t i = 0; i < this->activeEnemies.size(); i++){
		delete this->activeEnemies[i];
	}
	this->theme.stop();
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime()){
		if (!this->paused)
			this->pauseState();
		else
			this->unpauseState();
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
}

void GameState::updatePlayerGUI(const float & dt){
	this->playerGUI->update(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("TOGGLE_PLAYER_TAB_CHARACTER"))) && this->getKeyTime()){
		this->playerGUI->toggleCharacterTab();
	}
}

void GameState::updatePauseMenuButtons(){
	if (this->pmenu->isButtonPressed("SAVE")) {
		this->save();
	}
	if (this->pmenu->isButtonPressed("QUIT")) {
		this->save();
		this->endState();
	}
}

void GameState::updateTileMap(const float & dt){
	this->tileMap->updateWorldBoundsCollision(this->player, dt); 
	this->tileMap->updateTileCollision(this->player, dt);
	this->tileMap->updateTiles(this->player, dt, *this->enemySystem);
}

void GameState::updatePlayer(const float & dt){
	this->player->update(dt, this->mousePosView, this->view);
	if (this->player->getAttributeComponent()->isDead())
		this->endState();
}

void GameState::updateCombatAndEnemies(const float & dt){
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

	this->player->setInitAttack(false);
}

void GameState::updateCombat(Enemy* enemy, const int index, const float & dt){
	if (this->player->getInitAttack()
	  && enemy->getGlobalBounds().contains(this->mousePosView)
		&& enemy->getSpriteDistance(*this->player) < this->player->getWeapon()->getRange() 
		&& enemy->getDamageTimerDone()){
		int dmg = static_cast<int>(this->player->getDamage());
		enemy->loseHP(dmg);
		enemy->resetDamageTimer();
		this->tts->addTextTag(DEFAULT_TAG, enemy->getPosition().x, enemy->getPosition().y, dmg, "", "");	
	}

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
	<< "Active Enemies: " << this->activeEnemies.size() << "\n";

	this->debugText.setString(ss.str());
}

void GameState::updateInGameTime(){
	if (this->isDay) { //ce je dan
		if (floor(this->dayTimer.getElapsedTime().asSeconds()*100/60)/100 >= this->dayTimerMax) {
			//cas za dan je pretuku je treba spremenit v noc
			this->isDay = false;
			this->nightTimer.restart();
			std::cout << "spreminjam v noc" << std::endl; //DEBUG
		}
	}
	else { // ce je noc
		if (floor(this->nightTimer.getElapsedTime().asSeconds()*100/60)/100 >= this->nightTimerMax) {
			//cas za noc je poteku je treba sprement v dan
			this->isDay = true;
			this->dayTimer.restart();
			this->gameDaysElapsed++;
			std::cout << "spreminjam v dan, to je dan : " << this->gameDaysElapsed+1 << std::endl; //DEBUG
			if (this->gameDaysElapsed % 20 == 0 && this->gameDaysElapsed != 0) {
				if (static_cast<int>(this->currentSeason) == 4)this->currentSeason = pomlad;
				else this->currentSeason = static_cast<letniCasi>(static_cast<int>(this->currentSeason) + 1);
				std::cout << "Spreminjam letni cas v : " << this->currentSeason << std::endl;
			}
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

		this->updatePlayer(dt);

		this->updatePlayerGUI(dt);

		//Updata vse enemye
		this->updateCombatAndEnemies(dt);

		//Updata systeme
		this->tts->update(dt);

		//updata inGametime
		this->updateInGameTime();
	}
	else{ //Pausan update
		this->pmenu->update(this->mousePosWindow);
		this->updatePauseMenuButtons();
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
		&this->core_shader,
		this->player->getCenter(),
		false
	);

	for (auto *enemy : this->activeEnemies){
		enemy->render(this->renderTexture, &this->core_shader, this->player->getCenter(), true);
	}

	this->player->render(this->renderTexture, &this->core_shader, this->player->getCenter(), true);

	this->tileMap->renderDeferred(this->renderTexture, &this->core_shader, this->player->getCenter());

	this->tts->render(this->renderTexture);

	//Rendera GUI
	this->renderTexture.setView(this->renderTexture.getDefaultView());
	this->playerGUI->render(this->renderTexture);

	if (this->paused){ 
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