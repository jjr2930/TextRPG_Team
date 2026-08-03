#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Tools.h"
#include "DungeonEventCollection.h"
#include "Random.h"
#include "Character.h"

/// <summary>던전 선택 화면에 표시할 맵 정보를 저장합니다.</summary>
struct DungeonMap {
	/// <summary>생성할 던전 이벤트를 구분하는 맵 종류입니다.</summary>
	DungeonMapType mapType;

	/// <summary>던전의 권장 난이도 수치입니다.</summary>
	int difficultyLevel;

	/// <summary>별 문자로 표시하는 던전 난이도입니다.</summary>
	std::string difficultyIcon;

	/// <summary>화면에 출력할 던전 이름입니다.</summary>
	std::string dungeonName;
};


/// <summary>던전 선택, 탐험 이벤트, 보스전을 순서대로 진행합니다.</summary>
class Dungeon {
public:
	/// <summary>던전을 탐험할 캐릭터를 연결합니다.</summary>
	/// <param name="character">던전에 입장하는 플레이어 캐릭터입니다.</param>
	Dungeon(Character& character);
	
	/// <summary>던전 진행 상태를 초기화하고 입장 절차를 시작합니다.</summary>
	void EnterDungeon();

	/// <summary>선택한 던전의 설명과 진입 선택지를 출력합니다.</summary>
	void StartDungeon();

	/// <summary>입장할 던전을 선택하고 해당 던전 이벤트를 생성합니다.</summary>
	/// <returns>던전 입장이 가능하면 true, 취소하거나 조건을 만족하지 못하면 false입니다.</returns>
	bool SelectDungeonPath();

	/// <summary>정해진 길이만큼 일반 이벤트를 진행한 뒤 보스 이벤트를 실행합니다.</summary>
	void ProcessDungeon();

	/// <summary>현재 던전의 무작위 일반 이벤트 하나를 처리합니다.</summary>
	void HandleDungeonEvent();

	/// <summary>현재 던전의 보스 이벤트를 처리하고 던전을 종료합니다.</summary>
	void EncounterBossEvent();

	/// <summary>현재 던전 탐험을 완료 상태로 변경합니다.</summary>
	void FinishDungeon();

private:
	/// <summary>던전을 탐험하는 플레이어 캐릭터 참조입니다.</summary>
	Character& character;

	/// <summary>던전 길이 등 무작위 값을 생성하는 도구입니다.</summary>
	Random random;

	/// <summary>맵 종류에 맞는 던전 이벤트 객체를 생성하는 컬렉션입니다.</summary>
	DungeonEventCollection dungeonEventCollection;

	/// <summary>현재 선택한 맵에서 실행할 던전 이벤트 객체입니다.</summary>
	std::unique_ptr<DungeonEvent> dungeonEvent;

	/// <summary>현재 던전 탐험이 완료되었는지 나타냅니다.</summary>
	bool dungeonFinished = false;

	/// <summary>선택한 던전의 난이도 수치입니다.</summary>
	int selectedDifficultyLevel = 0;

	/// <summary>보스전에 도달하기 전까지 진행할 이벤트 수입니다.</summary>
	int dungeonLength = 0;

	/// <summary>선택한 던전 경로의 배열 인덱스입니다.</summary>
	int selectedPathIndex = 0;

	/// <summary>현재까지 처리한 던전 이벤트 수입니다.</summary>
	int currentDungeonLength = 0;

	/// <summary>선택한 던전의 이름입니다.</summary>
	std::string selectedMap = "";

	/// <summary>선택한 던전의 난이도 아이콘입니다.</summary>
	std::string selectedDifficultyIcon = "";

	/// <summary>선택 가능한 던전 맵과 난이도 정보 목록입니다.</summary>
	std::vector<DungeonMap> dungeonPaths = {
		{DungeonMapType::GreenSlimeForest, 10, "★☆☆", "초록빛 슬라임 숲"},
		{DungeonMapType::UndeadTomb, 20, "★★☆", "망자의 지하묘지"},
		{DungeonMapType::DemonCastle, 30, "★★★", "마왕의 검은 성채"},
	};

	/// <summary>각 던전 선택 후 출력할 배경 설명 목록입니다.</summary>
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
