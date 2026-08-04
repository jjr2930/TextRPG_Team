#pragma once

#include <memory>

#include "DungeonEvent_DemonCastle.h"
#include "DungeonEvent_GreenSlimeForest.h"
#include "DungeonEvent_UndeadTomb.h"

/// <summary>생성 가능한 던전 맵 종류를 나타냅니다.</summary>
enum class DungeonMapType {
	GreenSlimeForest, // 초록빛 슬라임 숲
	UndeadTomb,       // 망자의 지하묘지
	DemonCastle       // 마왕의 검은 성채
};

/// <summary>맵 종류에 맞는 구체적인 던전 이벤트 객체를 생성합니다.</summary>
class DungeonEventCollection {
private:
	/// <summary>생성되는 모든 던전 이벤트에 연결할 플레이어 캐릭터입니다.</summary>
	Character& character;

public:
	/// <summary>던전 이벤트 생성에 사용할 캐릭터를 연결합니다.</summary>
	/// <param name="character">던전을 진행하는 플레이어 캐릭터입니다.</param>
	DungeonEventCollection(Character& character);

	/// <summary>맵 종류에 맞는 던전 이벤트 객체를 생성합니다.</summary>
	/// <param name="mapType">생성할 던전의 맵 종류입니다.</param>
	/// <returns>생성된 던전 이벤트 객체의 소유권을 반환합니다.</returns>
	std::unique_ptr<DungeonEvent> CreateDungeonEvent(DungeonMapType mapType);
};
