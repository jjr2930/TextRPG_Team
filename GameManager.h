#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>

#include "Character.h"
#include "Monster.h"
#include "Shop.h"


class GameManager {
private:
public:
    GameManager();
    void battle();


    Character character; // gamemanager 생성 시 캐릭터 생성



public:
    void encounter();
    bool isCharacterDead(int hp);
    bool isMonsterDead(int hp);
    void shopEnter();
    bool gameover();
    bool win();
    void showMainMenu();
    void levelUp();
    void makeCharacter();
};

void waitForKey()
{
    std::cout << "\n계속하려면 아무 키나 누르세요...";
    (void)_getch();
}





