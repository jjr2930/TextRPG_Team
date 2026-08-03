#pragma once

#include <memory>

#include "DungeonEvent_DemonCastle.h"
#include "DungeonEvent_GreenSlimeForest.h"
#include "DungeonEvent_UndeadTomb.h"

enum class DungeonMapType {
	GreenSlimeForest,
	UndeadTomb,
	DemonCastle
};

class DungeonEventCollection {
private:
	Character& character;

public:
	DungeonEventCollection(Character& character);
	std::unique_ptr<DungeonEvent> CreateDungeonEvent(DungeonMapType mapType);
};
