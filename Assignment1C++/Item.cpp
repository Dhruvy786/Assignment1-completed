#include <iostream>
#include "Item.h"

// Constructor to initialize the Item object with provided attributes
Item::Item(std::string name, int price, float svm, float escm, float oscm, float esc, float lrm) {
    this->name = name;
    this->price = price;
    this->scrapValueMultiplier = svm;
    this->explorerSurvivalChanceMultiplier = escm;
    this->operatorSurvivalChanceMultiplier = oscm;
    this->explorerSaveChance = esc;
    this->lootRecoveryMultiplier = lrm;
}

// Get the name of the item
std::string Item::getName() {
    return name;
}

// Get the price of the item
int Item::getPrice() {
    return price;
}

// Get the scrap value multiplier of the item
float Item::getSvm() {
    return scrapValueMultiplier;
}

// Get the explorer survival chance multiplier of the item
float Item::getEscm() {
    return explorerSurvivalChanceMultiplier;
}

// Get the operator survival chance multiplier of the item
float Item::getOscm() {
    return operatorSurvivalChanceMultiplier;
}

// Get the explorer save chance of the item
float Item::getEsc() {
    return explorerSaveChance;
}

// Get the loot recovery multiplier of the item
float Item::getLrm() {
    return lootRecoveryMultiplier;
}