#include <iostream>
#include "AbstractMoon.h"

AbstractMoon::AbstractMoon(std::string moonName) {
    this->moonName = moonName;
    setWeather(MoonWeather::Clear);
}

const std::string& AbstractMoon::name() { 
    return moonName;
}

AbstractMoon::MoonWeather AbstractMoon::getWeather() {
    return weather;
}

void AbstractMoon::setWeather(MoonWeather weather) {
    this->weather = weather;