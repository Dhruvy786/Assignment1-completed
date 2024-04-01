#include <iostream>
#include <algorithm>
#include <sstream>
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
					 "=============" << day << "============= \n"
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
		std::string* cmdptr = &chosenCommand;

		// Buy an item
		if (*cmdptr == "store") {
			std::vector<std::string> items = define_items();
			*cmdptr = read_and_dispatch_commands(items);
			int newBalance = itemManager.buy_item(*cmdptr);
			update_balance(newBalance);
		}

		// Show inventory
		else if (*cmdptr == "inventory") {
			// Handle inventory command
		}

		// Go to moons
		else if (*cmdptr == "moons") {
			moonManager.show_moons();
			std::cout << "Balance: " << balance << std::endl;
			*cmdptr = read_and_dispatch_commands(moonManager.getMoons());
			currentMoon = *cmdptr;
			update_game_phase(GamePhase::Orbiting);
			*cmdptr = read_and_dispatch_commands({ "land", "leave" });
			if (*cmdptr == "land") {
				// Land on moon
				handle_land_command();
			}
		}
	}

	int run_day_loop() {}
	
	// Reads the command and returns the chosen command 
	std::string read_and_dispatch_commands(const std::vector<std::string>& commands) {
		std::string command;
		std::istringstream iss(command);
		std::vector<std::string> tokens;
		std::string token;
		while (iss >> token) {
			tokens.push_back(token);
		}
		while (true) {
			std::cout << "> ";
			std::cin >> command;
			// Check if the first word is "route" and the second word is a valid moon name
			if (tokens.size() >= 2 && tokens[0] == "route") {
				std::string moon_name = tokens[1];
				// Convert moon_name to lowercase for case-insensitive comparison
				std::transform(moon_name.begin(), moon_name.end(), moon_name.begin(), ::tolower);
				// Check if the moon_name exists in the moons vector
				if (std::find(commands.begin(), commands.end(), moon_name) != commands.end()) {
					// Valid route command
					std::cout << "Routing to " << moon_name << std::endl;
					std::cout << "Now orbiting " << moon_name << ". Use the LAND command to land." << std::endl;
					// Proceed with routing logic
					return moon_name;
				}
				else {
					// Invalid moon name
					std::cout << "Invalid moon name: " << moon_name << std::endl;
				}
			}
			else {
				if (check_command(command, commands)) {
					return command;
				}
				else {
					std::cout << "Invalid command. Please enter a valid command.\n" << std::endl;
				}
			}
		}
	}

	int handle_land_command() {
		update_game_phase(GamePhase::Landed);
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
		this->phase = phase;
		return 0;
	}
	int update_cargo_value(int amount) {

	}
	int update_alive_employees(int count) {

	}

};