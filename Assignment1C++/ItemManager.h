#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

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
    // Constructor and Destructor
    ItemManager();
    ~ItemManager();

    // Methods
    void showInventory();
    std::vector<std::string> show_store();
    int buyItem(std::string itemName);
};

#endif // ITEM_MANAGER_H
