#pragma once

//enum ItemTypes {IT_DEFAULT = 0, IT_RANGEDWEAPON, IT_MELEEWEAPON};
//enum ItemRarities {COMMON = 0, UNCOMMON, RARE, EPIC, LEGENDARY, MYTHIC};

class Item{
private:
	void initVariables();

protected:
	//Lastnosti
	short unsigned type;
	unsigned value;

public:
	Item(short unsigned type, unsigned value);
	virtual ~Item();

	//Dostop
	const short unsigned& getType() const { return this->type;}
	const unsigned& getValue() const { return this->value;}

	//Funkcije
	virtual Item* clone() = 0;

	//enums
	enum ItemTypes { IT_UNUSABLE = 0, IT_USABLE };
	/*UNUSABLE: kt na foro pridelki kovanci kej kar ne vpliva na svet al pa kar kol
	USUABLE pa nasprotnu ksna orodja itd*/
};