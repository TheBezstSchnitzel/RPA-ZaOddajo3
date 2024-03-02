#pragma once
#include "Item.h"
class Tool : public Item{
private:
	int maxDurability;
	int durabiltity;
	bool isEquipped;
	bool isBroken;

public:
	Tool(short unsigned type, int maxDurability, int durability, bool isEquipped, bool isBroken = false);
	~Tool();
	
	void damageDurability(int damage);
	void healDurability(int heal);
	void setDurability(int durability);

	//dostop
	int getDurability();
	bool getIsEquipped();
	bool getIsBrooken();
	void setIsBrooken(bool value);

	//usage
	virtual void update() = 0;
};

