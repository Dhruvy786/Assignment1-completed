#include <iostream>
#include <vector>
#include <map>
#include "ItemManager.h"
#include "Item.h"


ItemManager::ItemManager() {
    for (const auto& pair : itemList) {
        items.push_back(new Item(pair.first, pair.second[0], pair.second[1], pair.second[2], pair.second[3], pair.second[4], pair.second[5]));
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

std::vector<Item*> ItemManager::getBoughtItems() {
    return boughtItems;
}

std::vector<float> ItemManager::calculator() {
    std::vector<float> multiplierValues = { 1, 1, 1, 1, 1 };
    
    for (Item* item : boughtItems) {
        multiplierValues[0] *= item->getSvm();
        multiplierValues[1] *= item->getEscm();
        multiplierValues[2] *= item->getOscm();
        multiplierValues[4] *= item->getLrm();

        if (item->getName() == "Teleporter") {
            multiplierValues[3] = item->getEsc();
        }
    }

    return multiplierValues;
}

ItemManager::~ItemManager() {

}