#pragma once

#include "Monster.h"
#include "Battle.h"

class SkeletonKing : public Monster {
protected:
	bool isReborn = false;

public:
	SkeletonKing(ItemDatabase* itemDB, int level);

	~SkeletonKing();

	virtual void Attack() override;
	virtual void TakeDamage(int damage) override;

	};