#include <iostream>
#include "AbstractMoon.h"

AbstractMoon::AbstractMoon(std::string moonName, int minScrapValue, int maxScrapValue) {
    this->moonName = moonName;
    this->minScrapValue = minScrapValue;
    this->maxScrapValue = maxScrapValue;
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