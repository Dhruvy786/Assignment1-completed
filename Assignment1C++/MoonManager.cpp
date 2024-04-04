#include "MoonManager.h"

void MoonManager::registerMoon(AbstractMoon* moon) {
    moons.push_back(moon);
}

AbstractMoon* MoonManager::moon(std::string moonName) {
    for (AbstractMoon* moon : moons) {
        if (moon->name() == moonName) {
            return moon;
        }
    }
    return nullptr;
}

void MoonManager::show_moons() {
    std::cout << "Welcome to the exomoons catalogue.\n"
        "To route the autopilot to a moon, use the word ROUTE.\n"
        "---------------------------------------\n" << std::endl;
    for (const auto& moon : moons) {
        std::cout << "* " << moon->name() << " (" << moonWeatherToString(moon->getWeather()) << ")\n";
    }
    std::cout << std::endl;
}

std::string MoonManager::moonWeatherToString(AbstractMoon::MoonWeather weather) {
    switch (weather) {
    case AbstractMoon::MoonWeather::Clear:
        return "";
    case AbstractMoon::MoonWeather::Flooded:
        return "Flooded";
    case AbstractMoon::MoonWeather::Eclipsed:
        return "Eclipsed";
    case AbstractMoon::MoonWeather::Stormy:
        return "Stormy";
    default:
        return "";
    }
}

void MoonManager::route_to_moon(std::string moon_name) {
    for (const auto& moon : moons) {
        if (moon->name() == moon_name) {
            std::cout << "Routing to " << moon_name << "...\n";
            return;
        }
    }
    std::cout << "Error: Moon '" << moon_name << "' not found!\n";
}

std::vector<std::string> MoonManager::getMoons() {
    std::vector<std::string> moonNames;

    for (const auto& moon : moons) {
        moonNames.push_back(moon->name());
    }

    return moonNames;
}

/*int MoonManager::addEmployee(std::vector<Employee> employees,
    int numExplorers,
    double bsc,
    int minScrapValue,
    int maxScrapValue,
    double explorerSurvivalChanceMultiplier,
    double operatorSurvivalChanceMultiplier,
    double scrapValueMultiplier,
    double explorerSaveChance,
    double lootRecoveryMultiplier) {
    int numOperators = employees.size() - numExplorers;
    int totalRevenue = 0;
    int deadExplorers = 0;
    int deadOperators = 0;

    RandomGenerator rd;

    for (int i = 0; i < numExplorers; ++i) {
        int revenue = rd.generateInt((minScrapValue * scrapValueMultiplier), (maxScrapValue * scrapValueMultiplier));
        double explorerSurvivalChance = bsc * explorerSurvivalChanceMultiplier;

        if (rd.generateFloat() < explorerSurvivalChance) {
            totalRevenue += revenue;
        }
        else if (rd.generateFloat() >= explorerSaveChance) {
            totalRevenue += revenue * lootRecoveryMultiplier;
            ++deadExplorers;
        }
    }

    for (int i = 0; i < numOperators; ++i) {
        if (rd.generateFloat() >= operatorSurvivalChanceMultiplier) {
            ++deadOperators;
        }
    }

    // Update the vector of employees (remove dead employees)
    employees.erase(employees.begin(), employees.begin() + deadExplorers + deadOperators);

    return totalRevenue;
}*/

std::vector<Employee> MoonManager::getRemainingEmployees() {
    return employees;
}

void MoonManager::resetEmployees() {
    employees.clear();
}
