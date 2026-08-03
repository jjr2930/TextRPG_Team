#pragma once

#include "Monster.h"
#include "Battle.h"

class DemonKing : public Monster {
protected:
	bool isRage = false;
	bool isAwaken = false;

	// bool isdestruct = false;
	// int destructcount = 3;

public:
	DemonKing(Item* item, int level);

	~DemonKing();

	virtual void Attack() override;
	virtual void TakeDamage(int damage) override;

};
