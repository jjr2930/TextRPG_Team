#include "DungeonEvent_UndeadTomb.h"

// 부모 이벤트가 같은 플레이어 상태를 사용하도록 참조를 전달한다.
UndeadTombEvent::UndeadTombEvent(Character& character) : DungeonEvent(character) {
	std::cout << "언데드 무덤 이벤트 생성!" << std::endl;
}

// 탐험·보물·함정·휴식 중 하나를 선택해 해당 효과를 적용한다.
GameState UndeadTombEvent::RunRandomEvent(Character& character) {
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

// 현재는 지하묘지 보스의 실제 전투 대신 이벤트 발생 안내만 출력한다.
GameState UndeadTombEvent::RunBossEvent() {
	std::cout << "보스 이벤트 발생!" << std::endl;
	return GameState::Playing;
}
