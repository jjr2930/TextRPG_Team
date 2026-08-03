#pragma once

#include "DungeonEvent.h"

// 초록빛 슬라임 숲에서 발생하는 일반 이벤트와 보스 이벤트를 구현한다.
class GreenSlimeForestEvent final : public DungeonEvent {
public:
    // 부모 클래스에 현재 플레이어 참조를 전달한다.
    GreenSlimeForestEvent(Character& character);
    // 숲의 일반 이벤트 중 하나를 무작위로 실행한다.
    virtual void RunRandomEvent(Character& character) override;
    // 숲의 보스 이벤트를 실행한다.
    virtual void RunBossEvent() override;
};
