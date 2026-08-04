#include "Dungeon.h"

#include <stdexcept>
#include <utility>



// 플레이어 참조를 저장하고 같은 플레이어를 사용할 이벤트 생성기를 준비한다.
Dungeon::Dungeon(Character& character)
	: character(character), dungeonEventCollection(character) {}


// 새 입장마다 이전 진행도를 초기화하고, 선택이 성공한 경우에만 던전을 시작한다.
GameState Dungeon::EnterDungeon() {
	dungeonFinished = false;
	currentDungeonLength = 0;

	std::cout << "앞에 여러가지 던전의 입구가 보입니다." << std::endl;
	if (!SelectDungeonPath()) {
		return GameState::Playing;
	}
	return StartDungeon();
}

// 목록을 출력하고 선택한 맵의 설정과 전용 이벤트 객체를 준비한다.
bool Dungeon::SelectDungeonPath() {
	std::cout << "들어갈 던전을 선택하세요." << std::endl << std::endl;

	// 내부 인덱스는 0부터지만 사용자에게는 1부터 번호를 보여 준다.
	int dungeonNumber = 1;
	for (DungeonMap& path : dungeonPaths) {
		std::cout << dungeonNumber << ".		난이도: " << path.difficultyIcon << "  " << path.dungeonName << std::endl;
		++dungeonNumber;
	}

	// 입력값에서 1을 빼 vector에서 사용할 수 있는 인덱스로 변환한다.
	selectedPathIndex = Tools::GetIntegerInRange(1, (int)dungeonPaths.size()) - 1; 
	
	// 마지막 던전은 캐릭터 레벨 10 이상일 때만 입장할 수 있다.
	if (selectedPathIndex == 2) {
		if (character.GetLevel() < 10) {
			std::cout << "마왕의 검은 성채는 레벨 10 이상부터 입장 가능합니다." << std::endl;
			std::cout << "레벨을 올린 후 다시 시도해주세요." << std::endl;
			Tools::WaitForKey();
			return false;
		}
	}

	// 선택한 맵 정보를 참조로 가져와 현재 던전 상태에 복사한다.
	const DungeonMap& selectedPath = dungeonPaths[selectedPathIndex];

	selectedMap = selectedPath.dungeonName;
	selectedDifficultyIcon = selectedPath.difficultyIcon;
	selectedDifficultyLevel = selectedPath.difficultyLevel;

	// 맵 종류에 맞는 자식 이벤트를 부모 포인터로 보관한다.
	dungeonEvent = dungeonEventCollection.CreateDungeonEvent(selectedPath.mapType);

	// 일반 이벤트 횟수는 입장할 때마다 7~14회 사이에서 결정한다.
	dungeonLength = random.GetRandomValue(7, 14);
	
	return true;
}

// 던전 설명을 보여 주고 플레이어가 진행을 확정하면 실제 이벤트 루프로 이동한다.
GameState Dungeon::StartDungeon() {
	std::cout << selectedMap << "으로 나아갑니다..." << std::endl << std::endl;
	Tools::WaitForKey();
	system("cls");

	std::cout << dungeonDescriptions[selectedPathIndex] << std::endl;
	std::cout << "선택지를 골라주십시오." << std::endl;
	std::cout << "1. 앞으로 나아간다." << std::endl;
	std::cout << "2. 아직은 때가 아니다. 물러선다." << std::endl;

	// 1은 진행, 2는 던전을 취소하고 거점으로 돌아가는 선택이다.
	int choice = Tools::GetIntegerInRange(1, 2);
	switch (choice) {
	case 1: {
		std::cout << "앞으로 나아갑니다..." << std::endl;
		return ProcessDungeon();
	}
	case 2: {
		std::cout << "물러섭니다. 거점으로 돌아갑니다..." << std::endl;
		return GameState::Playing;
	}
	default:
		break;
	}

	return GameState::Playing;
}

// 던전 길이만큼 일반 이벤트를 처리한 후 보스 이벤트를 한 번 실행한다.
GameState Dungeon::ProcessDungeon() {
	while (currentDungeonLength < dungeonLength) {
		// 도중에 사망하면 남은 이벤트와 보스를 건너뛰고 즉시 결과를 전달한다.
		GameState eventResult = HandleDungeonEvent();
		if (eventResult != GameState::Playing) {
			return eventResult;
		}

		++currentDungeonLength;
	}
	return EncounterBossEvent();
}

// 이벤트 객체가 정상 생성된 경우에만 무작위 이벤트를 실행한다.
GameState Dungeon::HandleDungeonEvent() {
	if (!dungeonEvent)
		return GameState::Playing;

	// 가상 함수를 통해 실제 맵에 해당하는 자식 클래스의 구현이 호출된다.
	GameState eventResult = dungeonEvent->RunRandomEvent(character);
	Tools::WaitForKey();
	return eventResult;
}

// 현재 맵 전용 보스 이벤트를 실행하고 던전을 완료 상태로 바꾼다.
GameState Dungeon::EncounterBossEvent() {
	if (!dungeonEvent)
		return GameState::Playing;

	GameState bossResult = dungeonEvent->RunBossEvent();
	Tools::WaitForKey();
	FinishDungeon();
	return bossResult;
}

// 이후 흐름에서 던전 종료 여부를 확인할 수 있도록 상태만 기록한다.
void Dungeon::FinishDungeon() {
	dungeonFinished = true;
}
