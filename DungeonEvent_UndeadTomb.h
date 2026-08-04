#pragma once

#include "DungeonEvent.h"

// 망자의 지하묘지에서 발생하는 일반 이벤트와 보스 이벤트를 구현한다.
class UndeadTombEvent final : public DungeonEvent {
public:
    // 부모 클래스에 현재 플레이어 참조를 전달한다.
    UndeadTombEvent(Character& character); 
    // 지하묘지의 일반 이벤트 중 하나를 무작위로 실행한다.
    virtual GameState RunRandomEvent(Character& character) override;
    // 지하묘지의 보스 이벤트를 실행한다.
    virtual GameState RunBossEvent() override;
};
