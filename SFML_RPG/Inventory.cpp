#include "stdafx.h"
#include "Inventory.h"

//Private functions
void Inventory::initialize(){
	this->nrOfItems = 0;
	this->itemArray = new Item*[this->capacity];

	this->nullify();
}

void Inventory::nullify(const unsigned from){
	for (size_t i = from; i < this->capacity; i++)
	{
		this->itemArray[i] = nullptr;
	}
}

void Inventory::freeMemory(){
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete this->itemArray[i];
	}

	delete[] this->itemArray;
}

//Konstruktor / Destruktor
Inventory::Inventory(unsigned capacity){
	this->capacity = capacity;
	this->inventoryGUI.loadFromFile("Resources/Images/Gui/inventory.png");
	this->initialize();
}

Inventory::~Inventory(){
	this->freeMemory();
}

//Dostop

const unsigned & Inventory::size() const{
	return this->nrOfItems;
}

const unsigned & Inventory::maxSize() const{
	return this->capacity;
}

void Inventory::makeInventoryTexture(const sf::VideoMode& vm){
	//this->textRect.setOutlineColor(sf::Color::Red);
	//this->textRect.setOutlineThickness(5.f);
	this->textRectINV.setSize(
		sf::Vector2f(gui::p2pX(55.f,vm),
					gui::p2pY(60.f,vm))
	);
	this->textRectINV.setPosition(sf::Vector2f(gui::p2pX(22.5f, vm), gui::p2pY(10.f, vm)));
	//this->textRect.setFillColor(sf::Color::Transparent);
	this->textRectINV.setTexture(&this->inventoryGUI);
}

//Funkcije

void Inventory::clear(){
	for (size_t i = 0; i < this->nrOfItems; i++){
		delete this->itemArray[i];
	}

	this->nrOfItems = 0;

	this->nullify();
}

const bool Inventory::isEmpty() const{
	return this->nrOfItems == 0;
}

const bool Inventory::add(Item * item){
	if (this->nrOfItems < this->capacity){
		this->itemArray[this->nrOfItems++] = item->clone();

		return true;
	}

	return false;
}

const bool Inventory::remove(const unsigned index){
	if (this->nrOfItems > 0){
		if (index < 0 || index >= this->capacity)
			return false;

		delete this->itemArray[index];
		this->itemArray[index] = nullptr;
		--this->nrOfItems;

		return true;
	}

	return false;
}

const bool Inventory::saveToFile(const std::string fileName){
	return false;
}

const bool Inventory::loadFromFile(const std::string fileName){
	return false;
}

void Inventory::updateINV(){
	//std::cout << "Dela" << std::endl;
}

void Inventory::renderINV(sf::RenderTarget& target){
	target.draw(this->textRectINV);
}