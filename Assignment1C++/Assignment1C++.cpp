﻿// Assignment1C++.cpp : Defines the entry point for the application.
//

#include "Assignment1C++.h"
#include "Game.h"

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
    Game* game = new Game();
    
    int num = game->runGame();

    delete game;

	return 0;
}
