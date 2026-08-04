#pragma once

#include "Monster.h"

class Skeleton  : public Monster{
public:
	Skeleton(ItemDatabase* itemDB, int level);

	virtual void Attack() override;
	virtual void TakeDamage(int damage) override;
	virtual Item GetItem() override;

	void NomalAttack();
	void ComboAttack();
};

