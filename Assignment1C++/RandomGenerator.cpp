#include <iostream>
#include <random>

class RandomGenerator {
private:
    std::mt19937 generator;

public:
    RandomGenerator() : generator(std::random_device{}()) {}

    int generateInt(int A, int B) {
        std::uniform_int_distribution<int> distribution(A, B);
        return distribution(generator);
    }

    float generateFloat() {
        std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
        return distribution(generator);
    }
};