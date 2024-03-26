#include <iostream>

class Game {
private:
	int cargoValue;
	int balance;
	int quota;
	int day;
	// Items[]

public:
	Game(int balance, int quota) :
		cargoValue(0),
		balance(balance),
		quota(quota),
		day(1){}


};