#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "ItemManager.h"
#include "MoonManager.h"
#include "RandomGenerator.h"

class Game {
private:
    int cargoValue;
    int balance;
    int quota;
    int day;
    std::string currentMoon;
    int remainingEmployees;
    ItemManager itemManeger;
    MoonManager moonManager;
    RandomGenerator randomGenerator;

public:
    // Constructor
    Game();

    // Methods
    void show_welcome_screen() const;
    void next_day();
    void land_on_moon(const std::string& moonName);
    void leave_moon();
    void buy_item(const std::string& itemName);
    void sell_scrap(int amount);
    bool check_quota_met();

    // Getter methods
    int get_cargo_value() const;
    int get_balance() const;
    int get_quota() const;
    int get_day() const;
    std::string get_current_moon() const;
    int get_remaining_employees() const;
};

#endif // GAME_H