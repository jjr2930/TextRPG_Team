#include <iostream>

#include "Monster.h"

Monster::Monster(std::string name, int hp, int power, int dropExp, std::string dropItemName, int dropItemPrice)
	: name(name), hp(hp), power(power), dropExp(dropExp), dropItemName(dropItemName), dropItemPrice(dropItemPrice) {}

int Monster::GetHp() { return hp; }
int Monster::GetPower() { return power; }
int Monster::GetDropExp() { return dropExp; }
std::string Monster::GetName() { return name; }
std::string Monster::GetDropItemName() { return dropItemName; }
int Monster::GetDropItemPrice() { return dropItemPrice; }

