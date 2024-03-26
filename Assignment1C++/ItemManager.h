#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <vector>
#include "Item.h" // Assuming Item class is defined in Item.h

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
    void showStore();
    void buyItem(std::string itemName);
};

#endif // ITEM_MANAGER_H