#include "GameManager.h"



GameManager::GameManager() 
    : itemDatabase()
    , character()
{
    MakeCharacter();
};

void GameManager::Battle(Monster* monster) {

	monster->SetTarget(&character);
	character.SetTarget(monster);

    while (true) {
        character.DoMyTurn();

        if (IsMonsterDead(monster->GetCurrentHp())) {
            std::cout << "몬스터 " << monster->GetName() << "(을)를 처치했습니다!" << std::endl;
            //캐릭터의 강화물약 효과가 전투 종료 시 사라지게 하는 함수입니다.
            character.EndBattle();
            break;
        }

		monster->DoMyTurn();

		if (IsCharacterDead(character.GetCurrentHP())) {
			Gameover();
			break;
		}
    }
};

void GameManager::Encounter() {
    if (!isLevelTen) {
        Slime monster(nullptr, character.GetLevel()); // 나중에 슬라임 드롭아이템 넣을것
        system("cls");
        std::cout << "몬스터 " << monster.GetName() << "(이)가 난입했습니다. 전투 시작!" << std::endl;
        std::cout << "체력 : " << monster.GetCurrentHp() << ", 공격력 : " << monster.GetPower() << std::endl;
        Tools::WaitForKey();

        Battle(&monster);

        std::cout << std::endl << monster.GetName() << " 처치!" << std::endl;
        std::cout << character.GetName() << "(이)가 " << monster.GetDropExp() << "EXP와 " << monster.RandomGold() << "골드를 획득했습니다.\n";


        character.SetCurrentEXP(character.GetCurrentEXP() + monster.GetDropExp());
        character.SetMoney(character.GetMoney() + monster.RandomGold());
        LevelUp();
        std::cout << std::endl << "현재 EXP : " << character.GetCurrentEXP() << "/" << character.GetMaxEXP() << ", 골드 : " << character.GetMoney() << std::endl;

        if (character.GetLevel() >= 10) {
            isLevelTen = true;
        }
    }
	else if (isLevelTen) {
        DemonKing DemonKing(nullptr, character.GetLevel());
		Battle(&DemonKing);
	}


    Tools::WaitForKey();
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
		MenuSelection menuSelect = static_cast<MenuSelection>(select);

        switch (menuSelect)
        {
        case MenuSelection::Character:
            character.ShowCharacterInfo();
            break;

        case MenuSelection::Shop:
            ShopEnter();
            break;

        case MenuSelection::Dungeon: {
            std::cout << "\n던전으로 입장합니다.\n";
			Dungeon dungeon(character);
			dungeon.EnterDungeon();
            return;
        }

        case MenuSelection::GameExit: {
            std::cout << "\n게임을 종료합니다.\n";
            isGameover = true;
            return;
        }

        case MenuSelection::Debug: 
            GetLevel();
            return;

        default:
            break;
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

MenuSelection GameManager::GetLevel() {
	for (int i = 1; i < 10; ++i) { // 하드코딩으로 레벨 10까지 올리는 코드, 나중에 제거
		character.LevelUP();
	}
	std::cout << "레벨10 설정" << std::endl;
    Tools::WaitForKey();
	return MenuSelection::Debug;
}
