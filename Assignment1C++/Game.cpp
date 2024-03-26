#include <iostream>
#include "ItemManager.h"

class Game {
private:
	int cargoValue;
	int balance;
	int quota;
	int day;
	std::string currentMoon;
	int remainingEmployees;
	ItemManager itemManeger;

	// Items[]

public:
	Game(int balance, int quota) :
		cargoValue(0),
		balance(balance),
		quota(quota),
		day(1){}


};