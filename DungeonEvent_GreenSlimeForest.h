#pragma once

#include "DungeonEvent.h"
#include "SlimeKing.h"

/// <summary>초록빛 슬라임 숲의 일반 이벤트와 슬라임 킹 보스전을 처리합니다.</summary>
class GreenSlimeForestEvent final : public DungeonEvent {
public:
	/// <summary>초록빛 슬라임 숲 이벤트를 캐릭터와 연결합니다.</summary>
	/// <param name="character">던전을 진행하는 플레이어 캐릭터입니다.</param>
    GreenSlimeForestEvent(Character& character);

	/// <summary>초록빛 슬라임 숲의 무작위 일반 이벤트를 실행합니다.</summary>
	/// <param name="character">이벤트 효과를 적용할 캐릭터입니다.</param>
    virtual void RunRandomEvent(Character& character) override;

	/// <summary>슬라임 킹과의 보스전 및 승리 보상을 처리합니다.</summary>
    virtual void RunBossEvent() override;
};
