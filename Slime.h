#pragma once
#include "Monster.h"

class Slime : public Monster{
public:
	Slime(Item* item, int level);

	virtual void Attack() override;
	virtual void TakeDamage(int damage) override;
};

