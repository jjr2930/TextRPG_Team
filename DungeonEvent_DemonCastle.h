#pragma once

#include "DungeonEvent.h"
#include "DemonKing.h"

/// <summary>마왕의 검은 성채의 일반 이벤트와 마왕 보스전을 처리합니다.</summary>
class DemonCastleEvent final : public DungeonEvent {
public:
	/// <summary>마왕의 검은 성채 이벤트를 캐릭터와 연결합니다.</summary>
	/// <param name="character">던전을 진행하는 플레이어 캐릭터입니다.</param>
    DemonCastleEvent(Character& character);

	/// <summary>마왕의 검은 성채의 무작위 일반 이벤트를 실행합니다.</summary>
	/// <param name="character">이벤트 효과를 적용할 캐릭터입니다.</param>
    virtual GameState RunRandomEvent(Character& character) override;

	/// <summary>마왕과의 보스전 및 승리 보상을 처리합니다.</summary>
    virtual GameState RunBossEvent() override;

};
