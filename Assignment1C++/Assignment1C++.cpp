// Assignment1C++.cpp : Defines the entry point for the application.
//

#include "Assignment1C++.h"

using namespace std;

//
// Created by Nic on 19/02/2024.
//

#ifndef GAME_TITLE_H
#define GAME_TITLE_H

#define DEADLY_CORP_TITLE \
    "    ___               _ _           ___                 \n" \
    "   /   \\___  __ _  __| | |_   _    / __\\___  _ __ _ __  \n" \
    "  / /\\ / _ \\/ _` |/ _` | | | | |  / /  / _ \\| '__| '_ \\ \n" \
    " / /_//  __/ (_| | (_| | | |_| | / /__| (_) | |  | |_) |\n" \
    "/___,' \\___|\\__,_|\\__,_|_|\\__, | \\____/\\___/|_|  | .__/ \n" \
    "                          |___/                  |_|    "

#endif //GAME_TITLE_H

int main()
{
    std::cout << "1. MOONS                (Show available moons and their weather conditions)\n";
    std::cout << "2. ROUTE [nameOfMoon]   (Change currently orbited moon)\n";
    std::cout << "3. LAND                 (Land on the currently orbited moon)\n";
    std::cout << "4. SEND [employeeCount] (Send employees on expedition)\n";
    std::cout << "5. SELL [amount]        (Sell scrap for cash)\n";
    std::cout << "6. LEAVE                (Leave the current moon)\n";
    std::cout << "7. STORE                (View available items for purchase)\n";
    std::cout << "8. BUY [itemName]       (Purchase an item)\n";
    std::cout << "9. INVENTORY            (View purchased items)\n";
    std::cout << "10. EXIT                (Exit the game)\n";

	return 0;
}
