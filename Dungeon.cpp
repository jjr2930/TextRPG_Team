#include "Dungeon.h"


Dungeon::Dungeon() {
	EnterDungeon();
};


void Dungeon::EnterDungeon() {
	std::cout << "던전 입구에 들어갔습니다." << std::endl;
	SelectDungeonPath();
	GenerateDungeonEvent(); 
}

void Dungeon::SelectDungeonPath() {
	std::cout << "들어갈 던전을 선택하세요." << std::endl << std::endl;
	for (DungeonMap& path : dungeonPaths) {
		std::cout << "		난이도: " << path.difficultyIcon << "  " << path.dungeonName << std::endl;
	}
	int selectedPathIndex = 0;
	selectedPathIndex = GetIntegerInRange(1, dungeonPaths.size()) - 1; 
	
	selectedMap = dungeonPaths[selectedPathIndex].dungeonName;
	selectedDifficultyIcon = dungeonPaths[selectedPathIndex].difficultyIcon;
	selectedDifficultyLevel = dungeonPaths[selectedPathIndex].difficultyLevel;
	
	dungeonLength = GetRandomValue(5, 15); // 던전 길이 랜덤 설정
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