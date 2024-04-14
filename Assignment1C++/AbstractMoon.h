#ifndef ABSTRACTMOON_H
#define ABSTRACTMOON_H

#include <string>

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

    const std::string& name() const;
    MoonWeather getWeather() const;
    void setWeather(int num);
    float getMinScrapValue();
    float getMaxScrapValue();
    float getBsc();
    std::vector<float> getMultiplierValue();
    //virtual void onDayBegin(Game& g);
    //virtual void sellCargo(Game& g, int amount);
    //virtual void sendEmployees(Game& g, int count);
};

#endif // ABSTRACTMOON_H
