#include <iostream>
#include <vector>
#include <map>
#include "ItemManager.h"
#include "Item.h"

ItemManager::ItemManager() {
    // Initialize items from itemList
    for (const auto& pair : itemList) {
        // Create new Item objects and add them to the items vector
        Item* item = new Item(pair.first, pair.second[0], pair.second[1], pair.second[2], pair.second[3], pair.second[4], pair.second[5]);
        registerItem(item);
    }
}

void ItemManager::registerItem(Item* item) {
    items.push_back(item);
}

// Displays the player's inventory
void ItemManager::showInventory() {
    std::cout << "The following items are available.\n"
        "---------------------------------------\n" << std::endl;

    // Display each bought item in the inventory
    for (Item* item : boughtItems) {
        std::cout << "* " << item->getName() << "\n" << std::endl;
    }
}

// Displays the items available for purchase in the store
std::vector<std::string> ItemManager::showStore() {
    std::vector<std::string> commands;

    std::cout << "Available Items:\n";

    // Display each item in the store and add its name to commands vector
    for (Item* item : items) {
        std::cout << item->getName() << " // Price: $" << item->getPrice() << std::endl;
        commands.push_back(item->getName());
    }

    return commands;
}

// Allows the player to buy an item from the store
int ItemManager::buyItem(std::string itemName) {
    int newBalance = 0;
    // Iterate through each item in the store
    for (Item* item : items) {
        // Check if the item name matches the desired item
        if (item->getName() == itemName) {
            // Add the item to the boughtItems vector and update the balance
            std::cout << item->getName() << std::endl;
            boughtItems.push_back(item);
            newBalance = item->getPrice();
            break;
        }
    }

    return -(newBalance);
}

// Get the list of bought items
std::vector<Item*> ItemManager::getBoughtItems() {
    return boughtItems;
}

void ItemManager::showBoughtItems() {
    for (Item* item : items) {
        std::cout << "*" << item->getName() << std::endl;
    }
}

// Calculate multiplier values based on bought items
std::vector<float> ItemManager::calculator() {
    std::vector<float> multiplierValues = { 1, 1, 1, 1, 1 };

    // Iterate through each bought item
    for (Item* item : boughtItems) {
        // Multiply each multiplier value by the corresponding value from the bought item
        multiplierValues[0] *= item->getSvm();
        multiplierValues[1] *= item->getEscm();
        multiplierValues[2] *= item->getOscm();
        multiplierValues[4] *= item->getLrm();

        // Check if the item is a Teleporter and update the multiplier value accordingly
        if (item->getName() == "Teleporter") {
            multiplierValues[3] = item->getEsc();
        }
    }

    return multiplierValues;
}

ItemManager::~ItemManager() {
    // Destructor
    // Clean up dynamically allocated memory for items
    for (Item* item : items) {
        delete item;
    }
}
