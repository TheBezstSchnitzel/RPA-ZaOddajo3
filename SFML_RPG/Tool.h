#pragma once
#include "Item.h"
class Tool : public Item{
private:
	int maxDurability;
	int durabiltity;
	bool isBroken;

public:
	Tool(short unsigned type, int maxDurability, int durability, bool isBroken = false);
	~Tool();
	
	void damageDurability(int damage);
	void healDurability(int heal);
	void setDurability(int durability);

	//dostop
	int getDurability();
	bool getIsBrooken();
	void setIsBrooken(bool value);

	//usage
	virtual void update() = 0;
};

