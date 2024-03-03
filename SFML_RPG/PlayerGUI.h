#pragma once

#include "PlayerGUITabs.h"
#include "Inventory.h"
#include "TileMap.h"
#include "Building.h"

class PlayerGUI{
private:
	struct InventorySlot {
		bool isHovered;
		bool isSelected;
		bool isFull;
		bool lastMouseState;
		int inventoryID;
		sf::RectangleShape shape;
		bool hasDurability;
		sf::Text durability;
	};
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
	bool mouseHasItem;
	int idMouseItem;
	sf::RectangleShape mouseRect;
	sf::Vector2f mouseOffset;
	sf::RectangleShape inventoryRect;
	sf::Texture inventoryText;
	InventorySlot inventorySlots[4][9];
	
	sf::Text moneySlot;

	//items ==============================================================
	sf::RectangleShape possible;
	bool isPlaceble;

	void initPossible(sf::VideoMode& vm);

	void initMousRect(sf::VideoMode& vm);
	void initINVSlots(sf::VideoMode& vm, sf::Font& font);
	void initMoneySlot(sf::VideoMode& vm, sf::Font &font);
	void initINV(sf::VideoMode& vm, sf::Font &font);

	void swapINVPlace(int from, int to);

	void updateMousRect(const sf::Vector2i& mousePosWindow);
	void updateINVSlots(const sf::Vector2i& mousePosWindow);

	void renderINVSlots(sf::RenderTarget& target);
	void renderMoney(sf::RenderTarget& target);
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
	PlayerGUI(Player* player, sf::VideoMode& vm, sf::Font &font);
	virtual ~PlayerGUI();

	//Dostop
	const bool getTabsOpen() const;
	void toggleCharacterTab();
	bool getIsPlaceble();

	//Funkcije
	void updateLevelBar();
	void updateEXPBar();
	void updateHPBar();
	void updatePlayerTabs();
	void updateClockDisplay(int hour,int minute);
	void updateSeasonDisplay(short unsigned seasonNum);
	void updateGameTimeDay(int daysElapsed);
	void updateHB();
	void updateINV(const sf::Vector2i& mousePosWindow);

	void update(const float& dt);

	void renderLevelBar(sf::RenderTarget & target);
	void renderEXPBar(sf::RenderTarget & target);
	void renderHPBar(sf::RenderTarget & target);
	void renderPlayerTabs(sf::RenderTarget& target);
	void renderGameClock(sf::RenderTarget& target);
	void renderHB(sf::RenderTarget& target);
	void renderINV(sf::RenderTarget& target);

	void render(sf::RenderTarget& target);


	//tools
	void updateItemPossibles(const sf::Vector2f& mousePosWindow, TileMap* map, sf::Texture* texture, std::string item, std::map<std::string, std::map<int, Building*>>* buildings);
	void renderItemPossibles(sf::RenderTarget& target);
};

