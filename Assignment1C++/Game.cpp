/*#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include "Game.h"
#include "ItemManager.h"
#include "MoonManager.h"
#include "RandomGenerator.h"

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
}

void Game::initialiseGame() {
	balance = 50;
	quota = 150;
	currentMoon = "Corporation";
	remainingEmployees = 4;

	showWelcomeScreen();

	phase = GamePhase::Orbiting;
}

void Game::defineMoons() {

}

std::vector<std::string> Game::defineItems() {
	std::vector<std::string> commands = itemManager.showStore();

	return commands;
}

void Game::showWelcomeScreen() const {
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
bool Game::checkCommand(std::string& command, const std::vector<std::string>& commands) {
	for (const auto& validCommand : commands) {
		if (command == validCommand) {
			return true;
		}
	}

	return false;
}

int Game::runGame() {
	showWelcomeScreen();
	initialiseGame();
	std::vector<std::string> startingCommands = { "moons", "store", "inventory" };
	std::string chosenCommand = readAndDispatchCommands(startingCommands);
	std::string* cmdPtr = &chosenCommand;
	moonManager.setRandomWeather();

	while (*cmdPtr != "exit") {
		// Buy an item
		if (*cmdPtr == "store") {
			std::vector<std::string> items = defineItems();
			std::string cmd = readAndDispatchCommands(items);
			std::string itemName = cmd;

			int newBalance = itemManager.buyItem(itemName);
			updateBalance(newBalance);
		}

		// Show inventory
		else if (*cmdPtr == "inventory") {
			std::cout << "The following items are available.\n"
						 "---------------------------------------" << std::endl;
			if (itemManager.getBoughtItems().size() > 0) {
				itemManager.showBoughtItems();
			}
			else {
				std::cout << "(Empty)" << std::endl;
			}

			std::cout << "\nBalance: " << balance << " (quota is $" << quota << ")\n"
						 "Cargo Value: $" << cargoValue << "\n" << std::endl;
		}

		// Go to moons
		else if (*cmdPtr == "moons") {
			moonManager.showMoons();
			std::cout << "Balance: " << balance << std::endl;
			*cmdPtr = readAndDispatchCommands(moonManager.getMoonNames());
			currentMoon = *cmdPtr;
			updateGamePhase(GamePhase::Orbiting);
			*cmdPtr = readAndDispatchCommands({ "land", "leave" });
			if (*cmdPtr == "land") {
				// Land on moon
				handleLandCommand(currentMoon);
			}
			else if (*cmdPtr == "leave") {
				handleLeaveCommand();
			}
		}
	}

	return 0;
}

void Game::runDayLoop() {}

// Reads the command and returns the chosen command 
std::string Game::readAndDispatchCommands(const std::vector<std::string>& commands) {
	std::string* command = new std::string; // Allocate memory for command pointer
	std::vector<std::string> tokens;
	moonManager.setRandomWeather();

	while (true) {
		std::cout << "> ";
		std::getline(std::cin, *command); // Read entire line of input
		std::istringstream iss(*command); // Initialize stringstream with input

		tokens.clear(); // Clear tokens vector for each iteration

		while (iss >> *command) {
			tokens.push_back(*command);
		}

		// Command processing based on game state and tokens
		if (tokens.empty()) {
			std::cout << "Invalid command. Please enter a command.\n";
			continue; // Skip further processing if command is empty
		}

		// Check if the first token is "route" and the second token is a valid moon name
		if (tokens.size() >= 2 && tokens[0] == "route") {
			std::string moonName = tokens[1];

			// Check if the moonName exists in the moons vector
			if (checkCommand(moonName, commands)) {
				// Valid route command
				std::cout << "Now orbiting " << moonName << ". Use the LAND command to land." << std::endl;
				currentMoon = moonName;
				// Proceed with routing logic
				delete command; // Delete command pointer
				return moonName;
			}
			else {
				// Invalid moon name
				std::cout << "Invalid moon name: " << moonName << std::endl;
			}
		}
		else if (phase == GamePhase::Landed && tokens.size() >= 2 && tokens[0] == "send" && currentMoon != "Corporation") {
			// Handle "send" command when landed
			int value = std::stoi(tokens[1]);

			if (value <= remainingEmployees) {
				delete command; // Delete command pointer
				return tokens[1];
			}
			else {
				std::cout << "You only have " << remainingEmployees << " employees." << std::endl;
			}
		}
		else if (phase == GamePhase::Landed && tokens[0] == "send" && tokens.size() < 2) {
			std::cout << "Bad command; the syntax is: \"send numberOfEmployees\"\n" << std::endl;
		}
		else if (checkCommand(tokens[0], commands)) {
			// Check if the command is valid
			delete command; // Delete command pointer
			return tokens[0];
		}
		else if (tokens[0] == "leave") {
			std::cout << "You entered leave commands." << std::endl;
			delete command; // Delete command pointer
			return tokens[0];
		}
		else {
			// Invalid command
			std::cout << "Invalid command. Please enter a valid command.\n";
		}
	}

	delete command; // Delete command pointer

	return "";
}


void Game::handleLandCommand(std::string currentMoon) {
	updateGamePhase(GamePhase::Landed);
	AbstractMoon* moon = moonManager.moon(currentMoon);
	updateCurrentMoon(currentMoon);
	std::vector<std::string> commands;
	std::cout << "WELCOME TO " << moon->name() << "!\n"
		<< "Current cargo value : $" << cargoValue << "\n"
		<< "Current balance : $" << balance << "\n"
		<< "Current quota : $" << quota << "(3 days left to meet quota)\n"
		<< "Number of employees : " << remainingEmployees << "\n\n" << std::endl;
	if (currentMoon != "Corporation") {
		std::cout << "Type SEND followed by the number of employees you wish to send inside the\n"
			<< "facility. All the other employees will stay on\n"
			<< " the ship.\n"
			<< "Type LEAVE to leave the planet.\n"
			<< std::endl;
		commands = { "send", "leave" };
	}
	else {
		std::cout << "Type SELL to sell your cargo contents and increase your balance and achieve quota.\n"
			"Specify the amount to sell after the SELL word to only sell a portion of your\n"
			"cargo.\n"
			"Type LEAVE to leave the planet.\n"
			<< std::endl;
		commands = { "sell", "leave" };
	}
	
	std::string sentEmployeesStr = readAndDispatchCommands(commands);
	while (sentEmployeesStr != "leave") {
		std::cout << cargoValue << std::endl;
		int sentEmployees = std::stoi(sentEmployeesStr);

		// Call addEmployee method directly
		auto expeditionResult = moonManager.addEmployee(
			remainingEmployees,
			sentEmployees,
			moon->getBsc(),
			moon->getMinScrapValue(),
			moon->getMaxScrapValue(),
			(1 * moon->getMultiplierValue()[1] * itemManager.calculator()[1]),
			(1 * moon->getMultiplierValue()[2] * itemManager.calculator()[2]),
			(1 * moon->getMultiplierValue()[0] * itemManager.calculator()[0]),
			itemManager.calculator()[3],
			itemManager.calculator()[4]
		);

		int deadExplorers = std::get<0>(expeditionResult);
		int deadOperators = std::get<1>(expeditionResult);
		int revenue = std::get<2>(expeditionResult);

		int returnedEmployees = sentEmployees - deadExplorers - deadOperators;

		std::cout << returnedEmployees << " employees made it back to the ship, bringing $" << revenue << " worth of scrap. " << deadExplorers + deadOperators << " died." << std::endl;

		if (remainingEmployees > 0) {
			updateCargoValue(revenue);
		}

		remainingEmployees = remainingEmployees - sentEmployees + returnedEmployees;

		sentEmployeesStr = readAndDispatchCommands(commands);
	}
	std::cout << cargoValue << std::endl;
}

void Game::handleLeaveCommand() {
	phase = GamePhase::Orbiting;
}

void Game::handleExitCommand() {

}

void Game::updateBalance(int amount) {
	balance = balance + amount;
}

void Game::updateCurrentMoon(std::string moonName) {
	currentMoon = moonName;
}

int Game::updateGamePhase(GamePhase phase) {
	this->phase = phase;
	return 0;
}

void Game::updateCargoValue(int amount) {
	cargoValue = cargoValue + amount;
}

void Game::updateAliveEmployees(int count) {
	remainingEmployees = count;
}*/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include "Game.h"
#include "ItemManager.h"
#include "MoonManager.h"
#include "../util/util.h"

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
}

