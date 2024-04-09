#include <vector>
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

void AbstractMoon::setWeather(int num) {
    if (num == 0) {
        this->weather = MoonWeather::Clear;
    }
    else if (num == 1) {
        this->weather = MoonWeather::Eclipsed;
    }
    else if (num == 2) {
        this->weather = MoonWeather::Flooded;
    }
    else if (num == 3) {
        this->weather = MoonWeather::Stormy;
    }
}

float AbstractMoon::getMinScrapValue() {
    return minScrapValue;
}

float AbstractMoon::getMaxScrapValue() {
    return maxScrapValue;
}

float AbstractMoon::getBsc() {
    return baseSurvivalChance;
}

std::vector<float> AbstractMoon::getMultiplierValue() {
    std::vector<float> weatherConditions = { 1, 1, 1 };
    if (this->weather == MoonWeather::Flooded) {
        weatherConditions = { 1, 0.7, 1 };
    }
    else if (this->weather == MoonWeather::Stormy) {
        weatherConditions = { 0.75, 1, 1 };
    }
    else if (this->weather == MoonWeather::Eclipsed) {
        weatherConditions = { 1, 0.9, 0.7 };
    }

    return weatherConditions;
}
