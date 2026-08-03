#include "DungeonEventCollection.h"

#include <stdexcept>

DungeonEventCollection::DungeonEventCollection(Character& character)
	: character(character)
{
}

std::unique_ptr<DungeonEvent> DungeonEventCollection::CreateDungeonEvent(int mapID) {
	switch (mapID) {
	case 0:
		return std::make_unique<GreenSlimeForestEvent>(character);
	case 1:
		return std::make_unique<UndeadTombEvent>(character);
	case 2:
		return std::make_unique<DemonCastleEvent>(character);
	default:
		throw std::out_of_range("존재하지 않는 던전 맵 ID입니다.");
	}
}
