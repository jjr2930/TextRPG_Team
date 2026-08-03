#pragma once

#include "DungeonEvent.h"

class UndeadTombEvent final : public DungeonEvent {
public:
    UndeadTombEvent(Character& character); 
    virtual void RunRandomEvent() override;
    virtual void RunBossEvent() override;
};