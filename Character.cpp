#include "Character.h"
#include <conio.h>
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

int Character::GetAttack() const
{
    return Attack;
}

int Character::GetDefense() const
{
    return Defense;
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

void Character::SetAttack(int attack)
{
    Attack = attack;
}

void Character::SetDefense(int defense)
{
    Defense = defense;
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
    std::cout << "공격력 : " << Attack << '\n';
    //std::cout << "방어력 : " << Defense << '\n';
    std::cout << "소지금 : " << Money << '\n';
    std::cout << ">> 계속하려면 아무 키나 누르세요" << std::endl;
    (void)_getch();
}

void Character::CharacterLevelUP()
{
    CurrentEXP = CurrentEXP - MaxEXP;
    Level += 1;

    MaxHP += Level * 20;
    MaxMP += Level * 20;
    CurrentHP = MaxHP;
    CurrentMP = MaxMP;

    Attack += Level * 5;
    Defense += Level * 5;
}
