// RandomGenerator.h

#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <random>

class RandomGenerator {
private:
    std::mt19937 generator;

public:
    RandomGenerator();

    int generateInt(int A, int B);
    float generateFloat();
};

#endif // RANDOMGENERATOR_H
