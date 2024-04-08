#ifndef MOON_MANAGER_H
#define MOON_MANAGER_H

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
    MoonManager();

    void registerMoon(AbstractMoon* moon);

    AbstractMoon* moon(std::string moonName);

    void show_moons();

    std::string moonWeatherToString(AbstractMoon::MoonWeather weather);

    void route_to_moon(std::string moon_name);

    std::vector<std::string> getMoons();

    int addEmployee(std::vector<Employee> employees, 
        int numExplorers,
        double bsc,
        int minScrapValue,
        int maxScrapValue,
        double explorerSurvivalChanceMultiplier,
        double operatorSurvivalChanceMultiplier,
        double scrapValueMultiplier,
        double explorerSaveChance,
        double lootRecoveryMultiplier);

    std::vector<Employee> getRemainingEmployees();

    void resetEmployees();
};

#endif // MOON_MANAGER_H
