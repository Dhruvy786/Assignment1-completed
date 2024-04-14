/*#include <iostream>
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

	// Utilize splitArguments from util.h to parse the input command
	util::splitArguments(cmd, tokens);

	// Handle the commands accordingly
	if (!tokens.empty() && checkCommand(tokens[0], commands)) {
		return tokens[0];
	}
	else {
		std::cout << "Invalid command." << std::endl;
		return ""; // Return empty string for invalid command
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
}*/