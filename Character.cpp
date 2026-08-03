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
    return maximumHealth
        + additionalMaximumHealth
        + gearMaxHealth;
} //체력 + 추가체력 + 장비체력

int Character::GetCurrentMP() const {
    return currentMana;
}

int Character::GetMaxMP() const {
    return maximumMana
        + additionalMaximumMana
        + gearMaxMana;
} //마나 + 추가마나 + 장비마나

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
    return attack
        + additionalAttack
        + gearAttack;
} //공격력 + 추가공격력 + 장비공격력

int Character::GetDefense() const {
    return defense
        + additionalDefense
        + gearDefense;
} //방어력과 + 추가방어력 + 장비방어력

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

const Job* Character::GetJob() const {
    return job;
}

Inventory& Character::GetInventory() {
    return inventory;
}

int Character::GetCurrentEquippedWeapon() const
{
    return currentEquippedWeapon;
}

int Character::GetGearAttack() const
{
    return gearAttack;
}

int Character::GetGearDefense() const
{
    return gearDefense;
}

int Character::GetGearMaxHealth() const
{
    return gearMaxHealth;
}

int Character::GetGearMaxMana() const
{
    return gearMaxMana;
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

/// <summary>
/// TODO: 안쓰네! CharacterLevelUP을 쓰네!
/// </summary>
/// <param name="level"></param>


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

void Character::ChangeJob() {
    job = Job::SelectJob();

    std::cout
        << job->GetName()
        << "(으)로 전직했습니다.\n";
}

void Character::ShowCharacterInfo() const {
    std::cout << "이름 : " << name << '\n';
    std::cout << "직업 : ";
    if (job == nullptr) {
        std::cout << "무직\n";
    }
    else {
        std::cout << job->GetName() << '\n';
    }
    std::cout << "레벨 : " << level << " (" << currentExperience << '/' << maximumExperience << ")\n";

    std::cout
    << "체력 : "
    << GetCurrentHP()
    << " / "
    << GetMaxHP()
    << '\n';

    std::cout
    << "마나 : "
    << GetCurrentMP()
    << " / "
    << GetMaxMP()
    << '\n';

    std::cout << "공격력 : " << GetAttack();
    if (additionalAttack > 0)
        std::cout << " (+" << additionalAttack << ')';
    std::cout << '\n';

    std::cout << "방어력 : " << GetDefense();
    if (additionalDefense > 0)
        std::cout << " (+" << additionalDefense << ')';
    std::cout << '\n';

    std::cout << "보유 스킬 :\n";

    if (learnedSkills.empty()) {
        std::cout << "  없음\n";
    }
    else {
        for (const Skill* skill : learnedSkills) {
            if (skill == nullptr) {
                continue;
            }

            std::cout
            << "  - "
            << skill->GetName()
            << '\n'
            << "    피해 계수 : "
            << skill->GetDamagePercent()
            << "% "
            << "    MP 소모 : "
            << skill->GetManaCost()
            << ' '
            << "    발동 확률 : "
            << skill->GetActivationChance()
            << "% ";
    }
}

    std::cout << "소지금 : " << money << '\n';
    inventory.ShowItems();
    std::cout << ">> 계속하려면 아무 키나 누르세요" << std::endl;
    (void)_getch();
}


void Character::LevelUP() {
    currentExperience -= maximumExperience;
    level += 1;

    maximumHealth += level * 20;
    maximumMana += level * 20;

    attack += level * 5;
    defense += level * 5;

    currentHealth = GetMaxHP();
    currentMana = GetMaxMP();

    if (level == 2) {
        ChangeJob();
    }

    LearnAvailableSkills();

    if (level == 10) {
        std::cout
            << "이제 일반 몬스터는 상대도 안 된다!\n";
    }
}

void Character::Attack() {
    if (target == nullptr) {
        return;
    }

    const Skill* selectedSkill =
        SelectSkill();

    if (selectedSkill != nullptr) {
        selectedSkill->Use(*this, *target);
        return;
    }

    NormalAttack();
}


//이렇게 쓰는게 맞는지 모르겠네요 찾아보고 한거긴 한데 제대로 작동하는지 검증이 안됨
const Skill* Character::SelectSkill()
{
    if (learnedSkills.empty()) {
        return nullptr;
    }

    const int roll =
        random.GetRandomValue(1, 100);

    int accumulatedChance = 0;

    for (const Skill* skill : learnedSkills) {
        if (skill == nullptr) {
            continue;
        }

        accumulatedChance +=
            skill->GetActivationChance();

        if (roll <= accumulatedChance) {
            if (skill->CanUse(*this)) {
                return skill;
            }

            return nullptr;
        }
    }

    return nullptr;
}

void Character::NormalAttack()
{
    if (target == nullptr) {
        return;
    }

    const int damage = GetAttack();

    std::cout
        << GetName()
        << "이(가) 공격하였습니다. ("
        << damage
        << ")\n";

    target->TakeDamage(damage);
}

void Character::TakeDamage(int damage) {
    int damageReduction = GetDefense() * 5 / 100; //방어력의 5%만큼 고정수치 피해감소
    int actualDamage = std::max(1, damage - damageReduction); //최소 1의 데미지는 입음
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

void Character::SetEquippedWeapon(
    int itemID,
    int weaponAttack,
    int weaponDefense,
    int weaponMaxHealth,
    int weaponMaxMana
) {
    if (itemID < 0) {
        return;
    }

    currentEquippedWeapon = itemID;

    gearAttack = weaponAttack;
    gearDefense = weaponDefense;
    gearMaxHealth = weaponMaxHealth;
    gearMaxMana = weaponMaxMana;

    // 장비 교체로 최대치가 감소했을 경우 보정
    currentHealth = std::min(currentHealth, GetMaxHP());
    currentMana = std::min(currentMana, GetMaxMP());
}

void Character::ClearEquippedWeapon()
{
    currentEquippedWeapon = noWeapon;

    gearAttack = 0;
    gearDefense = 0;
    gearMaxHealth = 0;
    gearMaxMana = 0;

    currentHealth = std::min(currentHealth, GetMaxHP());
    currentMana = std::min(currentMana, GetMaxMP());
}

const std::vector<const Skill*>&
Character::GetLearnedSkills() const
{
    return learnedSkills;
}

void Character::LearnAvailableSkills()
{
    if (job == nullptr) {
        return;
    }

    for (const Skill& skill : job->GetSkills()) {
        if (level < skill.GetRequiredLevel()) {
            continue;
        }

        learnedSkills.push_back(&skill);

        std::cout
            << "\n================================\n"
            << "새로운 스킬을 배웠습니다!\n"
            << "스킬 : "
            << skill.GetName()
            << '\n'
            << "피해 계수 : "
            << skill.GetDamagePercent()
            << "%\n"
            << "MP 소모 : "
            << skill.GetManaCost()
            << '\n'
            << "발동 확률 : "
            << skill.GetActivationChance()
            << "%\n"
            << "================================\n";
    }
}