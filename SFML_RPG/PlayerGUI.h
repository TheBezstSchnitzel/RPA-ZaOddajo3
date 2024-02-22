#pragma once

#include "PlayerGUITabs.h"
#include "Inventory.h"

class PlayerGUI{
private:
	Player* player;

	sf::VideoMode& vm;
	sf::Font font;

	//Level bar
	std::string levelBarString;
	sf::Text levelBarText;
	sf::RectangleShape levelBarBack;

	//EXP Bar
	gui::ProgressBar* expBar;

	//HP Bar
	gui::ProgressBar* hpBar;

	//Player GUI
	PlayerGUITabs* playerTabs;

	//inGameTime Display ======================================
	
	//Ura in minute
	sf::RectangleShape gameTimeDisplay;
	sf::Texture gameTimeDisplay_Texture;
	//inGameTime Numbers
	//ure
	sf::RectangleShape gameTimeNum_Hour;
	sf::IntRect gameTimeNum_Hour_TexRect;
	//minute
	sf::RectangleShape gameTimeNum_Minute;
	sf::IntRect gameTimeNum_Minute_TexRect;
	//tekstura
	sf::Texture gameTimeNum_Texture;

	//letni cas
	sf::Text currSeason;

	//dnevi
	sf::RectangleShape gameTimeDayText;
	sf::Texture gameTimeDayText_Texture;
	sf::RectangleShape gameTimeDay;
	sf::IntRect gameTimeDay_TexRect;
	
	//hotbar(GUI) =======================================================
	sf::RectangleShape hotbarRect;
	sf::Texture hotbarText;
	
	sf::RectangleShape hotbarRectSelected;
	sf::Texture hotbarTextSelected;

	void initHB(sf::VideoMode& vm);

	//inventory(GUI) ====================================================
	sf::RectangleShape inventoryRect;
	sf::Texture inventoryText;

	void initINV(sf::VideoMode& vm);

	//inicializacija
	void initFont();
	void initTextures();
	void initLevelBar();
	void initEXPBar();
	void initHPBar();
	void initPlayerTabs(sf::VideoMode &vm, sf::Font &font, Player &player);
	void initGameClockDisplay(sf::VideoMode& vm);
	void initGameClockNumbers(sf::VideoMode& vm);
	void initGameSeasonDisplay(sf::VideoMode& vm);
	void initGameDayDisplay(sf::VideoMode& vm);

public:
	PlayerGUI(Player* player, sf::VideoMode& vm);
	virtual ~PlayerGUI();

	//Dostop
	const bool getTabsOpen() const;
	void toggleCharacterTab();

	//Funkcije
	void updateLevelBar();
	void updateEXPBar();
	void updateHPBar();
	void updatePlayerTabs();
	void updateClockDisplay(int hour,int minute);
	void updateSeasonDisplay(short unsigned seasonNum);
	void updateGameTimeDay(int daysElapsed);
	void updateHB(Inventory* inventory);
	void updateINV();

	void update(const float& dt, Inventory* inventory);

	void renderLevelBar(sf::RenderTarget & target);
	void renderEXPBar(sf::RenderTarget & target);
	void renderHPBar(sf::RenderTarget & target);
	void renderPlayerTabs(sf::RenderTarget& target);
	void renderGameClock(sf::RenderTarget& target);
	void renderHB(sf::RenderTarget& target);
	void renderINV(sf::RenderTarget& target);

	void render(sf::RenderTarget& target);
};

