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

    // Displays the player's inventory
    void showInventory() {
        std::cout << "The following items are available.\n"
                     "---------------------------------------\n" << std::endl;

        for (Item* item : boughtItems) {
            std::cout << "* " << item->getName() << "\n" << std::endl;
        }
    }

    // Displays the items available for purchase in the store
    std::vector<std::string> show_store() {
        std::vector<std::string> commands;

        std::cout << "Available Items:\n";

        for (Item* item : items) {
            std::cout << item->getName() << " // Price: $" << item->getPrice() << std::endl;
            commands.push_back(item->getName());
        }

        return commands;
    }

    // Allows the player to buy an item from the store
    int buy_item(std::string itemName) {
        int newBalance = 0;
        for (Item* item : items) {
            if (itemName == item->getName()) {
                boughtItems.push_back(item);
                newBalance = item->getPrice();
            }
        }

        return newBalance;
    }

    ~ItemManager() {

    }
};