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
#include "Dungeon.h"
#include "DemonKing.h"

/// <summary>메인 메뉴에서 선택할 수 있는 행동을 나타냅니다.</summary>
enum class MenuSelection {
	Character = 1,
	Shop = 2,
	Dungeon = 3,
	GameExit = 4,
    Debug = 5
};

/// <summary>캐릭터 생성부터 메뉴 진행과 게임 종료까지 전체 게임 흐름을 관리합니다.</summary>
class GameManager {
private:
    /// <summary>현재 게임에서 사용하는 플레이어 캐릭터입니다.</summary>
    Character character;

    /// <summary>상점과 보상에서 참조하는 아이템 데이터베이스입니다.</summary>
    ItemDatabase itemDatabase;

public:
    /// <summary>게임에 사용할 캐릭터를 생성하고 게임 매니저를 초기화합니다.</summary>
    GameManager();

public:
    /// <summary>현재 캐릭터와 아이템 데이터베이스를 사용해 상점에 입장합니다.</summary>
    void ShopEnter();

    /// <summary>게임 오버 상태로 전환하고 안내 메시지를 출력합니다.</summary>
    void Gameover();

    /// <summary>게임 클리어 메시지를 출력하고 게임 진행을 종료합니다.</summary>
    void Win();

    /// <summary>메인 메뉴를 반복해서 출력하고 플레이어의 선택을 처리합니다.</summary>
    void ShowMainMenu();

    /// <summary>경험치가 조건을 만족하면 캐릭터의 레벨을 올립니다.</summary>
    void LevelUp();

    /// <summary>플레이어에게 이름을 입력받아 캐릭터를 생성합니다.</summary>
    void MakeCharacter();

public:
    /// <summary>게임 오버 또는 게임 종료 여부입니다.</summary>
    bool isGameover = false;

    /// <summary>게임 클리어 여부입니다.</summary>
    bool isWin = false;

    /// <summary>레벨 10 관련 진행 상태를 저장하기 위해 마련된 플래그입니다.</summary>
    bool isLevelTen = false;

public:
    /// <summary>디버그용으로 캐릭터를 레벨 10까지 올립니다.</summary>
    /// <returns>디버그 메뉴 선택값을 반환합니다.</returns>
    MenuSelection GetLevel();

};
