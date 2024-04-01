#include <iostream>
#include "AbstractMoon.h"

class MoonManager {
private:
    std::vector<AbstractMoon*> moons;

public:
    void registerMoon(AbstractMoon* moon) {
        moons.push_back(moon);
    }

    void show_moons() {
        std::cout << "Available moons:\n";
        for (const auto& moon : moons) {
            std::cout << "* " << moon->getName() << " " << moon->getWeather() << "\n";
        }
    }

    void route_to_moon(std::string moon_name) {
        for (const auto& moon : moons) {
            if (moon->getName() == moon_name) {
                std::cout << "Routing to " << moon_name << "...\n";
                return;
            }
        }
        std::cout << "Error: Moon '" << moon_name << "' not found!\n";
    }
};