#pragma once

#include "Monster.h"
#include "Battle.h"

class SlimeKing : public Monster {
protected:
	bool isRage = false;

public:
	SlimeKing(ItemDatabase* itemDB, int level);

	~SlimeKing();

	virtual void Attack() override;
	virtual void TakeDamage(int damage) override;
};