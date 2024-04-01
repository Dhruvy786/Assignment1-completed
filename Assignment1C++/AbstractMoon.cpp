#include <iostream>
#include "AbstractMoon.h"

class AbstractMoon {
private:
	std::string name;
	std::string weather;

public:
	AbstractMoon(std::string moonName) {
		name = moonName;
		weather = "";
	};

	std::string getName() {
		return name;
	}

	std::string getWeather() {
		return weather;
	}

	void setWeather(std::string newWeather) {
		weather = newWeather;
	}
};