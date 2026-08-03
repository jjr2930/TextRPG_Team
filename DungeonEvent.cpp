#include "DungeonEvent.h"

#include <algorithm>

DungeonEvent::DungeonEvent(Character& character)
	: character(character) {}

void DungeonEvent::GiveGold(int minGold, int maxGold) {
	int gold = random.GetRandomValue(minGold, maxGold);
	character.SetMoney(character.GetMoney() + gold);
}

void DungeonEvent::LoseGold(int minGold, int maxGold) {
	int gold = random.GetRandomValue(minGold, maxGold);
	character.SetMoney(std::max(0, character.GetMoney() - gold));
}

void DungeonEvent::AddItem(int itemIdentifier, int quantity) {
	character.GetInventory().AddItem(itemIdentifier, quantity);
}

void DungeonEvent::RestoreHealth(int minHealth, int maxHealth) {
	int health = random.GetRandomValue(minHealth, maxHealth);
	character.SetCurrentHP(character.GetCurrentHP() + health);
}

void DungeonEvent::DamageHealth(int minDamage, int maxDamage) {
	int damage = random.GetRandomValue(minDamage, maxDamage);
	character.TakeDamage(damage);
}

void DungeonEvent::MonsterEncounter() {}

DungeonEventType DungeonEvent::GetRandomEventType() {
	int randomValue = random.GetRandomValue(0, 3);
	return static_cast<DungeonEventType>(randomValue);
}
