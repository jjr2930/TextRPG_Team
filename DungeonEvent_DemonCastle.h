#pragma once

#include "DungeonEvent.h"
#include "Boss.h"

class DemonCastleEvent final : public DungeonEvent {
public:
    DemonCastleEvent(Character& character);
    virtual void RunRandomEvent(Character& character) override;
    virtual void RunBossEvent() override;

}; 