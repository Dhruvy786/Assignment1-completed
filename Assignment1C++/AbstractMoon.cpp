#include <iostream>
#include "AbstractMoon.h"

AbstractMoon::AbstractMoon(std::string moonName, float minScrapValue, float maxScrapValue, float baseSurvivalChance) {
    this->moonName = moonName;
    this->minScrapValue = minScrapValue;
    this->maxScrapValue = maxScrapValue;
    this->baseSurvivalChance = baseSurvivalChance;
};

const std::string& AbstractMoon::name() { 
    return moonName;
}

AbstractMoon::MoonWeather AbstractMoon::getWeather() const {
    return weather;
}

void AbstractMoon::setWeather(MoonWeather weather) {
    this->weather = weather;
}