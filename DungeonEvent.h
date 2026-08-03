#pragma once

#include <functional>
#include <string>
#include <vector>

#include "Random.h"
#include "Character.h"
#include "Tools.h"
#include "Monster.h"
#include "Slime.h"
#include "Goblin.h"
#include "Item.h"

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

enum class GameState {
	Playing,
	GameOver,
	Win
};


class DungeonEvent {

protected:
	explicit DungeonEvent(Character& character);

	void GiveGold(int minGold, int maxGold);
	void LoseGold(int minGold, int maxGold);
	void AddItem(Item item, int quantity);
	void RestoreHealth(int minHealth, int maxHealth);
	void DamageHealth(int minDamage, int maxDamage);
	void StartMonsterEncounter();
	GameState Battle(Monster* monster);
	GameState Encounter();
	bool IsCharacterDead(int currentHealth);
	bool IsMonsterDead(int currentHealth);
	DungeonEventType GetRandomEventType(Character& character);

protected:
	Character& GetCharacter();

public:
	virtual void RunRandomEvent(Character& character) = 0;
	virtual void RunBossEvent() = 0;
	virtual ~DungeonEvent() = default;

private:
	Character& character;
	Random random;
};
