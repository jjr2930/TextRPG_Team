#include "Slime.h"

Slime::Slime(std::string name, int hp, int power, int dropExp, std::string dropItemName, int dropItemPrice)
	: Monster(name, hp, power, dropExp, dropItemName, dropItemPrice) {}