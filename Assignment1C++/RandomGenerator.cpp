#include <iostream>
#include <random>
#include "RandomGenerator.h"

// Constructor: Initializes the random number generator with a random device seed
RandomGenerator::RandomGenerator() : generator(std::random_device{}()) {

}

// Generates a random integer within the range [A, B]
int RandomGenerator::generateInt(double A, double B) {
    // Create a uniform integer distribution with the specified range
    std::uniform_int_distribution<int> distribution(static_cast<int>(A), static_cast<int>(B));
    
    return distribution(generator);
}

// Generates a random floating-point number within the range [0.0, 1.0)
float RandomGenerator::generateFloat() {
    // Create a uniform real distribution with the range [0.0, 1.0)
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    
    return distribution(generator);
}

// Generates a random integer within the range [min, max]
int RandomGenerator::generateRandomNumber(int min, int max) {
    // Create a uniform integer distribution with the specified range
    std::uniform_int_distribution<int> distribution(min, max);
    
    return distribution(generator);
}