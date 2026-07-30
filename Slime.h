#pragma once
#include "Monster.h"

class Slime : public Monster{
public:
	Slime(Item* item, int level);

	virtual void Attack(Battle* other) override;
	virtual void TakeDamage(int damage) override;
};

