#include "Random.h"

Random::Random() : gen(std::random_device{}()) {}

int Random::GetRandomValue(int min, int max) {
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}
/*std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);*/