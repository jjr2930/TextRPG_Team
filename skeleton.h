#pragma once

#include "Monster.h"

class Skeleton  : public Monster{
	Skeleton(Item* item, int level);

	virtual void Attack() override;
	virtual void TakeDamage(int damage) override;

	void NomalAttack();
	void ComboAttack();
};

