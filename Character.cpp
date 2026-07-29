#include "Character.h"

#include <iostream>

const std::string& Character::GetName() const
{
    return Name;
}

int Character::GetCurrentHP() const
{
    return CurrentHP;
}

int Character::GetMaxHP() const
{
    return MaxHP;
}

int Character::GetCurrentMP() const
{
    return CurrentMP;
}

int Character::GetMaxMP() const
{
    return MaxMP;
}

int Character::GetCurrentEXP() const
{
    return CurrentEXP;
}

int Character::GetMaxEXP() const
{
    return MaxEXP;
}

int Character::GetLevel() const
{
    return Level;
}

int Character::GetATK() const
{
    return ATK;
}

int Character::GetDEF() const
{
    return DEF;
}

int Character::GetMoney() const
{
    return Money;
}

void Character::SetName(const std::string& name)
{
    Name = name;
}

void Character::SetCurrentHP(int currentHP)
{
    CurrentHP = currentHP;
}

void Character::SetMaxHP(int maxHP)
{
    MaxHP = maxHP;
}

void Character::SetCurrentMP(int currentMP)
{
    CurrentMP = currentMP;
}

void Character::SetMaxMP(int maxMP)
{
    MaxMP = maxMP;
}

void Character::SetCurrentEXP(int currentEXP)
{
    CurrentEXP = currentEXP;
}

void Character::SetMaxEXP(int maxEXP)
{
    MaxEXP = maxEXP;
}

void Character::SetLevel(int level)
{
    Level = level;
}

void Character::SetATK(int atk)
{
    ATK = atk;
}

void Character::SetDEF(int def)
{
    DEF = def;
}

void Character::SetMoney(int money)
{
    Money = money;
}

void Character::ShowCharacterInfo() const
{
    std::cout << "이름 : " << Name << '\n';
    std::cout << "레벨 : " << Level << " (" << CurrentEXP << '/' << MaxEXP << ")\n";
    std::cout << "체력 : " << CurrentHP << " / " << MaxHP << '\n';
    //std::cout << "마나 : " << CurrentMP << " / " << MaxMP << '\n';
    std::cout << "공격력 : " << ATK << '\n';
    //std::cout << "방어력 : " << DEF << '\n';
    std::cout << "소지금 : " << Money << '\n';
}

void Character::CharacterLevelUP()
{
    CurrentEXP = CurrentEXP - MaxEXP;
    Level += 1;

    MaxHP += Level * 20;
    //MaxMP += Level * 20;
    CurrentHP = MaxHP;
    //CurrentMP = MaxMP;

    ATK += Level * 5;
    //DEF += Level * 5;
}
