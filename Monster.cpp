#include <iostream>

#include "Monster.h"

int Monster::GetHp() { return hp; }
int Monster::GetPower() { return power; }
int Monster::GetDropExp() { return dropExp; }
std::string Monster::GetName() { return name; }
std::string Monster::GetDropItemName() { return dropItemName; }
int Monster::GetDropItemPrice() { return dropItemPrice; }