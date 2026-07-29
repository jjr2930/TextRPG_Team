#include <iostream>

#include "Monster.h"

Monster::Monster(std::string name, int minHp, int maxHp, int minPower, int maxPower, int dropExp, std::string dropItemName, int dropItemPrice, int level)
	: name(name), hp(RandomHp(minHp, maxHp, level)), power(power), dropExp(dropExp), dropItemName(dropItemName), dropItemPrice(dropItemPrice) {}

int Monster::GetHp() { return hp; }
int Monster::GetPower() { return power; }
int Monster::GetDropExp() { return dropExp; }
std::string Monster::GetName() { return name; }
std::string Monster::GetDropItemName() { return dropItemName; }
int Monster::GetDropItemPrice() { return dropItemPrice; }

void Monster::SetHp(int hp) { this->hp = hp; }
void Monster::SetPower(int power) { this->power = power; }

int Monster::RandomHp(int min, int max, int level) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max); // 1부터 10까지 범위
    int random = dis(gen);

    return random * level;
}

int Monster::RandomPower(int min, int max, int level)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    int random = dis(gen) * 2;

    return random * level;
}