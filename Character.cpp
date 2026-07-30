#include <iostream>
#include <conio.h>
#include <algorithm>

#include "Character.h"

const std::string& Character::GetName() const {
    return mName;
}

int Character::GetCurrentHP() const {
    return mCurrentHealth;
}

int Character::GetMaxHP() const {
    return mMaximumHealth + mAdditionalMaximumHealth;
} //최대체력과 추가체력의 합산을 get

int Character::GetCurrentMP() const {
    return mCurrentMana;
}

int Character::GetMaxMP() const {
    return mMaximumHealth + mAdditionalMaximumHealth;
} //최대마나와 추가마나의 합산을 get

int Character::GetCurrentEXP() const {
    return mCurrentExperience;
}

int Character::GetMaxEXP() const {
    return mMaximumExperience;
}

int Character::GetLevel() const {
    return mLevel;
}

int Character::GetAttack() const {
    return mAttack + mAdditionalAttack;
} //공격력과 추가공격력의 합산을 get

int Character::GetDefense() const {
    return mDefense + mAdditionalDefense;
} //방어력과 추가방어력의 합산을 get

int Character::GetMoney() const {
    return mMoney;
}

int Character::GetAdditionalMaxHP() const {
    return mAdditionalMaximumHealth;
}

int Character::GetAdditionalMaxMP() const {
    return mAdditionalMaximumMana;
}

int Character::GetAdditionalAttack() const {
    return mAdditionalAttack;
}

int Character::GetAdditionalDefense() const {
    return mAdditionalDefense;
}

Inventory& Character::GetInventory() {
    return mInventory;
}

void Character::SetName(const std::string& name) {
    mName = name;
}

void Character::SetCurrentHP(int currentHealth) {
    if(currentHealth > GetMaxHP()) {
        mCurrentHealth = GetMaxHP();
    }
    else {
    mCurrentHealth = currentHealth;
    }
} // 최대체력 초과회복이 되지 않게 수정

void Character::SetMaxHP(int maximumHealth) {
    mMaximumHealth = maximumHealth;
}

void Character::SetCurrentMP(int currentMana) {
    if(currentMana > GetMaxHP()) {
        mCurrentMana = GetMaxHP();
    }
    else {
    mCurrentMana = currentMana;
    }
} // 최대마나 초과회복이 되지 않게 수정

void Character::SetMaxMP(int maximumMana) {
    mMaximumMana = maximumMana;
}

void Character::SetCurrentEXP(int currentExperience) {
    mCurrentExperience = currentExperience;
}

void Character::SetMaxEXP(int maximumExperience) {
    mMaximumExperience = maximumExperience;
}

void Character::SetLevel(int level) {
    mLevel = level;
}

void Character::SetAttack(int attack) {
    mAttack = attack;
}

void Character::SetDefense(int defense) {
    mDefense = defense;
}

void Character::SetMoney(int money) {
    mMoney = money;
}

void Character::SetAdditionalMaxHP(int additionalMaximumHealth) {
    mAdditionalMaximumHealth = additionalMaximumHealth;
}

void Character::SetAdditionalMaxMP(int additionalMaximumMana) {
    mAdditionalMaximumMana = additionalMaximumMana;
}

void Character::SetAdditionalAttack(int additionalAttack) {
    mAdditionalAttack = additionalAttack;
}

void Character::SetAdditionalDefense(int additionalDefense) {
    mAdditionalDefense = additionalDefense;
}

void Character::ShowCharacterInfo() const {
    std::cout << "이름 : " << mName << '\n';
    std::cout << "레벨 : " << mLevel << " (" << mCurrentExperience << '/' << mMaximumExperience << ")\n";

    std::cout
    << "체력 : "
    << GetCurrentHP()
    << " / "
    << GetMaxHP()
    << '\n';


    /*
    std::cout
    << "마나 : "
    << GetCurrentMP()
    << " / "
    << GetMaxMP()
    << '\n';
    */

    std::cout << "공격력 : " << mAttack;
    if (mAdditionalAttack > 0)
        std::cout << " (+" << mAdditionalAttack << ')';
    std::cout << '\n';

    /*
    std::cout << "방어력 : " << mDefense;
    if (mAdditionalDefense > 0)
        std::cout << " (+" << mAdditionalDefense << ')';
    std::cout << '\n';
    */

    std::cout << "소지금 : " << mMoney << '\n';
    mInventory.ShowItems();
    std::cout << ">> 계속하려면 아무 키나 누르세요" << std::endl;
    (void)_getch();
}

void Character::CharacterLevelUP() {
    mCurrentExperience -= mMaximumExperience;
    mLevel += 1;

    mMaximumHealth += mLevel * 20;
    mMaximumMana += mLevel * 20;
    mCurrentHealth = mMaximumHealth;
    mCurrentMana = mMaximumMana;

    mAttack += mLevel * 5;
    mDefense += mLevel * 5;
}

void Character::Attack(Battle* other) {
    if (other == nullptr) {
        return;
    } //포인터 검사
    int damage = GetAttack();
    
    std::cout
        << GetName()
        << "가 공격했습니다.\n";

    other->TakeDamage(damage);
}

void Character::TakeDamage(int damage) {
    int actualDamage = std::max(0, damage);
    //추후 방어력이 적용될 여부로 인해 생성
    int remainingHP = std::max(0,GetCurrentHP() - actualDamage);

    SetCurrentHP(remainingHP);

    std::cout
        << GetName()
        << "가 "
        << actualDamage
        << "의 피해를 입었습니다.\n";

    std::cout
        << GetName()
        << "의 남은 체력: "
        << GetCurrentHP()
        << '\n';
}
