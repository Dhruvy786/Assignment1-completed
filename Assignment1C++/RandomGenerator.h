// RandomGenerator.h

#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <iostream>
#include <random>

class RandomGenerator {
private:
    std::mt19937 generator;

public:
    RandomGenerator();

    int generateInt(double A, double B);

    float generateFloat();

    int generateRandomNumber(int min, int max);
};

#endif // RANDOMGENERATOR_H