#include "DungeonEvent_GreenSlimeForest.h"

GreenSlimeForestEvent::GreenSlimeForestEvent(Character& character) : DungeonEvent(character) {
	std::cout << "초록 슬라임 숲 이벤트 생성!" << std::endl;
}

void GreenSlimeForestEvent::RunRandomEvent(Character& character) {
	DungeonEventType randomEventType = DungeonEvent::GetRandomEventType(character);

	switch (randomEventType) {
	case DungeonEventType::Exploration: {
		std::cout << "던전 탐험 이벤트 발생!" << std::endl;
		DungeonEvent::Encounter();
		break;
	}

	case DungeonEventType::Treasure: {
		std::cout << "보물 상자 이벤트 발생!" << std::endl;
		DungeonEvent::GiveGold(10, 50);
		std::cout << "보물 상자에서 금화를 얻었습니다!" << std::endl;
		std::cout << "현재 금화: " << character.GetMoney() << std::endl;
		break;
	}

	case DungeonEventType::Trap: {
		std::cout << "함정 이벤트 발생!" << std::endl;
		DungeonEvent::DamageHealth(5, 20);
		std::cout << "함정에 걸려 체력이 감소했습니다!" << std::endl;
		std::cout << "현재 체력: " << character.GetCurrentHP() << "/" << character.GetMaxHP() << std::endl;
		break;
	}

	case DungeonEventType::Rest: {
		std::cout << "휴식 이벤트 발생!" << std::endl;
		DungeonEvent::RestoreHealth(10, 30);
		std::cout << "휴식을 취하며 체력을 회복했습니다!" << std::endl;
		std::cout << "현재 체력: " << character.GetCurrentHP() << "/" << character.GetMaxHP() << std::endl;
		break;
	}

	default:
		std::cout << "알 수 없는 이벤트 발생!" << std::endl;
		break;
	}
}

void GreenSlimeForestEvent::RunBossEvent() {
	std::cout << "보스 이벤트 발생!" << std::endl;
}