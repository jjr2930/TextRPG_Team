#include <iostream>
#include <conio.h>
#include <algorithm>

#include "Character.h"

const std::string& Character::GetName() const {
    return name;
}

int Character::GetCurrentHP() const {
    return currentHealth;
}

int Character::GetMaxHP() const {
    return maximumHealth + additionalMaximumHealth;
} //최대체력과 추가체력의 합산을 get

int Character::GetCurrentMP() const {
    return currentMana;
}

int Character::GetMaxMP() const {
    return maximumMana + additionalMaximumMana;
} //최대마나와 추가마나의 합산을 get

int Character::GetCurrentEXP() const {
    return currentExperience;
}

int Character::GetMaxEXP() const {
    return maximumExperience;
}

int Character::GetLevel() const {
    return level;
}

int Character::GetAttack() const {
    return attack + additionalAttack;
} //공격력과 추가공격력의 합산을 get

int Character::GetDefense() const {
    return defense + additionalDefense;
} //방어력과 추가방어력의 합산을 get

int Character::GetMoney() const {
    return money;
}

int Character::GetAdditionalMaxHP() const {
    return additionalMaximumHealth;
}

int Character::GetAdditionalMaxMP() const {
    return additionalMaximumMana;
}

int Character::GetAdditionalAttack() const {
    return additionalAttack;
}

int Character::GetAdditionalDefense() const {
    return additionalDefense;
}

Inventory& Character::GetInventory() {
    return inventory;
}

void Character::SetName(const std::string& name) {
    this->name = name;
}

void Character::SetCurrentHP(int currentHealth) {
    if(currentHealth > GetMaxHP()) {
        this->currentHealth = GetMaxHP();
    }
    else {
    this->currentHealth = currentHealth;
    }
} // 최대체력 초과회복이 되지 않게 수정

void Character::SetMaxHP(int maximumHealth) {
    this->maximumHealth = maximumHealth;
}

void Character::SetCurrentMP(int currentMana) {
    if(currentMana > GetMaxMP()) {
        this->currentMana = GetMaxMP();
    }
    else {
    this->currentMana = currentMana;
    }
} // 최대마나 초과회복이 되지 않게 수정

void Character::SetMaxMP(int maximumMana) {
    this->maximumMana = maximumMana;
}

void Character::SetCurrentEXP(int currentExperience) {
    this->currentExperience = currentExperience;
}

void Character::SetMaxEXP(int maximumExperience) {
    this->maximumExperience = maximumExperience;
}

void Character::SetLevel(int level) {
    this->level = level;
    if(level == 10) {
        std::cout << "이제 일반 몬스터는 상대도 안 된다!\n";
    }
}

void Character::SetAttack(int attack) {
    this->attack = attack;
}

void Character::SetDefense(int defense) {
    this->defense = defense;
}

void Character::SetMoney(int money) {
    this->money = money;
}

void Character::SetAdditionalMaxHP(int additionalMaximumHealth) {
    this->additionalMaximumHealth = additionalMaximumHealth;
}

void Character::SetAdditionalMaxMP(int additionalMaximumMana) {
    this->additionalMaximumMana = additionalMaximumMana;
}

void Character::SetAdditionalAttack(int additionalAttack) {
    this->additionalAttack = additionalAttack;
}

void Character::SetAdditionalDefense(int additionalDefense) {
    this->additionalDefense = additionalDefense;
}

void Character::ShowCharacterInfo() const {
    std::cout << "이름 : " << name << '\n';
    std::cout << "레벨 : " << level << " (" << currentExperience << '/' << maximumExperience << ")\n";

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

    std::cout << "공격력 : " << attack;
    if (additionalAttack > 0)
        std::cout << " (+" << additionalAttack << ')';
    std::cout << '\n';

    /*
    std::cout << "방어력 : " << defense;
    if (additionalDefense > 0)
        std::cout << " (+" << additionalDefense << ')';
    std::cout << '\n';
    */

    std::cout << "소지금 : " << money << '\n';
    inventory.ShowItems();
    std::cout << ">> 계속하려면 아무 키나 누르세요" << std::endl;
    (void)_getch();
}

void Character::CharacterLevelUP() {
    currentExperience -= maximumExperience;
    level += 1;

    maximumHealth += level * 20;
    maximumMana += level * 20;
    currentHealth = maximumHealth;
    currentMana = maximumMana;

    attack += level * 5;
    defense += level * 5;
}

void Character::Attack() {
    if (target == nullptr) {
        return;
    } //포인터 검사
    int damage = GetAttack();
    
    std::cout
        << GetName()
        << "이(가) 공격하였습니다. ("
        << damage
        << ")\n";

    target->TakeDamage(damage);
}

void Character::TakeDamage(int damage) {
    int actualDamage = std::max(0, damage);
    //추후 방어력이 적용될 여부로 인해 생성
    int remainingHP = std::max(0,GetCurrentHP() - actualDamage);

    SetCurrentHP(remainingHP);

    std::cout
        << actualDamage
        << "만큼 "
        << GetName()
        << "이(가) 피해를 입었습니다.\n";

    if (GetCurrentHP() <= 0) {
        std::cout
            << GetName()
            << "이(가) 죽었습니다.\n";
    }
    else {
    std::cout
        << GetName()
        << "의 남은 체력: "
        << GetCurrentHP()
        << " / "
        << GetMaxHP()
        << '\n';
    }
}
