#ifndef MOON_MANAGER_H
#define MOON_MANAGER_H

#include "AbstractMoon.h"

class MoonManager {
private:
    

public:
    // Constructor and Destructor
    MoonManager();

    void registerMoon(AbstractMoon* moon);

    void show_moons();

    std::vector<std::string> getMoons();
};

#endif // MOON_MANAGER_H