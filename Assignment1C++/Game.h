#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include "ItemManager.h"
#include "MoonManager.h"
#include "RandomGenerator.h"
#include "Employee.h"

class Game {
private:
    enum class GamePhase {
        Orbiting,
        Landed,
        Selling
    };

    int cargoValue;
    int balance;
    int quota;
    int day;
    std::string currentMoon;
    int remainingEmployees;
    ItemManager itemManager;
    MoonManager moonManager;
    RandomGenerator randomGenerator;
    GamePhase phase;
    std::vector<Employee> employees;

public:
    Game() {};

    void initialiseGame();

    int define_moons();

    std::vector<std::string> define_items();

    void show_welcome_screen() const;

    bool check_command(std::string& command, const std::vector<std::string>& commands);

    int run_game();

    int run_day_loop();

    std::string read_and_dispatch_commands(const std::vector<std::string>& commands);

    int handle_land_command(std::string currentMoon);

    int handle_leave_command();

    int handle_exit_command();

    void update_balance(int amount);

    int update_current_moon(std::string moon_name);

    int update_game_phase(GamePhase phase);

    void update_cargo_value(int amount);

    void update_alive_employees(int count);
};

#endif // GAME_H
