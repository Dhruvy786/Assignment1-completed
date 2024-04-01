#include <iostream>
#include <vector>
#include "AbstractMoon.h"

class MoonManager {
private:
    std::vector<AbstractMoon*> moons;

public:
    void registerMoon(std::string moonName) {
        AbstractMoon* moon = new AbstractMoon(moonName);
        moons.push_back(moon);
    }

    void show_moons() {
        std::cout << "Welcome to the exomoons catalogue.\n"
                     "To route the autopilot to a moon, use the word ROUTE.\n"
                     "---------------------------------------\n" << std::endl;
        for (const auto& moon : moons) {
            std::cout << "* " << moon->name() << " (" << moonWeatherToString(moon->getWeather()) << ")\n";
        }
        std::cout << std::endl;
    }

    std::string moonWeatherToString(AbstractMoon::MoonWeather weather) {
        switch (weather) {
        case AbstractMoon::MoonWeather::Clear:
            return "";
        case AbstractMoon::MoonWeather::Flooded:
            return "Flooded";
        case AbstractMoon::MoonWeather::Eclipsed:
            return "Eclipsed";
        case AbstractMoon::MoonWeather::Stormy:
            return "Stormy";
        }
    }

    void route_to_moon(std::string moon_name) {
        for (const auto& moon : moons) {
            if (moon->name() == moon_name) {
                std::cout << "Routing to " << moon_name << "...\n";
                return;
            }
        }
        std::cout << "Error: Moon '" << moon_name << "' not found!\n";
    }

    std::vector<std::string> getMoons() {
        std::vector<std::string> moonNames;

        for (const auto& moon : moons) {
            moonNames.push_back(moon->name());
        }

        return moonNames;
    }
};