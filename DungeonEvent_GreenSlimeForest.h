#pragma once

#include "DungeonEvent.h"

class GreenSlimeForestEvent final : public DungeonEvent {
public:
    GreenSlimeForestEvent(Character& character);
    virtual void RunRandomEvent(Character& character) override;
    virtual void RunBossEvent() override;
};