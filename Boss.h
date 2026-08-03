#pragma once

#include "Monster.h"
#include "Battle.h"

class Boss : public Monster {
protected:
	bool isRage = false;
	bool isAwaken = false;

	// bool isdestruct = false;
	// int destructcount = 3;

public:
	Boss(Item* item, int level);

	~Boss();

	virtual void Attack() override;
	virtual void TakeDamage(int damage) override;

};
