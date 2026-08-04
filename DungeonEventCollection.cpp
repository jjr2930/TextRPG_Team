#include "DungeonEventCollection.h"

#include <stdexcept>

DungeonEventCollection::DungeonEventCollection(Character& character)
	: character(character)
{
}

std::unique_ptr<DungeonEvent> DungeonEventCollection::CreateDungeonEvent(DungeonMapType mapType) {
	switch (mapType) {
	case DungeonMapType::GreenSlimeForest:
		return std::make_unique<GreenSlimeForestEvent>(character);
	case DungeonMapType::UndeadTomb:
		return std::make_unique<UndeadTombEvent>(character);
	case DungeonMapType::DemonCastle:
		return std::make_unique<DemonCastleEvent>(character);
	default:
		throw std::out_of_range("존재하지 않는 던전 맵 종류입니다.");
	}
}
