#pragma once
#include <iostream>
#include <string>




class GameManager {
private:
public:
    GameManager() {};
    void battle();


    Character character(); // gamemanager 생성 시 캐릭터 생성



public:
    void encounter();
    bool isCharacterDead(int hp);
    bool isMonsterDead(int hp);
    void shopEnter();
    bool gameover();
    void win();
};







