#pragma once

#include "DungeonEvent.h"
#include "Boss.h"

// 마왕의 검은 성채에서 발생하는 일반 이벤트와 보스 전투를 구현한다.
class DemonCastleEvent final : public DungeonEvent {
public:
    // 부모 클래스에 현재 플레이어 참조를 전달한다.
    DemonCastleEvent(Character& character);
    // 성채의 일반 이벤트 중 하나를 무작위로 실행한다.
    virtual void RunRandomEvent(Character& character) override;
    // 마왕 보스를 생성해 최종 전투와 보상을 처리한다.
    virtual void RunBossEvent() override;

};
