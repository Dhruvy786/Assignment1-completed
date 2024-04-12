#include "MoonManager.h"

// Constructor: initializes moons vector with predefined moon data
MoonManager::MoonManager() {
    for (const auto& pair : moonMap) {
        AbstractMoon* moon = new AbstractMoon(pair.first, pair.second[0], pair.second[1], pair.second[2]);
        moons.push_back(moon);
    }
}

// Adds a moon to the moons vector
void MoonManager::registerMoon(AbstractMoon* moon) {
    moons.push_back(moon);
}

// Retrieves a moon object by its name
AbstractMoon* MoonManager::moon(std::string moonName) {
    for (AbstractMoon* moon : moons) {
        if (moon->name() == moonName) {
            return moon;
        }
    }
    return nullptr;
}

// Displays the list of moons available for routing
void MoonManager::show_moons() {
    std::cout << "Welcome to the exomoons catalogue.\n"
        "To route the autopilot to a moon, use the word ROUTE.\n"
        "---------------------------------------\n" << std::endl;
    for (const auto& moon : moons) {
        std::cout << "* " << moon->name() << " (" << moonWeatherToString(moon->getWeather()) << ")\n";
    }
    std::cout << std::endl;
}

// Converts moon weather enum to string representation
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

// Retrieves the names of all moons
std::vector<std::string> MoonManager::getMoons() {
    std::vector<std::string> moonNames;

    for (const auto& moon : moons) {
        moonNames.push_back(moon->name());
    }

    return moonNames;
}

// Sets random weather for all moons
void MoonManager::setRandomWeather() {
    for (AbstractMoon* moon : moons) {
        int num = rd.generateRandomNumber(0, 4);
        moon->setWeather(num);
    }
}

// Adds employees to a moon's expedition and calculates their survival and revenue
std::tuple<int, int, int> MoonManager::addEmployee(int aliveEmployees,
    int numExplorers,
    double explorerBaseSurvivalChance,
    int minScrapValue,
    int maxScrapValue,
    double explorerSurvivalChanceMultiplier,
    double operatorSurvivalChanceMultiplier,
    double scrapValueMultiplier,
    double explorerSaveChance,
    double lootRecoveryMultiplier) {

    int numOperators = aliveEmployees - numExplorers;
    int totalRevenue = 0;
    int deadExplorers = 0;
    int deadOperators = 0;

    RandomGenerator rd;

    // Calculate survival chances
    double explorerSurvivalChance = explorerBaseSurvivalChance * explorerSurvivalChanceMultiplier;
    double operatorSurvivalChance = 1.0 * operatorSurvivalChanceMultiplier;

    // Explore with numExplorers
    for (int i = 0; i < numExplorers; ++i) {
        int revenue = rd.generateInt((minScrapValue * scrapValueMultiplier), (maxScrapValue * scrapValueMultiplier));

        if (rd.generateFloat() < explorerSurvivalChance) {
            totalRevenue += revenue;
        }
        else if (rd.generateFloat() >= explorerSaveChance) {
            // Explorer dies and is not saved
            totalRevenue += revenue * lootRecoveryMultiplier;
            ++deadExplorers;
        }
    }

    // Operators' fate
    for (int i = 0; i < numOperators; ++i) {
        if (rd.generateFloat() >= operatorSurvivalChance) {
            // Operator dies
            ++deadOperators;
        }
    }

    // Calculate total number of employees who died
    int totalDead = deadExplorers + deadOperators;

    // Calculate remaining alive employees
    int aliveAfterExpedition = aliveEmployees - totalDead;

    return std::make_tuple(deadExplorers, deadOperators, totalRevenue);
}
