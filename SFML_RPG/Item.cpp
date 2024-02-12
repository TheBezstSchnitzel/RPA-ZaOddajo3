#include "stdafx.h"
#include "Item.h"

void Item::initVariables(){

}

Item::Item(short unsigned type, unsigned value){
	this->initVariables();

	this->value = value;
	this->type = type;
}

Item::~Item(){

}
