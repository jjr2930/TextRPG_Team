#pragma once
#include "Monster.h"

class Slime : public Monster{
public:
	Slime(Item* item, int level);

	void Attack(Battle* other) override;
	void TakeDamage(int damage) override;
};

