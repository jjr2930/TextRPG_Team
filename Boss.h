#pragma once


#include "Monster.h"

class Character;

class Boss : public Monster
{
public:
	Boss(Item* item, int level);

	~Boss();

	void Attack(Character* Character);

};
