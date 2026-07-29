#include <iostream>
#include <conio.h>

#include "Character.h"

const std::string& Character::GetName() const
{
    return mName;
}

int Character::GetCurrentHP() const
{
    return mCurrentHealth;
}

int Character::GetMaxHP() const
{
    return mMaximumHealth;
}

int Character::GetCurrentMP() const
{
    return mCurrentMana;
}

int Character::GetMaxMP() const
{
    return mMaximumMana;
}

int Character::GetCurrentEXP() const
{
    return mCurrentExperience;
}

int Character::GetMaxEXP() const
{
    return mMaximumExperience;
}

int Character::GetLevel() const
{
    return mLevel;
}

int Character::GetAttack() const
{
    return mAttack;
}

int Character::GetDefense() const
{
    return mDefense;
}

int Character::GetMoney() const
{
    return mMoney;
}

int Character::GetAdditionalMaxHP() const
{
    return mAdditionalMaximumHealth;
}

int Character::GetAdditionalMaxMP() const
{
    return mAdditionalMaximumMana;
}

int Character::GetAdditionalAttack() const
{
    return mAdditionalAttack;
}

int Character::GetAdditionalDefense() const
{
    return mAdditionalDefense;
}

Inventory& Character::GetInventory()
{
    return mInventory;
}

void Character::SetName(const std::string& name)
{
    mName = name;
}

void Character::SetCurrentHP(int currentHealth)
{
    mCurrentHealth = currentHealth;
}

void Character::SetMaxHP(int maximumHealth)
{
    mMaximumHealth = maximumHealth;
}

void Character::SetCurrentMP(int currentMana)
{
    mCurrentMana = currentMana;
}

void Character::SetMaxMP(int maximumMana)
{
    mMaximumMana = maximumMana;
}

void Character::SetCurrentEXP(int currentExperience)
{
    mCurrentExperience = currentExperience;
}

void Character::SetMaxEXP(int maximumExperience)
{
    mMaximumExperience = maximumExperience;
}

void Character::SetLevel(int level)
{
    mLevel = level;
}

void Character::SetAttack(int attack)
{
    mAttack = attack;
}

void Character::SetDefense(int defense)
{
    mDefense = defense;
}

void Character::SetMoney(int money)
{
    mMoney = money;
}

void Character::SetAdditionalMaxHP(int additionalMaximumHealth)
{
    mAdditionalMaximumHealth = additionalMaximumHealth;
}

void Character::SetAdditionalMaxMP(int additionalMaximumMana)
{
    mAdditionalMaximumMana = additionalMaximumMana;
}

void Character::SetAdditionalAttack(int additionalAttack)
{
    mAdditionalAttack = additionalAttack;
}

void Character::SetAdditionalDefense(int additionalDefense)
{
    mAdditionalDefense = additionalDefense;
}

void Character::ShowCharacterInfo() const
{
    std::cout << "이름 : " << mName << '\n';
    std::cout << "레벨 : " << mLevel << " (" << mCurrentExperience << '/' << mMaximumExperience << ")\n";

    std::cout << "체력 : " << mCurrentHealth << " / " << mMaximumHealth;
    if (mAdditionalMaximumHealth > 0)
        std::cout << " (+" << mAdditionalMaximumHealth << ')';
    std::cout << '\n';

    std::cout << "마나 : " << mCurrentMana << " / " << mMaximumMana;
    if (mAdditionalMaximumMana > 0)
        std::cout << " (+" << mAdditionalMaximumMana << ')';
    std::cout << '\n';

    std::cout << "공격력 : " << mAttack;
    if (mAdditionalAttack > 0)
        std::cout << " (+" << mAdditionalAttack << ')';
    std::cout << '\n';

    std::cout << "방어력 : " << mDefense;
    if (mAdditionalDefense > 0)
        std::cout << " (+" << mAdditionalDefense << ')';
    std::cout << '\n';

    std::cout << "소지금 : " << mMoney << '\n';
    mInventory.ShowItems();
    std::cout << ">> 계속하려면 아무 키나 누르세요" << std::endl;
    (void)_getch();
}

void Character::CharacterLevelUP()
{
    mCurrentExperience -= mMaximumExperience;
    mLevel += 1;

    mMaximumHealth += mLevel * 20;
    mMaximumMana += mLevel * 20;
    mCurrentHealth = mMaximumHealth;
    mCurrentMana = mMaximumMana;

    mAttack += mLevel * 5;
    mDefense += mLevel * 5;
}
