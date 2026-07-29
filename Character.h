#pragma once
#include <string>

class Character
{
private:
    std::string Name; //이름
    int CurrentHP = 200; //현재 체력
    int MaxHP = 200; //최대 체력
    int CurrentMP = 200; //현재 마나
    int MaxMP = 200; //최대 마나
    int CurrentEXP = 0; //현재 경험치
    int MaxEXP = 100; //최대 경험치
    int Level = 1; //레벨
    int Attack = 30; //공격력
    int Defense = 30; //방어력
    int Money = 0; //돈
    int AdditionalMaxHP = 0; //추가 체력
    int AdditionalMaxMP = 0; //추가 마나
    int AdditionalAttack = 0; //추가 공격력
    int AdditionalDefense = 0; //추가 방어력

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

    void SetName(const std::string& name);
    void SetCurrentHP(int currentHP);
    void SetMaxHP(int maxHP);
    void SetCurrentMP(int currentMP);
    void SetMaxMP(int maxMP);
    void SetCurrentEXP(int currentEXP);
    void SetMaxEXP(int maxEXP);
    void SetLevel(int level);
    void SetAttack(int attack);
    void SetDefense(int defense);
    void SetMoney(int money);
    void SetAdditionalMaxHP(int additionalMaxHP);
    void SetAdditionalMaxMP(int additionalMaxMP);
    void SetAdditionalAttack(int additionalAttack);
    void SetAdditionalDefense(int additionalDefense);

    void ShowCharacterInfo() const;
    //상태 출력 함수
    void CharacterLevelUP();
    //레벨업 함수, 최대경험치 초과분 다음레벨로 이월
};
