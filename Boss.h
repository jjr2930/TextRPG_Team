#pragma once

#include "Monster.h"
#include "Battle.h"

class Boss : public Monster {
public:
	Boss(Item* item, int level);

	~Boss();

	virtual void Attack() override;
	virtual void TakeDamage(int damage) override;

};
