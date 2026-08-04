#pragma once

#include <functional>
#include <string>
#include <vector>
#include <memory>

#include "Random.h"
#include "Character.h"
#include "Tools.h"
#include "Monster.h"

#include "Slime.h"
#include "Skeleton.h"
#include "Goblin.h"

#include "DemonKing.h"
#include "SlimeKing.h"
#include "SkeletonKing.h"

#include "Item.h"
#include "ItemDatabases.h"


/// <summary>일반 던전 이벤트의 종류를 나타냅니다.</summary>
enum class DungeonEventType {
	Exploration,
	Treasure,
	Trap,
	Rest
};

/// <summary>던전 이벤트가 캐릭터에게 적용할 수 있는 효과를 나타냅니다.</summary>
enum class DungeonEventEffectType {
	None,
	ItemAddition,
	HealthRecovery,
	HealthDamage,
	GoldGain,
	GoldLoss,
	MonsterEncounter
};

/// <summary>던전 전투 후의 게임 진행 상태를 나타냅니다.</summary>
enum class GameState {
	Playing,
	GameOver,
	Win
};

enum class NormalMonsterType {
	Slime,
	Skeleton,
	Goblin
};


/// <summary>모든 던전 이벤트가 공유하는 보상, 피해, 전투 기능을 제공합니다.</summary>
class DungeonEvent {

protected:
	/// <summary>이벤트 효과를 적용할 캐릭터를 연결합니다.</summary>
	/// <param name="character">던전을 진행하는 플레이어 캐릭터입니다.</param>
	explicit DungeonEvent(Character& character);

	/// <summary>지정 범위에서 무작위 금액을 캐릭터에게 지급합니다.</summary>
	/// <param name="minGold">지급할 최소 골드입니다.</param>
	/// <param name="maxGold">지급할 최대 골드입니다.</param>
	void GiveGold(int minGold, int maxGold);

	/// <summary>지정 범위에서 무작위 금액을 차감하되 골드가 0보다 작아지지 않게 합니다.</summary>
	/// <param name="minGold">잃을 최소 골드입니다.</param>
	/// <param name="maxGold">잃을 최대 골드입니다.</param>
	void LoseGold(int minGold, int maxGold);

	/// <summary>캐릭터 인벤토리에 아이템을 지정 수량만큼 추가합니다.</summary>
	/// <param name="item">추가할 아이템입니다.</param>
	/// <param name="quantity">추가할 수량입니다.</param>
	void AddItem(Item item, int quantity);

	/// <summary>지정 범위에서 무작위 수치만큼 캐릭터의 체력을 회복합니다.</summary>
	/// <param name="minHealth">최소 회복량입니다.</param>
	/// <param name="maxHealth">최대 회복량입니다.</param>
	void RestoreHealth(int minHealth, int maxHealth);

	/// <summary>지정 범위에서 무작위 수치만큼 캐릭터에게 피해를 줍니다.</summary>
	/// <param name="minDamage">최소 피해량입니다.</param>
	/// <param name="maxDamage">최대 피해량입니다.</param>
	GameState DamageHealth(int minDamage, int maxDamage);

	/// <summary>던전 일반 몬스터 조우를 시작하기 위한 확장 지점입니다.</summary>
	void StartMonsterEncounter();

	/// <summary>캐릭터와 지정 몬스터의 턴제 전투를 진행합니다.</summary>
	/// <param name="monster">전투할 몬스터 포인터입니다.</param>
	/// <returns>캐릭터가 패배하면 GameOver, 승리하면 Playing입니다.</returns>
	GameState Battle(Monster* monster);

	/// <summary>캐릭터 레벨에 맞는 일반 슬라임과 조우하여 전투와 보상을 처리합니다.</summary>
	/// <returns>전투 후의 게임 진행 상태를 반환합니다.</returns>
	GameState Encounter();

	/// <summary>현재 체력으로 캐릭터 사망 여부를 확인합니다.</summary>
	/// <param name="currentHealth">확인할 캐릭터의 현재 체력입니다.</param>
	/// <returns>체력이 0 이하면 true입니다.</returns>
	bool IsCharacterDead(int currentHealth);

	/// <summary>현재 체력으로 몬스터 사망 여부를 확인합니다.</summary>
	/// <param name="currentHealth">확인할 몬스터의 현재 체력입니다.</param>
	/// <returns>체력이 0 이하면 true입니다.</returns>
	bool IsMonsterDead(int currentHealth);

	/// <summary>탐험, 보물, 함정, 휴식 중 하나를 무작위로 선택합니다.</summary>
	/// <param name="character">이벤트를 진행하는 캐릭터입니다.</param>
	/// <returns>선택된 던전 이벤트 종류를 반환합니다.</returns>
	DungeonEventType GetRandomEventType(Character& character);

protected:
	/// <summary>이벤트에 연결된 플레이어 캐릭터를 반환합니다.</summary>
	/// <returns>플레이어 캐릭터 참조입니다.</returns>
	Character& GetCharacter();

	/// <summary> 이벤트에 연결된 몬스터를 설정합니다. 이 메서드는 던전 이벤트에서 몬스터를 생성하거나 변경할 때 사용됩니다.</summary>
	/// <param name="monster">설정할 몬스터입니다.</param>
	void SetMonster(NormalMonsterType monsterType);

public:
	/// <summary>던전별 무작위 일반 이벤트 하나를 실행합니다.</summary>
	/// <param name="character">이벤트 효과를 적용할 캐릭터입니다.</param>
	virtual GameState RunRandomEvent(Character& character) = 0;

	/// <summary>던전별 보스 이벤트를 실행합니다.</summary>
	virtual GameState RunBossEvent() = 0;

	/// <summary>파생 던전 이벤트 객체를 안전하게 제거합니다.</summary>
	virtual ~DungeonEvent() = default;

	std::unique_ptr<Monster> CreateBossMonster();

private:
	/// <summary>이벤트 효과와 전투 결과가 적용되는 플레이어 캐릭터입니다.</summary>
	Character& character;

	/// <summary> 던전에서 나올 몬스터를 가리키는 포인터입니다.</summary>
	Monster* monster = nullptr;

	NormalMonsterType monsterType = NormalMonsterType::Slime;

	std::unique_ptr<Monster> CreateMonster();


	/// <summary>이벤트 종류와 효과 수치를 결정하는 난수 생성기입니다.</summary>
	Random random;

	ItemDatabase itemDB;

	
};
