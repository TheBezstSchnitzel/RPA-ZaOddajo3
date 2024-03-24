#include "stdafx.h"
#include "Tool.h"

Tool::Tool(short unsigned type, int maxDurability, int durability, bool isBroken) : Item(type,"DEBUG") {
	this->maxDurability = maxDurability;
	this->durabiltity = durability;
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

void Tool::setDurability(int durability){
	this->durabiltity = durability;
}

int Tool::getDurability(){
	return this->durabiltity;
}


bool Tool::getIsBrooken(){
	return this->isBroken;
}

void Tool::setIsBrooken(bool value){
	this->isBroken = value;
}
