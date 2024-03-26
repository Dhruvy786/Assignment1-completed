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
	ItemManager itemManager;
	MoonManager moonManager;
	RandomGenerator randomGenerator;

	// Items[]

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
		randomGenerator() {}

	void initialiseGame() {

	}
};