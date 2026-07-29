#pragma once

#include <string>

class Character
{
private:
    std::string Name;
    int CurrentHP = 0;
    int MaxHP = 0;
    int CurrentMP = 0;
    int MaxMP = 0;
    int CurrentEXP = 0;
    int MaxEXP = 100;
    int Level = 0;
    int ATK = 0;
    int DEF = 0;
    int Money = 0;

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
    void CharacterLevelUP();
};
