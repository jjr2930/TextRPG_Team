#include <iostream>
#include "Monster.h"


Monster::Monster(std::string name, int minHp, int maxHp, int minPower, int maxPower, int dropExp, Item* item, int gold, int level)
	: name(name), maxHp(RandomHp(minHp, maxHp, level)), power(RandomPower(minPower, maxPower, level)), dropExp(dropExp), item(item), gold(gold) {
    currentHp = maxHp;
}

int Monster::GetCurrentHp() { 
    return currentHp; 
}
int Monster::GetPower() { 
    return power; 
}
int Monster::GetDropExp() { 
    return dropExp; 
}
std::string Monster::GetName() { 
    return name; 
}
Item Monster::GetItem() { 
    return *item; 
}

void Monster::SetHp(int currentHp) {
    this->currentHp = currentHp;
}
void Monster::SetPower(int power) { 
    this->power = power; 
}

int Monster::RandomGold() {
    return random.GetRandomValue(gold - gold / 2, gold + gold / 2);
}

int Monster::RandomHp(int min, int max, int level) {
    return random.GetRandomValue(min, max) * level;
}

int Monster::RandomPower(int min, int max, int level)
{
    return random.GetRandomValue(min, max) * level;
}