#pragma once
#include <string>

class Character
{
private:
    std::string Name; //이름
    int CurrentHP = 200; //현재 체력
    int MaxHP = 200; //최대 체력
    int CurrentMP = 200; //현재 마나
    int MaxMP = 200; //최대 마나
    int CurrentEXP = 0; //현재 경험치
    int MaxEXP = 100; //최대 경험치
    int Level = 1; //레벨
    int ATK = 30; //공격력
    int DEF = 30; //방어력
    int Money = 0; //돈

public:
    const std::string& GetName() const;
    int GetCurrentHP() const;
    int GetMaxHP() const;
    int GetCurrentMP() const;
    int GetMaxMP() const;
    int GetCurrentEXP() const;
    int GetMaxEXP() const;
    int GetLevel() const;
    int GetATK() const;
    int GetDEF() const;
    int GetMoney() const;

    void SetName(const std::string& name);
    void SetCurrentHP(int currentHP);
    void SetMaxHP(int maxHP);
    void SetCurrentMP(int currentMP);
    void SetMaxMP(int maxMP);
    void SetCurrentEXP(int currentEXP);
    void SetMaxEXP(int maxEXP);
    void SetLevel(int level);
    void SetATK(int atk);
    void SetDEF(int def);
    void SetMoney(int money);

    void ShowCharacterInfo() const;
    //상태 출력 함수
    void CharacterLevelUP();
    //레벨업 함수, 최대경험치 초과분 다음레벨로 이월
};
