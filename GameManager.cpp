#include "GameManager.h"



GameManager::GameManager() {
    MakeCharacter();
};

void GameManager::Battle(std::string attactName, std::string defenceName, int attactValue, int hpValue) {
    std::cout << std::endl << attactName << "이(가) " << defenceName << "을(를) 공격합니다!";
    std::cout << defenceName << " 체력 : " << hpValue - attactValue << std::endl;
};

void GameManager::Encounter() {
    Slime monster(nullptr, 1); // 나중에 슬라임 드롭아이템 넣을것
    system("cls");
    std::cout << "몬스터 " << monster.GetName() << "(이)가 난입했습니다. 전투 시작!" << std::endl;
    std::cout << "체력 : " << monster.GetHp() << ", 공격력 : " << monster.GetPower() << std::endl;
	WaitForKey();




    std::cout << std::endl << monster.GetName() << " 처치!" << std::endl;
    std::cout << character.GetName() << "(이)가 " << monster.GetDropExp() << "EXP와 " << monster.RandomGold() << "골드를 획득했습니다.\n";
    
    character.SetCurrentEXP(character.GetCurrentEXP() + monster.GetDropExp());
    character.SetMoney(character.GetMoney() + monster.RandomGold());

    LevelUp();
    
    std::cout << std::endl <<"현재 EXP : " << character.GetCurrentEXP() << "/" << character.GetMaxEXP() << ", 골드 : " << character.GetMoney() << std::endl;
    WaitForKey();
};

bool GameManager::IsCharacterDead(int hp) {
    if (hp <= 0) return true;
	return false;
};

bool GameManager::IsMonsterDead(int hp) {
	if (hp <= 0) return true;
	return false;
};

void GameManager::ShopEnter() {
	Shop shop;
	shop.PrintMainMenu();
};

void GameManager::Gameover() {
    isGameover = true;
	std::cout << "게임오버..." << std::endl;
	WaitForKey();
};

void GameManager::Win() {
	std::cout << "게임 클리어!" << std::endl;
    isGameover = true;
	WaitForKey();
};

void GameManager::ShowMainMenu() {

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
        std::cout << "       [4] 게임 종료\n";
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
            ShopEnter();
            break;

        case 3:
            std::cout << "\n행동을 종료합니다.\n";
            return;

        case 4: {
            std::cout << "\n게임을 종료합니다.\n";
            isGameover = true;
            return;
        }
        default: {
            std::cout << "\n잘못된 입력입니다.\n";
            WaitForKey();
            break;
        }
        }
    }
};

void GameManager::LevelUp() {
    if (character.GetCurrentEXP() >= 100) {
        character.CharacterLevelUP();
        std::cout << "레벨 업!      LV " << character.GetLevel() - 1 << " ->  LV " << character.GetLevel() << std::endl;
    }
};

void GameManager::MakeCharacter()
{
    std::cout << "이름을 입력해주세요 : ";
    std::string name;
    std::cin >> name;
    character.SetName(name);
    std::cout << std::endl << "캐릭터 " << name << " 생성 완료!" << std::endl;
    character.ShowCharacterInfo();
}

