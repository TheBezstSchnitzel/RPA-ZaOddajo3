#include "stdafx.h"
#include "Tool.h"

Tool::Tool(short unsigned type, int maxDurability, int durability, bool isEquipped, bool isBroken) : Item(type){
	this->maxDurability = maxDurability;
	this->durabiltity = durability;
	this->isEquipped = isEquipped;
	this->isBroken = isBroken;
}

Tool::~Tool(){
}

void Tool::damageDurability(int damage){
	if (this->durabiltity - damage <= 0) {
		this->isBroken = true;
		this->durabiltity = 0;
	}
	else {
		this->durabiltity -= damage;
	}
}

void Tool::healDurability(int heal){
	if (this->durabiltity + heal > this->maxDurability) {
		this->durabiltity = this->maxDurability;
	}
	else {
		this->durabiltity += heal;
	}
}

int Tool::getDurability(){
	return this->durabiltity;
}

bool Tool::getIsEquipped(){
	return this->isEquipped;
}

bool Tool::getIsBrooken(){
	return this->isBroken;
}
