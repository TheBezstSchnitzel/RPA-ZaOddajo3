#include "stdafx.h"
#include "Item.h"

void Item::initVariables(short unsigned type){
	this->type = type;
}

Item::Item(short unsigned type){
	this->initVariables(type);
}

Item::~Item(){
}
