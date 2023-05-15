#pragma once

#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"
#include "PlayerGUI.h"
#include "Sword.h"
#include "Bow.h"
#include "TextTagSystem.h"

class Game;

class GameState : public State{
private:
	Game* game;
	std::string savePath;

	sf::View view;
	sf::Vector2i viewGridPosition;
	sf::RenderTexture renderTexture;
	sf::Sprite renderSprite;

	sf::Font font;
	PauseMenu* pmenu;

	sf::Shader core_shader;

	sf::Clock keyTimer;
	float keyTimeMax;

	sf::Text debugText;

	Player* player;
	PlayerGUI* playerGUI;
	sf::Texture texture;
	
	std::vector<Enemy*> activeEnemies;
	EnemySystem *enemySystem;

	TileMap* tileMap;

	//Tematska pesem
	sf::Music theme;

	//Sistemi
	TextTagSystem* tts;

	//Privatne funkcije
	//inicializacija
	void initDeferredRender();
	void initView();
	void initKeybinds();
	void initFonts();
	void initTextures();
	void initPauseMenu();
	void initShaders();
	void initKeyTime();
	void initDebugText();

	void initPlayers();
	void initPlayerGUI();
	void initEnemySystem();
	void initTileMap();
	void initSystems();

public:
	GameState(StateData* state_data, Game* game, unsigned short save);
	virtual ~GameState();

	//Dostop
	const bool getKeyTime();

	//Funkcije
	void updateView(const float& dt);
	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void updatePlayerGUI(const float& dt);
	void updatePauseMenuButtons();
	void updateTileMap(const float& dt);
	void updatePlayer(const float& dt);
	void updateCombatAndEnemies(const float& dt);
	void updateCombat(Enemy* enemy, const int index, const float& dt);
	void updateDebugText(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget* target = NULL);
};