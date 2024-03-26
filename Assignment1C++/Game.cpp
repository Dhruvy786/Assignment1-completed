#include <iostream>
#include "ItemManager.h"
#include "MoonManager.h"
#include "RandomGenerator.h"

class Game {
	enum class GamePhase {
		Orbiting,
		Landed,
		Selling
	};

private:
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
	Game(int balance, int quota) :
		cargoValue(0),
		balance(balance),
		quota(quota),
		day(1),
		currentMoon(""),
		remainingEmployees(0),
		itemManager(),
		moonManager(),
		randomGenerator(),
		phase(GamePhase::Orbiting) {}

	void initialiseGame() {

	}

	int define_moons() {}
	int define_items() {}
	int show_welcome_screen() {}
	int run_game() {}
	int run_day_loop() {}
	int read_and_dispatch_commands() {}
	int handle_land_command() {}
	int handle_leave_command() {}
	int handle_exit_command() {}
	int update_balance(int amount) {}
	int update_current_moon(std::string moon_name) {}
	int update_game_phase(GamePhase phase) {}
	int update_cargo_value(int amount) {}
	int update_alive_employees(int count) {}

};