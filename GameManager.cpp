#include "GameManager.h"



GameManager::GameManager() 
    : itemDatabase()
    , character()
{
    MakeCharacter();
};

void GameManager::ShopEnter() {
	Shop shop(&itemDatabase, &character);
	shop.PrintMainMenu();
};

void GameManager::Gameover() {
    isGameover = true;
	std::cout << "게임오버..." << std::endl;
	Tools::WaitForKey();
};

void GameManager::Win() {
	std::cout << "게임 클리어!" << std::endl;
    isGameover = true;
	Tools::WaitForKey();
};

void GameManager::ShowMainMenu() {

    while (true)
    {
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

		int select = Tools::GetIntegerInRange(1, 5);
		MenuSelect menuSelect = static_cast<MenuSelect>(select);

        switch (menuSelect)
        {
        case MenuSelect::Character:
            character.ShowCharacterInfo();
            break;

        case MenuSelect::Shop:
            ShopEnter();
            break;

        case MenuSelect::Dungeon: {
            std::cout << "\n던전으로 입장합니다.\n";
			Dungeon dungeon(character);
			dungeon.EnterDungeon();
            return;
        }

        case MenuSelect::GameExit: {
            std::cout << "\n게임을 종료합니다.\n";
            isGameover = true;
            return;
        }

        case MenuSelect::Debug: 
            GetLevel();
            return;

        default: {
            break;
        }
        }
    }
};

void GameManager::LevelUp() {
    if (character.GetCurrentEXP() >= 100) {
        character.LevelUP();
        std::cout << "레벨 업!      LV " << character.GetLevel() - 1 << " ->  LV " << character.GetLevel() << std::endl;
    }
};

void GameManager::MakeCharacter()
{
    std::cout << "이름을 입력해주세요 : ";
    std::string name;
	std::getline(std::cin, name);
    character.SetName(name);
    std::cout << std::endl << "캐릭터 " << name << " 생성 완료!" << std::endl;
    character.ShowCharacterInfo();
}

MenuSelect GameManager::GetLevel() {
	character.SetLevel(10);
	std::cout << "레벨10 설정" << std::endl;
    Tools::WaitForKey();
	return MenuSelect::Debug;
}
