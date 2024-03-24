#include "stdafx.h"
#include "Item.h"

void Item::initVariables(short unsigned type){
	this->type = type;
}

Item::Item(short unsigned type, std::string id){
	this->initVariables(type);
	this->id = id;
}

Item::~Item(){
}
