#include <vector>
#include "AbstractMoon.h"
#include "Game.h"

AbstractMoon::AbstractMoon(std::string moonName, float minScrapValue, float maxScrapValue, float baseSurvivalChance) :
    moonName(moonName),
    minScrapValue(minScrapValue),
    maxScrapValue(maxScrapValue),
    baseSurvivalChance(baseSurvivalChance),
    weather(MoonWeather::Clear) {}

// Get the name of the moon
const std::string& AbstractMoon::name() const {
    return moonName;
}

// Get the weather condition of the moon
AbstractMoon::MoonWeather AbstractMoon::getWeather() const {
    return weather;
}

// Set the weather condition of the moon based on the given number
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

// Get the minimum scrap value of the moon
float AbstractMoon::getMinScrapValue() {
    return minScrapValue;
}

// Get the maximum scrap value of the moon
float AbstractMoon::getMaxScrapValue() {
    return maxScrapValue;
}

// Get the base survival chance of the moon
float AbstractMoon::getBsc() {
    return baseSurvivalChance;
}

// Get the multiplier values for different weather conditions
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

//void AbstractMoon::onDayBegin(Game& g) {
    
//}

//void AbstractMoon::sellCargo(Game& g, int amount) {
    
//}

//void AbstractMoon::sendEmployees(Game& g, int count) {
    
//}
