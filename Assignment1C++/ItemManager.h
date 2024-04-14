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
    std::map<std::string, std::vector<float>> itemList{
            {"Flashlight", {60, 1, 1.05, 1, 1, 1}},
            {"Shovel", {100, 1, 1.05, 1, 1, 1}},
            {"Pro-flashlight", {200, 1, 1.1, 1, 1, 1}},
            {"Teleporter", {300, 1, 1, 1, 0.33, 1}},
            {"Inverse-teleporter", {400, 1.1, 0.8, 1, 1, 1}},
            {"Backpack", {500, 1, 1, 1, 1, 1.25}},
            {"Hydraulics-Mk2", {1000, 1, 1, 1.25, 1, 1}}
    };

public:
    // Constructor and Destructor
    ItemManager();
    ~ItemManager();

    // Methods
    void registerItem(Item* item);
    void showInventory();
    std::vector<std::string> showStore();
    int buyItem(std::string itemName);
    std::vector<Item*> getBoughtItems();
    void showBoughtItems();
    std::vector<float> calculator();
};

#endif // ITEM_MANAGER_H
