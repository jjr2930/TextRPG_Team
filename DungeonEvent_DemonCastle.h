#pragma once

#include "DungeonEvent.h"

class DemonCastleEvent final : public DungeonEvent {
public:
    DemonCastleEvent(Character& character);
    void RandomEvent() override;
    void BossEvent() override;
};