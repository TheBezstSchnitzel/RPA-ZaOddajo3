#include "stdafx.h"
#include "PlayerGUI.h"

void PlayerGUI::initShopTextures(){
	if (!this->shopBasicTexture.loadFromFile("Resources/Images/Gui/shopBasic.png", sf::IntRect(sf::Vector2i(0, 3), sf::Vector2i(210, 124)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_ShopBasic_TEXTURE";
	}
	if (!this->shopPlantsSite.loadFromFile("Resources/Images/Gui/shopMenu_plants.png", sf::IntRect(sf::Vector2i(0, 3), sf::Vector2i(210, 124)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_shopPlants_TEXTURE";
	}
	if (!this->shopToolsSite.loadFromFile("Resources/Images/Gui/shopMenu_tools.png", sf::IntRect(sf::Vector2i(0, 3), sf::Vector2i(210, 124)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_shopPlants_TEXTURE";
	}
	if (!this->shopBuildingPlansSite.loadFromFile("Resources/Images/Gui/shopMenu_BuildingPlans.png", sf::IntRect(sf::Vector2i(0, 3), sf::Vector2i(210, 124)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_shopBPs_TEXTURE";
	}
}

void PlayerGUI::initButtons(){
	this->buttonsShop["DownSlide"] = new gui::Button(
		gui::p2pX(28.5f, vm), gui::p2pY(13.f, vm),
		gui::p2pX(4.2f, vm), gui::p2pY(9.4f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 0), sf::Color(255, 255, 255, 0), sf::Color(20, 20, 20, 0),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
	);
	this->buttonsShop["UpSlide"] = new gui::Button(
		gui::p2pX(67.f, vm), gui::p2pY(13.f, vm),
		gui::p2pX(4.2f, vm), gui::p2pY(9.4f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
	);
	this->buttonsShop["Plus1"] = new gui::Button(
		gui::p2pX(30.9f, vm), gui::p2pY(31.9f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red,sf::Color::Red
	);
	this->buttonsShop["Plus2"] = new gui::Button(
		gui::p2pX(30.9f, vm), gui::p2pY(43.8f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Plus3"] = new gui::Button(
		gui::p2pX(30.9f, vm), gui::p2pY(56.3f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Plus4"] = new gui::Button(
		gui::p2pX(55.8f, vm), gui::p2pY(31.9f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Plus5"] = new gui::Button(
		gui::p2pX(55.8f, vm), gui::p2pY(43.8f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Plus6"] = new gui::Button(
		gui::p2pX(55.8f, vm), gui::p2pY(56.3f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Minus1"] = new gui::Button(
		gui::p2pX(38.8f, vm), gui::p2pY(31.9f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Minus2"] = new gui::Button(
		gui::p2pX(38.8f, vm), gui::p2pY(43.8f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Minus3"] = new gui::Button(
		gui::p2pX(38.8f, vm), gui::p2pY(56.3f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Minus4"] = new gui::Button(
		gui::p2pX(63.6f, vm), gui::p2pY(31.9f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Minus5"] = new gui::Button(
		gui::p2pX(63.6f, vm), gui::p2pY(43.8f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Minus6"] = new gui::Button(
		gui::p2pX(63.6f, vm), gui::p2pY(56.3f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Buy1"] = new gui::Button(
		gui::p2pX(41.3f, vm), gui::p2pY(29.3f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Sell1"] = new gui::Button(
		gui::p2pX(41.3f, vm), gui::p2pY(33.9f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Buy2"] = new gui::Button(
		gui::p2pX(41.3f, vm), gui::p2pY(41.3f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Sell2"] = new gui::Button(
		gui::p2pX(41.3f, vm), gui::p2pY(45.9f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Buy3"] = new gui::Button(
		gui::p2pX(41.3f, vm), gui::p2pY(54.1f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Sell3"] = new gui::Button(
		gui::p2pX(41.3f, vm), gui::p2pY(58.7f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Buy4"] = new gui::Button(
		gui::p2pX(66.3f, vm), gui::p2pY(29.3f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Sell4"] = new gui::Button(
		gui::p2pX(66.3f, vm), gui::p2pY(33.9f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Buy5"] = new gui::Button(
		gui::p2pX(66.3f, vm), gui::p2pY(41.3f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Sell5"] = new gui::Button(
		gui::p2pX(66.3f, vm), gui::p2pY(45.9f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Buy6"] = new gui::Button(
		gui::p2pX(66.3f, vm), gui::p2pY(54.1f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Sell6"] = new gui::Button(
		gui::p2pX(66.3f, vm), gui::p2pY(58.7f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	//66.3f
}

void PlayerGUI::initTexts(sf::VideoMode& vm, sf::Font& font){
	this->texts["Amount1"].setCharacterSize(gui::calcCharSize(vm, 45U));
	this->texts["Amount1"].setPosition(sf::Vector2f(gui::p2pX(34.f,vm), gui::p2pY(29.8f,vm)));
	this->texts["Amount1"].setFont(font);
	this->texts["Amount1"].setFillColor(sf::Color::White);
	this->texts["Amount1"].setString("00");
	this->texts["Amount1"].setStyle(sf::Text::Bold);

	this->texts["Amount2"].setCharacterSize(gui::calcCharSize(vm, 45U));
	this->texts["Amount2"].setPosition(sf::Vector2f(gui::p2pX(34.f, vm), gui::p2pY(41.8f, vm)));
	this->texts["Amount2"].setFont(font);
	this->texts["Amount2"].setFillColor(sf::Color::White);
	this->texts["Amount2"].setString("00");
	this->texts["Amount2"].setStyle(sf::Text::Bold);

	this->texts["Amount3"].setCharacterSize(gui::calcCharSize(vm, 45U));
	this->texts["Amount3"].setPosition(sf::Vector2f(gui::p2pX(34.f, vm), gui::p2pY(54.5f, vm)));
	this->texts["Amount3"].setFont(font);
	this->texts["Amount3"].setFillColor(sf::Color::White);
	this->texts["Amount3"].setString("00");
	this->texts["Amount3"].setStyle(sf::Text::Bold);

	this->texts["Amount4"].setCharacterSize(gui::calcCharSize(vm, 45U));
	this->texts["Amount4"].setPosition(sf::Vector2f(gui::p2pX(59.f, vm), gui::p2pY(29.8f, vm)));
	this->texts["Amount4"].setFont(font);
	this->texts["Amount4"].setFillColor(sf::Color::White);
	this->texts["Amount4"].setString("00");
	this->texts["Amount4"].setStyle(sf::Text::Bold);

	this->texts["Amount5"].setCharacterSize(gui::calcCharSize(vm, 45U));
	this->texts["Amount5"].setPosition(sf::Vector2f(gui::p2pX(59.f, vm), gui::p2pY(41.8f, vm)));
	this->texts["Amount5"].setFont(font);
	this->texts["Amount5"].setFillColor(sf::Color::White);
	this->texts["Amount5"].setString("00");
	this->texts["Amount5"].setStyle(sf::Text::Bold);

	this->texts["Amount6"].setCharacterSize(gui::calcCharSize(vm, 45U));
	this->texts["Amount6"].setPosition(sf::Vector2f(gui::p2pX(59.f, vm), gui::p2pY(54.5f, vm)));
	this->texts["Amount6"].setFont(font);
	this->texts["Amount6"].setFillColor(sf::Color::White);
	this->texts["Amount6"].setString("00");
	this->texts["Amount6"].setStyle(sf::Text::Bold);

	this->texts["Price1"].setCharacterSize(gui::calcCharSize(vm, 100U));
	this->texts["Price1"].setPosition(sf::Vector2f(gui::p2pX(47.f, vm), gui::p2pY(31.8f, vm)));
	this->texts["Price1"].setFont(font);
	this->texts["Price1"].setFillColor(sf::Color::White);
	this->texts["Price1"].setString("00");
	this->texts["Price1"].setStyle(sf::Text::Bold);
}

void PlayerGUI::initShop(sf::VideoMode& vm, sf::Font& font){
	this->initShopTextures();
	this->basicShopRect.setFillColor(sf::Color::White);
	this->basicShopRect.setTexture(&this->shopBasicTexture);
	this->basicShopRect.setSize(sf::Vector2f(gui::p2pX(55.f, vm), gui::p2pY(60.f, vm)));
	this->basicShopRect.setPosition(sf::Vector2f(gui::p2pX(22.5f,vm), gui::p2pY(10.f,vm)));
	this->currShopSite = Plants;
	this->initButtons();
	this->siteShopRect = sf::RectangleShape(this->basicShopRect);
	this->initTexts(vm,font);
}

void PlayerGUI::resetTexts(){
	this->texts["Amount1"].setString("00");
	this->texts["Amount2"].setString("00");
	this->texts["Amount3"].setString("00");
	this->texts["Amount4"].setString("00");
	this->texts["Amount5"].setString("00");
	this->texts["Amount6"].setString("00");
}

std::string PlayerGUI::addOne(std::string id){
	//std::string temp = this->texts[id].getString().toAnsiString();
	int i = std::stoi(this->texts[id].getString().toAnsiString());
	//int i = std::stoi(temp);
	std::string temp = "";
	if(i != 60)i++;
	if (i < 10) {
		temp = "0" + std::to_string(i);
	}
	else temp = std::to_string(i);
	return temp;
}

std::string PlayerGUI::removeOne(std::string id){
	int i = std::stoi(this->texts[id].getString().toAnsiString());
	std::string temp = "";
	if (i != 0)i--;
	if (i < 10) {
		temp = "0" + std::to_string(i);
	}
	else temp = std::to_string(i);
	return temp;
}

bool PlayerGUI::buy(std::string what, int amount, int price){
	if (this->player->getInventory()->hasEnoughMoney(price)) {
		this->player->getInventory()->takeMoney(price);
		int id = 0;
		int a = amount;
		if (what == "Carrot") {
			std::map<int, Item*>& carrots = (*this->items)[what];
			if (!carrots.empty()) {
				for (const auto& value : carrots) {
					if (Carrot* carr = static_cast<Carrot*>(value.second)) {
						if (!carr->isFull()) {
							a = carr->addAmount(a);
							if (a == 0)break;
						}
					}
					id++;
				}
			}
			if (a != 0) {
				if (what == "Carrot") {
					this->items->at("Carrot")[id] = new Carrot(&this->textures->at("carrot"), a);
					this->player->getInventory()->add(this->items->at("Carrot")[id]);
				}
			}
		}
		return true;
	}
	return false;
}

bool PlayerGUI::sell(std::string what, int amount, int price){
	//checka ce ma player zadost teh itemou
	int a = amount;
	int has = 0;
	if (what == "Carrot") {
		Inventory* inv = this->player->getInventory();
		for (int i = 0; i < inv->maxSize(); i++) {
			if (inv->hasItem(i)) {
				if (Carrot* carrot = static_cast<Carrot*>(inv->getItem(i))) {
					has += carrot->getAmount();
					if (has >= a)break;
				}
			}
		}
		if (has >= a) {
			for (int i = 0; i < inv->maxSize(); i++) {
				if(inv->hasItem(i)) {
					if (Carrot* carrot = static_cast<Carrot*>(inv->getItem(i))) {
						a = carrot->removeAmount(a);
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
				}
			}
		}
		else return false;
	}
	return false;
}

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
	if (!this->gameTimeDayText_Texture.loadFromFile("Resources/Images/Gui/daySign.png")) {
		throw "ERROR::PLAYERGUI::COULD_NOT_LOAD_TIMEDISPLAYDAYTEXT_TEXTURE";
	}
	//hotbar
	if (!this->hotbarText.loadFromFile("Resources/Images/Gui/hotbar_Layer0.png")) {
		throw "ERROR::PLAYERGUI::COULD_NOT_LOAD_HOTBAR_TEXTURE";
	}
	if (!this->hotbarTextSelected.loadFromFile("Resources/Images/Gui/hotbar_Layer1.png")) {
		throw "ERROR::PLAYERGUI::COULD_NOT_LOAD_HOTBAR_TEXTURE";
	}
	//inventory
	if (!this->inventoryText.loadFromFile("Resources/Images/Gui/inventory.png")) {
		throw "ERROR::PLAYERGUI::COULD_NOT_LOAD_INVENTORY_TEXTURE";
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
	//this->gameTimeDisplay.setOutlineColor(sf::Color::Red);
	//this->gameTimeDisplay.setOutlineThickness(1.f);
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

void PlayerGUI::initGameSeasonDisplay(sf::VideoMode& vm){
	this->currSeason.setFont(this->font);
	this->currSeason.setCharacterSize(gui::calcCharSize(vm,120));
	this->currSeason.setString("Pomlad");
	this->currSeason.setPosition(sf::Vector2f(gui::p2pX(91.5f, vm), gui::p2pY(14.8f, vm)));
	this->currSeason.setColor(sf::Color(80,62,54,255));
	this->currSeason.setStyle(1);
}

void PlayerGUI::initGameDayDisplay(sf::VideoMode& vm){
	//Display
	//this->gameTimeDay.setOutlineColor(sf::Color::Blue);
	//this->gameTimeDay.setOutlineThickness(1.f);
	this->gameTimeDay.setSize(sf::Vector2f(gui::p2pX(2.5f, vm), gui::p2pY(2.6f, vm)));
	this->gameTimeDay.setPosition(gui::p2pX(93.5f, vm), gui::p2pY(3.55f, vm));
	//texture Rect
	this->gameTimeDay_TexRect.width = 16;
	this->gameTimeDay_TexRect.height = 9;
	this->gameTimeDay_TexRect.left = 0;
	this->gameTimeDay_TexRect.top = 0;
	//Textur gor
	this->gameTimeDay.setTexture(&this->gameTimeNum_Texture);
	this->gameTimeDay.setTextureRect(this->gameTimeDay_TexRect);

	//day text
	this->gameTimeDayText.setSize(sf::Vector2f(gui::p2pX(2.5f, vm), gui::p2pY(2.7f, vm)));
	this->gameTimeDayText.setPosition(gui::p2pX(90.f, vm), gui::p2pY(3.55f, vm));
	this->gameTimeDayText.setTexture(&this->gameTimeDayText_Texture);
}

void PlayerGUI::initHB(sf::VideoMode& vm){
	this->hotbarRect.setSize(
		sf::Vector2f(
			gui::p2pX(50.f, vm),
			gui::p2pY(11.f, vm)
		)
	);
	this->hotbarRect.setPosition(
		sf::Vector2f(
			gui::p2pX(25.f, vm),
			gui::p2pY(86.f, vm)
		)
	);
	this->hotbarRect.setTexture(&this->hotbarText);
	this->hotbarRectSelected = sf::RectangleShape(this->hotbarRect);
	this->hotbarRectSelected.setTexture(&this->hotbarTextSelected);
}

void PlayerGUI::initPossible(sf::VideoMode& vm){
	this->possible.setFillColor(sf::Color(255,255,255,150));
	this->possible.setPosition(sf::Vector2f(0.f, 0.f));
	this->possible.setSize(sf::Vector2f(16.f, 16.f));
	this->possible.setOutlineColor(sf::Color::Green);
	this->possible.setOutlineThickness(0.5f);
	this->isPlaceble = false;
}

void PlayerGUI::initMousRect(sf::VideoMode& vm){
	this->mouseHasItem = false;
	this->mouseRect.setFillColor(sf::Color::Transparent);
	//this->mouseRect.setOutlineThickness(1.f);
	//this->mouseRect.setOutlineColor(sf::Color::Red);
	this->mouseRect.setSize(sf::Vector2f(gui::p2pX(4.1f, vm), gui::p2pY(7.1f, vm)));
	//mouseoff
	this->mouseOffset.x = 0;
	this->mouseOffset.y = 0;
}

void PlayerGUI::initINVSlots(sf::VideoMode& vm, sf::Font& font) {
	//inventory
	float width = 4.1f;
	float height = 7.1f;
	float x = 26.f;
	float y = 32.f;
	float offsetX = width + 1.4f;
	float offsetY = height + 3.5f;
	int tmpID = 0;
	for (int j = 0; j < 3; j++) {
		if (j != 0)y += offsetY;
		for (int i = 0; i < 9; i++) {
			if (i != 0)x += offsetX;
			this->inventorySlots[j][i].isHovered = false;
			this->inventorySlots[j][i].isSelected = false;
			this->inventorySlots[j][i].isFull = false;
			this->inventorySlots[j][i].lastMouseState = false;
			this->inventorySlots[j][i].inventoryID = tmpID;
			this->inventorySlots[j][i].shape.setFillColor(sf::Color::Transparent);
			this->inventorySlots[j][i].shape.setSize(sf::Vector2f(gui::p2pX(width, vm), gui::p2pY(height, vm)));
			this->inventorySlots[j][i].shape.setPosition(sf::Vector2f(gui::p2pX(x, vm), gui::p2pY(y, vm)));
			this->inventorySlots[j][i].hasDurability = false;
			this->inventorySlots[j][i].durability.setCharacterSize(gui::calcCharSize(vm,100U));
			this->inventorySlots[j][i].durability.setPosition(sf::Vector2f(gui::p2pX(x, vm), gui::p2pY((y + 5.f), vm)));
			this->inventorySlots[j][i].durability.setFont(font);
			this->inventorySlots[j][i].durability.setString("");
			this->inventorySlots[j][i].durability.setColor(sf::Color::White);
			tmpID++;
		}
		x = 26.f;
	}
	//hotbar
	width = 3.9f;
	height = 6.7f;
	x = 26.7f;
	y = 88.14f;
	offsetX = width + 1.45f;
	for (int j = 3; j < 4; j++) {
		for (int i = 0; i < 9; i++) {
			if (i != 0)x += offsetX;
			this->inventorySlots[j][i].isHovered = false;
			this->inventorySlots[j][i].isSelected = false;
			this->inventorySlots[j][i].isFull = false;
			this->inventorySlots[j][i].lastMouseState = false;
			this->inventorySlots[j][i].inventoryID = tmpID;
			this->inventorySlots[j][i].shape.setFillColor(sf::Color::Transparent);
			this->inventorySlots[j][i].shape.setSize(sf::Vector2f(gui::p2pX(width, vm), gui::p2pY(height, vm)));
			this->inventorySlots[j][i].shape.setPosition(sf::Vector2f(gui::p2pX(x, vm), gui::p2pY(y, vm)));
			this->inventorySlots[j][i].hasDurability = false;
			this->inventorySlots[j][i].durability.setCharacterSize(gui::calcCharSize(vm, 100U));
			this->inventorySlots[j][i].durability.setPosition(sf::Vector2f(gui::p2pX(x, vm), gui::p2pY((y + 5.f), vm)));
			this->inventorySlots[j][i].durability.setFont(font);
			this->inventorySlots[j][i].durability.setString("");
			this->inventorySlots[j][i].durability.setColor(sf::Color::White);
			tmpID++;
		}
	}
}

void PlayerGUI::initMoneySlot(sf::VideoMode& vm, sf::Font &font){
	this->moneySlot.setCharacterSize(gui::calcCharSize(vm, 90U));
	this->moneySlot.setPosition(sf::Vector2f(gui::p2pX(60.f, vm), gui::p2pY(23.6f, vm)));
	this->moneySlot.setString("Money:");
	this->moneySlot.setColor(sf::Color::Black);
	this->moneySlot.setFont(font);
	this->moneySlot.setStyle(sf::Text::Bold);
}

void PlayerGUI::initINV(sf::VideoMode& vm, sf::Font &font){
	this->inventoryRect.setSize(
		sf::Vector2f(
			gui::p2pX(55.f, vm),
			gui::p2pY(60.f, vm)
		)
	);
	this->inventoryRect.setPosition(
		sf::Vector2f(
			gui::p2pX(22.5f, vm),
			gui::p2pY(10.f, vm)
		)
	);
	this->inventoryRect.setTexture(&this->inventoryText);
	this->initINVSlots(vm,font);
	this->initMousRect(vm);
	this->initMoneySlot(vm,font);
}

PlayerGUI::PlayerGUI(Player* player, sf::VideoMode& vm, sf::Font &font, std::map<std::string, std::map<int, Item*>>* items, std::map<std::string, sf::Texture>* textures) : vm(vm){
	this->player = player;
	this->items = items;
	this->textures = textures;
	this->initTextures();
	this->initFont();
	//this->initLevelBar();
	//this->initEXPBar();
	//this->initHPBar();
	//this->initPlayerTabs(vm, font, *player);
	
	this->initGameClockDisplay(vm);
	this->initGameClockNumbers(vm);
	this->initGameSeasonDisplay(vm);
	this->initGameDayDisplay(vm);

	//hotbar
	this->initHB(vm);
	//inventory
	this->initINV(vm,font);
	//items
	this->initPossible(vm);
	//shop
	this->initShop(vm,font);
}

PlayerGUI::~PlayerGUI(){
	//delete this->hpBar;
	//delete this->expBar;
	//delete this->playerTabs;
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

void PlayerGUI::updateSeasonDisplay(short unsigned seasonNum){
	switch (seasonNum) {
	case 1:this->currSeason.setString("Pomlad");break;//pomlad
	case 2:this->currSeason.setString("Poletje");break;//poletje
	case 3:this->currSeason.setString("Jesen"); break;//jesen
	case 4:this->currSeason.setString("Zima"); break;//zima
	}
}

void PlayerGUI::updateGameTimeDay(int daysElapsed){
	int tmpX = 0;
	int tmpY = 0;
	tmpX = ((daysElapsed % 10) * this->gameTimeDay_TexRect.width);
	tmpY = ((daysElapsed / 10) * this->gameTimeDay_TexRect.height);
	this->gameTimeDay_TexRect.left = tmpX;
	this->gameTimeDay_TexRect.top = tmpY;
	this->gameTimeDay.setTextureRect(this->gameTimeDay_TexRect);
}

void PlayerGUI::updateHB(){
	unsigned short id = this->player->getInventory()->getIDSelectedHB() + 1;
	std::string path = "Resources/Images/Gui/hotbar_Layer" + std::to_string(id) + ".png";
	this->hotbarTextSelected.loadFromFile(path);
	this->hotbarRectSelected.setTexture(&this->hotbarTextSelected);

	//sloti
	//hotbar
	for (int j = 3; j < 4; j++) {
		for (int i = 0; i < 9; i++) {
			if (this->inventorySlots[j][i].hasDurability) {
				Item* item = this->player->getInventory()->getItem(this->inventorySlots[j][i].inventoryID);
				if (Tool* temp = dynamic_cast<Tool*>(item)) {
					std::string dur = std::to_string(temp->getDurability());
					this->inventorySlots[j][i].durability.setString(dur);
				}
			}
		}
	}

}

void PlayerGUI::swapINVPlace(int from, int to){
	//std::cout << "Menjava Mesta" << std::endl;
	Inventory* inv = this->player->getInventory();
	bool dva = false;
	//preveri ce je "to" mesto zasedeno
	if (inv->hasItem(to)) {
		//je zasedenu
		dva = true;
		Item* fromTMP = inv->getItem(from);
		inv->add(inv->getItem(to), from); //NE VEM CE DELA !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		inv->add(fromTMP, to);
	}
	else {
		//ni zasedenu
		inv->add(inv->getItem(from), to);
		inv->remove(from);
	}
	//posodobi se isFull atribute
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 9; x++) {
			if (!dva) { //je sam en item
				if (this->inventorySlots[y][x].inventoryID == from)this->inventorySlots[y][x].isFull = false; //ta nima vec itema
				else if (this->inventorySlots[y][x].inventoryID == to)this->inventorySlots[y][x].isFull = true; //ta ga je pa dubu
			}
			//else ce sta dva itema sta bla ze prej obadva full
		}
	}
}

void PlayerGUI::updateINVSlots(const sf::Vector2i& mousePosWindow){
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 9; i++) {
			//prever ce je poun =============================================//
			if (this->player->getInventory()->hasItem(this->inventorySlots[j][i].inventoryID)) {
				//je poun
				this->inventorySlots[j][i].isFull = true;
				this->inventorySlots[j][i].hasDurability = true; //ker majo usi sam enim je amount
				Item* item = this->player->getInventory()->getItem(this->inventorySlots[j][i].inventoryID);
				if (Tool* temp = dynamic_cast<Tool*>(item)) {
					std::string dur = std::to_string(temp->getDurability());
					this->inventorySlots[j][i].durability.setString(dur);
				}
				if (Carrot* temp = dynamic_cast<Carrot*>(item)) {
					std::string dur = std::to_string(temp->getAmount());
					this->inventorySlots[j][i].durability.setString(dur);
				}
			}
			else {
				this->inventorySlots[j][i].isFull = false; //ni poun
				this->inventorySlots[j][i].hasDurability = false;
			}
			//==============================================================//
			//preveri ce je miska nad njim =================================//
			if (this->inventorySlots[j][i].shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosWindow))) {
				//miska je nad njim
				this->inventorySlots[j][i].isHovered = true;
			}
			else if (this->inventorySlots[j][i].isHovered)this->inventorySlots[j][i].isHovered = false; //miska ni vec nad njim
			//==============================================================//
			//preveri ce je biu kliknen med tem ko je bil hoveran ==========//
			if (this->inventorySlots[j][i].isHovered &&
				sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->inventorySlots[j][i].lastMouseState = true;
			}
			else { //ko spustis misko se sele izvede da se ne ponavlja izvajanje
				if (this->inventorySlots[j][i].lastMouseState) { //preveri da je biu kliknjen
					if (this->inventorySlots[j][i].isSelected) {//ce je ze zbran ga unzberes
						this->inventorySlots[j][i].isSelected = false;
						this->mouseHasItem = false;
						this->idMouseItem = -1;
					}
					else{ //biu je kliknen slot k se ni biu zbran
						if (this->inventorySlots[j][i].isFull && !this->mouseHasItem) { //preveri ce je biu ta kliknen pa ma item in miska ga nima
							this->inventorySlots[j][i].isSelected = true;
							this->mouseHasItem = true;
							this->idMouseItem = this->inventorySlots[j][i].inventoryID;
							this->mouseOffset = this->inventorySlots[j][i].shape.getPosition() - static_cast<sf::Vector2f>(mousePosWindow);
							this->mouseRect.setTexture(this->inventorySlots[j][i].shape.getTexture());
							this->mouseRect.setFillColor(sf::Color(153, 151, 150, 255));
						}
						else if (this->mouseHasItem && this->idMouseItem != this->inventorySlots[j][i].inventoryID) { //ce ma miska ze item in ni isti slot iz kerga ma ta item
							this->swapINVPlace(this->idMouseItem, this->inventorySlots[j][i].inventoryID); //zamena ta slota
							//ponastavi vse vrednosti
							for (int y = 0; y < 3; y++) {
								for (int x = 0; x < 9; x++) {
									if (this->inventorySlots[y][x].inventoryID == this->idMouseItem) {
										this->inventorySlots[y][x].isSelected = false;
										//std::cout << "brisanje selecta" << this->inventorySlots[y][x].inventoryID << std::endl;
									}
								}
							}
							this->mouseHasItem = false;
							this->idMouseItem = -1;
							this->inventorySlots[j][i].isSelected = false;
						}
					}
					this->inventorySlots[j][i].lastMouseState = false; //ko konca sz spremembami da nazaj na false
				}
			}
			//==============================================================//
		}
	}
	//preveri za klike izven slotou
	bool isIn = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		for (int j = 0; j < 4 && !isIn; j++) {
			for (int i = 0; i < 9 && !isIn; i++) {
				if (this->inventorySlots[j][i].isHovered) {
					//std::cout<<"vredi" << std::endl;
					isIn = true;
				}
			}
		}
		if (!isIn) {
			this->mouseHasItem = false;
			//this->mouseRect.setTexture(nullptr);
			//this->mouseRect.setFillColor(sf::Color::Transparent);
			for (int j = 0; j < 4; j++) {
				for (int i = 0; i < 9; i++) {
					if (this->inventorySlots[j][i].inventoryID == this->idMouseItem) {
						this->inventorySlots[j][i].isSelected = false;
					}
				}
			}
		}
	}
}

void PlayerGUI::updateMousRect(const sf::Vector2i& mousePosWindow) {
	this->mouseRect.setPosition(static_cast<sf::Vector2f>(mousePosWindow) + this->mouseOffset);
	if (!this->mouseHasItem) {
		this->mouseRect.setTexture(nullptr);
		this->mouseRect.setFillColor(sf::Color::Transparent);
	}
}

void PlayerGUI::updateINV(const sf::Vector2i& mousePosWindow){
	//se klice po potrebi (k je inventory odprrt)
	this->updateMousRect(mousePosWindow);
	this->updateINVSlots(mousePosWindow);
}

void PlayerGUI::updateButtons(const sf::Vector2i& mousePosWindow){
	for (const auto& pair : this->buttonsShop) {
		pair.second->update(mousePosWindow);
	}
	if (this->buttonsShop["DownSlide"]->isPressed()) {
		this->buttonsShop["DownSlide"]->makeSound();
		if (static_cast<int>(this->currShopSite) == 0)this->currShopSite = BuildingPlans;
		else this->currShopSite = static_cast<ShopSite>(static_cast<int>(this->currShopSite)-1);
		this->resetTexts();
	}
	if (this->buttonsShop["UpSlide"]->isPressed()) {
		this->buttonsShop["UpSlide"]->makeSound();
		if (static_cast<int>(this->currShopSite) == 2)this->currShopSite = Plants;
		else this->currShopSite = static_cast<ShopSite>(static_cast<int>(this->currShopSite) + 1);
		this->resetTexts();
	}
	if (this->buttonsShop["Plus1"]->isPressed()) {
		this->buttonsShop["Plus1"]->makeSound();
		this->texts["Amount1"].setString(this->addOne("Amount1"));
		this->texts["Price1"].setString(this->addOne("Price1"));
		this->texts["Price1"].setString(this->addOne("Price1"));
	}
	if (this->buttonsShop["Plus2"]->isPressed()) {
		this->buttonsShop["Plus2"]->makeSound();
		this->texts["Amount2"].setString(this->addOne("Amount2"));
	}
	if (this->buttonsShop["Plus3"]->isPressed()) {
		this->buttonsShop["Plus3"]->makeSound();
		this->texts["Amount3"].setString(this->addOne("Amount3"));
	}
	if (this->buttonsShop["Plus4"]->isPressed()) {
		this->buttonsShop["Plus4"]->makeSound();
		this->texts["Amount4"].setString(this->addOne("Amount4"));
	}
	if (this->buttonsShop["Plus5"]->isPressed()) {
		this->buttonsShop["Plus5"]->makeSound();
		this->texts["Amount5"].setString(this->addOne("Amount5"));
	}
	if (this->buttonsShop["Plus6"]->isPressed()) {
		this->buttonsShop["Plus6"]->makeSound();
		this->texts["Amount6"].setString(this->addOne("Amount6"));
	}
	if (this->buttonsShop["Minus1"]->isPressed()) {
		this->buttonsShop["Minus1"]->makeSound();
		this->texts["Amount1"].setString(this->removeOne("Amount1"));
		this->texts["Price1"].setString(this->removeOne("Price1"));
		this->texts["Price1"].setString(this->removeOne("Price1"));
	}
	if (this->buttonsShop["Minus2"]->isPressed()) {
		this->buttonsShop["Minus2"]->makeSound();
		this->texts["Amount2"].setString(this->removeOne("Amount2"));
	}
	if (this->buttonsShop["Minus3"]->isPressed()) {
		this->buttonsShop["Minus3"]->makeSound();
		this->texts["Amount3"].setString(this->removeOne("Amount3"));
	}
	if (this->buttonsShop["Minus4"]->isPressed()) {
		this->buttonsShop["Minus4"]->makeSound();
		this->texts["Amount4"].setString(this->removeOne("Amount4"));
	}
	if (this->buttonsShop["Minus5"]->isPressed()) {
		this->buttonsShop["Minus5"]->makeSound();
		this->texts["Amount5"].setString(this->removeOne("Amount5"));
	}
	if (this->buttonsShop["Minus6"]->isPressed()) {
		this->buttonsShop["Minus6"]->makeSound();
		this->texts["Amount6"].setString(this->removeOne("Amount6"));
	}
	if (this->buttonsShop["Buy1"]->isPressed()) {
		this->buttonsShop["Buy1"]->makeSound();
		if (this->currShopSite == Plants) {
			if (this->buy("Carrot",
				std::stoi(this->texts["Amount1"].getString().toAnsiString()),
				std::stoi(this->texts["Price1"].getString().toAnsiString()))) {
				this->texts["Amount1"].setString("00");
				this->texts["Price1"].setString("00");
			}
		}
	}
	if (this->buttonsShop["Sell1"]->isPressed()) {
		this->buttonsShop["Sell1"]->makeSound();
		if (this->currShopSite == Plants) {
			if (this->sell("Carrot",
				std::stoi(this->texts["Amount1"].getString().toAnsiString()),
				std::stoi(this->texts["Price1"].getString().toAnsiString()))) {
				this->texts["Amount1"].setString("00");
				this->texts["Price1"].setString("00");
			}
		}
	}
	if (this->buttonsShop["Buy2"]->isPressed()) {
		this->buttonsShop["Buy2"]->makeSound();
	}
	if (this->buttonsShop["Sell2"]->isPressed()) {
		this->buttonsShop["Sell2"]->makeSound();
	}
	if (this->buttonsShop["Buy3"]->isPressed()) {
		this->buttonsShop["Buy3"]->makeSound();
	}
	if (this->buttonsShop["Sell3"]->isPressed()) {
		this->buttonsShop["Sell3"]->makeSound();
	}
	if (this->buttonsShop["Buy4"]->isPressed()) {
		this->buttonsShop["Buy4"]->makeSound();
	}
	if (this->buttonsShop["Sell4"]->isPressed()) {
		this->buttonsShop["Sell4"]->makeSound();
	}
	if (this->buttonsShop["Buy5"]->isPressed()) {
		this->buttonsShop["Buy5"]->makeSound();
	}
	if (this->buttonsShop["Sell5"]->isPressed()) {
		this->buttonsShop["Sell5"]->makeSound();
	}
	if (this->buttonsShop["Buy6"]->isPressed()) {
		this->buttonsShop["Buy6"]->makeSound();
	}
	if (this->buttonsShop["Sell6"]->isPressed()) {
		this->buttonsShop["Sell6"]->makeSound();
	}
}

void PlayerGUI::updateSites(){
	switch (this->currShopSite) {
	case Plants:
		this->siteShopRect.setTexture(&this->shopPlantsSite);
		break;
	case Tools:
		this->siteShopRect.setTexture(&this->shopToolsSite);
		break;
	case BuildingPlans:
		this->siteShopRect.setTexture(&this->shopBuildingPlansSite);
		break;
	}
}

void PlayerGUI::updateShop(const sf::Vector2i& mousePosWindow){
	this->updateButtons(mousePosWindow);
	this->updateSites();
}

void PlayerGUI::update(const float & dt){
	//this->updateLevelBar();
	//this->updateEXPBar();
	//this->updateHPBar();
	//this->updatePlayerTabs();
	this->updateHB();
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
	target.draw(this->currSeason);
	target.draw(this->gameTimeDay);
	target.draw(this->gameTimeDayText);
}

void PlayerGUI::renderHB(sf::RenderTarget& target){
	target.draw(this->hotbarRect);
	target.draw(this->hotbarRectSelected);
	for (int j = 3; j < 4; j++) {
		for (int i = 0; i < 9; i++) {
			//ureja barvo
			if (this->inventorySlots[j][i].isFull)this->inventorySlots[j][i].shape.setFillColor(sf::Color::White);
			else this->inventorySlots[j][i].shape.setFillColor(sf::Color::Transparent);
			//ureja teksturo
			if (this->inventorySlots[j][i].isFull) {
				sf::Texture* tmp = this->player->getInventory()->getItemIcon(this->inventorySlots[j][i].inventoryID);
				this->inventorySlots[j][i].shape.setTexture(tmp);
			}
			else {
				this->inventorySlots[j][i].shape.setTexture(nullptr);
			}
			//narise
			target.draw(this->inventorySlots[j][i].shape);
			if (this->inventorySlots[j][i].hasDurability) {
				target.draw(this->inventorySlots[j][i].durability);
			}
		}
	}
}

void PlayerGUI::renderINVSlots(sf::RenderTarget& target){
	Inventory* tmp = this->player->getInventory();
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 9; i++) {
			//spremeni barvo
			if (this->inventorySlots[j][i].isSelected) {
				this->inventorySlots[j][i].shape.setFillColor(sf::Color(92, 84, 64, 50));
			}
			else if (this->inventorySlots[j][i].isHovered) {
				if (this->inventorySlots[j][i].isFull)this->inventorySlots[j][i].shape.setFillColor(sf::Color(153, 151, 150, 255));
				else this->inventorySlots[j][i].shape.setFillColor(sf::Color::Transparent);
			}
			else {
				if (this->inventorySlots[j][i].isFull) {
					this->inventorySlots[j][i].shape.setFillColor(sf::Color::White);
					//ubistvu majo usi sam da eni majo amount eni pa durability
					this->inventorySlots[j][i].hasDurability = true;
				}
				else this->inventorySlots[j][i].shape.setFillColor(sf::Color::Transparent);
			}
			//========
			//Ce ma item doda teksturo
			if (this->inventorySlots[j][i].isFull) {
				sf::Texture* tmp = this->player->getInventory()->getItemIcon(this->inventorySlots[j][i].inventoryID);
				std::cout << j << "  " << i << std::endl;
				this->inventorySlots[j][i].shape.setTexture(tmp);
			}
			else {
				this->inventorySlots[j][i].shape.setTexture(nullptr);
			}
			
			target.draw(this->inventorySlots[j][i].shape);
			//ce ma durability
			if (this->inventorySlots[j][i].hasDurability) {
				target.draw(this->inventorySlots[j][i].durability);
			}
		}
	}
}

void PlayerGUI::renderMoney(sf::RenderTarget& target){
	std::string tmp = "Money: " + std::to_string(this->player->getInventory()->getMoney());
	this->moneySlot.setString(tmp);
	target.draw(this->moneySlot);
}

void PlayerGUI::renderINV(sf::RenderTarget& target){
	//se klice po potrebi (k je inventory odprrt)
	target.draw(this->inventoryRect);
	target.draw(this->mouseRect);
	this->renderINVSlots(target);
	this->renderMoney(target);
}

void PlayerGUI::renderButtons(sf::RenderTarget& target){
	for (const auto& pair : this->buttonsShop) {
		pair.second->render(target);
	}
}

void PlayerGUI::renderTexts(sf::RenderTarget& target){
	for (const auto& pair : this->texts) {
		target.draw(pair.second);
	}
}

void PlayerGUI::renderSite(sf::RenderTarget& target){
	target.draw(this->siteShopRect);
}

void PlayerGUI::renderShop(sf::RenderTarget& target){
	target.draw(this->basicShopRect);
	this->renderButtons(target);
	this->renderSite(target);
	this->renderTexts(target);
}

void PlayerGUI::render(sf::RenderTarget & target){
	//this->renderLevelBar(target);
	//this->renderEXPBar(target);
	//this->renderHPBar(target);
	//this->renderPlayerTabs(target);
	this->renderGameClock(target);
	this->renderHB(target);
}


//tools

float calculateDistance2D(sf::Vector2f pos1, sf::Vector2f pos2) {
	float dx = pos2.x - pos1.x;
	float dy = pos2.y - pos1.y;
	dx = std::abs(dx);
	dy = std::abs(dy);
	return std::sqrt(dx * dx + dy * dy);
}

bool checkBuild(std::string buildingType, sf::Vector2f pos, std::map<std::string, std::map<int, Building*>>* buildings) {
	if (buildingType == "farmland") { //checka ce placas farmland
		for (const auto& value : buildings->at("farmland")) { //prever da ne placa na se en farmland
			if (value.second->getPos() == pos)return false;
		}
		return true;
	}
	if (buildingType == "carrotPlant") { //checka ce placas carrotPlant
		for (const auto& value : buildings->at("farmland")) {
			if (value.second->getPos() == pos) { //preveri da se placa na farmland
				for (const auto& v : buildings->at("carrotPlant")) {
					if (v.second->getPos() == pos)return false;//preveri da se ne placa na se en korencek
				}
				return true;
			}
		}
		return false;
	}
}

void PlayerGUI::updateItemPossibles(const sf::Vector2f& mousePosWindow, TileMap* map,sf::Texture* texture, std::string item, std::map<std::string, std::map<int, Building*>>* buildings){
	sf::Vector2f temp = map->getPosOfRectWithMousOver(mousePosWindow);
	if (item == "hoe") {
		if (calculateDistance2D(mousePosWindow, player->getPosition()) < 32.f) {
			this->possible.setPosition(temp);
			this->possible.setTexture(texture);
			if (checkBuild("farmland", temp, buildings)) {
				this->possible.setFillColor(sf::Color(255, 255, 255, 150));
				this->possible.setOutlineColor(sf::Color::Green);
				this->isPlaceble = true;
			}
			else {
				this->possible.setFillColor(sf::Color(212, 23, 13, 200));
				this->possible.setOutlineColor(sf::Color::Red);
				this->isPlaceble = false;
			}
		}
		else {
			this->possible.setFillColor(sf::Color::Transparent);
			this->possible.setOutlineColor(sf::Color::Transparent);
			this->isPlaceble = false;
		}
	}
	if (item == "carrotSeed") {
		if (calculateDistance2D(mousePosWindow, player->getPosition()) < 32.f) {
			this->possible.setPosition(temp);
			this->possible.setTexture(texture);
			if (checkBuild("carrotPlant", temp, buildings)) {
				this->possible.setFillColor(sf::Color(255, 255, 255, 150));
				this->possible.setOutlineColor(sf::Color::Green);
				this->isPlaceble = true;
			}
			else {
				this->possible.setFillColor(sf::Color(212, 23, 13, 200));
				this->possible.setOutlineColor(sf::Color::Red);
				this->isPlaceble = false;
			}
		}
		else {
			this->possible.setFillColor(sf::Color::Transparent);
			this->possible.setOutlineColor(sf::Color::Transparent);
			this->isPlaceble = false;
		}
	}
}

bool PlayerGUI::getIsPlaceble(){
	return this->isPlaceble;
}

void PlayerGUI::renderItemPossibles(sf::RenderTarget& target){
	target.draw(this->possible);
}
