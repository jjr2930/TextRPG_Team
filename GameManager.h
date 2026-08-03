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

enum class DebugMode {
	None,
	All,
	Character,
	Shop,
	Dungeon
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
    DebugMode GetLevel();

};