#pragma once

#include "Monster.h"
#include "Battle.h"

class Character;

class Boss : public Monster
{
public:
	Boss(Item* item, int level);

	~Boss();

	virtual float Attack();
	virtual void TakeDamage(float damage);

};
