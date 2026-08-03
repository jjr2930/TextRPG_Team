#pragma once

#include "DungeonEvent.h"

class DemonCastleEvent final : public DungeonEvent {
public:
    DemonCastleEvent(Character& character);
    virtual void RunRandomEvent() override;
    virtual void RunBossEvent() override;
};