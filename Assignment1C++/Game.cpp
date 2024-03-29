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
	//std::vector<Employee> employees;


public:
	Game() :
		cargoValue(0),
		balance(0),
		quota(0),
		day(1),
		currentMoon(""),
		remainingEmployees(0),
		itemManager(),
		moonManager(),
		randomGenerator(),
		phase(GamePhase::Orbiting) {}

	void initialiseGame() {
		balance = 50;
		quota = 150;
		currentMoon = "Corporation";
		remainingEmployees = 4;

		show_welcome_screen();

		phase = GamePhase::Orbiting;
	}

	int define_moons() {

	}
	int define_items() {}

	int show_welcome_screen() {
		std::cout << "    ___               _ _           ___                 \n" \
					 "   /   \\___  __ _  __| | |_   _    / __\\___  _ __ _ __  \n" \
					 "  / /\\ / _ \\/ _` |/ _` | | | | |  / /  / _ \\| '__| '_ \\ \n" \
					 " / /_//  __/ (_| | (_| | | |_| | / /__| (_) | |  | |_) |\n" \
					 "/___,' \\___|\\__,_|\\__,_|_|\\__, | \\____/\\___/|_|  | .__/ \n" \
					 "                          |___/                  |_|    " << std::endl;
		std::cout << "Welcome!\n"
					 "We trust you will be a great asset to the corporation!\n\n"
					 "============ = DAY 1 ============ =\n"
					 "Current cargo value : $0\n"
					 "Current balance : $50\n"
					 "Current quota : $150(3 days left to meet quota)\n"
					 "Currently orbiting : Corporation\n\n"
					 "> MOONS\n"
					 "To see the list of moons the autopilot can route to.\n\n"
					 "> STORE\n"
					 "To see the company store's selection of useful items.\n\n"
					 "> INVENTORY\n"
					 "To see the list of items you've already bought.\n\n" 
					 "> " << std::endl;

		return 0;
	}

	int run_game() {}
	int run_day_loop() {}
	std::string read_and_dispatch_commands() {
		std::string command;

		while (true) {
			std::cout << "Enter a command: ";
			std::cin >> command;

			if (command == "LAND" || command == "LEAVE" || command == "EXIT") {
				return command;
			}
			else {
				std::cout << "Invalid command. Please enter a valid command.\n" << std::endl;
			}
		}
	}

	int handle_land_command() {}
	int handle_leave_command() {}
	int handle_exit_command() {}
	int update_balance(int amount) {}
	int update_current_moon(std::string moon_name) {}
	int update_game_phase(GamePhase phase) {}
	int update_cargo_value(int amount) {}
	int update_alive_employees(int count) {}

};