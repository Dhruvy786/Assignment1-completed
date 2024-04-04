#include <iostream>

class Item {
private:
	std::string name;
	int price;

public:
	Item(std::string name, int price) {
		this->name = name;
		this->price = price;
	}

	std::string getName() {
		return name;
	}

	int getPrice() {
		return price;
	}
};