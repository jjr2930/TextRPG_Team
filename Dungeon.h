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
	
	void ProcessDungeon(); // 던전 진행

	void EnterDungeon(); // 던전 입장
	void StartDungeon(); // 던전 시작
	void SelectDungeonPath(); // 던전 경로 선택
	void GenerateDungeonEvent(); // 던전 이벤트 생성
	void HandleDungeonEvent(); // 던전 이벤트 처리
	void HandleDungeonBattle(); // 던전 전투 처리
	bool IsDungeonFinished(); // 던전 완료 여부 확인

private:
	bool isDungeonFinished = false;
	int selectedDifficultyLevel = 0;
	int dungeonLength = 0;
	int selectedMapID = 0;
	int currentDungeonLength = 0;

	std::string selectedMap = "";
	std::string selectedDifficultyIcon = "";


	std::vector<DungeonMap> dungeonPaths = { // 난이도 설정 아이콘, 복사해서 사용 -> ★ ☆
		{0, 10, "★☆☆", "초록빛 슬라임 숲"},
		{1, 20, "★★☆", "망자의 지하묘지"}, 
		{2, 30, "★★★", "마왕의 검은 성채"},
	};
	std::vector<std::string> dungeonDescriptions = {
		// 초록빛 슬라임 숲에 대한 설명
		"울창한 나무 사이로 희미한 햇빛이 스며들고 있다.\n"
		"축축한 풀잎 곳곳에는 끈적한 초록색 점액이 묻어 있다.\n\n"
		"숲속 깊은 곳에서 무언가 통통 튀는 소리가 들려온다.\n"
		"인기척을 느낀 슬라임들이 수풀 너머에서 모습을 드러내기 시작한다.\n\n"
		"이 숲을 지나려면 녀석들을 상대해야 할 것 같다.",

		"낡은 돌계단을 따라 지하묘지 안으로 들어섰다.\n"
		"차가운 공기와 함께 오래된 흙냄새가 코끝을 스친다.\n\n"
		"벽에 걸린 푸른 횃불이 저절로 타오르고,\n"
		"굳게 닫혀 있던 석관들이 하나둘 흔들리기 시작한다.\n\n"
		"잠들어 있던 망자들이 침입자의 기척을 알아챈 것 같다.\n",

		// 마왕의 검은 성채
		"거대한 철문이 무거운 굉음을 내며 천천히 열렸다.\n"
		"성채 안에서는 숨쉬기조차 힘들 만큼 강한 마력이 흘러나온다.\n\n"
		"붉게 물든 하늘 아래, 검은 갑옷을 입은 마물들이 길을 막아선다.\n"
		"성채 가장 높은 곳에서는 섬뜩한 웃음소리가 울려 퍼진다.\n\n"
		"이 문을 넘어서는 순간, 되돌아가기는 어려울 것 같다.\n"
	};
};