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

int Character::GetAdditionalMaxHP() const
{
    return AdditionalMaxHP;
}

int Character::GetAdditionalMaxMP() const
{
    return AdditionalMaxMP;
}

int Character::GetAdditionalAttack() const
{
    return AdditionalAttack;
}

int Character::GetAdditionalDefense() const
{
    return AdditionalDefense;
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

void Character::SetAdditionalMaxHP(int additionalMaxHP)
{
    AdditionalMaxHP = additionalMaxHP;
}

void Character::SetAdditionalMaxMP(int additionalMaxMP)
{
    AdditionalMaxMP = additionalMaxMP;
}

void Character::SetAdditionalAttack(int additionalAttack)
{
    AdditionalAttack = additionalAttack;
}

void Character::SetAdditionalDefense(int additionalDefense)
{
    AdditionalDefense = additionalDefense;
}

void Character::ShowCharacterInfo() const
{
    std::cout << "이름 : " << Name << '\n';
    std::cout << "레벨 : " << Level << " (" << CurrentEXP << '/' << MaxEXP << ")\n";
    std::cout << "체력 : " << CurrentHP << " / " << MaxHP;
    if (AdditionalMaxHP > 0)
    {
        std::cout << " (+" << AdditionalMaxHP << ')';
    }
    std::cout << '\n';

    std::cout << "마나 : " << CurrentMP << " / " << MaxMP;
    if (AdditionalMaxMP > 0)
    {
        std::cout << " (+" << AdditionalMaxMP << ')';
    }
    std::cout << '\n';

    std::cout << "공격력 : " << Attack;
    if (AdditionalAttack > 0)
    {
        std::cout << " (+" << AdditionalAttack << ')';
    }
    std::cout << '\n';

    std::cout << "방어력 : " << Defense;
    if (AdditionalDefense > 0)
    {
        std::cout << " (+" << AdditionalDefense << ')';
    }
    std::cout << '\n';

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
