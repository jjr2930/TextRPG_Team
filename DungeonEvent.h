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

// 일반 던전에서 무작위로 선택되는 이벤트의 종류다.
enum class DungeonEventType {
	Exploration, // 몬스터 조우
	Treasure,    // 골드 또는 보상 획득
	Trap,        // 체력 피해
	Rest         // 체력 회복
};

// 이벤트가 캐릭터에게 적용할 수 있는 효과를 분류한다.
enum class DungeonEventEffectType {
	None,             // 효과 없음
	ItemAddition,     // 아이템 추가
	HealthRecovery,   // 체력 회복
	HealthDamage,     // 체력 피해
	GoldGain,         // 골드 획득
	GoldLoss,         // 골드 손실
	MonsterEncounter  // 몬스터 전투
};

// 던전 전투 결과를 상위 진행 코드에 전달하기 위한 상태다.
enum class GameState {
	Playing,  // 게임을 계속 진행할 수 있음
	GameOver, // 캐릭터가 사망함
	Win       // 최종 승리함
};


// 모든 맵 이벤트가 공통으로 사용하는 보상·피해·전투 기능을 제공하는 추상 부모 클래스다.
class DungeonEvent {

protected:
	// 자식 클래스만 생성 과정에서 호출할 수 있으며 플레이어 참조를 공유한다.
	explicit DungeonEvent(Character& character);

	void GiveGold(int minGold, int maxGold);               // 범위 내 골드를 지급한다.
	void LoseGold(int minGold, int maxGold);               // 골드를 잃되 0 아래로 내려가지 않게 한다.
	void AddItem(Item item, int quantity);                 // 캐릭터 인벤토리에 아이템을 넣는다.
	void RestoreHealth(int minHealth, int maxHealth);      // 범위 내 수치만큼 체력을 회복한다.
	void DamageHealth(int minDamage, int maxDamage);       // 범위 내 수치만큼 체력 피해를 준다.
	void StartMonsterEncounter();                          // 몬스터 조우 확장용 함수다.
	GameState Battle(Monster* monster);                    // 캐릭터와 몬스터의 턴 전투를 처리한다.
	GameState Encounter();                                 // 일반 몬스터 생성부터 보상까지 처리한다.
	bool IsCharacterDead(int currentHealth);               // 캐릭터 사망 여부를 판정한다.
	bool IsMonsterDead(int currentHealth);                 // 몬스터 사망 여부를 판정한다.
	DungeonEventType GetRandomEventType(Character& character); // 일반 이벤트 종류를 무작위 선택한다.

protected:
	// 매개변수 없이 현재 플레이어가 필요한 자식 클래스에 참조를 제공한다.
	Character& GetCharacter();

public:
	// 이벤트 결과를 반환해 상위 던전 진행이 사망·승리를 판단할 수 있게 한다.
	virtual GameState RunRandomEvent(Character& character) = 0; // 맵별 일반 이벤트 구현 지점
	virtual GameState RunBossEvent() = 0;                       // 맵별 보스 이벤트 구현 지점
	virtual ~DungeonEvent() = default;                     // 부모 포인터 삭제를 위한 가상 소멸자

private:
	Character& character; // GameManager가 소유한 실제 플레이어
	Random random;        // 이벤트 수치와 종류 결정용 난수 생성기
};
