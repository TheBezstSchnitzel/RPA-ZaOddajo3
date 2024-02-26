#pragma once

//enum ItemTypes {IT_DEFAULT = 0, IT_RANGEDWEAPON, IT_MELEEWEAPON};
//enum ItemRarities {COMMON = 0, UNCOMMON, RARE, EPIC, LEGENDARY, MYTHIC};


enum ItemTypes { IT_UNUSABLE = 0, IT_USABLE };
/*UNUSABLE: kt na foro pridelki kovanci kej kar ne vpliva na svet al pa kar kol
USUABLE pa nasprotnu ksna orodja itd*/
class Item{
private:
	//static std::vector<int> takenIDs; //kolk je itemou narjenioh oziroma jih ze obstaja

	//sf::Texture* inventoryIcon;

	//inicializacija
	void initVariables(short unsigned type);

	//void findFreeID();
protected:
	//Lastnosti
	short unsigned type;
	int id;

public:
	Item(short unsigned type);
	~Item();

	//Dostop
	const short unsigned& getType() const { return this->type;}
	//int getID() const { return this->id;}

	//Funkcije
	virtual Item* clone() = 0;
	virtual sf::Texture* getTexture() = 0;
};