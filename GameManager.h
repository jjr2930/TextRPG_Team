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

enum class MenuSelection {
	Character = 1,
	Shop = 2,
	Dungeon = 3,
	GameExit = 4,
    Debug = 5
};

class GameManager {
private:
    Character character; // gamemanager 생성 시 캐릭터 생성
    ItemDatabase itemDatabase;

public:
    GameManager();

public:
    void ShopEnter();
    void Gameover();
    void Win();
    void ShowMainMenu();
    void LevelUp();
    void MakeCharacter();

public:
    bool isGameover = false;
    bool isWin = false;
    bool isLevelTen = false;

public:
    MenuSelection GetLevel();

};