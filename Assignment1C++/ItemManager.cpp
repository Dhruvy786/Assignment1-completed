#include <iostream>
#include <vector>
#include <map>
#include "Item.h"

class ItemManager {
private:
    std::vector<Item*> items;
    std::vector<Item*> boughtItems;
    std::map<std::string, int> itemList{
            {"Flashlight", 60},
            {"Shovel", 100},
            {"Pro-flashlight", 200},
            {"Teleporter", 300},
            {"Inverse-teleporter", 400},
            {"Backpack", 500},
            {"Hydraulics-Mk2", 1000}
    };

public:
    ItemManager() {
        for (const auto& pair : itemList) {
            items.push_back(new Item(pair.first, pair.second));
        }
    }
    // Registers a new item in the item manager
    Item* registerItem(std::string) {
        Item* newItem = new Item();

        return newItem;
    }

    // Displays the player's inventory
    void showInventory() {

    }

    // Displays the items available for purchase in the store
    std::vector<std::string> show_store() {
        std::cout << "Available Items:\n";
        std::cout << "Flashlight // Price: $60\n";
        std::cout << "* Shovel // Price: $100\n";
        std::cout << "* Pro-flashlight // Price: $200\n";
        std::cout << "* Teleporter // Price: $300\n";
        std::cout << "* Inverse-teleporter // Price: $400\n";
        std::cout << "* Backpack // Price: $500\n";
        std::cout << "* Hydraulics-Mk2 // Price: $1000\n";

        std::vector<std::string> commands;

        return { "Flashlight", "Shovel", "Pro-flashlight", "Teleporter", "Inverse-teleporter", "Backpack", "Hydraulics-Mk2" };
    }

    // Allows the player to buy an item from the store
    int buy_item(std::string item_name) {
        Item* newItem = registerItem(item_name);
        int newBalance = newItem->getPrice();
        boughtItems.push_back(newItem);

        return newBalance;
    }

    ~ItemManager() {

    }
};