void Game::initialiseGame() {
	balance = 50;
	quota = 150;
	currentMoon = "Corporation";
	remainingEmployees = 4;

	showWelcomeScreen();

	phase = GamePhase::Orbiting;
}

std::vector<std::string> Game::defineItems() {
	std::vector<std::string> commands = itemManager.showStore();

	return commands;
}

void Game::defineMoons() {
	for (std::string moonName : moonManager.getMoonNames()) {
		std::cout << moonName << std::endl;
	}
}

void Game::showWelcomeScreen() const {
	std::cout << "=============" << day << "============= \n"
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

bool Game::checkCommand(std::string& command, const std::vector<std::string>& commands) {
	for (const auto& validCommand : commands) {
		if (command == validCommand) {
			return true;
		}
	}

	return false;
}

int Game::runGame() {
	while (true) {
		if (phase == GamePhase::Orbiting) {
			std::vector<std::string> commands = { "moons", "store", "inventory" };
			std::string cmd = readAndDispatchCommands(commands);
			if (cmd == "moons") {
				defineMoons();
				std::string moon = routeToMoon();
			}
			else if (cmd == "store") {
				defineItems();
			}
			else if (cmd == "inventory") {
				std::cout << "The following items are available.\n"
					"---------------------------------------" << std::endl;
				if (itemManager.getBoughtItems().size() > 0) {
					itemManager.showBoughtItems();
				}
				else {
					std::cout << "(Empty)" << std::endl;
				}
			}
			else if (cmd == "exit") {
				handleExitCommand();
			}
			else {
				// Invalid command
			}
		}
		else if (phase == GamePhase::Landed) {
			handleLandCommand(currentMoon);
		}
	}
	return 0;
}

void Game::runDayLoop() {
	day += 1;
}

std::string Game::routeToMoon() {
	std::string moon = readAndDispatchCommands(moonManager.getMoonNames());
	while (moon != "") {
		moon = readAndDispatchCommands(moonManager.getMoonNames());
	}
	std::cout << "Routing to " << moon << std::endl;
	updateGamePhase(GamePhase::Landed);

	return moon;
}

std::string Game::readAndDispatchCommands(const std::vector<std::string>& commands) {
	std::string cmd;
	std::cout << "> ";
	std::getline(std::cin, cmd);

	std::vector<std::string> tokens;
	std::istringstream iss(cmd);

	// Tokenize the input command
	std::string token;
	while (iss >> token) {
		tokens.push_back(token);
	}

	// Handle the commands accordingly
	if (!tokens.empty() && checkCommand(tokens[0], commands)) {
		return tokens[0];
	}
	else {
		std::cout << "Invalid command." << std::endl;
		return "";
	}
}

int Game::handleMoonCommands(AbstractMoon* moon) {
	std::string cmd;

	if (currentMoon == "Corporation") {
		cmd = readAndDispatchCommands({ "sell", "leave" });
		if (cmd != "leave") {
			int cargo = std::stoi(cmd);

			return cargo;
		}

		return -1;
	}
	else {
		cmd = readAndDispatchCommands({ "send", "leave" });
		if (cmd != "leave") {
			int sentEmployees = std::stoi(cmd);

			return sentEmployees;
		}

		return -1;
	}
}

void Game::handleLandCommand(std::string currentMoon) {
	updateGamePhase(GamePhase::Landed);
	AbstractMoon* moon = moonManager.moon(currentMoon);
	updateCurrentMoon(currentMoon);
	if (currentMoon == "Corporation") {
		int newCargo = handleMoonCommands(moon);
		cargoValue += newCargo;
	}
	else {
		int sentEmployees = handleMoonCommands(moon);
		auto expeditionResult = moonManager.addEmployee(
			remainingEmployees,
			sentEmployees,
			moon->getBsc(),
			moon->getMinScrapValue(),
			moon->getMaxScrapValue(),
			(1 * moon->getMultiplierValue()[1] * itemManager.calculator()[1]),
			(1 * moon->getMultiplierValue()[2] * itemManager.calculator()[2]),
			(1 * moon->getMultiplierValue()[0] * itemManager.calculator()[0]),
			itemManager.calculator()[3],
			itemManager.calculator()[4]
		);

		int deadExplorers = std::get<0>(expeditionResult);
		int deadOperators = std::get<1>(expeditionResult);
		int revenue = std::get<2>(expeditionResult);

		int returnedEmployees = sentEmployees - deadExplorers - deadOperators;

		std::cout << returnedEmployees << " employees made it back to the ship, bringing $" << revenue << " worth of scrap. " << deadExplorers + deadOperators << " died." << std::endl;

		if (remainingEmployees > 0) {
			updateCargoValue(revenue);
		}

		updateAliveEmployees(-(sentEmployees + returnedEmployees));
	}
}

void Game::handleLeaveCommand() {

}

void Game::handleExitCommand() {

}

void Game::updateBalance(int amount) {
	balance = balance + amount;
}

void Game::updateCurrentMoon(std::string moonName) {
	currentMoon = moonName;
}

int Game::updateGamePhase(GamePhase phase) {
	this->phase = phase;

	return 0;
}

void Game::updateCargoValue(int amount) {
	cargoValue = cargoValue + amount;
}

void Game::updateAliveEmployees(int count) {
	remainingEmployees = remainingEmployees + count;
}