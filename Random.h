#pragma once
#include <random>


class Random {
private:
	std::mt19937 gen;
public:
	Random();
	int GetRandomValue(int min, int max);
};

