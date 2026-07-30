#include <iostream>
#include <random>
#include "Monster.h"

Monster::Monster(std::string name, int minHp, int maxHp, int minPower, int maxPower, int dropExp, Item* item, int gold, int level)
	: name(name), hp(RandomHp(minHp, maxHp, level)), power(RandomPower(minPower, maxPower, level)), dropExp(dropExp), item(item), gold(gold) {}

int Monster::GetHp() { return hp; }
int Monster::GetPower() { return power; }
int Monster::GetDropExp() { return dropExp; }
std::string Monster::GetName() { return name; }
Item Monster::GetItem() { return *item; }

void Monster::SetHp(int hp) { this->hp = hp; }
void Monster::SetPower(int power) { this->power = power; }

int Monster::RandomGold() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(gold - gold / 2, gold + gold / 2);
    return dis(gen);
}

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
    int random = dis(gen);

    return random * level;
}