#include "GameManager.h"


GameManager::GameManager() {
    makeCharacter();
};

void GameManager::battle(std::string attactName, std::string defenceName, int attactValue, int hpValue) {
    std::cout << attactName << "이(가) " << defenceName << "을(를) 공격합니다!";
    std::cout << defenceName << " 체력 : " << hpValue - attactValue << std::endl;
};

void GameManager::encounter() {
    Slime monster(
        "슬라임",
        50,
        10,
        20,
        "슬라임 젤리",
        100
    );

    std::cout << "몬스터 " << monster.GetName() << "가 난입했습니다. 전투 시작!" << std::endl;
    std::cout << "체력 : " << monster.GetHp() << ", 공격력 : " << monster.GetPower() << std::endl;
	waitForKey();

    int monHp = monster.GetHp();
    int charHp = character.GetCurrentHP();

    while (true) {
        battle(character.GetName(), monster.GetName(), character.GetAttack(), monHp);
        monHp -= character.GetAttack();
        if (isMonsterDead(monHp)) {
            break;
        }
        battle(monster.GetName(), character.GetName(), monster.GetPower(), charHp);
        charHp -= monster.GetPower();
        if (isCharacterDead(charHp)) {
            gameover();
            return;
        }
    }

    std::cout << monster.GetName() << " 처치!" << std::endl;
    std::cout << character.GetName() << "(이)가 " << monster.GetDropExp() << "EXP와 " << monster.GetDropItemPrice() << "골드를 획득했습니다.\n";
    
    character.SetCurrentEXP(character.GetCurrentEXP() + monster.GetDropExp());
    character.SetMoney(character.GetMoney() + monster.GetDropItemPrice());
    
    std::cout << "현재 EXP : " << character.GetCurrentEXP() << "/" << character.GetMaxEXP() << ", 골드 : " << character.GetMoney() << std::endl;
    waitForKey();
};

bool GameManager::isCharacterDead(int hp) {
	if (hp <= 0) {
		return true;
	}
	return false;
};

bool GameManager::isMonsterDead(int hp) {
	if (hp <= 0) {
		return true;
	}
	return false;
};

void GameManager::shopEnter() {
	Shop shop;
	shop.PrintMainMenu();
};

void GameManager::gameover() {
    isGameover = true;
	std::cout << "게임오버..." << std::endl;
	waitForKey();
};

void GameManager::win() {
	std::cout << "게임 클리어!" << std::endl;
    isWin = true;
	waitForKey();
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

void GameManager::makeCharacter()
{
    std::cout << "이름을 입력해주세요 : ";
    std::string name;
    std::cin >> name;
    character.SetName(name);
    std::cout << "캐릭터 " << name << " 생성 완료!" << std::endl;
    character.ShowCharacterInfo();
    waitForKey();
}

