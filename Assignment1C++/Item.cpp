#include <iostream>
#include "Item.h"


Item::Item(std::string name, int price, float svm, float escm, float oscm, float esc, float lrm) {
	this->name = name;
	this->price = price;
	this->scrapValueMultiplier = svm;
	this->explorerSurvivalChanceMultiplier = escm;
	this->operatorSurvivalChanceMultiplier = oscm;
	this->explorerSaveChance = esc;
	this->lootRecoveryMultiplier = lrm;
}

std::string Item::getName() {
	return name;
}

int Item::getPrice() {
	return price;
}

float Item::getSvm() {
	return scrapValueMultiplier;
}

float Item::getEscm() {
	return explorerSurvivalChanceMultiplier;
}

float Item::getOscm() {
	return operatorSurvivalChanceMultiplier;
}

float Item::getEsc() {
	return explorerSaveChance;
}

float Item::getLrm() {
	return lootRecoveryMultiplier;
}