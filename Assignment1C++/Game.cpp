#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include "Game.h"
#include "ItemManager.h"
#include "MoonManager.h"
#include "RandomGenerator.h"
#include "Employee.h"

using namespace std;

Game::Game() :
	cargoValue(0),
	balance(0),
	quota(0),
	day(1),
	currentMoon(""),
	remainingEmployees(4),
	itemManager(),
	moonManager(),
	phase(GamePhase::Orbiting)
	{
	for (int i = 0; i < 4; i++) {
		Employee* employee = new Employee();
		employees.push_back(employee);
	}
}

void Game::initialiseGame() {
	balance = 50;
	quota = 150;
	currentMoon = "Corporation";
	remainingEmployees = 4;

	show_welcome_screen();

	phase = GamePhase::Orbiting;
}

void Game::define_moons() {

}

std::vector<std::string> Game::define_items() {
	std::vector<std::string> commands = itemManager.show_store();

	return commands;
}

void Game::show_welcome_screen() const {
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
bool Game::check_command(std::string& command, const std::vector<std::string>& commands) {
	for (const auto& valid_command : commands) {
		if (command == valid_command) {
			return true;
		}
	}

	return false;
}

int Game::run_game() {
	show_welcome_screen();
	initialiseGame();
	std::vector<std::string> startingCommands = { "moons", "store", "inventory" };
	std::string chosenCommand = read_and_dispatch_commands(startingCommands);
	std::string* cmdptr = &chosenCommand;
	moonManager.setRandomWeather();

	// Buy an item
	if (*cmdptr == "store") {
		std::vector<std::string> items = define_items();
		std::string cmd = read_and_dispatch_commands(items);
		std::string itemName = cmd;
		int newBalance = itemManager.buyItem(itemName);
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
			handle_land_command(currentMoon);
		}
	}

	return 0;
}

void Game::run_day_loop() {}
	
// Reads the command and returns the chosen command 
std::string Game::read_and_dispatch_commands(const std::vector<std::string>& commands) {
	std::string command;
	std::vector<std::string> tokens;
	moonManager.setRandomWeather();

	while (true) {
		std::cout << "> ";
		std::getline(std::cin, command); // Read entire line of input
		std::istringstream iss(command); // Initialize stringstream with input

		tokens.clear(); // Clear tokens vector for each iteration

		while (iss >> command) {
			tokens.push_back(command);
		}

		// Command processing based on game state and tokens
		if (tokens.empty()) {
			std::cout << "Invalid command. Please enter a command.\n";
			continue; // Skip further processing if command is empty
		}

		// Check if the first token is "route" and the second token is a valid moon name
		if (tokens.size() >= 2 && tokens[0] == "route") {
			std::string moon_name = tokens[1];

			// Check if the moon_name exists in the moons vector
			if (check_command(moon_name, commands)) {
				// Valid route command
				std::cout << "Now orbiting " << moon_name << ". Use the LAND command to land." << std::endl;
				currentMoon = moon_name;
				// Proceed with routing logic
				return moon_name;
			}
			else {
				// Invalid moon name
				std::cout << "Invalid moon name: " << moon_name << std::endl;
			}
		}
		else if (phase == GamePhase::Landed && tokens.size() >= 2 && tokens[0] == "send") {
			// Handle "send" command when landed
			int value = std::stoi(tokens[1]);

			if (value <= remainingEmployees) {
				return tokens[1];
			}
			else {
				std::cout << "You only have " << remainingEmployees << " employees." << std::endl;
			}
		}
		else if (phase == GamePhase::Landed && tokens[0] == "send" && tokens.size() < 2) {
			std::cout << "Bad command; the syntax is: \"send numberOfEmployees\"\n" << std::endl;
		}
		else if (check_command(tokens[0], commands)) {
			// Check if the command is valid
			return tokens[0];
		}
		else if (tokens[0] == "leave") {
			std::cout << "You entered leave commands." << std::endl;
			return tokens[0];
		}
		else {
			// Invalid command
			std::cout << "Invalid command. Please enter a valid command.\n";
		}
	}
}

void Game::handle_land_command(std::string currentMoon) {
	update_game_phase(GamePhase::Landed);
	AbstractMoon* moon = moonManager.moon(currentMoon);
	update_current_moon(currentMoon);
	std::cout << "WELCOME TO " << moon->name() << "!\n"
		"Current cargo value : $" << cargoValue << "\n"
		"Current balance : $" << balance << "\n"
		"Current quota : $" << quota << "(3 days left to meet quota)\n"
		"Number of employees : " << remainingEmployees << "\n\n"
		"Type SEND followed by the number of employees you wish to send inside the\n"
		"facility.All the other employees will stay on\n"
		" the ship.\n"
		"Type LEAVE to leave the planet.\n" << std::endl;

	std::vector<std::string> commands = { "send", "leave" };
	std::string sentEmployeesStr = read_and_dispatch_commands(commands);
	while (sentEmployeesStr != "leave") {
		std::cout << cargoValue << std::endl;
		int sentEmployees = std::stoi(sentEmployeesStr);

		// Assign pointers to member functions and values
		int remainingEmp = remainingEmployees;
		int bsc = moon->getBsc();
		int minScrap = moon->getMinScrapValue();
		int maxScrap = moon->getMaxScrapValue();
		int multiplier1 = moon->getMultiplierValue()[1];
		int multiplier2 = moon->getMultiplierValue()[2];
		int multiplier0 = moon->getMultiplierValue()[0];
		int item3 = itemManager.calculator()[3];
		int item4 = itemManager.calculator()[4];

		// Call addEmployee method using pointers
		std::tuple<int, int, int> expeditionResult = moonManager.addEmployee(remainingEmp, sentEmployees,
			bsc, minScrap, maxScrap,
			(1 * multiplier1 * itemManager.calculator()[1]),
			(1 * multiplier2 * itemManager.calculator()[2]),
			(1 * multiplier0 * itemManager.calculator()[0]),
			item3, item4
		);

		int deadExplorers = std::get<0>(expeditionResult);
		int deadOperators = std::get<1>(expeditionResult);
		int revenue = std::get<2>(expeditionResult);

		int returnedEmployees = sentEmployees - deadExplorers - deadOperators;

		std::cout << returnedEmployees << " employees made it back to the ship, bringing $" << revenue << " worth of scrap. " << deadExplorers + deadOperators << " died." << std::endl;

		if (remainingEmployees > 0) {
			update_cargo_value(revenue);
		}

		remainingEmployees = remainingEmployees - sentEmployees + returnedEmployees;

		sentEmployeesStr = read_and_dispatch_commands(commands);
	}
	std::cout << cargoValue << std::endl;
}

void Game::handle_leave_command() {

}

void Game::handle_exit_command() {

}

void Game::update_balance(int amount) {
	balance = balance + amount;
}

void Game::update_current_moon(std::string moon_name) {

}

int Game::update_game_phase(GamePhase phase) {
	this->phase = phase;
	return 0;
}

void Game::update_cargo_value(int amount) {
	cargoValue = cargoValue + amount;
}

void Game::update_alive_employees(int count) {
	remainingEmployees = count;
}
