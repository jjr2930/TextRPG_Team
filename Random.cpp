#include "Random.h"

Random::Random() : gen(std::random_device{}()) {}

// 랜덤 함수 최소값과 최대값 필요
int Random::GetRandomValue(int min, int max) {
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}
/*std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);*/