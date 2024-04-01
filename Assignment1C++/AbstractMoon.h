#ifndef ABSTRACT_MOON_H
#define ABSTRACT_MOON_H

#include <vector>
#include "AbstractMoon.h"

class AbstractMoon {
private:
    std::string name;
    std::string weather;

public:
    // Constructor and Destructor
    AbstractMoon();

    std::string getName();

    std::string getWeather();

    void setWeather(std::string newWeather);

};

#endif // ABSTRACT_MOON_H