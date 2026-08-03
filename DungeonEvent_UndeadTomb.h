#pragma once

#include "DungeonEvent.h"

class UndeadTombEvent final : public DungeonEvent {
public:
    UndeadTombEvent(Character& character); 
    void RandomEvent() override;
    void BossEvent() override;
};