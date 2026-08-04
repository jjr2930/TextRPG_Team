#pragma once

#include "Monster.h"

class Skeleton  : public Monster{
public:
	Skeleton(Item* item, int level);

	virtual void Attack() override;
	virtual void TakeDamage(int damage) override;

	void NomalAttack();
	void ComboAttack();
};

