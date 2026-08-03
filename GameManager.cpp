#include "GameManager.h"



// 멤버를 생성한 뒤 플레이어 이름을 입력받아 게임 시작 상태를 준비한다.
GameManager::GameManager() 
    : itemDatabase()
    , character()
{
    MakeCharacter();
};

// 아이템 데이터베이스와 현재 캐릭터의 주소를 상점에 전달한다.
void GameManager::ShopEnter() {
	Shop shop(&itemDatabase, &character);
	shop.PrintMainMenu();
};

// 게임 오버 플래그를 켜고 사용자가 확인할 때까지 대기한다.
void GameManager::Gameover() {
    isGameover = true;
	std::cout << "게임오버..." << std::endl;
	Tools::WaitForKey();
};

// 승리 메시지를 출력한 뒤 메인 게임 루프가 끝날 수 있도록 상태를 바꾼다.
void GameManager::Win() {
	std::cout << "게임 클리어!" << std::endl;
    isGameover = true;
	Tools::WaitForKey();
};

// 사용자가 종료하거나 던전으로 이동할 때까지 메인 메뉴를 반복한다.
void GameManager::ShowMainMenu() {

    while (true)
    {
        // 이전 화면을 지우고 현재 선택 가능한 메뉴를 다시 그린다.
        system("cls");

        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "              TEXT RPG\n";
        std::cout << "========================================\n";
        std::cout << "\n";
        std::cout << "       무엇을 하시겠습니까?\n";
        std::cout << "\n";
        std::cout << "       [1] 캐릭터 상태 보기\n";
        std::cout << "       [2] 상점 들어가기\n";
        std::cout << "       [3] 던전 입장\n";
        std::cout << "       [4] 게임 종료\n";
        std::cout << "       [5] 디버그 : 레벨10설정 <- 던전3 들어가는데 사용\n"; // 나중에 제거
        std::cout << "\n";
        std::cout << "----------------------------------------\n";
        std::cout << "       행동을 선택해 주세요 : ";

		// 허용 범위의 정수만 받은 뒤 의미가 분명한 열거형으로 변환한다.
		int select = Tools::GetIntegerInRange(1, 5);
		MenuSelection menuSelect = static_cast<MenuSelection>(select);

        switch (menuSelect)
        {
        case MenuSelection::Character:
            // 현재 캐릭터의 능력치와 보유 정보를 확인한다.
            character.ShowCharacterInfo();
            break;

        case MenuSelection::Shop:
            // 상점 이용이 끝나면 다시 메인 메뉴 반복문으로 돌아온다.
            ShopEnter();
            break;

        case MenuSelection::Dungeon: {
            // 던전은 입장할 때 생성하며 현재 캐릭터를 참조로 공유한다.
            std::cout << "\n던전으로 입장합니다.\n";
			Dungeon dungeon(character);
			dungeon.EnterDungeon();
            // 던전 흐름이 끝나면 현재 메뉴 호출도 종료한다.
            return;
        }

        case MenuSelection::GameExit: {
            // 바깥 게임 루프가 종료 상태를 확인할 수 있도록 플래그를 저장한다.
            std::cout << "\n게임을 종료합니다.\n";
            isGameover = true;
            return;
        }

        case MenuSelection::Debug: 
            // 마왕의 성채 입장 조건을 빠르게 확인하기 위한 임시 디버그 기능이다.
            GetLevel();
            return;

        default: {
            break;
        }
        }
    }
};

// 현재 경험치가 레벨 업 기준을 넘었는지 검사한다.
void GameManager::LevelUp() {
    if (character.GetCurrentEXP() >= 100) {
        character.LevelUP();
        std::cout << "레벨 업!      LV " << character.GetLevel() - 1 << " ->  LV " << character.GetLevel() << std::endl;
    }
};

// 한 줄 전체를 이름으로 입력받고 생성된 캐릭터 정보를 보여 준다.
void GameManager::MakeCharacter()
{
    std::cout << "이름을 입력해주세요 : ";
    std::string name;
	std::getline(std::cin, name);
    character.SetName(name);
    std::cout << std::endl << "캐릭터 " << name << " 생성 완료!" << std::endl;
    character.ShowCharacterInfo();
}

// 레벨을 아홉 번 올려 레벨 10 던전을 시험할 수 있게 한다.
MenuSelection GameManager::GetLevel() {
	for (int i = 1; i < 10; ++i) { // 하드코딩으로 레벨 10까지 올리는 코드, 나중에 제거
		character.LevelUP();
	}
	std::cout << "레벨10 설정" << std::endl;
    Tools::WaitForKey();
	return MenuSelection::Debug;
}
