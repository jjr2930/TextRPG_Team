#include "DungeonEvent.h"

#include <stdexcept>
#include <utility>

#include "DungeonEvent_DemonCastle.h"
#include "DungeonEvent_GreenSlimeForest.h"
#include "DungeonEvent_UndeadTomb.h"

DungeonEvent::DungeonEvent(std::vector<DungeonEventData> events)
	: events(std::move(events)) {}

const DungeonEventData& DungeonEvent::GetRandomEvent() {
	if (events.empty())
		throw std::logic_error("던전 이벤트가 비어 있습니다.");

	int eventIndex = random.GetRandomValue(0, static_cast<int>(events.size()) - 1);
	return events[eventIndex];
}

const std::vector<DungeonEventData>& DungeonEvent::GetEvents() const {
	return events;
}

std::unique_ptr<DungeonEvent> CreateDungeonEvent(int mapID) {
	switch (mapID) {
	case 0:
		return std::make_unique<GreenSlimeForestEvent>();
	case 1:
		return std::make_unique<UndeadTombEvent>();
	case 2:
		return std::make_unique<DemonCastleEvent>();
	default:
		throw std::out_of_range("존재하지 않는 던전 맵 ID입니다.");
	}
}
