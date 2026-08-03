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
	ItemAddition,
	HealthRecovery,
	HealthDamage,
	GoldGain,
	GoldLoss,
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
	void StartMonsterEncounter();
	DungeonEventType GetRandomEventType();

public:
	virtual void RunRandomEvent() = 0;
	virtual void RunBossEvent() = 0;
	virtual ~DungeonEvent() = default;

private:
	Character& character;
	Random random;
};
