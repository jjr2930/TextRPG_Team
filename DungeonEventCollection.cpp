#include "DungeonEventCollection.h"

#include <stdexcept>

// 이벤트 팩토리가 사용할 플레이어를 복사하지 않고 참조로 저장한다.
DungeonEventCollection::DungeonEventCollection(Character& character)
	: character(character)
{
}

// 각 맵 열거형을 실제 이벤트 자식 클래스와 연결한다.
std::unique_ptr<DungeonEvent> DungeonEventCollection::CreateDungeonEvent(DungeonMapType mapType) {
	switch (mapType) {
	case DungeonMapType::GreenSlimeForest:
		// unique_ptr<DungeonEvent>로 변환되어 부모 인터페이스로 관리된다.
		return std::make_unique<GreenSlimeForestEvent>(character);
	case DungeonMapType::UndeadTomb:
		return std::make_unique<UndeadTombEvent>(character);
	case DungeonMapType::DemonCastle:
		return std::make_unique<DemonCastleEvent>(character);
	default:
		// 정의되지 않은 맵 값이 들어오면 잘못된 인덱스 사용을 즉시 알린다.
		throw std::out_of_range("존재하지 않는 던전 맵 종류입니다.");
	}
}
