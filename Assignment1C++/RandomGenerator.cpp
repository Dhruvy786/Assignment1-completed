#include <iostream>
#include <random>
#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() : generator(std::random_device{}()) {

}

int RandomGenerator::generateInt(double A, double B) {
    std::uniform_int_distribution<int> distribution(static_cast<int>(A), static_cast<int>(B));
    return distribution(generator);
}

float RandomGenerator::generateFloat() {
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    return distribution(generator);
}

int RandomGenerator::generateRandomNumber(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}