#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Tools.h"
#include "DungeonEvent.h"

struct DungeonMap {
	int mapID; // 던전 맵 ID
	int difficultyLevel; // 난이도 레벨
	std::string difficultyIcon; // 난이도 아이콘
	std::string dungeonName; //	던전 이름

};


class Dungeon { // 던전 클래스
public:
	Dungeon(); // 던전 생성자
	void EnterDungeon(); // 던전 입장
	void SelectDungeonPath(); // 던전 경로 선택
	void GenerateDungeonEvent(); // 던전 이벤트 생성
	void HandleDungeonEvent(); // 던전 이벤트 처리
	void HandleDungeonBattle(); // 던전 전투 처리
	bool IsDungeonFinished(); // 던전 완료 여부 확인

private:
	bool isDungeonFinished = false;
	int selectedDifficultyLevel = 0;
	int dungeonLength = 0;

	std::string selectedMap = "";
	std::string selectedDifficultyIcon = "";


	std::vector<DungeonMap> dungeonPaths = { // 난이도 설정 아이콘, 복사해서 사용 -> ★ ☆
		{1, 10, "★☆☆", "초록빛 슬라임 숲"},
		{2, 20, "★★☆", "망자의 지하묘지"}, 
		{3, 30, "★★★", "마왕의 검은 성채"},
	};
};