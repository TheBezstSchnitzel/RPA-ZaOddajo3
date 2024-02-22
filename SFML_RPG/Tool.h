#pragma once
#include "Item.h"
class Tool : public Item{
private:
	int maxDurability;
	int durabiltity;
	bool isEquipped;
	bool isBroken;

public:
	Tool(short unsigned type, sf::Texture* inventoryIcon, int maxDurability, int durability, bool isEquipped, bool isBroken = false);
	~Tool();
	
	void damageDurability(int damage);
	void healDurability(int heal);

	//dostop
	int getDurability();
	bool getIsEquipped();
	bool getIsBrooken();

	//usage
	virtual void use() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
};

