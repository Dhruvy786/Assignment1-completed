#include <iostream>
#include "Item.h"


Item::Item(std::string name, int price) {
	this->name = name;
	this->price = price;
}

std::string Item::getName() {
	return name;
}

int Item::getPrice() {
	return price;
}