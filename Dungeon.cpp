#include "Dungeon.h"


Dungeon::Dungeon() {
	EnterDungeon();
};


void Dungeon::EnterDungeon() {
	std::cout << "앞에 여러가지 던전의 입구가 보입니다." << std::endl;
	SelectDungeonPath();
	GenerateDungeonEvent(); 
}

void Dungeon::SelectDungeonPath() {
	std::cout << "들어갈 던전을 선택하세요." << std::endl << std::endl;
	for (DungeonMap& path : dungeonPaths) {
		std::cout << "		난이도: " << path.difficultyIcon << "  " << path.dungeonName << std::endl;
	}
	int selectedPathIndex = 0;
	selectedPathIndex = GetIntegerInRange(1, (int)dungeonPaths.size()) - 1; 
	
	selectedMap = dungeonPaths[selectedPathIndex].dungeonName;
	selectedMapID = dungeonPaths[selectedPathIndex].mapID;
	selectedDifficultyIcon = dungeonPaths[selectedPathIndex].difficultyIcon;
	selectedDifficultyLevel = dungeonPaths[selectedPathIndex].difficultyLevel;
	
	dungeonLength = GetRandomValue(7, 14); // 던전 길이 랜덤 설정
}

void Dungeon::ProcessDungeon() {
	while (!isDungeonFinished) {
		GenerateDungeonEvent();
		HandleDungeonEvent();
		HandleDungeonBattle();
		isDungeonFinished = IsDungeonFinished();
	}
	std::cout << "던전을 클리어했습니다!" << std::endl;
}

void Dungeon::StartDungeon() {
	std::cout << selectedMap << "으로 나아갑니다..." << std::endl << std::endl;
	WaitForKey();
	system("cls");

	std::cout << dungeonDescriptions[selectedDifficultyLevel - 1] << std::endl;
}

void Dungeon::GenerateDungeonEvent() {

}

void Dungeon::HandleDungeonEvent() {

}

void Dungeon::HandleDungeonBattle() {

}

bool Dungeon::IsDungeonFinished() {
	return false;
}