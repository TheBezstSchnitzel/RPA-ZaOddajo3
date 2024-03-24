#pragma once

//enum ItemTypes {IT_DEFAULT = 0, IT_RANGEDWEAPON, IT_MELEEWEAPON};
//enum ItemRarities {COMMON = 0, UNCOMMON, RARE, EPIC, LEGENDARY, MYTHIC};


enum ItemTypes { IT_UNUSABLE = 0, IT_USABLE };
/*UNUSABLE: kt na foro pridelki kej kar ne vpliva na svet al pa kar kol
USUABLE pa nasprotnu ksna orodja itd*/
class Item{
private:

	//inicializacija
	void initVariables(short unsigned type);

	//void findFreeID();
protected:
	//Lastnosti
	short unsigned type;
	std::string id;
	//int id;

public:
	Item(short unsigned type, std::string id);
	~Item();

	//Dostop
	const short unsigned& getType() const { return this->type;}
	//int getID() const { return this->id;}
	std::string getID() { return this->id; }

	//Funkcije
	//virtual Item* clone() = 0;
	virtual sf::Texture* getTexture() = 0;
	//virtual void use() = 0;

	virtual void saveToFile(std::string savePath) = 0;
	virtual void loadFromSave(std::string savePath) = 0;
};