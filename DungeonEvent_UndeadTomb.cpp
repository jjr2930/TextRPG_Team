#include "DungeonEvent_UndeadTomb.h"

UndeadTombEvent::UndeadTombEvent(Character& character) : DungeonEvent(character) {
	std::cout << "언데드 무덤 이벤트 생성!" << std::endl;
}

void UndeadTombEvent::RunRandomEvent() {
	DungeonEventType randomEventType = DungeonEvent::GetRandomEventType();

	switch (randomEventType) {
	case DungeonEventType::Exploration:
		std::cout << "던전 탐험 이벤트 발생!" << std::endl;
		break;
	case DungeonEventType::Treasure:
		std::cout << "보물 상자 이벤트 발생!" << std::endl;
		break;
	case DungeonEventType::Trap:
		std::cout << "함정 이벤트 발생!" << std::endl;
		break;
	case DungeonEventType::Rest:
		std::cout << "휴식 이벤트 발생!" << std::endl;
		break;
	default:
		std::cout << "알 수 없는 이벤트 발생!" << std::endl;
		break;
	}
}

void UndeadTombEvent::RunBossEvent() {
	std::cout << "보스 이벤트 발생!" << std::endl;
}