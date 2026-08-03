#include "DungeonEvent_DemonCastle.h"



// 부모 이벤트가 같은 플레이어 상태를 사용하도록 참조를 전달한다.
DemonCastleEvent::DemonCastleEvent(Character& character) : DungeonEvent(character) {
	std::cout << "마왕의 검은 성채 이벤트 생성!" << std::endl;
}

// 탐험·보물·함정·휴식 중 하나를 선택해 해당 효과를 적용한다.
GameState DemonCastleEvent::RunRandomEvent(Character& character) {
	DungeonEventType randomEventType = DungeonEvent::GetRandomEventType(character);

	switch (randomEventType) {	
	case DungeonEventType::Exploration: {
		// 탐험 이벤트는 공통 일반 몬스터 전투로 이어지며, 사망하면 그대로 알린다.
		std::cout << "던전 탐험 이벤트 발생!" << std::endl;
		return DungeonEvent::Encounter();
	}

	case DungeonEventType::Treasure: {
		// 보물 이벤트는 10~50 골드를 지급한다.
		std::cout << "보물 상자 이벤트 발생!" << std::endl;
		DungeonEvent::GiveGold(10, 50);
		std::cout << "보물 상자에서 금화를 얻었습니다!" << std::endl;
		std::cout << "현재 금화: " << character.GetMoney() << std::endl;
		break;
	}

	case DungeonEventType::Trap: {
		// 함정 이벤트는 캐릭터에게 5~20의 피해를 준다.
		std::cout << "함정 이벤트 발생!" << std::endl;
		DungeonEvent::DamageHealth(5, 20);
		std::cout << "함정에 걸려 체력이 감소했습니다!" << std::endl;
		std::cout << "현재 체력: " << character.GetCurrentHP() << "/" << character.GetMaxHP() << std::endl;
		break;
	}

	case DungeonEventType::Rest: {
		// 휴식 이벤트는 캐릭터 체력을 10~30 회복한다.
		std::cout << "휴식 이벤트 발생!" << std::endl;
		DungeonEvent::RestoreHealth(10, 30);
		std::cout << "휴식을 취하며 체력을 회복했습니다!" << std::endl;
		std::cout << "현재 체력: " << character.GetCurrentHP() << "/" << character.GetMaxHP() << std::endl;
		break;
	}

	default:
		// 열거형 범위 밖의 값이 들어온 경우를 방어한다.
		std::cout << "알 수 없는 이벤트 발생!" << std::endl;
		break;
	}

	// 전투가 없는 이벤트는 항상 진행 가능한 상태로 끝난다.
	return GameState::Playing;
}
// 보스를 생성해 전투를 진행하고, 승리한 경우 경험치와 골드를 지급한다.
GameState DemonCastleEvent::RunBossEvent() {

	std::cout << "보스 이벤트 발생!" << std::endl;

	// 현재 캐릭터 레벨을 기준으로 마왕 보스의 능력치를 설정한다.
	DemonKing boss(nullptr, GetCharacter().GetLevel());

	std::cout << boss.GetName() << "(이)가 등장했습니다!\n";
	std::cout << "체력: " << boss.GetCurrentHp()
		<< ", 공격력: " << boss.GetPower() << std::endl;

	Tools::WaitForKey();

	// 부모 클래스의 공통 턴 전투를 실행하고 결과를 받아 처리한다.
	GameState result = Battle(&boss);

	if (result == GameState::GameOver) {
		std::cout << "보스에게 패배했습니다." << std::endl;
		return GameState::GameOver;
	}

	std::cout << boss.GetName() << "(을)를 처치했습니다!" << std::endl;

	// 골드 보상은 한 번만 추첨해 지급과 결과 출력에 같은 값을 사용한다.
	int rewardGold = boss.RandomGold();

	// 부모가 보관 중인 실제 캐릭터에 보스 경험치와 골드를 반영한다.
	GetCharacter().SetCurrentEXP(
		GetCharacter().GetCurrentEXP() + boss.GetDropExp()
	);
	GetCharacter().SetMoney(
		GetCharacter().GetMoney() + rewardGold
	);

	std::cout << boss.GetDropExp() << " EXP와 " << rewardGold << " 골드를 획득했습니다.\n";

	// 마왕 격파는 게임의 최종 목표이므로 승리 상태로 알린다.
	return GameState::Win;
}
