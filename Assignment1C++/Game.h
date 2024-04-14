#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "ItemManager.h"
#include "MoonManager.h"

enum class GamePhase { Orbiting, Landed };

class Game {
public:
    Game();

    void initialiseGame();

    std::vector<std::string> defineItems();

    void defineMoons();

    void showWelcomeScreen() const;

    bool checkCommand(std::string& command, const std::vector<std::string>& commands);

    int runGame();

    void runDayLoop();

    std::string readAndDispatchCommands(const std::vector<std::string>& commands);

    int handleMoonCommands(AbstractMoon* moon);

    std::string routeToMoon();

    void handleLandCommand(std::string currentMoon);

    void handleLeaveCommand();

    void handleExitCommand();

    void updateBalance(int amount);

    void updateCurrentMoon(std::string moonName);

    int updateGamePhase(GamePhase phase);

    void updateCargoValue(int amount);

    void updateAliveEmployees(int count);

private:
    int cargoValue;
    int balance;
    int quota;
    int day;
    std::string currentMoon;
    int remainingEmployees;
    ItemManager itemManager;
    MoonManager moonManager;
    GamePhase phase;
};

#endif // GAME_H
