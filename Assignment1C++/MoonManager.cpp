#include <iostream>
#include <vector>
#include <map>
#include "AbstractMoon.h"
#include "Employee.h"
#include "RandomGenerator.h"

class MoonManager {
private:
    std::vector<AbstractMoon*> moons;
    std::vector<Employee> employees;
    RandomGenerator rd;
    std::map<std::string, std::vector<float>> moonMap{
        {"Corporation", {0.0f, 0.0f, 0.0f}},
        {"Prototyping", {3.0f, 30.0f, 0.5f}},
        {"Insurance", {5.0f, 50.0f, 0.45f}},
        {"Pledge", {30.0f, 50.0f, 0.40f}},
        {"Defence", {10.0f, 70.0f, 0.35f}}
    };

public:
    MoonManager() {
        for (std::string i : {"Corporation", "Prototyping", "Insurance", "Pledge", "Defence"}) {
            registerMoon(i);
        }
    }

    void registerMoon(std::string moonName) {
        AbstractMoon* moon = new AbstractMoon(moonName, moonMap[moonName][0], moonMap[moonName][1], moonMap[moonName][2]);
        moons.push_back(moon);
    }

    AbstractMoon* moon(std::string moonName) {
        for (AbstractMoon* moon : moons) {
            if (moon->name() == moonName) {
                return moon;
            }
        }
        return nullptr; // Return nullptr if moon not found
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

    int addEmployee(std::vector<Employee> employees,
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

        for (int i = 0; i < numExplorers; ++i) {
            int revenue = rd.generateInt(minScrapValue * scrapValueMultiplier, maxScrapValue * scrapValueMultiplier);
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
        this->employees = employees;

        return totalRevenue;
    }

    std::vector<Employee> getRemainingEmployees() {
        return employees;
    }

    void resetEmployees() {
        employees.clear();
    }
};
