#pragma once
#include <iostream>
#include <string>
#include <conio.h>

#include "Character.h"
#include "Monster.h"
#include "Shop.h"
#include "Slime.h"


class GameManager {
private:
public:
    GameManager();
    void Battle(std::string attactName, std::string defenceName, int attactValue, int hpValue);

    Character character; // gamemanager 생성 시 캐릭터 생성


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
};

inline void WaitForKey()
{
    std::cout << std::endl <<"계속하려면 아무 키나 누르세요...\n";
    (void)_getch();
}





