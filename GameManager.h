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


class GameManager {
private:
public:
    GameManager();
    void Battle(Monster* monster);

    //TODO: 멤버변수는 특별한 사유가 없다면 숨겨야함 고로 private;
    Character character; // gamemanager 생성 시 캐릭터 생성
    ItemDatabase itemDatabase;

public:
    void Encounter();
    bool IsCharacterDead(int hp);
    bool IsMonsterDead(int hp);
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
};