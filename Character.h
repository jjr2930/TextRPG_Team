#pragma once
#include <string>

#include "Inventory.h"
#include "Battle.h"
#include "job.h"

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
    const Job* job = nullptr; //직업
    Inventory inventory;

    const int noWeapon = -1; // 무기 미착용 상태 = -1
    int currentEquippedWeapon = noWeapon; // 현재 무기

    int gearAttack = 0; // 장비 공격력
    int gearDefense = 0; // 장비 방어력
    int gearMaxHealth = 0; // 장비 체력
    int gearMaxMana = 0; // 장비 마나

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
    const Job* GetJob() const;
    Inventory& GetInventory();
    int GetCurrentEquippedWeapon() const;
    int GetGearAttack() const;
    int GetGearDefense() const;
    int GetGearMaxHealth() const;
    int GetGearMaxMana() const;


    void SetName(const std::string& name);
    void SetCurrentHP(int currentHealth);
    void SetMaxHP(int maximumHealth);
    void SetCurrentMP(int currentMana);
    void SetMaxMP(int maximumMana);
    void SetCurrentEXP(int currentExperience);
    void SetMaxEXP(int maximumExperience);
    void SetAttack(int attack);
    void SetDefense(int defense);
    void SetMoney(int money);
    void SetAdditionalMaxHP(int additionalMaximumHealth);
    void SetAdditionalMaxMP(int additionalMaximumMana);
    void SetAdditionalAttack(int additionalAttack);
    void SetAdditionalDefense(int additionalDefense);

    //무기 장착
    void SetEquippedWeapon(
        int itemID,
        int weaponAttack,
        int weaponDefense,
        int weaponMaxHealth,
        int weaponMaxMana
    );
    //장착 해제
    void ClearEquippedWeapon();
    
    //전직 함수
    void ChangeJob();
    //상태 출력 함수
    void ShowCharacterInfo() const;
    //레벨업 함수, 최대경험치 초과분 다음레벨로 이월
    void LevelUP();
    //플레이어 공격 함수
    virtual void Attack() override;
    //플레이어 피격 함수
    virtual void TakeDamage(int damage) override;


};

