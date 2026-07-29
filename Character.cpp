#include "Character.h"

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
