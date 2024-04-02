// AbstractMoon.h
#ifndef ABSTRACTMOON_H
#define ABSTRACTMOON_H

#include <iostream>
#include "Employee.h"
#include "RandomGenerator.h"

class AbstractMoon {
public:
    enum class MoonWeather {
        Clear = 0,
        Flooded,
        Eclipsed,
        Stormy
    };

private:
    std::string moonName;
    MoonWeather weather;
    float minScrapValue;
    float maxScrapValue;
    float baseSurvivalChance;

public:
    AbstractMoon(std::string moonName, float minScrapValue, float maxScrapValue, float baseSurvivalChance);

    const std::string& name();
    AbstractMoon::MoonWeather getWeather() const;
    void setWeather(MoonWeather weather);

};

#endif // ABSTRACTMOON_H
