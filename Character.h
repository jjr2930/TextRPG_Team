#pragma once
#include <string>

#include "Inventory.h"
#include "Battle.h"

class Character : public Battle {
private:
    std::string name;
    int currentHealth = 200; //현재 체력
    int maximumHealth = 200; //최대 체력
    int currentMana = 200; //현재 마나
    int maximumMana = 200; //최대 마나
    int currentExperience = 0; //현재 경험치
    int maximumExperience = 100; //최대 경험치
    int level = 1; //레벨
    int attack = 30; //공격력
    int defense = 30; //방어력
    int money = 0; //돈
    int additionalMaximumHealth = 0; //추가 체력
    int additionalMaximumMana = 0; //추가 마나
    int additionalAttack = 0; //추가 공격력
    int additionalDefense = 0; //추가 방어력
    Inventory inventory;

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
    //플레이어 공격 함수
    void TakeDamage(int damage) override;
    //플레이어 피격 함수
};
