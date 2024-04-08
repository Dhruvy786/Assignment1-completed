#include <iostream>
#include <vector>
#include <map>
#include "ItemManager.h"
#include "Item.h"


ItemManager::ItemManager() {
    for (const auto& pair : itemList) {
        items.push_back(new Item(pair.first, pair.second));
    }
}

// Displays the player's inventory
void ItemManager::showInventory() {
    std::cout << "The following items are available.\n"
                    "---------------------------------------\n" << std::endl;

    for (Item* item : boughtItems) {
        std::cout << "* " << item->getName() << "\n" << std::endl;
    }
}

// Displays the items available for purchase in the store
std::vector<std::string> ItemManager::show_store() {
    std::vector<std::string> commands;

    std::cout << "Available Items:\n";

    for (Item* item : items) {
        std::cout << item->getName() << " // Price: $" << item->getPrice() << std::endl;
        commands.push_back(item->getName());
    }

    return commands;
}

// Allows the player to buy an item from the store
int ItemManager::buyItem(std::string itemName) {
    int newBalance = 0;
    for (Item* item : items) {
        if (itemName == item->getName()) {
            boughtItems.push_back(item);
            newBalance = item->getPrice();
            break;
        }
    }

    return newBalance;
}

ItemManager::~ItemManager() {

}