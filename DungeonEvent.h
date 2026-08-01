#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Random.h"

enum class DungeonEventType {
	Exploration,
	Treasure,
	Trap,
	Rest
};

struct DungeonEventData {
	DungeonEventType eventType;
	std::string eventName;
	std::string description;
};

class DungeonEvent {
public:
	virtual ~DungeonEvent() = default;

	const DungeonEventData& GetRandomEvent();
	const std::vector<DungeonEventData>& GetEvents() const;

protected:
	explicit DungeonEvent(std::vector<DungeonEventData> events);

private:
	Random random;
	std::vector<DungeonEventData> events;
};

std::unique_ptr<DungeonEvent> CreateDungeonEvent(int mapID);
