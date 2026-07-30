#pragma once
#include <string>

#include "Inventory.h"
#include "Battle.h"

class Character : public Battle 
{
private:
    std::string mName;
    int mCurrentHealth = 200; //현재 체력
    int mMaximumHealth = 200; //최대 체력
    int mCurrentMana = 200; //현재 마나
    int mMaximumMana = 200; //최대 마나
    int mCurrentExperience = 0; //현재 경험치
    int mMaximumExperience = 100; //최대 경험치
    int mLevel = 1; //레벨
    int mAttack = 30; //공격력
    int mDefense = 30; //방어력
    int mMoney = 0; //돈
    int mAdditionalMaximumHealth = 0; //추가 체력
    int mAdditionalMaximumMana = 0; //추가 마나
    int mAdditionalAttack = 0; //추가 공격력
    int mAdditionalDefense = 0; //추가 방어력
    Inventory mInventory;

public:
    const std::string& GetName() const;
    int GetCurrentHP() const;
    int GetMaxHP() const;
    int GetCurrentMP() const;
    int GetMaxMP() const;
    int GetCurrentEXP() const;
    int GetMaxEXP() const;
    int GetLevel() const;
    int GetAttack() const;
    int GetDefense() const;
    int GetMoney() const;
    int GetAdditionalMaxHP() const;
    int GetAdditionalMaxMP() const;
    int GetAdditionalAttack() const;
    int GetAdditionalDefense() const;
    Inventory& GetInventory();

    void SetName(const std::string& name);
    void SetCurrentHP(int currentHealth);
    void SetMaxHP(int maximumHealth);
    void SetCurrentMP(int currentMana);
    void SetMaxMP(int maximumMana);
    void SetCurrentEXP(int currentExperience);
    void SetMaxEXP(int maximumExperience);
    void SetLevel(int level);
    void SetAttack(int attack);
    void SetDefense(int defense);
    void SetMoney(int money);
    void SetAdditionalMaxHP(int additionalMaximumHealth);
    void SetAdditionalMaxMP(int additionalMaximumMana);
    void SetAdditionalAttack(int additionalAttack);
    void SetAdditionalDefense(int additionalDefense);

    void ShowCharacterInfo() const;
    //상태 출력 함수
    void CharacterLevelUP();
    //레벨업 함수, 최대경험치 초과분 다음레벨로 이월
    void Attack(Battle* other) override;
    void TakeDamage(int damage) override;
};
