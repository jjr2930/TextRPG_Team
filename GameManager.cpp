#include "GameManager.h"


GameManager::GameManager() {
    makeCharacter();
};

void GameManager::battle() {
	std::cout << character.GetName();
};

void GameManager::encounter() {
	Monster monster; // encounter 실행 시 몬스터 생성, 배틀 종료시 제거
	std::cout << "몬스터" << monster.GetName() << "가 난입했습니다.전투 시작!" << std::endl;

	waitForKey();
	system("cls");

    while (isCharacterDead(character.GetCurrentHP()) || isMonsterDead(monster.GetHp())){
        battle(); // battle 반복 실행
    }
};

bool GameManager::isCharacterDead(int hp) {
	if (hp <= 0) {
		gameover();
		return false;
	}
	return true;
};

bool GameManager::isMonsterDead(int hp) {
	if (hp <= 0) {
		std::cout << "승리!" << std::endl;
		return false;
	}
	return true;
};

void GameManager::shopEnter() {
	Shop shop;
	Shop::PrintMainMenu;
};

bool GameManager::gameover() {
	std::cout << "게임오버" << std::endl;
	waitForKey();
    return true;
};

bool GameManager::win() {
	std::cout << "게임 클리어" << std::endl;
	waitForKey();
    return true;
};

void GameManager::showMainMenu() {
    int select = 0;

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
        std::cout << "       [3] 행동 종료\n";
        std::cout << "\n";
        std::cout << "----------------------------------------\n";
        std::cout << "       행동을 선택해 주세요 : ";

        std::cin >> select;

        switch (select)
        {
        case 1:
            character.ShowCharacterInfo();
            break;

        case 2:
            shopEnter();
            break;

        case 3:
            std::cout << "\n행동을 종료합니다.\n";
            return;

        default:
            std::cout << "\n잘못된 입력입니다.\n";
            waitForKey();
            break;
        }
    }
};

void GameManager::levelUp() {
    if (character.GetCurrentEXP() >= 100) {
        character.CharacterLevelUP();
    }
};

void GameManager::makeCharacter() {
    std::cout << "이름을 입력해주세요 : ";
    std::string name;
    std::cin >> name;
    character.SetName(name);
    std::cout << "캐릭터" << name << "생성 완료!" << std::endl;
    character.ShowCharacterInfo();
    waitForKey();
};