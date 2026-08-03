#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Tools.h"
#include "DungeonEventCollection.h"
#include "Random.h"
#include "Character.h"

// 던전 선택 화면과 이벤트 생성에 필요한 한 맵의 설정값을 묶는다.
struct DungeonMap {
	DungeonMapType mapType;          // 생성할 던전 이벤트의 종류
	int difficultyLevel;             // 던전의 수치상 난이도
	std::string difficultyIcon;      // 선택 화면에 표시할 별 아이콘
	std::string dungeonName;         // 선택 화면과 안내문에 표시할 이름
};


// 던전 선택부터 일반 이벤트 반복, 보스 이벤트까지의 진행 순서를 관리한다.
class Dungeon {
public:
	// GameManager가 보유한 캐릭터를 참조로 받아 같은 상태를 계속 사용한다.
	Dungeon(Character& character);
	
	void EnterDungeon();          // 진행 상태를 초기화하고 던전 선택을 시작한다.
	void StartDungeon();          // 선택한 던전 설명과 최종 입장 여부를 처리한다.
	bool SelectDungeonPath();     // 맵을 선택하고 해당 이벤트 객체를 생성한다.
	void ProcessDungeon();        // 정해진 길이만큼 일반 이벤트를 반복한다.
	void HandleDungeonEvent();    // 현재 맵의 무작위 일반 이벤트 하나를 실행한다.
	void EncounterBossEvent();   // 현재 맵의 보스 이벤트를 실행한다.
	void FinishDungeon();         // 던전 완료 상태를 기록한다.

private:
	Character& character;                              // GameManager가 소유한 플레이어
	Random random;                                     // 던전 길이 결정용 난수 생성기
	DungeonEventCollection dungeonEventCollection;     // 맵별 이벤트 객체 생성 담당
	std::unique_ptr<DungeonEvent> dungeonEvent;         // 현재 선택한 맵의 이벤트 객체

	bool dungeonFinished = false;      // 보스 이벤트까지 끝났는지 여부
	int selectedDifficultyLevel = 0;   // 선택한 던전의 난이도 값
	int dungeonLength = 0;             // 보스 전까지 실행할 일반 이벤트 수
	int selectedPathIndex = 0;         // dungeonPaths에서 선택한 위치
	int currentDungeonLength = 0;      // 지금까지 처리한 일반 이벤트 수

	std::string selectedMap = "";             // 현재 던전 이름
	std::string selectedDifficultyIcon = "";  // 현재 던전 난이도 아이콘




	// 선택 가능한 맵의 종류, 난이도, 표시 정보를 같은 순서로 보관한다.
	std::vector<DungeonMap> dungeonPaths = {
		{DungeonMapType::GreenSlimeForest, 10, "★☆☆", "초록빛 슬라임 숲"},
		{DungeonMapType::UndeadTomb, 20, "★★☆", "망자의 지하묘지"},
		{DungeonMapType::DemonCastle, 30, "★★★", "마왕의 검은 성채"},
	};
	// dungeonPaths와 같은 인덱스를 사용하는 맵별 입장 설명이다.
	std::vector<std::string> dungeonDescriptions = {
		// 초록빛 슬라임 숲에 대한 설명
		"울창한 나무 사이로 희미한 햇빛이 스며들고 있다.\n"
		"축축한 풀잎 곳곳에는 끈적한 초록색 점액이 묻어 있다.\n\n"
		"숲속 깊은 곳에서 무언가 통통 튀는 소리가 들려온다.\n"
		"인기척을 느낀 슬라임들이 수풀 너머에서 모습을 드러내기 시작한다.\n\n"
		"이 숲을 지나려면 녀석들을 상대해야 할 것 같다.",

		// 망자의 지하묘지에 대한 설명
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
