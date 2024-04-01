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
	std::vector<std::string> define_items() {
		std::vector<std::string> commands = itemManager.show_store();

		return commands;
	}

	void show_welcome_screen() {
		std::cout << "    ___               _ _           ___                 \n" \
					 "   /   \\___  __ _  __| | |_   _    / __\\___  _ __ _ __  \n" \
					 "  / /\\ / _ \\/ _` |/ _` | | | | |  / /  / _ \\| '__| '_ \\ \n" \
					 " / /_//  __/ (_| | (_| | | |_| | / /__| (_) | |  | |_) |\n" \
					 "/___,' \\___|\\__,_|\\__,_|_|\\__, | \\____/\\___/|_|  | .__/ \n" \
					 "                          |___/                  |_|    \n" << std::endl;
		std::cout << "Welcome!\n"
					 "We trust you will be a great asset to the corporation!\n\n"
					 "============ = DAY 1 ============ =\n"
					 "Current cargo value : $" << cargoValue << "\n"
					 "Current balance : $" << balance << "\n"
					 "Current quota : $" << quota << "(3 days left to meet quota)\n"
					 "Currently orbiting : " << currentMoon << "\n\n"
					 "> MOONS\n"
					 "To see the list of moons the autopilot can route to.\n\n"
					 "> STORE\n"
					 "To see the company store's selection of useful items.\n\n"
					 "> INVENTORY\n"
					 "To see the list of items you've already bought.\n\n" << std::endl;
	}

	// Checks if the command is in the array of commands available
	bool check_command(std::string& command, const std::vector<std::string>& commands) {
		for (const auto& valid_command : commands) {
			if (command == valid_command) {
				return true;
			}
		}

		return false;
	}

	int run_game() {
		show_welcome_screen();
		std::vector<std::string> startingCommands = { "moons", "store", "inventory" };
		std::string chosenCommand = read_and_dispatch_commands(startingCommands);
		// Buy an item
		if (chosenCommand == "store") {
			std::vector<std::string> items = define_items();
			chosenCommand = read_and_dispatch_commands(items);
			int newBalance = itemManager.buy_item(chosenCommand);
			update_balance(newBalance);
		}

		// Show inventory
		else if (chosenCommand == "invetory") {

		}

		// Go to moons
		else if (chosenCommand == "moons") {

		}
	}

	int run_day_loop() {}
	
	// Reads the command and returns the chosen command 
	std::string read_and_dispatch_commands(const std::vector<std::string>& commands) {
		std::string command;

		while (true) {
			std::cout << "> ";
			std::cin >> command;

			if (check_command(command, commands)) {
				return command;
			}
			else {
				std::cout << "Invalid command. Please enter a valid command.\n" << std::endl;
			}
		}
	}

	int handle_land_command() {

	}
	int handle_leave_command() {

	}
	int handle_exit_command() {

	}

	void update_balance(int amount) {
		balance = balance + amount;
	}

	int update_current_moon(std::string moon_name) {

	}
	int update_game_phase(GamePhase phase) {

	}
	int update_cargo_value(int amount) {

	}
	int update_alive_employees(int count) {

	}

};