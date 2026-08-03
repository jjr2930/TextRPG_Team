#pragma once

#include <functional>
#include <string>
#include <vector>

#include "Random.h"
#include "Character.h"
#include "Tools.h"

enum class DungeonEventType {
	Exploration,
	Treasure,
	Trap,
	Rest
};

enum class DungeonEventEffectType {
	None,
	AddItem,
	RestoreHealth,
	DamageHealth,
	GainGold,
	LoseGold,
	MonsterEncounter
};

class DungeonEvent {

protected:
	explicit DungeonEvent(Character& character);

	void GiveGold(int minGold, int maxGold);
	void LoseGold(int minGold, int maxGold);
	void AddItem(int itemIdentifier, int quantity);
	void RestoreHealth(int minHealth, int maxHealth);
	void DamageHealth(int minDamage, int maxDamage);
	void MonsterEncounter();
	DungeonEventType GetRandomEventType(int min, int max);

public:
	virtual void RandomEvent() = 0;
	virtual void BossEvent() = 0;
	virtual ~DungeonEvent() = default;

private:
	Character& character;
	Random random;
};
