#pragma once

#include <memory>

#include "DungeonEvent_DemonCastle.h"
#include "DungeonEvent_GreenSlimeForest.h"
#include "DungeonEvent_UndeadTomb.h"

// 던전 맵과 맵별 이벤트 클래스 사이를 연결하는 식별자다.
enum class DungeonMapType {
	GreenSlimeForest, // 초록빛 슬라임 숲
	UndeadTomb,       // 망자의 지하묘지
	DemonCastle       // 마왕의 검은 성채
};

// 선택한 맵 종류에 맞는 DungeonEvent 자식 객체를 생성하는 팩토리 클래스다.
class DungeonEventCollection {
private:
	Character& character; // 생성되는 모든 이벤트가 공유할 플레이어 원본

public:
	// 플레이어 참조를 보관해 이벤트 객체 생성 시 전달한다.
	DungeonEventCollection(Character& character);
	// 맵 종류에 맞는 이벤트 객체를 만들어 소유권과 함께 반환한다.
	std::unique_ptr<DungeonEvent> CreateDungeonEvent(DungeonMapType mapType);
};
