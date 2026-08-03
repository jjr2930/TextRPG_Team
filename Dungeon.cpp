#include "Dungeon.h"

#include <stdexcept>
#include <utility>



Dungeon::Dungeon(Character& character)
	: character(character), dungeonEventCollection(character) {}


void Dungeon::EnterDungeon() {
	dungeonFinished = false;
	currentDungeonLength = 0;

	std::cout << "앞에 여러가지 던전의 입구가 보입니다." << std::endl;
	if (!SelectDungeonPath()) {
		return;
	}
	StartDungeon();
}

bool Dungeon::SelectDungeonPath() {
	std::cout << "들어갈 던전을 선택하세요." << std::endl << std::endl;

	int dungeonNumber = 1;
	for (DungeonMap& path : dungeonPaths) {
		std::cout << dungeonNumber << ".		난이도: " << path.difficultyIcon << "  " << path.dungeonName << std::endl;
		++dungeonNumber;
	}

	selectedPathIndex = Tools::GetIntegerInRange(1, (int)dungeonPaths.size()) - 1; 
	
	if (selectedPathIndex == 2) {
		if (character.GetLevel() < 10) {
			std::cout << "마왕의 검은 성채는 레벨 10 이상부터 입장 가능합니다." << std::endl;
			std::cout << "레벨을 올린 후 다시 시도해주세요." << std::endl;
			Tools::WaitForKey();
			return false;
		}
	}

	const DungeonMap& selectedPath = dungeonPaths[selectedPathIndex];

	selectedMap = selectedPath.dungeonName;
	selectedDifficultyIcon = selectedPath.difficultyIcon;
	selectedDifficultyLevel = selectedPath.difficultyLevel;

	dungeonEvent = dungeonEventCollection.CreateDungeonEvent(selectedPath.mapType);

	dungeonLength = random.GetRandomValue(7, 14);
	
	return true;
}

void Dungeon::StartDungeon() {
	std::cout << selectedMap << "으로 나아갑니다..." << std::endl << std::endl;
	Tools::WaitForKey();
	system("cls");

	std::cout << dungeonDescriptions[selectedPathIndex] << std::endl;
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
	while (currentDungeonLength < dungeonLength) {
		HandleDungeonEvent();
		++currentDungeonLength;
	}
	EncounterBossEvent();
}

void Dungeon::HandleDungeonEvent() {
	if (!dungeonEvent)
		return;

	dungeonEvent->RunRandomEvent(character);
	Tools::WaitForKey();
}

void Dungeon::EncounterBossEvent() {
	if (!dungeonEvent)
		return;

	dungeonEvent->RunBossEvent();
	Tools::WaitForKey();
	FinishDungeon();
}

void Dungeon::FinishDungeon() {
	dungeonFinished = true;
}
