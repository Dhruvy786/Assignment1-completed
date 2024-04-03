#include "AbstractMoon.h"

AbstractMoon::AbstractMoon(std::string moonName, float minScrapValue, float maxScrapValue, float baseSurvivalChance) :
    moonName(moonName),
    minScrapValue(minScrapValue),
    maxScrapValue(maxScrapValue),
    baseSurvivalChance(baseSurvivalChance),
    weather(MoonWeather::Clear) {}

const std::string& AbstractMoon::name() const {
    return moonName;
}

AbstractMoon::MoonWeather AbstractMoon::getWeather() const {
    return weather;
}

void AbstractMoon::setWeather(MoonWeather weather) {
    this->weather = weather;
}
