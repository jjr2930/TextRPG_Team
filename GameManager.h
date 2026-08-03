#pragma once
#include <iostream>
#include <string>
#include <conio.h>


#include "Tools.h"
#include "Character.h"
#include "Monster.h"
#include "Shop.h"
#include "Slime.h"
#include "ItemDatabases.h"
#include "Inventory.h"
#include "Boss.h"
#include "Dungeon.h"

// 메인 메뉴에서 사용자가 선택할 수 있는 항목과 입력 번호를 연결한다.
enum class MenuSelection {
	Character = 1,
	Shop = 2,
	Dungeon = 3,
	GameExit = 4,
    Debug = 5
};

// 캐릭터 생성부터 상점·던전 진입, 게임 종료까지 전체 게임 흐름을 관리한다.
class GameManager {
private:
    Character character;       // 게임 전체에서 계속 사용하는 플레이어 캐릭터
    ItemDatabase itemDatabase; // 상점에서 조회할 공용 아이템 데이터베이스

public:
    // 게임 매니저를 만들면서 캐릭터 생성 절차를 시작한다.
    GameManager();

public:
    void ShopEnter();     // 현재 캐릭터와 아이템 DB를 사용해 상점에 입장한다.
    void Gameover();      // 게임 오버 상태로 전환하고 안내를 출력한다.
    void Win();           // 승리 안내 후 게임 종료 상태로 전환한다.
    void ShowMainMenu();  // 메뉴 입력을 받아 각 콘텐츠로 이동한다.
    void LevelUp();       // 경험치가 충분하면 캐릭터 레벨을 올린다.
    void MakeCharacter(); // 이름을 입력받아 플레이어 캐릭터를 완성한다.

public:
    bool isGameover = false; // 게임 종료 여부
    bool isWin = false;      // 최종 승리 여부
    bool isLevelTen = false; // 레벨 10 도달 여부

public:
    // 디버그용으로 캐릭터 레벨을 10까지 올리고 선택 결과를 반환한다.
    MenuSelection GetLevel();

};
