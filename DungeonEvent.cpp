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

void DungeonEvent::StartMonsterEncounter() {}

DungeonEventType DungeonEvent::GetRandomEventType(Character& character) {
	int randomValue = random.GetRandomValue(0, 3);
	return static_cast<DungeonEventType>(randomValue);
}

GameState DungeonEvent::Battle(Monster* monster) {

    monster->SetTarget(&character);
    character.SetTarget(monster);

    while (true) {
        character.DoMyTurn();

        if (IsMonsterDead(monster->GetCurrentHp())) {
            std::cout << "몬스터 " << monster->GetName() << "(을)를 처치했습니다!" << std::endl;
            break;
        }

        monster->DoMyTurn();

        if (IsCharacterDead(character.GetCurrentHP())) {
			return GameState::GameOver;
        }
    }
	return GameState::Playing;
};

GameState DungeonEvent::Encounter() {
    Slime monster(nullptr, character.GetLevel()); // 나중에 슬라임 드롭아이템 넣을것
    system("cls");
    std::cout << "몬스터 " << monster.GetName() << "(이)가 난입했습니다. 전투 시작!" << std::endl;
    std::cout << "체력 : " << monster.GetCurrentHp() << ", 공격력 : " << monster.GetPower() << std::endl;
    Tools::WaitForKey();

    if (Battle(&monster) == GameState::GameOver) {
        std::cout << "게임 오버!" << std::endl;
        return GameState::GameOver;
    }

    std::cout << std::endl << monster.GetName() << " 처치!" << std::endl;
    std::cout << character.GetName() << "(이)가 " << monster.GetDropExp() << "EXP와 " << monster.RandomGold() << "골드를 획득했습니다.\n";


    character.SetCurrentEXP(character.GetCurrentEXP() + monster.GetDropExp());
    character.SetMoney(character.GetMoney() + monster.RandomGold());

    if (character.GetCurrentEXP() >= character.GetMaxEXP()) character.CharacterLevelUP();

    std::cout << std::endl << "현재 EXP : " << character.GetCurrentEXP() << "/" << character.GetMaxEXP() << ", 골드 : " << character.GetMoney() << std::endl;
	
    return GameState::Playing;
};

bool DungeonEvent::IsCharacterDead(int hp) {
    if (hp <= 0) return true;
    return false;
};

bool DungeonEvent::IsMonsterDead(int hp) {
    if (hp <= 0) return true;
    return false;
};

Character& DungeonEvent::GetCharacter() {
	return character;
}