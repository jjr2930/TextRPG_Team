#include "Character.h"


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