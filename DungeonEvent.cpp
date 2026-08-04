#include "DungeonEvent.h"

#include <algorithm>

// 전달받은 플레이어를 복사하지 않고 참조로 보관한다.
DungeonEvent::DungeonEvent(Character& character)
	: character(character), monster(nullptr), itemDB() {}

// 지정 범위에서 획득량을 뽑아 현재 보유 골드에 더한다.
void DungeonEvent::GiveGold(int minGold, int maxGold) {
	int gold = random.GetRandomValue(minGold, maxGold);
	character.SetMoney(character.GetMoney() + gold);
}

// 차감 후 골드가 음수가 되지 않도록 최솟값을 0으로 제한한다.
void DungeonEvent::LoseGold(int minGold, int maxGold) {
	int gold = random.GetRandomValue(minGold, maxGold);
	character.SetMoney(std::max(0, character.GetMoney() - gold));
}

// 캐릭터가 보유한 인벤토리에 아이템과 수량을 전달한다.
void DungeonEvent::AddItem(Item item, int quantity) {
	character.GetInventory().AddItem(item, quantity);
}

// 범위 내 회복량을 뽑아 현재 체력에 더한다.
void DungeonEvent::RestoreHealth(int minHealth, int maxHealth) {
	int health = random.GetRandomValue(minHealth, maxHealth);
	character.SetCurrentHP(character.GetCurrentHP() + health);
}

// 범위 내 피해량을 뽑고 캐릭터의 공통 피해 처리 함수를 사용한다.
GameState DungeonEvent::DamageHealth(int minDamage, int maxDamage) {
	int damage = random.GetRandomValue(minDamage, maxDamage);
	character.TakeDamage(damage);
	if (IsCharacterDead(character.GetCurrentHP())) {
		return GameState::GameOver;
	}
	return GameState::Playing;
}

// 추후 별도의 몬스터 조우 연출이나 준비 로직을 넣기 위한 자리다.
void DungeonEvent::StartMonsterEncounter() {}

// 네 가지 이벤트 열거형 값과 같은 0~3 중 하나를 균등하게 선택한다.
DungeonEventType DungeonEvent::GetRandomEventType(Character& character) {
	int randomValue = random.GetRandomValue(0, 3);
	return static_cast<DungeonEventType>(randomValue);
}

// 캐릭터가 먼저 공격하고, 생존한 몬스터가 반격하는 턴 전투를 반복한다.
GameState DungeonEvent::Battle(Monster* monster) {

    // 양쪽이 서로를 공격 대상으로 참조하도록 전투 시작 전에 한 번 연결한다.
    monster->SetTarget(&character);
    character.SetTarget(monster);

    while (true) {
        // 플레이어 턴이 끝난 즉시 몬스터 사망 여부를 확인한다.
        character.DoMyTurn();

        if (IsMonsterDead(monster->GetCurrentHp())) {
            std::cout << "몬스터 " << monster->GetName() << "(을)를 처치했습니다!" << std::endl;
            break;
        }

        // 살아남은 몬스터가 반격한 뒤 플레이어 사망 여부를 확인한다.
        monster->DoMyTurn();

        if (IsCharacterDead(character.GetCurrentHP())) {
            character.EndBattle();
			return GameState::GameOver;
        }
    }
    //전투 종료 시 강화 물약 효과가 제거되는 함수입니다.
    character.EndBattle();
	return GameState::Playing;
};

// 일반 슬라임 한 마리를 생성해 전투하고 승리 보상을 캐릭터에게 지급한다.
GameState DungeonEvent::Encounter() {
	std::unique_ptr<Monster> monster = CreateMonster();

    system("cls");
    std::cout << "몬스터 " << monster->GetName() << "(이)가 난입했습니다. 전투 시작!" << std::endl;
    std::cout << "체력 : " << monster->GetCurrentHp() << ", 공격력 : " << monster->GetPower() << std::endl;
    Tools::WaitForKey();

    if (Battle(monster.get()) == GameState::GameOver) {
        std::cout << "게임 오버!" << std::endl;
        return GameState::GameOver;
    }

    int quantity = random.GetRandomValue(1, 3);
	character.GetInventory().AddItem(monster->GetItem(), quantity);
	int goldDropped = monster->RandomGold();

    std::cout << std::endl << monster->GetName() << " 처치!" << std::endl;
    std::cout << character.GetName() << "(이)가 " << monster->GetDropExp() << "EXP와 " << goldDropped << "골드를 획득했습니다.\n";
	std::cout << monster->GetName() << "이(가) " << monster->GetItem().name << "을(를) " << quantity << "개 드랍했습니다." << std::endl;

    character.SetCurrentEXP(character.GetCurrentEXP() + monster->GetDropExp());
    character.SetMoney(character.GetMoney() + goldDropped);

    // 누적 경험치가 현재 요구량 이상이면 한 번 레벨 업한다.
    if (character.GetCurrentEXP() >= character.GetMaxEXP()) character.LevelUP();

    std::cout << std::endl << "현재 EXP : " << character.GetCurrentEXP() << "/" << character.GetMaxEXP() << ", 골드 : " << character.GetMoney() << std::endl;
	
    character.SetTarget(nullptr);
	monster->SetTarget(nullptr);

    return GameState::Playing;
};

// 체력이 0 이하이면 캐릭터가 전투 불능인 것으로 판정한다.
bool DungeonEvent::IsCharacterDead(int hp) {
    if (hp <= 0) return true;
    return false;
};

// 체력이 0 이하이면 몬스터가 처치된 것으로 판정한다.
bool DungeonEvent::IsMonsterDead(int hp) {
    if (hp <= 0) return true;
    return false;
};

// 자식 이벤트가 부모가 보관 중인 플레이어 원본에 접근하도록 반환한다.
Character& DungeonEvent::GetCharacter() {
	return character;
}

void DungeonEvent::SetMonster(NormalMonsterType monsterType) {
	this->monsterType = monsterType;
}

std::unique_ptr<Monster> DungeonEvent::CreateMonster() {
	int level = character.GetLevel();

	switch (monsterType) {
	case NormalMonsterType::Slime:
		return std::make_unique<Slime>(&itemDB, level);
	case NormalMonsterType::Skeleton:
		return std::make_unique<Skeleton>(&itemDB, level);
	case NormalMonsterType::Goblin:
		return std::make_unique<Goblin>(&itemDB, level);

	default:
		throw std::out_of_range("알 수 없는 몬스터 타입입니다.");
	}
}

std::unique_ptr<Monster> DungeonEvent::CreateBossMonster() {
	int level = character.GetLevel();

	switch (monsterType) {
	case NormalMonsterType::Slime:
		return std::make_unique<SlimeKing>(&itemDB, level);
	case NormalMonsterType::Skeleton:
		return std::make_unique<SkeletonKing>(&itemDB, level);
	case NormalMonsterType::Goblin:
		return std::make_unique<DemonKing>(&itemDB, level);

	default:
		throw std::out_of_range("알 수 없는 몬스터 타입입니다.");
	}
}