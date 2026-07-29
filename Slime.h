#pragma once
#include "Monster.h"

class Slime : public Monster{
public:
	Slime(std::string name, int hp, int power, int dropExp, std::string dropItemName, int dropItemPrice);
};

