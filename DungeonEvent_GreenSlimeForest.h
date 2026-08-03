#pragma once

#include "DungeonEvent.h"

class GreenSlimeForestEvent final : public DungeonEvent {
public:
    GreenSlimeForestEvent(Character& character);
    void RandomEvent() override;
    void BossEvent() override;
};