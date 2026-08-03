#include "Dungeon.h"

#include <stdexcept>
#include <utility>



Dungeon::Dungeon(Character& character)
	: character(character) {}


void Dungeon::EnterDungeon() {
	dungeonFinished = false;
	currentDungeonLength = 0;

	std::cout << "앞에 여러가지 던전의 입구가 보입니다." << std::endl;
	SelectDungeonPath();
	StartDungeon();
}

void Dungeon::SelectDungeonPath() {
	std::cout << "들어갈 던전을 선택하세요." << std::endl << std::endl;
	for (DungeonMap& path : dungeonPaths) {
		std::cout << "		난이도: " << path.difficultyIcon << "  " << path.dungeonName << std::endl;
	}
	int selectedPathIndex = 0;
	selectedPathIndex = Tools::GetIntegerInRange(1, (int)dungeonPaths.size()) - 1; 
	
	selectedMap = dungeonPaths[selectedPathIndex].dungeonName;
	selectedMapID = dungeonPaths[selectedPathIndex].mapID;
	selectedDifficultyIcon = dungeonPaths[selectedPathIndex].difficultyIcon;
	selectedDifficultyLevel = dungeonPaths[selectedPathIndex].difficultyLevel;
	dungeonLength = random.GetRandomValue(7, 14);

	DungeonEventCollection dungeonEventCollection(character, selectedMapID);
	

}

void Dungeon::StartDungeon() {
	std::cout << selectedMap << "으로 나아갑니다..." << std::endl << std::endl;
	Tools::WaitForKey();
	system("cls");

	std::cout << dungeonDescriptions[selectedMapID] << std::endl;
	std::cout << "선택지를 골라주십시오." << std::endl;
	std::cout << "1. 앞으로 나아간다." << std::endl;
	std::cout << "2. 아직은 때가 아니다. 물러선다." << std::endl;

	int choice = Tools::GetIntegerInRange(1, 2);
	switch (choice) {
	case 1: {
		std::cout << "앞으로 나아갑니다..." << std::endl;
		ProcessDungeon();
		break;
	}
	case 2: {
		std::cout << "물러섭니다. 거점으로 돌아갑니다..." << std::endl;
		return;
	}
	default:
		break;
	}
}

void Dungeon::ProcessDungeon() {
	while (!dungeonFinished) {
		GenerateDungeonEvent();
		currentDungeonLength++;
	}
}

void Dungeon::GenerateDungeonEvent() {
	if (currentDungeonLength >= dungeonLength) {
		EncounterBossEvent();
		return;
	}
	HandleDungeonEvent();
}

void Dungeon::HandleDungeonEvent() {
	dungeonEvent->RandomEvent();
}

void Dungeon::EncounterBossEvent() {
	dungeonEvent->BossEvent();
	FinishDungeon();
}


void Dungeon::FinishDungeon() {
	dungeonFinished = true;
}
