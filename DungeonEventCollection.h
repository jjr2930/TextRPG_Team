#pragma once

#include <memory>

#include "DungeonEvent_DemonCastle.h"
#include "DungeonEvent_GreenSlimeForest.h"
#include "DungeonEvent_UndeadTomb.h"

class DungeonEventCollection {
private:
	Character& character;

public:
	explicit DungeonEventCollection(Character& character);
	std::unique_ptr<DungeonEvent> CreateDungeonEvent(int mapID);
};
