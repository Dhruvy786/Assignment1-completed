#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <vector>
#include "Item.h"

class ItemManager {
private:
    std::vector<Item*> items;

public:
    // Constructor and Destructor
    ItemManager();
    ~ItemManager();

    // Methods
    void registerItem(Item* item);
    void showInventory();
    std::vector<std::string> show_store();
    int buy_item(std::string itemName);
};

#endif // ITEM_MANAGER_H