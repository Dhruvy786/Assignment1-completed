#ifndef ITEM_H
#define ITEM_H

class Item {
private:
    std::string name;
    int price;

public:
    Item(std::string name, int price);

    std::string getName();

    int getPrice();

};

#endif // ITEM_H